/*
  ==============================================================================

    Voice.cpp
    Created: 20 Jan 2015 6:41:18pm
    Author:  Karl

  ==============================================================================
*/

#include "Voice.h"
#include "Sound.h"

Voice::Voice ()
{
    sourceSampleRate = 44100.0;
    
    env.setTargetRatioA(.010);
    env.setTargetRatioDR(.010);
    
    env.setAttackRate(.001 * sourceSampleRate);
    env.setDecayRate(.03 * sourceSampleRate);
    
    env.setReleaseRate(0);
    env.setSustainLevel(0);
}

Voice::~Voice()
{
}

void Voice::renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
    SamplerVoice::renderNextBlock(outputBuffer, startSample, numSamples);
    float* outL = outputBuffer.getWritePointer (0, startSample);
    float* outR = outputBuffer.getNumChannels() > 1 ? outputBuffer.getWritePointer (1, startSample) : nullptr;

    while (--numSamples >= 0) {
        env.process();
        *outL++ *= env.getOutput();
        *outR++ *= env.getOutput();
    }
    
    if(env.getState() == env.env_sustain) {
        env.reset();
        stopNote(0, false);
    }
    
    // alternatively you could try
    // env.process();
    // outputBuffer.applyGain(env.getOutput());
}

void Voice::startNote (const int midiNoteNumber,
                              const float velocity,
                                SynthesiserSound* s,
                              const int pitchWheel)
{
    SamplerVoice::startNote(midiNoteNumber, velocity, s, pitchWheel);
    env.reset();
    env.gate(1);
}
