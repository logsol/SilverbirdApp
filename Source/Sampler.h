/*
  ==============================================================================

    Track.h
    Created: 5 Mar 2014 6:19:52pm
    Author:  Pannek Karl

  ==============================================================================
*/

#ifndef TRACK_H_INCLUDED
#define TRACK_H_INCLUDED

#include "JuceHeader.h"
#include "Sound.h"
class Source;
class Controller;

class Sampler : public Synthesiser {
public:
    
    Sampler(int trackId, Source* source, Controller* controller);
    ~Sampler();
    
    void setSelection(int selection);
    int getSelection();
    
    void noteOn(const int midiChannel, const int midiNoteNumber, const float velocity) override;
    void stopVoice (SynthesiserVoice* voice, const bool allowTailOff);
    virtual SynthesiserVoice* findFreeVoice (SynthesiserSound* soundToPlay,
                                             int midiChannel,
                                             int midiNoteNumber,
                                             bool stealIfNoneAvailable) const override;
    
    int getNumberOfSounds();

    
protected:
    int trackId;
    Controller* controller;
    Source* source;
};



#endif  // SAMPLER_H_INCLUDED
