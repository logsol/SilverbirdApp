/*
  ==============================================================================

    Synth.h
    Created: 10 Feb 2014 12:08:13am
    Author:  Pannek Karl

  ==============================================================================
*/

#ifndef SILVERSYNTHESIZER_H_INCLUDED
#define SILVERSYNTHESIZER_H_INCLUDED


#include "../JuceLibraryCode/JuceHeader.h"
#include "Sound.h"
#include "Sampler.h"

class Source : public AudioSource
{
    
public:
    Source(int trackId, String name, MidiMessageCollector& midiCollector);
    ~Source();
    
    void updateSampleRate(int sampleRate);
    void prepareToPlay(int samplesPerBlockExpected, double sampleRate);
    void releaseResources();
    void getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill);
    
    void setLevel(float value);
    void setMute(bool isMuted);
    void setSample(int value);
    
    MidiMessageCollector& midiCollector;
    String name;
    int trackId;
    
    MidiBuffer incomingMidi;
    
protected:
    
    void configure(int trackId);
    void setup(int index, int note, int numSounds, MemoryInputStream* streams[]);
    
    Sampler sampler;
    
    float level;
    bool mute;
    int sample;
    float attack;
    float decay;
};


#endif  // SILVERSYNTHESIZER_H_INCLUDED
