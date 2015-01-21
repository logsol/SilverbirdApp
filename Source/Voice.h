/*
  ==============================================================================

    Voice.h
    Created: 20 Jan 2015 6:41:18pm
    Author:  Karl

  ==============================================================================
*/

#ifndef VOICE_H_INCLUDED
#define VOICE_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "Sound.h"
#include "ADSR.h"

class Voice : public SamplerVoice
{
public:
    //==============================================================================
    
    Voice();
    ~Voice();
    
    void renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples) override;
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound*, int pitchWheel) override;

protected:
    ADSR env;
    double sourceSampleRate;
    int lastEnvState = ADSR::env_idle;
    
private:
    JUCE_LEAK_DETECTOR (Voice);
};




#endif  // VOICE_H_INCLUDED
