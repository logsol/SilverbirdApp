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

#include "HistoryComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
HistoryComponent::HistoryComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (save = new TextButton ("save"));
    save->setButtonText (TRANS("Save"));
    save->addListener (this);

    addAndMakeVisible (load = new TextButton ("load"));
    load->setButtonText (TRANS("Load"));
    load->addListener (this);

    addAndMakeVisible (redo = new TextButton ("redo"));
    redo->setButtonText (TRANS("Redo"));
    redo->addListener (this);

    addAndMakeVisible (undo = new TextButton ("undo"));
    undo->setButtonText (TRANS("Undo"));
    undo->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (300, 40);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

HistoryComponent::~HistoryComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    save = nullptr;
    load = nullptr;
    redo = nullptr;
    undo = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void HistoryComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void HistoryComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    save->setBounds (proportionOfWidth (0.2898f), proportionOfHeight (0.2303f), proportionOfWidth (0.1992f), proportionOfHeight (0.5770f));
    load->setBounds (proportionOfWidth (0.0672f), proportionOfHeight (0.2303f), proportionOfWidth (0.1992f), proportionOfHeight (0.5770f));
    redo->setBounds (proportionOfWidth (0.7375f), proportionOfHeight (0.2303f), proportionOfWidth (0.1992f), proportionOfHeight (0.5770f));
    undo->setBounds (proportionOfWidth (0.5148f), proportionOfHeight (0.2303f), proportionOfWidth (0.1992f), proportionOfHeight (0.5770f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void HistoryComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == save)
    {
        //[UserButtonCode_save] -- add your button handler code here..
        //[/UserButtonCode_save]
    }
    else if (buttonThatWasClicked == load)
    {
        //[UserButtonCode_load] -- add your button handler code here..
        //[/UserButtonCode_load]
    }
    else if (buttonThatWasClicked == redo)
    {
        //[UserButtonCode_redo] -- add your button handler code here..
        //[/UserButtonCode_redo]
    }
    else if (buttonThatWasClicked == undo)
    {
        //[UserButtonCode_undo] -- add your button handler code here..
        //[/UserButtonCode_undo]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="HistoryComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="300" initialHeight="40">
  <BACKGROUND backgroundColour="0"/>
  <TEXTBUTTON name="save" id="ae6f6f001f0e0f94" memberName="save" virtualName=""
              explicitFocusOrder="0" pos="29.05% 23.077% 20.112% 57.692%" buttonText="Save"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="load" id="d073f4931f861d5b" memberName="load" virtualName=""
              explicitFocusOrder="0" pos="6.704% 23.077% 20.112% 57.692%" buttonText="Load"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="redo" id="550f5d2f473463e8" memberName="redo" virtualName=""
              explicitFocusOrder="0" pos="73.743% 23.077% 20.112% 57.692%"
              buttonText="Redo" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="undo" id="734eb6d517ff5b27" memberName="undo" virtualName=""
              explicitFocusOrder="0" pos="51.397% 23.077% 20.112% 57.692%"
              buttonText="Undo" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
