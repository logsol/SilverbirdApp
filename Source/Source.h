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
    Source(MidiKeyboardState& keyState);
    ~Source();
    
    void updateSampleRate(int sampleRate);
    void prepareToPlay(int samplesPerBlockExpected, double sampleRate);
    void releaseResources();
    void getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill);
    void renderNextBlock (AudioSampleBuffer outputAudio,
                          const MidiBuffer inputMidi,
                          int startSample,
                          int numSamples);
    
    void addTrack (int index,
                  int note,
                  int numSounds,
                  MemoryInputStream* streams[]);
    
    Sampler* getTrackByIndex(int index);
    void setMaster(float value);
    
    void setTrackVolume(float value, int trackIndex);
    
    MidiMessageCollector midiCollector;

    enum trackIndex {
        kick,
        snare,
        hihat,
        maxTracks
    };
    
protected:
    MidiKeyboardState& keyboardState;
    
    int selection = 0;
    int numTracks = 0;
    float gain;
    
    Sampler tracks[trackIndex::maxTracks];
};


#endif  // SILVERSYNTHESIZER_H_INCLUDED
