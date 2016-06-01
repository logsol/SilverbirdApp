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
#include "DelayAudioSource.cpp"
#include "ReverberationAudioSource.cpp"


Mixer::Mixer(Controller* controller) : controller(controller)
{
    const bool deleteOnRemove = true;
    
    delayAudioSource = new DelayAudioSource();
    
    for (int i = 0; i < Mixer::tracks::max; i++) {
        createAndAddTrack(i, deleteOnRemove);
        delayAudioSource->addInputSource(sources[i]->getDelayBus(), deleteOnRemove);
        //reverbAudioSource->addInputSource(sources[i]->getReverbBus(), deleteOnRemove);
    }
    
    addInputSource(delayAudioSource, deleteOnRemove);
    addInputSource(reverbAudioSource, deleteOnRemove);
}

Mixer::~Mixer() {
    //faustDelay = nullptr;
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

void Mixer::createAndAddTrack(int trackId, const bool deleteWhenRemoved)
{
    Source* source = new Source(trackId, String("track") + String(trackId), midiCollector, controller);
    
    addInputSource(source, deleteWhenRemoved);
    
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

    float level = controller->getParameterValue(Controller::params::level);
    bufferToFill.buffer->applyGainRamp(0, bufferToFill.numSamples, lastLevel, level);
    lastLevel = level;
    
    //const float* buf = bufferToFill.buffer->getReadPointer(0);
    //std::cout << round(*buf * 1000)/1000.0 << std::endl;
}

void Mixer::playNote(int note, float velocity)
{
    midiCollector.handleNoteOn(&keyboardState, 1, note, velocity);
}

int Mixer::getNumberOfSoundsByTrack(int track)
{
    return sources.getUnchecked(track)->getNumberOfSounds();
}

void Mixer::resetStepModulations()
{
    jassert(Mixer::tracks::max == sources.size());
    
    for (int i = 0; i < Mixer::tracks::max; i++) {
        sources[i]->resetStepModulations();
    }
}

void Mixer::addStepModulationValue(int modTrackId, float value, int targetTrackId)
{
    jassert(isPositiveAndBelow(targetTrackId, sources.size()));
    
    sources[targetTrackId]->addStepModulationValue(modTrackId, value);
}
