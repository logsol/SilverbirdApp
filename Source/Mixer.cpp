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
    Source* source = new Source(trackId, String("track") + String(trackId), midiCollector, &globalParams);
    
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
    
    bufferToFill.buffer->applyGain(globalParams.master);
}

void Mixer::playNote(int note, float velocity)
{
    // dying here? probably forgot to bootstrap.
    midiCollector.handleNoteOn(&keyboardState, 1, note, velocity);
//    midiCollector.handleNoteOff(&keyboardState, 1, note);
}

void Mixer::setSampleAll (int value)
{
    globalParams.sample = value;
}

void Mixer::setPitch(float value)
{
    globalParams.pitch = value;
}

void Mixer::setDecay(float value)
{
    globalParams.decay = value;
}

void Mixer::setDistort(float value)
{
    globalParams.distort = value;
}

void Mixer::setCutoff(float value)
{
    globalParams.cutoff = value;
}

void Mixer::setShuffle(float value)
{
    globalParams.shuffle = value;
}

void Mixer::setMaster (float value)
{
    globalParams.master = value;
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
