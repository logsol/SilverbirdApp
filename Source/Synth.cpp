/*
  ==============================================================================

    Synth.cpp
    Created: 10 Feb 2014 12:08:13am
    Author:  Pannek Karl

  ==============================================================================
*/

#include "Synth.h"
#include "Sound.h"

Synth::Synth()
{
    /*
    AiffAudioFormat aifFormat;
    ScopedPointer<AudioFormatReader> sampleReader;
    
    // KICK
    int index = 0;
    int note = 36;
	const int numKicks = 5;
    
    kickTrack.setTrackIndex(index);
    kickTrack.setNote(note);
    kickTrack.setNumberOfSounds(numKicks);
    
    MemoryInputStream *kicks[numKicks] = {
        new MemoryInputStream (BinaryData::kick1_aif, BinaryData::kick1_aifSize, false),
        new MemoryInputStream (BinaryData::kick2_aif, BinaryData::kick2_aifSize, false),
        new MemoryInputStream (BinaryData::kick3_aif, BinaryData::kick3_aifSize, false),
        new MemoryInputStream (BinaryData::kick4_aif, BinaryData::kick4_aifSize, false),
        new MemoryInputStream (BinaryData::kick5_aif, BinaryData::kick5_aifSize, false)
    };
    
    kickTrack.clearSounds();
    for(int i = 0; i < numKicks; i++) {
        sampleReader = aifFormat.createReaderFor (kicks[i], true);
        kickTrack.addSound(new Sound ("sound", note, i, *sampleReader));
    }
    
    
    // Snare
    index = 1;
    note = 36;
	const int numSnares = 5;
    
    snareTrack.setTrackIndex(index);
    snareTrack.setNote(note);
    snareTrack.setNumberOfSounds(numSnares);
    
    MemoryInputStream *snares[numSnares] = {
        new MemoryInputStream (BinaryData::snare1_aif, BinaryData::snare1_aifSize, false),
        new MemoryInputStream (BinaryData::snare2_aif, BinaryData::snare2_aifSize, false),
        new MemoryInputStream (BinaryData::snare3_aif, BinaryData::snare3_aifSize, false),
        new MemoryInputStream (BinaryData::snare4_aif, BinaryData::snare4_aifSize, false),
        new MemoryInputStream (BinaryData::snare5_aif, BinaryData::snare5_aifSize, false)
    };
    
    snareTrack.clearSounds();
    for(int i = 0; i < numSnares; i++) {
        sampleReader = aifFormat.createReaderFor (snares[i], true);
        snareTrack.addSound(new Sound ("sound", note, i, *sampleReader));
    }
    
    // Hihat
    index = 2;
    note = 42;
	const int numHihats = 5;
    
    hihatTrack.setTrackIndex(index);
    hihatTrack.setNote(note);
    hihatTrack.setNumberOfSounds(numHihats);
    
    MemoryInputStream *hihats[numHihats] = {
        new MemoryInputStream (BinaryData::hihat1_aif, BinaryData::hihat1_aifSize, false),
        new MemoryInputStream (BinaryData::hihat2_aif, BinaryData::hihat2_aifSize, false),
        new MemoryInputStream (BinaryData::hihat3_aif, BinaryData::hihat3_aifSize, false),
        new MemoryInputStream (BinaryData::hihat4_aif, BinaryData::hihat4_aifSize, false),
        new MemoryInputStream (BinaryData::hihat5_aif, BinaryData::hihat5_aifSize, false)
    };
    
    hihatTrack.clearSounds();
    for(int i = 0; i < numHihats; i++) {
        sampleReader = aifFormat.createReaderFor (hihats[i], true);
        hihatTrack.addSound(new Sound ("sound", note, i, *sampleReader));
    }
    */
    
    //// ALL
    
    // KICK
	const int numKicks = 5;
    MemoryInputStream* kicks[numKicks] = {
        new MemoryInputStream (BinaryData::kick1_aif, BinaryData::kick1_aifSize, false),
        new MemoryInputStream (BinaryData::kick2_aif, BinaryData::kick2_aifSize, false),
        new MemoryInputStream (BinaryData::kick3_aif, BinaryData::kick3_aifSize, false),
        new MemoryInputStream (BinaryData::kick4_aif, BinaryData::kick4_aifSize, false),
        new MemoryInputStream (BinaryData::kick5_aif, BinaryData::kick5_aifSize, false)
    };
    addTrack(0, 36, numKicks, kicks, &kickTrack);
    
    // SNARE
	const int numSnares = 5;
    MemoryInputStream* snares[numSnares] = {
        new MemoryInputStream (BinaryData::snare1_aif, BinaryData::snare1_aifSize, false),
        new MemoryInputStream (BinaryData::snare2_aif, BinaryData::snare2_aifSize, false),
        new MemoryInputStream (BinaryData::snare3_aif, BinaryData::snare3_aifSize, false),
        new MemoryInputStream (BinaryData::snare4_aif, BinaryData::snare4_aifSize, false),
        new MemoryInputStream (BinaryData::snare5_aif, BinaryData::snare5_aifSize, false)
    };
    addTrack(0, 38, numSnares, snares, &snareTrack);
    
    // KICK
	const int numHihats = 5;
    MemoryInputStream* hihats[numHihats] = {
        new MemoryInputStream (BinaryData::hihat1_aif, BinaryData::hihat1_aifSize, false),
        new MemoryInputStream (BinaryData::hihat2_aif, BinaryData::hihat2_aifSize, false),
        new MemoryInputStream (BinaryData::hihat3_aif, BinaryData::hihat3_aifSize, false),
        new MemoryInputStream (BinaryData::hihat4_aif, BinaryData::hihat4_aifSize, false),
        new MemoryInputStream (BinaryData::hihat5_aif, BinaryData::hihat5_aifSize, false)
    };
    addTrack(0, 42, numHihats, hihats, &hihatTrack);
}
Synth::~Synth() {
}

void Synth::addTrack(int index, int note, int numSounds, MemoryInputStream* streams[], Track* track) {

    AiffAudioFormat aifFormat;
    ScopedPointer<AudioFormatReader> sampleReader;
    
    
    track->setTrackIndex(index);
    track->setNote(note);
    track->setNumberOfSounds(numSounds);
    
    
    
    track->clearSounds();
    for(int i = 0; i < numSounds; i++) {
        sampleReader = aifFormat.createReaderFor (streams[i], true);
        track->addSound(new Sound ("sound", note, i, *sampleReader));
    }
}

void Synth::updateSampleRate(int sampleRate) {
    kickTrack.setCurrentPlaybackSampleRate(sampleRate);
    snareTrack.setCurrentPlaybackSampleRate(sampleRate);
    hihatTrack.setCurrentPlaybackSampleRate(sampleRate);
}

void Synth::renderNextBlock (AudioSampleBuffer outputAudio, const MidiBuffer inputMidi, int startSample, int numSamples) {
    kickTrack.renderNextBlock(outputAudio, inputMidi, startSample, numSamples);
    snareTrack.renderNextBlock(outputAudio, inputMidi, startSample, numSamples);
    hihatTrack.renderNextBlock(outputAudio, inputMidi, startSample, numSamples);
}

void Synth::noteOn (int midiChannel, int midiNoteNumber, float velocity) {
    kickTrack.noteOn(midiChannel, midiNoteNumber, velocity);
	snareTrack.noteOn(midiChannel, midiNoteNumber, velocity);
    hihatTrack.noteOn(midiChannel, midiNoteNumber, velocity);
}




