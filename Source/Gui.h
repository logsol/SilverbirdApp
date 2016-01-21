/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 4.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_1B7D314A9B5D26__
#define __JUCE_HEADER_1B7D314A9B5D26__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "Knob.h"
class Controller;
//[/Headers]

#include "Transport.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class Gui  : public AudioProcessorEditor,
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

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    bool keyPressed (const KeyPress& key) override;

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
    ScopedPointer<Slider> kickVolumeSlider;
    ScopedPointer<Slider> snareVolumeSlider;
    ScopedPointer<Slider> hihatVolumeSlider;
    ScopedPointer<Label> label7;
    ScopedPointer<Label> label8;
    ScopedPointer<Label> label9;
    ScopedPointer<Label> label11;
    ScopedPointer<TabbedComponent> trackTabs;
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
    ScopedPointer<Slider> perc1VolumeSlider;
    ScopedPointer<Slider> perc2VolumeSlider;
    ScopedPointer<Slider> tonesVolumeSlider;
    ScopedPointer<Label> label12;
    ScopedPointer<Label> label13;
    ScopedPointer<Label> label14;
    ScopedPointer<TabbedComponent> sequencerTabs;
    ScopedPointer<TextButton> kickMuteButton;
    ScopedPointer<TextButton> snareMuteButton;
    ScopedPointer<TextButton> hihatMuteButton;
    ScopedPointer<TextButton> perc2MuteButton;
    ScopedPointer<TextButton> tonesMuteButton;
    ScopedPointer<TextButton> perc1MuteButton;
    ScopedPointer<Transport> transport;
    Image cachedImage_background_png_1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Gui)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_1B7D314A9B5D26__
