/*
  ==============================================================================

    Voice.cpp
    Created: 20 Jan 2015 6:41:18pm
    Author:  Karl

  ==============================================================================
*/

#include "Voice.h"
#include "Sound.h"

Voice::Voice (int id) : id(id)
{
    posi = 0;
    
    env.setTargetRatioA(.010);
    env.setTargetRatioDR(.010);
    
    env.setAttackRate(0);
    env.setDecayRate(0);
    
    env.setReleaseRate(0);
    env.setSustainLevel(0);
}

Voice::~Voice()
{
}

void Voice::renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
    Sound* sound = (Sound*) getCurrentlyPlayingSound().get();
    if(sound){
        AudioSampleBuffer* data = sound->getAudioData();

        
        const float* const inL = data->getReadPointer (0);
        const float* const inR = data->getNumChannels() > 1
            ? data->getReadPointer (1)
            : nullptr;
        
        float* outL = outputBuffer.getWritePointer (0, startSample);
        float* outR = outputBuffer.getNumChannels() > 1 ? outputBuffer.getWritePointer (1, startSample) : nullptr;
        
        while (--numSamples >= 0) {
            
            env.process();
            
            *outL++ += inL[(int) posi] * env.getOutput();
            *outR++ += inR[(int) posi] * env.getOutput();
            
            posi++;
            
            if (posi > data->getNumSamples())
            {
                posi = 0;
                stopNote (0.0f, false);
                break;
            }
        }
        
        if(env.getState() == env.env_sustain) {
            env.reset();
            stopNote(0, false);
        }
    }
}

void Voice::startNote (const int midiNoteNumber,
                             const float velocity,
                             SynthesiserSound* s,
                             const int pitchWheel)
{
    //std::cout << "playing voice nr: " << id << std::endl;
    
    SamplerVoice::startNote(midiNoteNumber, velocity, s, pitchWheel);
    env.reset();
    env.gate(1);
}

void Voice::setEnvelopeParameters(float attack, float decay)
{
    env.setAttackRate(attack * (float) getSampleRate());
    env.setDecayRate(decay * (float) getSampleRate());
}
