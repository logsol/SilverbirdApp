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

#ifndef __JUCE_HEADER_BB8DDE5D2A6021DA__
#define __JUCE_HEADER_BB8DDE5D2A6021DA__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "SlideView.h"
#include "Controller.h"
#include "VPMixer.h"
#include "VPSetup.h"
//[/Headers]

#include "VPNavigate.h"
#include "VPSequencer.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class Portrait  : public SlideView
{
public:
    //==============================================================================
    Portrait (Controller* controller);
    ~Portrait();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    ScopedPointer<VPMixer> vpMixer;
    ScopedPointer<VPSetup> vpSetup;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<VPNavigate> transport;
    ScopedPointer<VPSequencer> vpSequencer;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Portrait)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_BB8DDE5D2A6021DA__
