/*
  ==============================================================================

    Mixer.cpp
    Created: 16 Jan 2015 11:11:23am
    Author:  Karl

  ==============================================================================
*/

#include "Mixer.h"

Mixer::Mixer()
{
    createAndAddTrack(0, "Kick");
    createAndAddTrack(1, "Snare");
    createAndAddTrack(2, "Hihat");
}

Mixer::~Mixer() {
}

void Mixer::createAndAddTrack(int trackId, String name)
{
    
    Source* source = new Source(trackId, name, midiCollector);
    
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
}

void Mixer::playNote(int note)
{
    midiCollector.handleNoteOn(&keyboardState, 1, note, 1);
}

void Mixer::setMaster (float value)
{
}

void Mixer::setTrackLevel (float value, int trackId)
{
    Source* source = getTrackById(trackId);
    source->setLevel(value);
}

void Mixer::setTrackMute (bool value, int trackId)
{
    Source* source = getTrackById(trackId);
    source->setMute(value);
}
