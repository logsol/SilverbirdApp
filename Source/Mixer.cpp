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
    for (int i = 0; i < maxTracks; i++) {
        createAndAddTrack(i);
    }
}

Mixer::~Mixer() {
}

int Mixer::getTrackByName(String name)
{
    for (int i = 0; i < maxTracks; i++) {
        if (getNameByTrackId(i) == name) {
            return i;
        }
    }
    
    std::cout << "Got Wrong Track: " << name << std::endl;
    std::cout << "This means, that SNARE is being used as a default." << std::endl;
    return Mixer::snare;
}

String Mixer::getNameByTrackId(int trackId)
{
    switch (trackId) {
        case Mixer::kick:
            return "kick";
        case Mixer::snare:
            return "snare";
        case Mixer::hihat:
            return "hihat";
        case Mixer::perc1:
            return "perc1";
        case Mixer::perc2:
            return "perc2";
        case Mixer::tones:
            return "tones";
            
    }
    std::cout << "Got Wrong Track id: " << trackId << std::endl;
    return "snare";
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
