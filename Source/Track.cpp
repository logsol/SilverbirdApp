/*
  ==============================================================================

    Track.cpp
    Created: 5 Mar 2014 6:19:52pm
    Author:  Pannek Karl

  ==============================================================================
*/

#include "Track.h"
#include "../JuceLibraryCode/JuceHeader.h"

Track::Track()
{
    //for (int i = 1; --i >= 0;)
    //{
        SamplerVoice* sv = new SamplerVoice();
        addVoice (sv);
    //}
}

Track::~Track() {
}

void Track::setSelection (int selection) {
    this->selection = selection;
}

int Track::getSelection(int note) {
    return this->selection;
}

void Track::setTrackIndex(int index) {
    this->trackIndex = index;
}

int Track::getTrackIndex() {
	return this->trackIndex;
}

void Track::setNote(int note) {
    this->note = note;
}

int Track::getNote() {
	return this->note;
}

void Track::setNumberOfSounds(int numSounds) {
    this->numberOfSounds = numSounds;
}

int Track::getNumberOfSounds() {
	return this->numberOfSounds;
}

void Track::setMute(bool active) {
    this->mute = active;
}

void Track::setVolume(float value){
    this->volume = value;
}

float Track::getVolume(){
    return volume;
}

void Track::noteOn (const int midiChannel,
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

void Track::stopVoice (SynthesiserVoice* voice, const bool allowTailOff)
{
    jassert (voice != nullptr);
    
    voice->stopNote (0, allowTailOff);
    
    // the subclass MUST call clearCurrentNote() if it's not tailing off! RTFM for stopNote()!
    jassert (allowTailOff || (voice->getCurrentlyPlayingNote() < 0 && voice->getCurrentlyPlayingSound() == 0));
}