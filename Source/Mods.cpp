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

//[Headers] You can add your own extra header files here...
#include "Controller.h"
//[/Headers]

#include "Mods.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Mods::Mods (Controller* controller)
    : controller(controller)
{
    addAndMakeVisible (kickStepBipolar = new BipolarStepper (controller));
    addAndMakeVisible (kickStepBipolar2 = new BipolarStepper (controller));
    addAndMakeVisible (kickStepBipolar3 = new BipolarStepper (controller));

    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

Mods::~Mods()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    kickStepBipolar = nullptr;
    kickStepBipolar2 = nullptr;
    kickStepBipolar3 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Mods::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void Mods::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    kickStepBipolar->setBounds (8, 8, 400, 60);
    kickStepBipolar2->setBounds (8, 112, 400, 60);
    kickStepBipolar3->setBounds (8, 216, 400, 60);
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

<JUCER_COMPONENT documentType="Component" className="Mods" componentName="" parentClasses="public Component"
                 constructorParams="Controller* controller" variableInitialisers="controller(controller)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffff"/>
  <JUCERCOMP name="kick" id="edaf762d44b011e1" memberName="kickStepBipolar"
             virtualName="" explicitFocusOrder="0" pos="8 8 400 60" sourceFile="BipolarStepper.cpp"
             constructorParams="controller"/>
  <JUCERCOMP name="kick" id="12b261afd0a6481d" memberName="kickStepBipolar2"
             virtualName="" explicitFocusOrder="0" pos="8 112 400 60" sourceFile="BipolarStepper.cpp"
             constructorParams="controller"/>
  <JUCERCOMP name="kick" id="ce8ced319e6c7204" memberName="kickStepBipolar3"
             virtualName="" explicitFocusOrder="0" pos="8 216 400 60" sourceFile="BipolarStepper.cpp"
             constructorParams="controller"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
