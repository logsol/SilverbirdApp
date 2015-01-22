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
    delete globalParams;
}

void Mixer::createAndAddTrack(int trackId, String name)
{
    
    Source* source = new Source(trackId, name, midiCollector, globalParams);
    
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
    
    bufferToFill.buffer->applyGain(globalParams->master);
}

void Mixer::playNote(int note)
{
    midiCollector.handleNoteOn(&keyboardState, 1, note, 1);
//    midiCollector.handleNoteOff(&keyboardState, 1, note);
}

void Mixer::setSampleAll (int value)
{
    globalParams->sample = value;
}

void Mixer::setPitch(float value)
{
    globalParams->pitch = value;
}

void Mixer::setDecay(float value)
{
    globalParams->decay = value;
}

void Mixer::setDistort(float value)
{
    globalParams->distort = value;
}

void Mixer::setCutoff(float value)
{
    globalParams->cutoff = value;
}

void Mixer::setShuffle(float value)
{
    globalParams->shuffle = value;
}

void Mixer::setMaster (float value)
{
    globalParams->master = value;
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

void Mixer::setTrackSample(int value, int trackId)
{
    Source* source = getTrackById(trackId);
    source->setSample(value);
}

void Mixer::setTrackAttack(float value, int trackId)
{
    Source* source = getTrackById(trackId);
    source->setAttack(value);
}

void Mixer::setTrackDecay(float value, int trackId)
{
    Source* source = getTrackById(trackId);
    source->setDecay(value);
}

void Mixer::setTrackPitch(float value, int trackId)
{
    Source* source = getTrackById(trackId);
    source->setPitch(value);
}

void Mixer::setTrackDistort(float value, int trackId)
{
    Source* source = getTrackById(trackId);
    source->setDistort(value);
}

void Mixer::setTrackCutoff(float value, int trackId)
{
    Source* source = getTrackById(trackId);
    source->setCutoff(value);
}
