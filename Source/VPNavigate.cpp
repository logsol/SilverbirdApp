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
#include "Portrait.h" // fixme remove this
//[/Headers]

#include "VPNavigate.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
VPNavigate::VPNavigate (Controller* controller)
    : BaseComponent(controller)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (sequencer = new SbButton (String()));
    sequencer->setButtonText (TRANS("Sequencer"));
    sequencer->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    sequencer->setRadioGroupId (6937);
    sequencer->addListener (this);
    sequencer->setColour (TextButton::buttonColourId, Colour (0xffcecece));

    addAndMakeVisible (setup = new SbButton (String()));
    setup->setButtonText (TRANS("Setup"));
    setup->setConnectedEdges (Button::ConnectedOnRight);
    setup->setRadioGroupId (6937);
    setup->addListener (this);
    setup->setColour (TextButton::buttonColourId, Colour (0xffcecece));

    addAndMakeVisible (mixer = new SbButton (String()));
    mixer->setButtonText (TRANS("Mixer"));
    mixer->setConnectedEdges (Button::ConnectedOnLeft);
    mixer->setRadioGroupId (6937);
    mixer->addListener (this);
    mixer->setColour (TextButton::buttonColourId, Colour (0xffcecece));

    addAndMakeVisible (playButton = new SbButton (String()));
    playButton->setButtonText (TRANS("Play"));
    playButton->addListener (this);
    playButton->setColour (TextButton::buttonColourId, Colour (0xffcecece));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (320, 38);


    //[Constructor] You can add your own custom stuff here..
    setup->setClickingTogglesState(true);
    sequencer->setClickingTogglesState(true);
    mixer->setClickingTogglesState(true);

    sequencer->setToggleState(true, dontSendNotification);

    //[/Constructor]
}

VPNavigate::~VPNavigate()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    sequencer = nullptr;
    setup = nullptr;
    mixer = nullptr;
    playButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void VPNavigate::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void VPNavigate::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    sequencer->setBounds (proportionOfWidth (0.0000f) + roundFloatToInt (proportionOfWidth (0.2188f) * 0.9857f), proportionOfHeight (0.0000f), proportionOfWidth (0.3031f), proportionOfHeight (1.0000f));
    setup->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.0000f), proportionOfWidth (0.2188f), proportionOfHeight (1.0000f));
    mixer->setBounds ((proportionOfWidth (0.0000f) + roundFloatToInt (proportionOfWidth (0.2188f) * 0.9857f)) + roundFloatToInt (proportionOfWidth (0.3031f) * 0.9794f), proportionOfHeight (0.0000f), proportionOfWidth (0.2188f), proportionOfHeight (1.0000f));
    playButton->setBounds (proportionOfWidth (0.7594f), proportionOfHeight (0.0000f), proportionOfWidth (0.2406f), proportionOfHeight (1.0000f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void VPNavigate::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    Component* a = getParentComponent();
    Portrait* p = dynamic_cast<Portrait*>(a);
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == sequencer)
    {
        //[UserButtonCode_sequencer] -- add your button handler code here..
        p->slideTo(1);
        //[/UserButtonCode_sequencer]
    }
    else if (buttonThatWasClicked == setup)
    {
        //[UserButtonCode_setup] -- add your button handler code here..
        p->slideTo(0);
        //[/UserButtonCode_setup]
    }
    else if (buttonThatWasClicked == mixer)
    {
        //[UserButtonCode_mixer] -- add your button handler code here..
        p->slideTo(2);
        //[/UserButtonCode_mixer]
    }
    else if (buttonThatWasClicked == playButton)
    {
        //[UserButtonCode_playButton] -- add your button handler code here..
        bool isPlaying = controller->togglePlayPause();
        playButton->setButtonText (TRANS(isPlaying ? "Stop" : "Play"));
        //[/UserButtonCode_playButton]
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

<JUCER_COMPONENT documentType="Component" className="VPNavigate" componentName=""
                 parentClasses="public BaseComponent" constructorParams="Controller* controller"
                 variableInitialisers="BaseComponent(controller)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="320" initialHeight="38">
  <BACKGROUND backgroundColour="0"/>
  <TEXTBUTTON name="" id="7de12c148a506af0" memberName="sequencer" virtualName="SbButton"
              explicitFocusOrder="0" pos="98.571% 0% 30.312% 100%" posRelativeX="e3472dc8542a2fb4"
              bgColOff="ffcecece" buttonText="Sequencer" connectedEdges="3"
              needsCallback="1" radioGroupId="6937"/>
  <TEXTBUTTON name="" id="e3472dc8542a2fb4" memberName="setup" virtualName="SbButton"
              explicitFocusOrder="0" pos="0% 0% 21.875% 100%" bgColOff="ffcecece"
              buttonText="Setup" connectedEdges="2" needsCallback="1" radioGroupId="6937"/>
  <TEXTBUTTON name="" id="b9d502978143d2ff" memberName="mixer" virtualName="SbButton"
              explicitFocusOrder="0" pos="97.938% 0% 21.875% 100%" posRelativeX="7de12c148a506af0"
              bgColOff="ffcecece" buttonText="Mixer" connectedEdges="1" needsCallback="1"
              radioGroupId="6937"/>
  <TEXTBUTTON name="" id="e919a91fb78e40b3" memberName="playButton" virtualName="SbButton"
              explicitFocusOrder="0" pos="75.938% 0% 24.062% 100%" bgColOff="ffcecece"
              buttonText="Play" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
