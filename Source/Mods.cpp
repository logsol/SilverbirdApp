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
//[/Headers]

#include "Mods.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Mods::Mods (Controller* controller)
    : controller(controller)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (decayStepper = new BipolarStepper (controller, Mixer::mods::decay, true));
    addAndMakeVisible (selectStepper = new BipolarStepper (controller, Mixer::mods::sample, true));
    addAndMakeVisible (pitchStepper = new BipolarStepper (controller, Mixer::mods::pitch, true));
    addAndMakeVisible (filterStepper = new BipolarStepper (controller, Mixer::mods::cutoff, true));

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

    decayStepper = nullptr;
    selectStepper = nullptr;
    pitchStepper = nullptr;
    filterStepper = nullptr;


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
    /*
    //[/UserPreResize]

    decayStepper->setBounds (8, 152, 400, 60);
    selectStepper->setBounds (8, 8, 400, 60);
    pitchStepper->setBounds (8, 80, 400, 60);
    filterStepper->setBounds (8, 224, 400, 60);
    //[UserResized] Add your own custom resize handling here..
     */
    int space = 2;
    float h = (getHeight() - space * 2) / 4;

    decayStepper->setBounds (0, 0, getWidth(), h);
    selectStepper->setBounds (0, (h+space)*1, getWidth(), h);
    pitchStepper->setBounds (0, (h+space)*2, getWidth(), h);
    filterStepper->setBounds (0, (h+space)*3, getWidth(), h);
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
  <JUCERCOMP name="decay" id="edaf762d44b011e1" memberName="decayStepper"
             virtualName="" explicitFocusOrder="0" pos="8 152 400 60" sourceFile="BipolarStepper.cpp"
             constructorParams="controller, Mixer::mods::decay, true"/>
  <JUCERCOMP name="select" id="12b261afd0a6481d" memberName="selectStepper"
             virtualName="" explicitFocusOrder="0" pos="8 8 400 60" sourceFile="BipolarStepper.cpp"
             constructorParams="controller, Mixer::mods::sample, true"/>
  <JUCERCOMP name="pitch" id="ce8ced319e6c7204" memberName="pitchStepper"
             virtualName="" explicitFocusOrder="0" pos="8 80 400 60" sourceFile="BipolarStepper.cpp"
             constructorParams="controller, Mixer::mods::pitch, true"/>
  <JUCERCOMP name="filter" id="abd63af6b458b15e" memberName="filterStepper"
             virtualName="" explicitFocusOrder="0" pos="8 224 400 60" sourceFile="BipolarStepper.cpp"
             constructorParams="controller, Mixer::mods::cutoff, true"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
