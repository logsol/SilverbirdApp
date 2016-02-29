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
#include "Parameter.h"

class Sampler : public Synthesiser {
public:
    
    Sampler(int trackId, OwnedArray<Parameter>* parameters);
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
    void setModulations(Array<float>* currentModulations);
    Array<float>* currentModulations = nullptr;
    
protected:
    int trackId;
    OwnedArray<Parameter>* parameters;
};



#endif  // SAMPLER_H_INCLUDED
