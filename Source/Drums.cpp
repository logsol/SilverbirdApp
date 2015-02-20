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
#include "Mixer.h"
#include "BipolarStepper.h"
//[/Headers]

#include "Drums.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Drums::Drums (Controller* controller)
    : controller(controller)
{
    addAndMakeVisible (kickStepper = new Stepper (controller, Mixer::tracks::kick, false));
    addAndMakeVisible (snareStepper = new Stepper (controller, Mixer::tracks::snare, false));
    addAndMakeVisible (hihatStepper = new Stepper (controller, Mixer::tracks::hihat, false));
    addAndMakeVisible (perc1Stepper = new Stepper (controller, Mixer::tracks::perc1, false));
    addAndMakeVisible (perc2Stepper = new Stepper (controller, Mixer::tracks::perc2, false));
    addAndMakeVisible (tonesStepper = new Stepper (controller, Mixer::tracks::tones, false));

    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

Drums::~Drums()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    kickStepper = nullptr;
    snareStepper = nullptr;
    hihatStepper = nullptr;
    perc1Stepper = nullptr;
    perc2Stepper = nullptr;
    tonesStepper = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Drums::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void Drums::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    kickStepper->setBounds (8, 8, 400, 60);
    snareStepper->setBounds (8, 80, 400, 60);
    hihatStepper->setBounds (8, 152, 400, 60);
    perc1Stepper->setBounds (8, 224, 400, 60);
    perc2Stepper->setBounds (8, 296, 400, 60);
    tonesStepper->setBounds (8, 368, 400, 60);
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

<JUCER_COMPONENT documentType="Component" className="Drums" componentName="" parentClasses="public Component"
                 constructorParams="Controller* controller" variableInitialisers="controller(controller)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffff"/>
  <JUCERCOMP name="kick" id="d3558cec6b0505db" memberName="kickStepper" virtualName=""
             explicitFocusOrder="0" pos="8 8 400 60" sourceFile="Stepper.cpp"
             constructorParams="controller, Mixer::tracks::kick, false"/>
  <JUCERCOMP name="snare" id="ce8e2fe038f9a041" memberName="snareStepper"
             virtualName="" explicitFocusOrder="0" pos="8 80 400 60" sourceFile="Stepper.cpp"
             constructorParams="controller, Mixer::tracks::snare, false"/>
  <JUCERCOMP name="kick" id="c34ad782f2a5f719" memberName="hihatStepper" virtualName=""
             explicitFocusOrder="0" pos="8 152 400 60" sourceFile="Stepper.cpp"
             constructorParams="controller, Mixer::tracks::hihat, false"/>
  <JUCERCOMP name="perc1" id="f899291c5652d18a" memberName="perc1Stepper"
             virtualName="" explicitFocusOrder="0" pos="8 224 400 60" sourceFile="Stepper.cpp"
             constructorParams="controller, Mixer::tracks::perc1, false"/>
  <JUCERCOMP name="perc2" id="7e3f2afb02bd829e" memberName="perc2Stepper"
             virtualName="" explicitFocusOrder="0" pos="8 296 400 60" sourceFile="Stepper.cpp"
             constructorParams="controller, Mixer::tracks::perc2, false"/>
  <JUCERCOMP name="tones" id="2356b855f087cee0" memberName="tonesStepper"
             virtualName="" explicitFocusOrder="0" pos="8 368 400 60" sourceFile="Stepper.cpp"
             constructorParams="controller, Mixer::tracks::tones, false"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
