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
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (kickStepper = new Stepper (controller, Mixer::tracks::kick, false));
    addAndMakeVisible (snareStepper = new Stepper (controller, Mixer::tracks::snare, false));
    addAndMakeVisible (hihatStepper = new Stepper (controller, Mixer::tracks::hihat, false));
    addAndMakeVisible (perc1Stepper = new Stepper (controller, Mixer::tracks::perc1, false));
    addAndMakeVisible (perc2Stepper = new Stepper (controller, Mixer::tracks::perc2, false));
    addAndMakeVisible (tonesStepper = new Stepper (controller, Mixer::tracks::tones, false));

    //[UserPreSize]
    //[/UserPreSize]

    setSize (400, 400);


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
    /*
    //[/UserPreResize]

    kickStepper->setBounds (0, 0, proportionOfWidth (1.0000f), proportionOfHeight (0.1388f));
    snareStepper->setBounds (0, proportionOfHeight (0.1672f), proportionOfWidth (1.0000f), proportionOfHeight (0.1388f));
    hihatStepper->setBounds (0, proportionOfHeight (0.3470f), proportionOfWidth (1.0000f), proportionOfHeight (0.1388f));
    perc1Stepper->setBounds (0, proportionOfHeight (0.5174f), proportionOfWidth (1.0000f), proportionOfHeight (0.1388f));
    perc2Stepper->setBounds (0, proportionOfHeight (0.6751f), proportionOfWidth (1.0000f), proportionOfHeight (0.1388f));
    tonesStepper->setBounds (0, proportionOfHeight (0.8612f), proportionOfWidth (1.0000f), proportionOfHeight (0.1388f));
    //[UserResized] Add your own custom resize handling here..
    */
    int space = 2;
    float h = (getHeight() - space * 4) / 6;

    kickStepper->setBounds (0, 0, getWidth(), h);
    snareStepper->setBounds (0, (h+space)*1, getWidth(), h);
    hihatStepper->setBounds (0, (h+space)*2, getWidth(), h);
    perc1Stepper->setBounds (0, (h+space)*3, getWidth(), h);
    perc2Stepper->setBounds (0, (h+space)*4, getWidth(), h);
    tonesStepper->setBounds (0, (h+space)*5, getWidth(), h);

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
                 fixedSize="1" initialWidth="400" initialHeight="400">
  <BACKGROUND backgroundColour="ffffff"/>
  <JUCERCOMP name="kick" id="d3558cec6b0505db" memberName="kickStepper" virtualName=""
             explicitFocusOrder="0" pos="0 0 100% 14.027%" sourceFile="Stepper.cpp"
             constructorParams="controller, Mixer::tracks::kick, false"/>
  <JUCERCOMP name="snare" id="ce8e2fe038f9a041" memberName="snareStepper"
             virtualName="" explicitFocusOrder="0" pos="0 16.742% 100% 14.027%"
             sourceFile="Stepper.cpp" constructorParams="controller, Mixer::tracks::snare, false"/>
  <JUCERCOMP name="kick" id="c34ad782f2a5f719" memberName="hihatStepper" virtualName=""
             explicitFocusOrder="0" pos="0 34.842% 100% 14.027%" sourceFile="Stepper.cpp"
             constructorParams="controller, Mixer::tracks::hihat, false"/>
  <JUCERCOMP name="perc1" id="f899291c5652d18a" memberName="perc1Stepper"
             virtualName="" explicitFocusOrder="0" pos="0 51.584% 100% 14.027%"
             sourceFile="Stepper.cpp" constructorParams="controller, Mixer::tracks::perc1, false"/>
  <JUCERCOMP name="perc2" id="7e3f2afb02bd829e" memberName="perc2Stepper"
             virtualName="" explicitFocusOrder="0" pos="0 67.421% 100% 14.027%"
             sourceFile="Stepper.cpp" constructorParams="controller, Mixer::tracks::perc2, false"/>
  <JUCERCOMP name="tones" id="2356b855f087cee0" memberName="tonesStepper"
             virtualName="" explicitFocusOrder="0" pos="0 85.973% 100% 14.027%"
             sourceFile="Stepper.cpp" constructorParams="controller, Mixer::tracks::tones, false"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
