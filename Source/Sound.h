/*
  ==============================================================================

    Sound.h
    Created: 7 Feb 2014 12:56:34am
    Author:  Pannek Karl

  ==============================================================================
*/

#ifndef SILVERSAMPLERSOUND_H_INCLUDED
#define SILVERSAMPLERSOUND_H_INCLUDED


#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/**
 A subclass of SynthesiserSound that represents a sampled audio clip.
 
 This is a pretty basic sampler, and just attempts to load the whole audio stream
 into memory.
 
 To use it, create a Synthesiser, add some SamplerVoice objects to it, then
 give it some SampledSound objects to play.
 
 @see SamplerVoice, Synthesiser, SynthesiserSound
 */
class Sound : public SynthesiserSound
{
public:
    //==============================================================================
    /** Creates a sampled sound from an audio reader.
     
     This will attempt to load the audio from the source into memory and store
     it in this object.
     
     @param name         a name for the sample
     @param source       the audio to load. This object can be safely deleted by the
     caller after this constructor returns
     @param midiNotes    the set of midi keys that this sound should be played on. This
     is used by the SynthesiserSound::appliesToNote() method
     @param midiNoteForNormalPitch   the midi note at which the sample should be played
     with its natural rate. All other notes will be pitched
     up or down relative to this one
     @param attackTimeSecs   the attack (fade-in) time, in seconds
     @param releaseTimeSecs  the decay (fade-out) time, in seconds
     @param maxSampleLengthSeconds   a maximum length of audio to read from the audio
     source, in seconds
     */
    Sound (const String& name,
                        int midiNoteForNormalPitch,
                        int selection,
                        AudioFormatReader& source);
    
    /** Destructor. */
    ~Sound();
    
    //==============================================================================
    /** Returns the sample's name */
    const String& getName() const noexcept                  { return name; }
    
    /** Returns the audio sample data.
     This could return nullptr if there was a problem loading the data.
     */
    AudioSampleBuffer* getAudioData() const noexcept        { return data; }
    
    
    //==============================================================================
    bool appliesToNote (const int midiNoteNumber) override;
    bool appliesToChannel (const int midiChannel) override;
    bool appliesToSelection (int selection);
    
    
private:
    //==============================================================================
    friend class Voice;
    
    String name;
    ScopedPointer<AudioSampleBuffer> data;
    double sourceSampleRate;
    BigInteger midiNotes;
    int length, attackSamples, releaseSamples;
    int midiRootNote;
    int selection;
    
    JUCE_LEAK_DETECTOR (Sound)
};


#endif  // SILVERSAMPLERSOUND_H_INCLUDED
