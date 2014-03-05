/*
 ==============================================================================
 
 This file was auto-generated!
 
 ==============================================================================
 */

#ifndef MAINCOMPONENT_H_INCLUDED
#define MAINCOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthAudioSource.h"
#include "Knob.h"




//==============================================================================
/*
 This component lives inside our window, and this is where you should put all
 your controls and content.
 */
class MainContentComponent   : public Component,
public Button::Listener,
public Slider::Listener
{
public:
    //==============================================================================
    MainContentComponent();
    ~MainContentComponent();
    
    void paint (Graphics&);
    void resized();
    void buttonClicked (Button* button);
    void sliderValueChanged (Slider* slider);
    
private:
    ImageComponent* background;
    TextButton* button1;
    TextButton* button2;
    TextButton* button3;
    Slider* knob;
    Slider* selectKnob;
    MidiKeyboardState keyboardState;
    AudioSourcePlayer* audioSourcePlayer;
    SynthAudioSource* synthAudioSource;
    AudioDeviceManager* audioDeviceManager;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};


#endif  // MAINCOMPONENT_H_INCLUDED
