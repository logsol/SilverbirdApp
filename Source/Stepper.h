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

#ifndef __JUCE_HEADER_78C8D5E3CE4B77EA__
#define __JUCE_HEADER_78C8D5E3CE4B77EA__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "Controller.h"
#include "BaseComponent.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class Stepper  : public BaseComponent,
                 public ClockListener
{
public:
    //==============================================================================
    Stepper (Controller* controller, int trackId, bool isModulationTrack);
    ~Stepper();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void clockStep(int cursor) override;
    void setComponentID (const String& newID);

    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void mouseDown (const MouseEvent& e) override;
    void mouseDrag (const MouseEvent& e) override;
    void mouseDoubleClick (const MouseEvent& e) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.

protected:
    virtual bool isBipolar();
    virtual void updateSequencer(int cellId, float value);

    int trackId;
    bool isModulationTrack;
    int cursor = -1;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Label> stepperLabel;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Stepper)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_78C8D5E3CE4B77EA__
