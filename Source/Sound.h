/*
  ==============================================================================

    Sound.h
    Created: 7 Feb 2014 12:56:34am
    Author:  Pannek Karl

  ==============================================================================
*/

#ifndef SILVERSAMPLERSOUND_H_INCLUDED
#define SILVERSAMPLERSOUND_H_INCLUDED


#include "JuceHeader.h"

//==============================================================================
/**
 A subclass of SynthesiserSound that represents a sampled audio clip.
 
 This is a pretty basic sampler, and just attempts to load the whole audio stream
 into memory.
 
 To use it, create a Synthesiser, add some SamplerVoice objects to it, then
 give it some SampledSound objects to play.
 
 @see SamplerVoice, Synthesiser, SynthesiserSound
 */
class Sound : public SamplerSound
{
public:
    //==============================================================================

    Sound (const String& name,
                        int midiNoteForNormalPitch,
                        int selection,
                        AudioFormatReader& source,
                        float attackTimeSecs,
                        float releaseTimeSecs);
    
    /** Destructor. */
    ~Sound();    
    
    bool appliesToNote (const int midiNoteNumber) override;
    bool appliesToSelection (int selection);
    
protected:
    ScopedPointer<AudioSampleBuffer> data;
    int length, attackSamples, releaseSamples;
    
private:
    
    friend class Voice;
    
    String name;
    int midiRootNote;
    int selection;
    
    JUCE_LEAK_DETECTOR (Sound)
};


#endif  // SILVERSAMPLERSOUND_H_INCLUDED
