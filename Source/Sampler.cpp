
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
#include "Source.h"

Sampler::Sampler(int trackId, Source* source, Controller* controller) : trackId(trackId),
                                                                        controller(controller),
                                                                        source(source)
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
    
    float trackSample = controller->getParameterValueScaled(Controller::params::sample, trackId);
    float trackPitch = controller->getParameterValueScaled(Controller::params::pitch, trackId);
    float trackAttack = controller->getParameterValueScaled(Controller::params::attack, trackId);
    float trackDecay = controller->getParameterValueScaled(Controller::params::decay, trackId);
    
    float globalSample = controller->getParameterValueScaled(Controller::params::sample);
    float globalPitch = controller->getParameterValueScaled(Controller::params::pitch);
    float globalDecay = controller->getParameterValueScaled(Controller::params::decay);
    
    /*
    float modulationSample = Parameter::scale(Controller::params::sample, true, currentModulations->getUnchecked(Mixer::mods::sample));
    float modulationPitch = Parameter::scale(Controller::params::pitch, true, currentModulations->getUnchecked(Mixer::mods::pitch));
    float modulationDecay = Parameter::scale(Controller::params::decay, true, currentModulations->getUnchecked(Mixer::mods::decay));
     */
    
    float modulationSample = Parameter::scale(Controller::params::sample, true, source->modulations[Mixer::mods::sample]);
    float modulationPitch = Parameter::scale(Controller::params::pitch, true, source->modulations[Mixer::mods::pitch]);
    float modulationDecay = Parameter::scale(Controller::params::decay, true, source->modulations[Mixer::mods::decay]);

    
    // +getNumberOfSounds to shift into positive range
    sample =  ((int) trackSample + (int) globalSample + (int) modulationSample + getNumberOfSounds()) % getNumberOfSounds();
    pitch = pow(2, trackPitch + globalPitch + modulationPitch);
    
    // formula from reaktor version
    attack = pow(1.12202, (trackAttack * 100 - 60));
    decay = pow(1.12202, fmin(1, fmax(0.1, trackDecay + globalDecay + modulationDecay)) * 100 - 60);

    
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



