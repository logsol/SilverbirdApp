/*
  ==============================================================================

    Synth.cpp
    Created: 10 Feb 2014 12:08:13am
    Author:  Pannek Karl

  ==============================================================================
*/

#include "Source.h"
#include "Sound.h"
#include "Mixer.h"



Source::Source(int trackId, String name, MidiMessageCollector& midiCollector) :
    midiCollector (midiCollector),
    name (name),
    trackId (trackId)
{
    //std::cout << "configuring track: " << trackId << ". Name: " << name << std::endl;
    configure(trackId);
}

Source::~Source() {

}

void Source::configure(int trackId)
{
    
    switch (trackId) {
        {
        case Mixer::kick:
            const int numKicks = 5;
            MemoryInputStream* kicks[numKicks] = {
                new MemoryInputStream (BinaryData::kick1_aif, BinaryData::kick1_aifSize, false),
                new MemoryInputStream (BinaryData::kick2_aif, BinaryData::kick2_aifSize, false),
                new MemoryInputStream (BinaryData::kick3_aif, BinaryData::kick3_aifSize, false),
                new MemoryInputStream (BinaryData::kick4_aif, BinaryData::kick4_aifSize, false),
                new MemoryInputStream (BinaryData::kick5_aif, BinaryData::kick5_aifSize, false)
            };
            setup(Mixer::trackIndex::kick, 36, numKicks, kicks);
            break;
        }
        {
        case Mixer::snare:
            const int numSnares = 5;
            MemoryInputStream* snares[numSnares] = {
                new MemoryInputStream (BinaryData::snare1_aif, BinaryData::snare1_aifSize, false),
                new MemoryInputStream (BinaryData::snare2_aif, BinaryData::snare2_aifSize, false),
                new MemoryInputStream (BinaryData::snare3_aif, BinaryData::snare3_aifSize, false),
                new MemoryInputStream (BinaryData::snare4_aif, BinaryData::snare4_aifSize, false),
                new MemoryInputStream (BinaryData::snare5_aif, BinaryData::snare5_aifSize, false)
            };
            setup(Mixer::trackIndex::snare, 38, numSnares, snares);
            break;
        }
        {
        case Mixer::hihat:
            const int numHihats = 5;
            MemoryInputStream* hihats[numHihats] = {
                new MemoryInputStream (BinaryData::hihat1_aif, BinaryData::hihat1_aifSize, false),
                new MemoryInputStream (BinaryData::hihat2_aif, BinaryData::hihat2_aifSize, false),
                new MemoryInputStream (BinaryData::hihat3_aif, BinaryData::hihat3_aifSize, false),
                new MemoryInputStream (BinaryData::hihat4_aif, BinaryData::hihat4_aifSize, false),
                new MemoryInputStream (BinaryData::hihat5_aif, BinaryData::hihat5_aifSize, false)
            };
            setup(Mixer::trackIndex::hihat, 42, numHihats, hihats);
        }
        {
        default:
            break;
        }
    }
}

void Source::setup(int index, int note, int numSounds, MemoryInputStream* streams[])
{
    sampler.setNote(note);
    sampler.setNumberOfSounds(numSounds);
    sampler.clearSounds();
    
    AiffAudioFormat aifFormat;
    ScopedPointer<AudioFormatReader> sampleReader;
    
    for(int i = 0; i < numSounds; i++) {
        sampleReader = aifFormat.createReaderFor (streams[i], true);
        sampler.addSound(new Sound ("sound", note, i, *sampleReader));
    }
}

void Source::updateSampleRate(int sampleRate) {
    sampler.setCurrentPlaybackSampleRate(sampleRate);
}

void Source::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    midiCollector.reset (sampleRate);
    updateSampleRate(sampleRate);
}

void Source::releaseResources()
{
}

void Source::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    bufferToFill.clearActiveBufferRegion();
    
    midiCollector.removeNextBlockOfMessages (incomingMidi, bufferToFill.numSamples);

    sampler.renderNextBlock(*bufferToFill.buffer, incomingMidi, 0, bufferToFill.numSamples);
    bufferToFill.buffer->applyGain(0, bufferToFill.numSamples, level * (!mute));
}

void Source::setLevel(float value)
{
    level = value;
}

void Source::setMute(bool isMuted)
{
    mute = isMuted;
}

void Source::setSample(int value)
{
    sampler.setSelection(value);
}
