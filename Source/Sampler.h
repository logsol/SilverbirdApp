/*
  ==============================================================================

    Track.h
    Created: 5 Mar 2014 6:19:52pm
    Author:  Pannek Karl

  ==============================================================================
*/

#ifndef TRACK_H_INCLUDED
#define TRACK_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Sound.h"

class Sampler : public Synthesiser {
public:
    
    Sampler();
    ~Sampler();
    
    void setSelection(int selection);
    int getSelection(int note);
    
    void setTrackIndex(int index);
    int getTrackIndex();
    
    void setNote(int note);
    int getNote();
    
    void setNumberOfSounds(int numSounds);
    int getNumberOfSounds();
    
    void setMute(bool active);
    void setVolume(float value);
    float getVolume();
    
    void noteOn(const int midiChannel, const int midiNoteNumber, const float velocity);
    void stopVoice (SynthesiserVoice* voice, const bool allowTailOff);
    
protected:
    int trackIndex;
    int note;
    int numberOfSounds;
    int selection = 0;
    bool mute = false;
    float volume = 0;
};



#endif  // TRACK_H_INCLUDED
