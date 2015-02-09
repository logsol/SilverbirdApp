/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.1

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_1B7D314A9B5D26__
#define __JUCE_HEADER_1B7D314A9B5D26__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "Controller.h"
#include "Knob.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class Gui  : public Component,
             public SliderListener,
             public ButtonListener
{
public:
    //==============================================================================
    Gui (Controller* controller);
    ~Gui();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);
    bool keyPressed (const KeyPress& key);

    // Binary resources:
    static const char* background_png;
    static const int background_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    Controller* controller;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Label> label;
    ScopedPointer<Knob> masterSlider;
    ScopedPointer<ToggleButton> kickMuteButton;
    ScopedPointer<ToggleButton> snareMuteButton;
    ScopedPointer<ToggleButton> HihatMuteButton;
    ScopedPointer<Slider> kickVolumeSlider;
    ScopedPointer<Slider> snareVolumeSlider;
    ScopedPointer<Slider> hihatVolumeSlider;
    ScopedPointer<Label> label7;
    ScopedPointer<Label> label8;
    ScopedPointer<Label> label9;
    ScopedPointer<Label> label11;
    ScopedPointer<TabbedComponent> tabbedComponent;
    ScopedPointer<Knob> sampleAllSlider;
    ScopedPointer<Label> label2;
    ScopedPointer<Knob> pitchSlider;
    ScopedPointer<Label> label3;
    ScopedPointer<Knob> decaySlider;
    ScopedPointer<Label> label4;
    ScopedPointer<Knob> distortSlider;
    ScopedPointer<Label> label5;
    ScopedPointer<Knob> cutoffSlider;
    ScopedPointer<Label> label6;
    ScopedPointer<Knob> shuffleSlider;
    ScopedPointer<Label> label10;
    ScopedPointer<ToggleButton> perc1MuteButton;
    ScopedPointer<ToggleButton> perc2MuteButton;
    ScopedPointer<ToggleButton> tonesMuteButton;
    ScopedPointer<Slider> perc1VolumeSlider;
    ScopedPointer<Slider> perc2VolumeSlider;
    ScopedPointer<Slider> tonesVolumeSlider;
    ScopedPointer<Label> label12;
    ScopedPointer<Label> label13;
    ScopedPointer<Label> label14;
    ScopedPointer<TabbedComponent> sequencerTabs;
    Image cachedImage_background_png;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Gui)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_1B7D314A9B5D26__
