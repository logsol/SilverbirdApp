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
#include "Voice.h"
#include "Track.h"

class Synth {
    
public:
    Synth();
    ~Synth();

    void updateSampleRate(int sampleRate);
    void renderNextBlock (AudioSampleBuffer outputAudio,
                          const MidiBuffer inputMidi,
                          int startSample,
                          int numSamples);
    
    void noteOn (int midiChannel,
                         int midiNoteNumber,
                         float velocity);
    
    void addTrack (int index,
                  int note,
                  int numSounds,
                  MemoryInputStream* streams[],
                  Track* track);
    
    Track kickTrack;
    Track snareTrack;
    Track hihatTrack;
    
protected:
    int selection = 0;
    
    

};


#endif  // SILVERSYNTHESIZER_H_INCLUDED
