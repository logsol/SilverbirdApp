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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "MixerComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MixerComponent::MixerComponent (Controller* controller)
    : controller(controller)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (component = new MixerStrip (controller, 0));
    addAndMakeVisible (component2 = new MixerStrip (controller, 1));
    addAndMakeVisible (component3 = new MixerStrip (controller, 2));
    addAndMakeVisible (component4 = new MixerStrip (controller, 3));
    addAndMakeVisible (component5 = new MixerStrip (controller, 4));
    addAndMakeVisible (component6 = new MixerStrip (controller, 5));

    //[UserPreSize]
    //[/UserPreSize]

    setSize (400, 150);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MixerComponent::~MixerComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    component = nullptr;
    component2 = nullptr;
    component3 = nullptr;
    component4 = nullptr;
    component5 = nullptr;
    component6 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MixerComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MixerComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    component->setBounds (proportionOfWidth (0.0065f), proportionOfHeight (0.0000f), proportionOfWidth (0.1484f), proportionOfHeight (1.0000f));
    component2->setBounds (proportionOfWidth (0.1774f), proportionOfHeight (0.0000f), proportionOfWidth (0.1484f), proportionOfHeight (1.0000f));
    component3->setBounds (proportionOfWidth (0.3452f), proportionOfHeight (0.0000f), proportionOfWidth (0.1484f), proportionOfHeight (1.0000f));
    component4->setBounds (proportionOfWidth (0.5097f), proportionOfHeight (0.0000f), proportionOfWidth (0.1484f), proportionOfHeight (1.0000f));
    component5->setBounds (proportionOfWidth (0.6774f), proportionOfHeight (0.0000f), proportionOfWidth (0.1484f), proportionOfHeight (1.0000f));
    component6->setBounds (proportionOfWidth (0.8452f), proportionOfHeight (0.0000f), proportionOfWidth (0.1484f), proportionOfHeight (1.0000f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MixerComponent" componentName=""
                 parentClasses="public Component" constructorParams="Controller* controller"
                 variableInitialisers="controller(controller)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="400" initialHeight="150">
  <BACKGROUND backgroundColour="0"/>
  <JUCERCOMP name="" id="2082ceb4984fc266" memberName="component" virtualName=""
             explicitFocusOrder="0" pos="0.75% 0% 14.75% 100%" sourceFile="MixerStrip.cpp"
             constructorParams="controller, 0"/>
  <JUCERCOMP name="" id="fb7708f454bc61f0" memberName="component2" virtualName=""
             explicitFocusOrder="0" pos="17.75% 0% 14.75% 100%" sourceFile="MixerStrip.cpp"
             constructorParams="controller, 1"/>
  <JUCERCOMP name="" id="62501aac3a687188" memberName="component3" virtualName=""
             explicitFocusOrder="0" pos="34.5% 0% 14.75% 100%" sourceFile="MixerStrip.cpp"
             constructorParams="controller, 2"/>
  <JUCERCOMP name="" id="8abf6913990e9d94" memberName="component4" virtualName=""
             explicitFocusOrder="0" pos="51% 0% 14.75% 100%" sourceFile="MixerStrip.cpp"
             constructorParams="controller, 3"/>
  <JUCERCOMP name="" id="8d925570f6433a1b" memberName="component5" virtualName=""
             explicitFocusOrder="0" pos="67.75% 0% 14.75% 100%" sourceFile="MixerStrip.cpp"
             constructorParams="controller, 4"/>
  <JUCERCOMP name="" id="d4eeb1caf95d7015" memberName="component6" virtualName=""
             explicitFocusOrder="0" pos="84.5% 0% 14.75% 100%" sourceFile="MixerStrip.cpp"
             constructorParams="controller, 5"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
