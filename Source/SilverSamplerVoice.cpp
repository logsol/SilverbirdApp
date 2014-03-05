/*
  ==============================================================================

    SilverSamplerVoice.cpp
    Created: 7 Feb 2014 12:59:57am
    Author:  Pannek Karl

  ==============================================================================
*/

#include "SilverSamplerVoice.h"



//==============================================================================
SilverSamplerVoice::SilverSamplerVoice()
: pitchRatio (0.0),
sourceSamplePosition (0.0),
lgain (0.0f), rgain (0.0f),
attackReleaseLevel (0), attackDelta (0), releaseDelta (0),
isInAttack (false), isInRelease (false)
{
}

SilverSamplerVoice::~SilverSamplerVoice()
{
}

bool SilverSamplerVoice::canPlaySound (SynthesiserSound* sound)
{
    return dynamic_cast<const SilverSamplerSound*> (sound) != nullptr;
}

void SilverSamplerVoice::startNote (const int midiNoteNumber,
                                    const float velocity,
                                    SynthesiserSound* s,
                                    const int /*currentPitchWheelPosition*/)
{
    
    if (const SilverSamplerSound* const sound = dynamic_cast <const SilverSamplerSound*> (s))
    {
        //pitchRatio = pow (2.0, (midiNoteNumber - sound->midiRootNote) / 12.0) * sound->sourceSampleRate / getSampleRate();
        pitchRatio = 1;
        
        sourceSamplePosition = 0.0;
        lgain = velocity;
        rgain = velocity;
        
        isInAttack = (sound->attackSamples > 0);
        isInRelease = false;
        
        if (isInAttack)
        {
            attackReleaseLevel = 0.0f;
            attackDelta = (float) (pitchRatio / sound->attackSamples);
        }
        else
        {
            attackReleaseLevel = 1.0f;
            attackDelta = 0.0f;
        }
        
        if (sound->releaseSamples > 0)
            releaseDelta = (float) (-pitchRatio / sound->releaseSamples);
        else
            releaseDelta = 0.0f;
    }
    else
    {
        jassertfalse; // this object can only play SilverSamplerSounds!
    }
}

void SilverSamplerVoice::stopNote (const bool allowTailOff)
{
    if (allowTailOff)
    {
        isInAttack = false;
        isInRelease = true;
    }
    else
    {
        clearCurrentNote();
    }
}

void SilverSamplerVoice::pitchWheelMoved (const int /*newValue*/)
{
}

void SilverSamplerVoice::controllerMoved (const int /*controllerNumber*/,
                                          const int /*newValue*/)
{
}

//==============================================================================
void SilverSamplerVoice::renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
    if (const SilverSamplerSound* const playingSound = static_cast <SilverSamplerSound*> (getCurrentlyPlayingSound().get()))
    {
        const float* const inL = playingSound->data->getSampleData (0, 0);
        const float* const inR = playingSound->data->getNumChannels() > 1
        ? playingSound->data->getSampleData (1, 0) : nullptr;
        
        float* outL = outputBuffer.getSampleData (0, startSample);
        float* outR = outputBuffer.getNumChannels() > 1 ? outputBuffer.getSampleData (1, startSample) : nullptr;
        
        while (--numSamples >= 0)
        {
            const int pos = (int) sourceSamplePosition;
            const float alpha = (float) (sourceSamplePosition - pos);
            const float invAlpha = 1.0f - alpha;
            
            // just using a very simple linear interpolation here..
            float l = (inL [pos] * invAlpha + inL [pos + 1] * alpha);
            float r = (inR != nullptr) ? (inR [pos] * invAlpha + inR [pos + 1] * alpha)
            : l;
            
            l *= lgain;
            r *= rgain;
            
            if (isInAttack)
            {
                l *= attackReleaseLevel;
                r *= attackReleaseLevel;
                
                attackReleaseLevel += attackDelta;
                
                if (attackReleaseLevel >= 1.0f)
                {
                    attackReleaseLevel = 1.0f;
                    isInAttack = false;
                }
            }
            else if (isInRelease)
            {
                l *= attackReleaseLevel;
                r *= attackReleaseLevel;
                
                attackReleaseLevel += releaseDelta;
                
                if (attackReleaseLevel <= 0.0f)
                {
                    stopNote (false);
                    break;
                }
            }
            
            if (outR != nullptr)
            {
                *outL++ += l;
                *outR++ += r;
            }
            else
            {
                *outL++ += (l + r) * 0.5f;
            }
            
            sourceSamplePosition += pitchRatio;
            
            if (sourceSamplePosition > playingSound->length)
            {
                stopNote (false);
                break;
            }
        }
    }
}