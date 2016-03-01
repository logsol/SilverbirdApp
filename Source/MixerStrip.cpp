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
class Controller;
//[/Headers]

#include "MixerStrip.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MixerStrip::MixerStrip (Controller* controller, int trackId)
    : BaseComponent(controller),
      trackId(trackId)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (volumeSlider = new Knob (String()));
    volumeSlider->setRange (0, 1, 0);
    volumeSlider->setSliderStyle (Slider::LinearBar);
    volumeSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    volumeSlider->setColour (Slider::thumbColourId, Colour (0xffffeb86));
    volumeSlider->addListener (this);

    addAndMakeVisible (striplabel = new Label (String(),
                                               TRANS("Label")));
    striplabel->setFont (Font (15.00f, Font::plain));
    striplabel->setJustificationType (Justification::centred);
    striplabel->setEditable (false, false, false);
    striplabel->setColour (Label::textColourId, Colours::white);
    striplabel->setColour (TextEditor::textColourId, Colours::black);
    striplabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (muteButton = new TextButton (String()));
    muteButton->setButtonText (TRANS("M"));
    muteButton->addListener (this);
    muteButton->setColour (TextButton::buttonColourId, Colour (0xffcecece));
    muteButton->setColour (TextButton::buttonOnColourId, Colour (0xffffeb86));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (60, 100);


    //[Constructor] You can add your own custom stuff here..
    Parameter* p;
    p = controller->getParameterByAttrs(Controller::params::level, trackId);

    volumeSlider->addListener(controller);
    volumeSlider->getValueObject().referTo(*p);
    volumeSlider->setDoubleClickReturnValue(true, p->getDefaultValue());
    volumeSlider->setSliderStyle(Slider::LinearBarVertical);

    p = controller->getParameterByAttrs(Controller::params::mute, trackId);
    muteButton->addListener(controller);
    muteButton->getToggleStateValue().referTo(*p);
    muteButton->setClickingTogglesState(true);

    striplabel->setText(controller->mixer.getNameByTrackId(trackId), dontSendNotification);
    //[/Constructor]
}

MixerStrip::~MixerStrip()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    volumeSlider = nullptr;
    striplabel = nullptr;
    muteButton = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MixerStrip::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MixerStrip::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    volumeSlider->setBounds (proportionOfWidth (0.0667f), proportionOfHeight (0.2300f), proportionOfWidth (0.8167f), proportionOfHeight (0.5000f));
    striplabel->setBounds (0, proportionOfHeight (0.0600f), proportionOfWidth (1.0000f), proportionOfHeight (0.1400f));
    muteButton->setBounds (proportionOfWidth (0.0667f), proportionOfHeight (0.7300f), proportionOfWidth (0.8167f), proportionOfHeight (0.2300f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void MixerStrip::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == volumeSlider)
    {
        //[UserSliderCode_volumeSlider] -- add your slider handling code here..
        //[/UserSliderCode_volumeSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void MixerStrip::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == muteButton)
    {
        //[UserButtonCode_muteButton] -- add your button handler code here..
        //[/UserButtonCode_muteButton]
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

<JUCER_COMPONENT documentType="Component" className="MixerStrip" componentName=""
                 parentClasses="public BaseComponent" constructorParams="Controller* controller, int trackId"
                 variableInitialisers="BaseComponent(controller),&#10;trackId(trackId)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="60" initialHeight="100">
  <BACKGROUND backgroundColour="0"/>
  <SLIDER name="" id="caab896538cb75ff" memberName="volumeSlider" virtualName="Knob"
          explicitFocusOrder="0" pos="6.78% 22.667% 81.356% 50%" thumbcol="ffffeb86"
          min="0" max="1" int="0" style="LinearBar" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="" id="3c135fce2ca970bf" memberName="striplabel" virtualName=""
         explicitFocusOrder="0" pos="0 6% 100% 14%" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Label" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <TEXTBUTTON name="" id="77cd8f798e359cb1" memberName="muteButton" virtualName=""
              explicitFocusOrder="0" pos="6.78% 73.333% 81.356% 22.667%" bgColOff="ffcecece"
              bgColOn="ffffeb86" buttonText="M" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
