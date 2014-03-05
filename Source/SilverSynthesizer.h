/*
  ==============================================================================

    SilverSynthesizer.h
    Created: 10 Feb 2014 12:08:13am
    Author:  Pannek Karl

  ==============================================================================
*/

#ifndef SILVERSYNTHESIZER_H_INCLUDED
#define SILVERSYNTHESIZER_H_INCLUDED


#include "../JuceLibraryCode/JuceHeader.h"
#include "SilverSamplerSound.h"
#include "SilverSamplerVoice.h"

class SilverSynthesizer : public Synthesiser {
    
public:
    SilverSynthesizer();
    ~SilverSynthesizer();
    
    void noteOn(const int midiChannel, const int midiNoteNumber, const float velocity);
    
    int getCurrentSelection(int midiNoteNumber);
    void addKicks(int midiNoteNumber);

protected:
};


#endif  // SILVERSYNTHESIZER_H_INCLUDED
