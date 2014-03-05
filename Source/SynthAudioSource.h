/*
 ==============================================================================
 
 SynthAudioSource.h
 Created: 30 Jan 2014 2:31:23am
 Author:  Pannek Karl
 
 ==============================================================================
 */

#ifndef SYNTHAUDIOSOURCE_H_INCLUDED
#define SYNTHAUDIOSOURCE_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "SilverSamplerVoice.h"
#include "SilverSynthesizer.h"



class SynthAudioSource   : public AudioSource
{
public:
    SynthAudioSource(MidiKeyboardState& keyState);
    //~SynthAudioSource();
    
    void prepareToPlay(int samplesPerBlockExpected, double sampleRate);
    void releaseResources();
    void getNextAudioBlock(const AudioSourceChannelInfo& bufferToFill);
    void setGain(float value);
    
    // this collects real-time midi messages from the midi input device, and
    // turns them into blocks that we can process in our audio callback
    MidiMessageCollector midiCollector;
    
    // this represents the state of which keys on our on-screen keyboard are held
    // down. When the mouse is clicked on the keyboard component, this object also
    // generates midi messages for this, which we can pass on to our synth.
    MidiKeyboardState& keyboardState;
    
    // the synth itself!
    SilverSynthesizer synth;
    
private:
    
    float gain;
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SynthAudioSource)
};


#endif  // SYNTHAUDIOSOURCE_H_INCLUDED
