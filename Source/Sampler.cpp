
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

Sampler::Sampler()
{
    for (int i = 6; --i >= 0;)
    {
        Voice* sv = new Voice();
        addVoice (sv);
    }
}

Sampler::~Sampler() {
}

void Sampler::setSelection (int selection) {
    this->selection = selection;
}

int Sampler::getSelection(int note) {
    return this->selection;
}

void Sampler::setTrackIndex(int index) {
    this->trackIndex = index;
}

int Sampler::getTrackIndex() {
	return this->trackIndex;
}

void Sampler::setNote(int note) {
    this->note = note;
}

int Sampler::getNote() {
	return this->note;
}

void Sampler::setNumberOfSounds(int numSounds) {
    this->numberOfSounds = numSounds;
}

int Sampler::getNumberOfSounds() {
	return this->numberOfSounds;
}

void Sampler::setMute(bool active) {
    this->mute = active;
}

void Sampler::setVolume(float value){
    this->volume = value;
}

float Sampler::getVolume(){
    return volume;
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
            && sound->appliesToSelection(this->getSelection(midiNoteNumber)))
        {
            startVoice (findFreeVoice (sound, 1, midiNoteNumber, true), sound, midiChannel, midiNoteNumber, velocity);
        }
    } 
}

void Sampler::stopVoice (SynthesiserVoice* voice, const bool allowTailOff)
{
    
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
