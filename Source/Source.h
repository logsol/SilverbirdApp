/*
  ==============================================================================

    Synth.h
    Created: 10 Feb 2014 12:08:13am
    Author:  Pannek Karl

  ==============================================================================
*/

#ifndef SILVERSYNTHESIZER_H_INCLUDED
#define SILVERSYNTHESIZER_H_INCLUDED


#include "JuceHeader.h"
#include "Sound.h"
#include "Sampler.h"
class Controller;

class Source : public AudioSource
{
    
    friend class Sampler;
    
public:
    Source(int trackId, String name, MidiMessageCollector& midiCollector, Controller* controller);
    ~Source();
    
    void updateSampleRate(int sampleRate);
    void prepareToPlay(int samplesPerBlockExpected, double sampleRate);
    void releaseResources();
    void getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill);
    
    float foldback(float in, float threshold);
    
    MidiMessageCollector& midiCollector;
    String name;
    int trackId;
    
    MidiBuffer incomingMidi;

    int getNumberOfSounds();
    
    void resetStepModulations();
    void addStepModulationValue(int paramId, float value);
    
protected:
    
    void configure(int trackId);
    void setup(int index, int note, int numSounds, MemoryInputStream* streams[]);
    
    IIRFilter filterL;
    IIRFilter filterR;

    double sampleRate;
    float lastLevel = 1;

    Sampler sampler;
    Controller* controller;
    
    Array<float> modulations;
};


#endif  // SILVERSYNTHESIZER_H_INCLUDED
