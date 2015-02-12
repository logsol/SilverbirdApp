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

#include "TrackParameters.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TrackParameters::TrackParameters (Controller* controller, int trackId)
    : controller(controller), trackId(trackId)
{
    addAndMakeVisible (selectSlider = new Knob ("Select"));
    selectSlider->setRange (0, 20, 1);
    selectSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    selectSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    selectSlider->addListener (this);

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("Select")));
    label2->setFont (Font (15.00f, Font::plain));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (attackSlider = new Knob ("Attack"));
    attackSlider->setRange (0, 1, 0);
    attackSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    attackSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    attackSlider->addListener (this);

    addAndMakeVisible (label4 = new Label ("new label",
                                           TRANS("Attack\n")));
    label4->setFont (Font (15.00f, Font::plain));
    label4->setJustificationType (Justification::centred);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (decaySlider = new Knob ("Decay"));
    decaySlider->setRange (0, 1, 0);
    decaySlider->setSliderStyle (Slider::RotaryVerticalDrag);
    decaySlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    decaySlider->addListener (this);

    addAndMakeVisible (label5 = new Label ("new label",
                                           TRANS("Decay")));
    label5->setFont (Font (15.00f, Font::plain));
    label5->setJustificationType (Justification::centred);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (pitchSlider = new Knob ("Pitch"));
    pitchSlider->setRange (-2, 2, 0.0833333);
    pitchSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    pitchSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    pitchSlider->addListener (this);

    addAndMakeVisible (label6 = new Label ("new label",
                                           TRANS("Pitch")));
    label6->setFont (Font (15.00f, Font::plain));
    label6->setJustificationType (Justification::centred);
    label6->setEditable (false, false, false);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (cutoffSlider = new Knob ("Pitch"));
    cutoffSlider->setRange (0, 1, 0);
    cutoffSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    cutoffSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    cutoffSlider->addListener (this);

    addAndMakeVisible (label10 = new Label ("new label",
                                            TRANS("Cutoff")));
    label10->setFont (Font (15.00f, Font::plain));
    label10->setJustificationType (Justification::centred);
    label10->setEditable (false, false, false);
    label10->setColour (TextEditor::textColourId, Colours::black);
    label10->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (distortSlider = new Knob ("Distort"));
    distortSlider->setRange (0, 1, 0);
    distortSlider->setSliderStyle (Slider::RotaryVerticalDrag);
    distortSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    distortSlider->addListener (this);

    addAndMakeVisible (label3 = new Label ("new label",
                                           TRANS("Distort")));
    label3->setFont (Font (15.00f, Font::plain));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..

    Parameter* p;

    p = controller->getParameterByAttrs(Controller::params::sample, trackId);
    selectSlider->getValueObject().referTo(*p);
    selectSlider->addListener(controller);

    p = controller->getParameterByAttrs(Controller::params::pitch, trackId);
    pitchSlider->getValueObject().referTo(*p);
    pitchSlider->addListener(controller);

    p = controller->getParameterByAttrs(Controller::params::attack, trackId);
    attackSlider->getValueObject().referTo(*p);
    attackSlider->addListener(controller);

    p = controller->getParameterByAttrs(Controller::params::decay, trackId);
    decaySlider->getValueObject().referTo(*p);
    decaySlider->addListener(controller);

    p = controller->getParameterByAttrs(Controller::params::distort, trackId);
    distortSlider->getValueObject().referTo(*p);
    distortSlider->addListener(controller);

    p = controller->getParameterByAttrs(Controller::params::cutoff, trackId);
    cutoffSlider->getValueObject().referTo(*p);
    cutoffSlider->addListener(controller);

    selectSlider->setValue(3);
    decaySlider->setValue(1);
    pitchSlider->setValue(0);
    cutoffSlider->setValue(1);

    //[/Constructor]
}

