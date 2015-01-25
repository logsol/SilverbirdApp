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

#ifndef __JUCE_HEADER_78C8D5E3CE4B77EA__
#define __JUCE_HEADER_78C8D5E3CE4B77EA__

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
class Stepper  : public Component,
                 public ClockListener
{
public:
    //==============================================================================
    Stepper (Controller* controller);
    ~Stepper();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void clockStep(int cursor) override;
    void setComponentID (const String& newID);

    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void mouseDown (const MouseEvent& e);
    void mouseDrag (const MouseEvent& e);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    Controller* controller;

    int cursor = 0;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Label> stepperLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Stepper)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_78C8D5E3CE4B77EA__
