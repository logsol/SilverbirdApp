/*
  ==============================================================================

    Mixer.cpp
    Created: 16 Jan 2015 11:11:23am
    Author:  Karl

  ==============================================================================
*/

#include "Mixer.h"
#include "Controller.h"
#include "Parameter.h"

Mixer::Mixer(OwnedArray<Parameter>* parameters) : parameters(parameters)
{
    for (int i = 0; i < Mixer::tracks::max; i++) {
        createAndAddTrack(i);
    }
}

Mixer::~Mixer() {
}

String Mixer::getNameByTrackId(int trackId, bool isModulationTrack)
{
    if (isModulationTrack) {
        switch (trackId) {
            case Mixer::mods::sample:
                return "Select";
            case Mixer::mods::pitch:
                return "Pitch";
            case Mixer::mods::decay:
                return "Decay";
            case Mixer::mods::cutoff:
                return "Filter";
            default:
                break;
        }
    }
    
    switch (trackId) {
        case Mixer::tracks::kick:
            return "Kick";
        case Mixer::tracks::snare:
            return "Snare";
        case Mixer::tracks::hihat:
            return "Hihat";
        case Mixer::tracks::perc1:
            return "Perc1";
        case Mixer::tracks::perc2:
            return "Perc2";
        case Mixer::tracks::tones:
            return "Tones";
            
    }
    return "<Undefined> Track";
}

void Mixer::createAndAddTrack(int trackId)
{
    Source* source = new Source(trackId, String("track") + String(trackId), midiCollector, parameters);
    
    addInputSource(source, false);
    
    sources.insert(trackId, source);
}

Source* Mixer::getTrackById(int trackId)
{
    return sources[trackId];
}

void Mixer::prepareToPlay (int samplesPerBlockExpected, double sampleRate) {
    midiCollector.reset (sampleRate);
    MixerAudioSource::prepareToPlay(samplesPerBlockExpected, sampleRate);
}

void Mixer::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    bufferToFill.clearActiveBufferRegion();
    
    MidiBuffer incomingMidi;
    
    midiCollector.removeNextBlockOfMessages (incomingMidi, bufferToFill.numSamples);
    
    for (int i=0; i<sources.size(); i++) {
        // copying object with copy constructor:
        //fixme: shouldnt copy constructor look like MidiBuffer sharedMidi(incomingMidi) ?
        MidiBuffer sharedMidi = incomingMidi;
        sources[i]->incomingMidi = sharedMidi;
    }
    
    MixerAudioSource::getNextAudioBlock(bufferToFill);

    float level = parameters->getUnchecked(Controller::getParameterId(Controller::params::level))->getValue();
    bufferToFill.buffer->applyGainRamp(0, bufferToFill.numSamples, lastLevel, level);
    lastLevel = level;
}

void Mixer::playNote(int note, float velocity)
{
    midiCollector.handleNoteOn(&keyboardState, 1, note, velocity);
}

int Mixer::getNumberOfSoundsByTrack(int track)
{
    return sources.getUnchecked(track)->getNumberOfSounds();
}

void Mixer::setColumnModulations(Array<float>* currentModulations)
{
    // setting all sources with modulation so far. (no target selection yet)
    for (int i=0; i<sources.size(); i++) {
        sources[i]->setModulations(currentModulations);
    }
}