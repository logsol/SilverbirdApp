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
}
Synth::~Synth() {
}

void Synth::updateSampleRate(int sampleRate) {
    kickTrack.setCurrentPlaybackSampleRate(sampleRate);
}

void Synth::renderNextBlock (AudioSampleBuffer outputAudio, const MidiBuffer inputMidi, int startSample, int numSamples) {
    kickTrack.renderNextBlock(outputAudio, inputMidi, startSample, numSamples);
}

void Synth::noteOn (int midiChannel, int midiNoteNumber, float velocity) {
    kickTrack.noteOn(midiChannel, midiNoteNumber, velocity);
}




