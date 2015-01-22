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
#include "TrackParamList.h"
#include "GlobalParamList.h"

class Source : public AudioSource
{
    
public:
    Source(int trackId, String name, MidiMessageCollector& midiCollector, globalParamList* globalParams);
    ~Source();
    
    void updateSampleRate(int sampleRate);
    void prepareToPlay(int samplesPerBlockExpected, double sampleRate);
    void releaseResources();
    void getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill);
    
    void setLevel(float value);
    void setMute(bool isMuted);
    void setSample(int value);
    void setAttack(float value);
    void setDecay(float value);
    void setPitch(float value);
    void setDistort(float value);
    void setCutoff(float value);
    
    float foldback(float in, float threshold);
    
    MidiMessageCollector& midiCollector;
    String name;
    int trackId;
    
    MidiBuffer incomingMidi;
    
protected:
    
    void configure(int trackId);
    void setup(int index, int note, int numSounds, MemoryInputStream* streams[]);
    
    IIRFilter filterL;
    IIRFilter filterR;

    trackParamList* trackParams = new trackParamList();
    Sampler sampler;
    double sampleRate;
    globalParamList* globalParams;
};


#endif  // SILVERSYNTHESIZER_H_INCLUDED
