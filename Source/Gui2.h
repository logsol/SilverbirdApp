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

#ifndef __JUCE_HEADER_475F5D9246C919F6__
#define __JUCE_HEADER_475F5D9246C919F6__

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
class Gui2  : public AudioProcessorEditor,
              public SliderListener,
              public ButtonListener
{
public:
    //==============================================================================
    Gui2 (Controller* controller);
    ~Gui2();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void setTrackFocus(int trackId);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    Controller* controller;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Transport> transport;
    ScopedPointer<TabbedComponent> trackTabs;
    ScopedPointer<TabbedComponent> sequencerTabs;
    ScopedPointer<Slider> masterSlider;
    ScopedPointer<Label> label;
    ScopedPointer<TextButton> save;
    ScopedPointer<TextButton> load;
    ScopedPointer<TextButton> redo;
    ScopedPointer<TextButton> undo;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Gui2)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_475F5D9246C919F6__
