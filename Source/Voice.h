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
    
    Voice(int id);
    ~Voice();
    
    void renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples) override;
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound*, int pitchWheel) override;
    void setVoiceParameters(float attack, float decay, float pitch);

protected:
    
    float translatePitchValue(float pitch);
    
    ADSR env;
    int lastEnvState = ADSR::env_idle;
    int id;
    float pitch;
    float velocity;
    
private:
    float posi;
//    JUCE_LEAK_DETECTOR (Voice);
};




#endif  // VOICE_H_INCLUDED
