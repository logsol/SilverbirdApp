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

#ifndef __JUCE_HEADER_A1882F64DEF5AEB6__
#define __JUCE_HEADER_A1882F64DEF5AEB6__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "BaseComponent.h"
//[/Headers]

#include "TargetStepper.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class Mods  : public BaseComponent
{
public:
    //==============================================================================
    Mods (Controller* controller);
    ~Mods();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<TargetStepper> decayStepper;
    ScopedPointer<TargetStepper> selectStepper;
    ScopedPointer<TargetStepper> pitchStepper;
    ScopedPointer<TargetStepper> filterStepper;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Mods)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_A1882F64DEF5AEB6__
