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

#ifndef __JUCE_HEADER_E740E5DEE8AB6ED4__
#define __JUCE_HEADER_E740E5DEE8AB6ED4__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "BaseComponent.h"
#include "SbButton.h"
#include "Sequencer.h"
//[/Headers]

#include "BipolarStepper.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TargetStepper  : public BaseComponent,
                       public ButtonListener
{
public:
    //==============================================================================
    TargetStepper (Controller* controller, int trackId, bool isModulationTrack );
    ~TargetStepper();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    Sequencer* sequencer;
    Array<TextButton*> buttons;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<BipolarStepper> component;
    ScopedPointer<SbButton> target1;
    ScopedPointer<SbButton> target2;
    ScopedPointer<SbButton> target3;
    ScopedPointer<SbButton> target4;
    ScopedPointer<SbButton> target5;
    ScopedPointer<SbButton> target6;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TargetStepper)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_E740E5DEE8AB6ED4__