TrackParameters::~TrackParameters()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    selectSlider = nullptr;
    label2 = nullptr;
    attackSlider = nullptr;
    label4 = nullptr;
    decaySlider = nullptr;
    label5 = nullptr;
    pitchSlider = nullptr;
    label6 = nullptr;
    cutoffSlider = nullptr;
    label10 = nullptr;
    distortSlider = nullptr;
    label3 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TrackParameters::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TrackParameters::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    selectSlider->setBounds (16, 40, 40, 40);
    label2->setBounds (-11, 13, 96, 24);
    attackSlider->setBounds (158, 40, 40, 40);
    label4->setBounds (131, 13, 96, 24);
    decaySlider->setBounds (208, 40, 40, 40);
    label5->setBounds (179, 13, 96, 24);
    pitchSlider->setBounds (83, 48, 32, 32);
    label6->setBounds (65, 13, 67, 24);
    cutoffSlider->setBounds (337, 40, 40, 40);
    label10->setBounds (310, 13, 96, 24);
    distortSlider->setBounds (284, 40, 40, 40);
    label3->setBounds (256, 13, 96, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void TrackParameters::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == selectSlider)
    {
        //[UserSliderCode_selectSlider] -- add your slider handling code here..
        //[/UserSliderCode_selectSlider]
    }
    else if (sliderThatWasMoved == attackSlider)
    {
        //[UserSliderCode_attackSlider] -- add your slider handling code here..
        //[/UserSliderCode_attackSlider]
    }
    else if (sliderThatWasMoved == decaySlider)
    {
        //[UserSliderCode_decaySlider] -- add your slider handling code here..
        //[/UserSliderCode_decaySlider]
    }
    else if (sliderThatWasMoved == pitchSlider)
    {
        //[UserSliderCode_pitchSlider] -- add your slider handling code here..
        //[/UserSliderCode_pitchSlider]
    }
    else if (sliderThatWasMoved == cutoffSlider)
    {
        //[UserSliderCode_cutoffSlider] -- add your slider handling code here..
        //[/UserSliderCode_cutoffSlider]
    }
    else if (sliderThatWasMoved == distortSlider)
    {
        //[UserSliderCode_distortSlider] -- add your slider handling code here..
        //[/UserSliderCode_distortSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TrackParameters" componentName=""
                 parentClasses="public Component" constructorParams="Controller* controller, int trackId"
                 variableInitialisers="controller(controller), trackId(trackId)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffff"/>
  <SLIDER name="Select" id="ae2904d9e602bae7" memberName="selectSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="16 40 40 40" min="0"
          max="20" int="1" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="9b95e80f4bba0ec3" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="-11 13 96 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Select" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="Attack" id="dcf2dbaf52d14406" memberName="attackSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="158 40 40 40"
          min="0" max="1" int="0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="600acbb5e03c4485" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="131 13 96 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Attack&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <SLIDER name="Decay" id="9c5da3b543af0acd" memberName="decaySlider" virtualName="Knob"
          explicitFocusOrder="0" pos="208 40 40 40" min="0" max="1" int="0"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="6d80791f4a659e3" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="179 13 96 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Decay" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="Pitch" id="a0bcc16014a81d26" memberName="pitchSlider" virtualName="Knob"
          explicitFocusOrder="0" pos="83 48 32 32" min="-2" max="2" int="0.083333333333299994261"
          style="RotaryVerticalDrag" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="1f974eb41a59cc16" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="65 13 67 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Pitch" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="Pitch" id="ec9ceab9e8f418ea" memberName="cutoffSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="337 40 40 40"
          min="0" max="1" int="0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="c2f8b942c21a3df3" memberName="label10" virtualName=""
         explicitFocusOrder="0" pos="310 13 96 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Cutoff" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="Distort" id="43b059df97ad4e4a" memberName="distortSlider"
          virtualName="Knob" explicitFocusOrder="0" pos="284 40 40 40"
          min="0" max="1" int="0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="d9e5fba9bb477192" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="256 13 96 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Distort" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
