
/*
  ==============================================================================

    Sampler.cpp
    Created: 5 Mar 2014 6:19:52pm
    Author:  Pannek Karl

  ==============================================================================
*/

#include "Sampler.h"
#include "Voice.h"
#include "../JuceLibraryCode/JuceHeader.h"

Sampler::Sampler(struct trackParamList* trackParams) : trackParams(trackParams)
{
    for (int i = 0; i < 16; i++)
    {
        Voice* sv = new Voice(i);
        addVoice (sv);
    }
}

Sampler::~Sampler() {
}


void Sampler::noteOn (const int midiChannel,
                                const int midiNoteNumber,
                                const float velocity)
{
    
    
    const ScopedLock sl (lock);
    
    for (int i = sounds.size(); --i >= 0;)
    {
        Sound* const sound = (ReferenceCountedObjectPtr<Sound>) sounds.getUnchecked(i);
        
        if (sound->appliesToNote (midiNoteNumber)
            && sound->appliesToChannel (midiChannel)
            && sound->appliesToSelection(trackParams->sample))
        {
            Voice* voice = (Voice*) findFreeVoice (sound, 1, midiNoteNumber, true);
            voice->setEnvelopeParameters(trackParams->attack, trackParams->decay);
            startVoice (voice, sound, midiChannel, midiNoteNumber, velocity);
        }
    } 
}

void Sampler::stopVoice (SynthesiserVoice* voice, const bool allowTailOff)
{
    // voice is not stopped manually. only by finishing the sample or envelope reaching sustain env state.
    return;

    /*
    jassert (voice != nullptr);
    
    voice->stopNote (0, allowTailOff);
    
    // the subclass MUST call clearCurrentNote() if it's not tailing off! RTFM for stopNote()!
    jassert (allowTailOff || (voice->getCurrentlyPlayingNote() < 0 && voice->getCurrentlyPlayingSound() == 0));
     */
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
