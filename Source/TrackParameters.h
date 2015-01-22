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

#ifndef __JUCE_HEADER_D95E31031232A3F6__
#define __JUCE_HEADER_D95E31031232A3F6__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "Controller.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TrackParameters  : public Component,
                         public SliderListener
{
public:
    //==============================================================================
    TrackParameters (Controller* controller);
    ~TrackParameters();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    Controller* controller;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> selectSlider;
    ScopedPointer<Label> label2;
    ScopedPointer<Slider> attackSlider;
    ScopedPointer<Label> label4;
    ScopedPointer<Slider> decaySlider;
    ScopedPointer<Label> label5;
    ScopedPointer<Slider> pitchSlider;
    ScopedPointer<Label> label6;
    ScopedPointer<Slider> cutoffSlider;
    ScopedPointer<Label> label10;
    ScopedPointer<Slider> distortSlider;
    ScopedPointer<Label> label3;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TrackParameters)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_D95E31031232A3F6__
