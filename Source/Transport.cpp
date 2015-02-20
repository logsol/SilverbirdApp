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
#include "BpmSlider.h"
#include "Controller.h"
//[/Headers]

#include "Transport.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Transport::Transport (Controller* controller)
    : controller(controller)
{
    addAndMakeVisible (bpmSlider = new BpmSlider (String::empty));
    bpmSlider->setRange (100, 180, 1);
    bpmSlider->setSliderStyle (Slider::LinearBar);
    bpmSlider->setTextBoxStyle (Slider::TextBoxLeft, false, 100, 20);
    bpmSlider->setColour (Slider::backgroundColourId, Colour (0x30000000));
    bpmSlider->setColour (Slider::thumbColourId, Colour (0xffcecece));
    bpmSlider->setColour (Slider::trackColourId, Colour (0xffcecece));
    bpmSlider->setColour (Slider::rotarySliderFillColourId, Colour (0x000000ff));
    bpmSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0x00000000));
    bpmSlider->setColour (Slider::textBoxTextColourId, Colours::black);
    bpmSlider->setColour (Slider::textBoxHighlightColourId, Colour (0x001111ee));
    bpmSlider->addListener (this);

    addAndMakeVisible (playButton = new TextButton ("play"));
    playButton->setButtonText (TRANS("Play"));
    playButton->addListener (this);
    playButton->setColour (TextButton::buttonColourId, Colour (0xffcecece));

    addAndMakeVisible (stopButton = new TextButton ("stop"));
    stopButton->setButtonText (TRANS("Stop"));
    stopButton->addListener (this);
    stopButton->setColour (TextButton::buttonColourId, Colour (0xffcecece));

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("BPM")));
    label->setFont (Font (15.00f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (230, 40);


    //[Constructor] You can add your own custom stuff here..
    bpmSlider->setSliderStyle(Slider::SliderStyle::LinearBarVertical);
    //[/Constructor]
}

Transport::~Transport()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    bpmSlider = nullptr;
    playButton = nullptr;
    stopButton = nullptr;
    label = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Transport::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void Transport::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    bpmSlider->setBounds (16, 8, 40, 24);
    playButton->setBounds (104, 8, 48, 24);
    stopButton->setBounds (160, 8, 47, 24);
    label->setBounds (61, 8, 40, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Transport::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == bpmSlider)
    {
        //[UserSliderCode_bpmSlider] -- add your slider handling code here..
        controller->setBpm(bpmSlider->getValue());
        //[/UserSliderCode_bpmSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void Transport::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == playButton)
    {
        //[UserButtonCode_playButton] -- add your button handler code here..
        controller->setPlayPause(true);
        //[/UserButtonCode_playButton]
    }
    else if (buttonThatWasClicked == stopButton)
    {
        //[UserButtonCode_stopButton] -- add your button handler code here..
        controller->setPlayPause(false);
        //[/UserButtonCode_stopButton]
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

<JUCER_COMPONENT documentType="Component" className="Transport" componentName=""
                 parentClasses="public Component" constructorParams="Controller* controller"
                 variableInitialisers="controller(controller)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="230" initialHeight="40">
  <BACKGROUND backgroundColour="0"/>
  <SLIDER name="" id="3368eda71e194b82" memberName="bpmSlider" virtualName="BpmSlider"
          explicitFocusOrder="0" pos="16 8 40 24" bkgcol="30000000" thumbcol="ffcecece"
          trackcol="ffcecece" rotarysliderfill="ff" rotaryslideroutline="0"
          textboxtext="ff000000" textboxhighlight="1111ee" min="100" max="180"
          int="1" style="LinearBar" textBoxPos="TextBoxLeft" textBoxEditable="1"
          textBoxWidth="100" textBoxHeight="20" skewFactor="1"/>
  <TEXTBUTTON name="play" id="e919a91fb78e40b3" memberName="playButton" virtualName=""
              explicitFocusOrder="0" pos="104 8 48 24" bgColOff="ffcecece"
              buttonText="Play" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="stop" id="1373f2a4112d3d9f" memberName="stopButton" virtualName=""
              explicitFocusOrder="0" pos="160 8 47 24" bgColOff="ffcecece"
              buttonText="Stop" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="e5bd61ea8c7a90cf" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="61 8 40 24" edTextCol="ff000000"
         edBkgCol="0" labelText="BPM" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
