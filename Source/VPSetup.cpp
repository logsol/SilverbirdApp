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

#include "VPSetup.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
VPSetup::VPSetup (Controller* controller)
    : BaseComponent(controller)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Setup")));
    label->setFont (Font (15.00f, Font::plain));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (Label::textColourId, Colours::white);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (history = new HistoryComponent (controller));
    addAndMakeVisible (component = new Transport (controller));

    //[UserPreSize]
    //[/UserPreSize]

    setSize (320, 420);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

VPSetup::~VPSetup()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    label = nullptr;
    history = nullptr;
    component = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void VPSetup::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void VPSetup::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    label->setBounds (proportionOfWidth (0.2500f), proportionOfHeight (0.0381f), proportionOfWidth (0.4688f), proportionOfHeight (0.0571f));
    history->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (1.0000f) - 62, proportionOfWidth (1.0000f), 62);
    component->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.1333f), proportionOfWidth (1.0000f), proportionOfHeight (0.1905f));
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

<JUCER_COMPONENT documentType="Component" className="VPSetup" componentName=""
                 parentClasses="public BaseComponent" constructorParams="Controller* controller"
                 variableInitialisers="BaseComponent(controller)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="320" initialHeight="420">
  <BACKGROUND backgroundColour="0"/>
  <LABEL name="new label" id="2c03953cb1a8c8b4" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="25% 3.81% 46.875% 5.714%" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Setup" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <JUCERCOMP name="" id="b82ece55084724b2" memberName="history" virtualName=""
             explicitFocusOrder="0" pos="0% 100%r 100% 62" posRelativeX="309379987650ac71"
             sourceFile="HistoryComponent.cpp" constructorParams="controller"/>
  <JUCERCOMP name="" id="5e01859b6589b66f" memberName="component" virtualName=""
             explicitFocusOrder="0" pos="0% 13.333% 100% 19.048%" sourceFile="Transport.cpp"
             constructorParams="controller"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
