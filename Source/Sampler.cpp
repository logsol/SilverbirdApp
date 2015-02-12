
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
    int sample = 1;
    float pitch = 1;
    float attack = 0.01;
    float decay = 0.99;
    
    int   trackSample = parameters->getUnchecked(Controller::getParameterId(Controller::params::sample, trackId))->getValue();
    float trackPitch = parameters->getUnchecked(Controller::getParameterId(Controller::params::pitch, trackId))->getValue();
    float trackAttack = parameters->getUnchecked(Controller::getParameterId(Controller::params::attack, trackId))->getValue();
    float trackDecay = parameters->getUnchecked(Controller::getParameterId(Controller::params::decay, trackId))->getValue();
    
    int   globalSample = parameters->getUnchecked(Controller::getParameterId(Controller::params::sample))->getValue();
    float globalPitch = parameters->getUnchecked(Controller::getParameterId(Controller::params::pitch))->getValue();
    float globalDecay = parameters->getUnchecked(Controller::getParameterId(Controller::params::decay))->getValue();


    
    if (true) {
        // +1000 -1 to safely shift far into positive range but keep first sample
        
        sample = (trackSample + globalSample /*+ 999*/)  % sounds.size();
        pitch = trackPitch + globalPitch;
        attack = trackAttack;
        decay = fmax(0, fmin(1, trackDecay + globalDecay));
    }
    
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
