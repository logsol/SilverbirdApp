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

#include "VPMixer.h"
#include "ReverbComponent.h"
#include "DelayComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
VPMixer::VPMixer (Controller* controller)
    : BaseComponent(controller)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (component = new MixerComponent (controller));
    addAndMakeVisible (tabbedComponent = new TabbedComponent (TabbedButtonBar::TabsAtTop));
    tabbedComponent->setTabBarDepth (28);
    tabbedComponent->addTab (TRANS("Reverb"), Colour (0xf1383838), new ReverbComponent (controller), true);
    tabbedComponent->addTab (TRANS("Delay"), Colour (0xf1383838), new DelayComponent (controller), true);
    tabbedComponent->setCurrentTabIndex (1);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (320, 420);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

VPMixer::~VPMixer()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    component = nullptr;
    tabbedComponent = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void VPMixer::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void VPMixer::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    component->setBounds (0, proportionOfHeight (1.0000f) - proportionOfHeight (0.5500f), proportionOfWidth (1.0000f), proportionOfHeight (0.5500f));
    tabbedComponent->setBounds (0, 0, proportionOfWidth (1.0000f), proportionOfHeight (0.4405f));
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

<JUCER_COMPONENT documentType="Component" className="VPMixer" componentName=""
                 parentClasses="public BaseComponent" constructorParams="Controller* controller"
                 variableInitialisers="BaseComponent(controller)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="320" initialHeight="420">
  <BACKGROUND backgroundColour="0"/>
  <JUCERCOMP name="" id="309379987650ac71" memberName="component" virtualName=""
             explicitFocusOrder="0" pos="0 100%r 100% 55%" sourceFile="MixerComponent.cpp"
             constructorParams="controller"/>
  <TABBEDCOMPONENT name="new tabbed component" id="e9db00d451869082" memberName="tabbedComponent"
                   virtualName="" explicitFocusOrder="0" pos="0 0 100% 44.048%"
                   orientation="top" tabBarDepth="28" initialTab="1">
    <TAB name="Reverb" colour="f1383838" useJucerComp="1" contentClassName=""
         constructorParams="controller" jucerComponentFile="ReverbComponent.cpp"/>
    <TAB name="Delay" colour="f1383838" useJucerComp="1" contentClassName=""
         constructorParams="controller" jucerComponentFile="DelayComponent.cpp"/>
  </TABBEDCOMPONENT>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
