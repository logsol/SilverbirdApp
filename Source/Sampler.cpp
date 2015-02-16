
/*
  ==============================================================================

    Sampler.cpp
    Created: 5 Mar 2014 6:19:52pm
    Author:  Pannek Karl

  ==============================================================================
*/

#include "Sampler.h"
#include "Voice.h"
#include "JuceHeader.h"
#include "Controller.h"
#include "Parameter.h"
#include "Mixer.h"

Sampler::Sampler(int trackId, OwnedArray<Parameter>* parameters) : trackId(trackId),
                                                               parameters(parameters)
{
    for (int i = 0; i < 16; i++)
    {
        Voice* sv = new Voice(i);
        addVoice (sv);
    }
}

Sampler::~Sampler() {
}


void Sampler::noteOn (const int midiChannel, const int midiNoteNumber, const float velocity)
{
    int   sample = 1;
    float pitch = 1;
    float attack = 0.01;
    float decay = 0.99;
    
    float trackSample = parameters->getUnchecked(Controller::getParameterId(Controller::params::sample, trackId))->getScaledValue();
    float trackPitch = parameters->getUnchecked(Controller::getParameterId(Controller::params::pitch, trackId))->getScaledValue();
    float trackAttack = parameters->getUnchecked(Controller::getParameterId(Controller::params::attack, trackId))->getScaledValue();
    float trackDecay = parameters->getUnchecked(Controller::getParameterId(Controller::params::decay, trackId))->getScaledValue();
    
    float globalSample = parameters->getUnchecked(Controller::getParameterId(Controller::params::sample))->getScaledValue();
    float globalPitch = parameters->getUnchecked(Controller::getParameterId(Controller::params::pitch))->getScaledValue();
    float globalDecay = parameters->getUnchecked(Controller::getParameterId(Controller::params::decay))->getScaledValue();


    
    // +getNumberOfSounds to shift into positive range
    sample =  ((int) trackSample + (int) globalSample + getNumberOfSounds()) % getNumberOfSounds();
    pitch = pow(2, trackPitch + globalPitch);
    
    // formula from reaktor version
    attack = pow(1.12202, (trackAttack * 100 - 60));
    decay = pow(1.12202, fmin(1, fmax(0.1, trackDecay + globalDecay)) * 100 - 60);

    
    const ScopedLock sl (lock);
    for (int i = sounds.size(); --i >= 0;)
    {
        Sound* const sound = (ReferenceCountedObjectPtr<Sound>) sounds.getUnchecked(i);
        
        if (sound->appliesToNote (midiNoteNumber)
            && sound->appliesToChannel (midiChannel)
            && sound->appliesToSelection(sample))
        {
            Voice* voice = (Voice*) findFreeVoice (sound, 1, midiNoteNumber, true);
            voice->setVoiceParameters(attack, decay, pitch);
            startVoice (voice, sound, midiChannel, midiNoteNumber, velocity);
        }
    }
}

void Sampler::stopVoice (SynthesiserVoice* voice, const bool allowTailOff)
{
    // voice is not stopped manually. only by finishing the sample or envelope reaching sustain env state.
    return;
}

SynthesiserVoice* Sampler::findFreeVoice (SynthesiserSound* soundToPlay,
                                              int midiChannel, int midiNoteNumber,
                                              const bool stealIfNoneAvailable) const
{
    const ScopedLock sl (lock);
    
    for (int i = 0; i < voices.size(); ++i)
    {
        SynthesiserVoice* const voice = voices.getUnchecked (i);
        
        if ((! voice->isVoiceActive()) && voice->canPlaySound (soundToPlay))
            return voice;
    }
    
    if (stealIfNoneAvailable)
        return findVoiceToSteal (soundToPlay, midiChannel, midiNoteNumber);
    
    return nullptr;
}

int Sampler::getNumberOfSounds()
{
    return sounds.size();
}
