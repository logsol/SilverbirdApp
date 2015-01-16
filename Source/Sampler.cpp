/*
  ==============================================================================

    Sampler.cpp
    Created: 5 Mar 2014 6:19:52pm
    Author:  Pannek Karl

  ==============================================================================
*/

#include "Sampler.h"
#include "../JuceLibraryCode/JuceHeader.h"

Sampler::Sampler()
{
    //for (int i = 1; --i >= 0;)
    //{
        SamplerVoice* sv = new SamplerVoice();
        addVoice (sv);
    //}
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
            // If hitting a note that's still ringing, stop it first (it could be
            // still playing because of the sustain or sostenuto pedal).
            
            for (int j = voices.size(); --j >= 0;)
            {
                SynthesiserVoice* const voice = voices.getUnchecked (j);
                
                if (voice->getCurrentlyPlayingNote() == midiNoteNumber
                    && voice->isPlayingChannel (midiChannel)) {
                    stopVoice (voice, true);
                }
            }
             
            //startVoice (findFreeVoice (sound, true), sound, midiChannel, midiNoteNumber, velocity);
            startVoice (voices[0], sound, midiChannel, midiNoteNumber, velocity);

        }
    }
}

void Sampler::stopVoice (SynthesiserVoice* voice, const bool allowTailOff)
{
    jassert (voice != nullptr);
    
    voice->stopNote (0, allowTailOff);
    
    // the subclass MUST call clearCurrentNote() if it's not tailing off! RTFM for stopNote()!
    jassert (allowTailOff || (voice->getCurrentlyPlayingNote() < 0 && voice->getCurrentlyPlayingSound() == 0));
}