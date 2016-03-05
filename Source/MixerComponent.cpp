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

#include "MixerComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MixerComponent::MixerComponent (Controller* controller)
    : BaseComponent(controller)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (ch2 = new MixerStrip (controller, 1));
    addAndMakeVisible (ch3 = new MixerStrip (controller, 2));
    addAndMakeVisible (ch4 = new MixerStrip (controller, 3));
    addAndMakeVisible (ch5 = new MixerStrip (controller, 4));
    addAndMakeVisible (ch6 = new MixerStrip (controller, 5));
    addAndMakeVisible (ch1 = new MixerStrip (controller, 0));
    addAndMakeVisible (muteLabel = new Label ("new label",
                                              TRANS("Mute")));
    muteLabel->setFont (Font (15.00f, Font::plain));
    muteLabel->setJustificationType (Justification::centred);
    muteLabel->setEditable (false, false, false);
    muteLabel->setColour (Label::textColourId, Colours::white);
    muteLabel->setColour (Label::outlineColourId, Colour (0x00ffffff));
    muteLabel->setColour (TextEditor::textColourId, Colours::black);
    muteLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (levelLabel = new Label ("new label",
                                               TRANS("Level")));
    levelLabel->setFont (Font (15.00f, Font::plain));
    levelLabel->setJustificationType (Justification::centred);
    levelLabel->setEditable (false, false, false);
    levelLabel->setColour (Label::textColourId, Colours::white);
    levelLabel->setColour (TextEditor::textColourId, Colours::black);
    levelLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (reverbLabel = new Label ("new label",
                                                TRANS("Reverb")));
    reverbLabel->setFont (Font (15.00f, Font::plain));
    reverbLabel->setJustificationType (Justification::centred);
    reverbLabel->setEditable (false, false, false);
    reverbLabel->setColour (Label::textColourId, Colours::white);
    reverbLabel->setColour (TextEditor::textColourId, Colours::black);
    reverbLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (delayLabel = new Label ("new label",
                                               TRANS("Delay")));
    delayLabel->setFont (Font (15.00f, Font::plain));
    delayLabel->setJustificationType (Justification::centred);
    delayLabel->setEditable (false, false, false);
    delayLabel->setColour (Label::textColourId, Colours::white);
    delayLabel->setColour (TextEditor::textColourId, Colours::black);
    delayLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (panLabel = new Label ("new label",
                                             TRANS("Pan\n")));
    panLabel->setFont (Font (15.00f, Font::plain));
    panLabel->setJustificationType (Justification::centred);
    panLabel->setEditable (false, false, false);
    panLabel->setColour (Label::textColourId, Colours::white);
    panLabel->setColour (Label::outlineColourId, Colour (0x00ffffff));
    panLabel->setColour (TextEditor::textColourId, Colours::black);
    panLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (400, 220);


    //[Constructor] You can add your own custom stuff here..
    labels.add(reverbLabel);
    labels.add(delayLabel);
    labels.add(panLabel);
    labels.add(levelLabel);
    labels.add(muteLabel);

    channelStrips.add(ch1);
    channelStrips.add(ch2);
    channelStrips.add(ch3);
    channelStrips.add(ch4);
    channelStrips.add(ch5);
    channelStrips.add(ch6);
    //[/Constructor]
}

MixerComponent::~MixerComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    ch2 = nullptr;
    ch3 = nullptr;
    ch4 = nullptr;
    ch5 = nullptr;
    ch6 = nullptr;
    ch1 = nullptr;
    muteLabel = nullptr;
    levelLabel = nullptr;
    reverbLabel = nullptr;
    delayLabel = nullptr;
    panLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    labels.clear();
    //[/Destructor]
}

//==============================================================================
void MixerComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..



    for (auto label : labels) {

        //label->setColour (Label::outlineColourId, Colours::white);
        label->setFont (Font (12.00f, Font::plain));

        AffineTransform transform = myTransform.rotated(
            -double_Pi*0.5f,
            label->getX()+label->getWidth()/2.0,
            label->getY()+label->getHeight()/2.0
        );

        Component* reference = nullptr;

        if (label == reverbLabel) {
            reference = ch1->reverbSlider;
        } else if (label == delayLabel) {
            reference = ch1->delaySlider;
        } else if (label == panLabel) {
            reference = ch1->panSlider;
        } else if (label == levelLabel) {
            reference = ch1->volumeSlider;
        } else if (label == muteLabel) {
            reference = ch1->muteButton;
        }

        Rectangle<int> bounds = label->getBounds();
        bounds.setY(ch1->getY() + reference->getY() + reference->getHeight()/2.0 - bounds.getHeight()/2.0);
        bounds.setX(-((label->getWidth()-label->getHeight())/2.0));
        label->setBounds(bounds);

        label->setTransform(transform);
    }

    //[/UserPaint]
}

void MixerComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    ch2->setBounds (83, proportionOfHeight (0.0000f), proportionOfWidth (0.1425f), proportionOfHeight (1.0000f));
    ch3->setBounds (142, proportionOfHeight (0.0000f), proportionOfWidth (0.1475f), proportionOfHeight (1.0000f));
    ch4->setBounds (203, proportionOfHeight (0.0000f), proportionOfWidth (0.1475f), proportionOfHeight (1.0000f));
    ch5->setBounds (264, proportionOfHeight (0.0000f), proportionOfWidth (0.1475f), proportionOfHeight (1.0000f));
    ch6->setBounds (325, proportionOfHeight (0.0000f), proportionOfWidth (0.1475f), proportionOfHeight (1.0000f));
    ch1->setBounds (22, proportionOfHeight (0.0000f), proportionOfWidth (0.1475f), proportionOfHeight (1.0000f));
    muteLabel->setBounds (-24, proportionOfHeight (0.7091f), 53, 16);
    levelLabel->setBounds (-32, proportionOfHeight (0.0318f), 62, 16);
    reverbLabel->setBounds (-32, proportionOfHeight (0.1500f), 62, 16);
    delayLabel->setBounds (-32, proportionOfHeight (0.3136f), 53, 16);
    panLabel->setBounds (-32, proportionOfHeight (0.4864f), 53, 16);
    //[UserResized] Add your own custom resize handling here..

    int padding = 1;
    Rectangle<int> bounds;

    for (int i = 1; i < channelStrips.size(); i++) {
        bounds = channelStrips[i-1]->getBounds();
        channelStrips[i]->setBounds(bounds.getX()+bounds.getWidth()+padding, bounds.getY(), bounds.getWidth(), bounds.getHeight());
    }
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

<JUCER_COMPONENT documentType="Component" className="MixerComponent" componentName=""
                 parentClasses="public BaseComponent" constructorParams="Controller* controller"
                 variableInitialisers="BaseComponent(controller)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="400" initialHeight="220">
  <BACKGROUND backgroundColour="0"/>
  <JUCERCOMP name="ch2" id="fb7708f454bc61f0" memberName="ch2" virtualName=""
             explicitFocusOrder="0" pos="83 0% 14.25% 100%" sourceFile="MixerStrip.cpp"
             constructorParams="controller, 1"/>
  <JUCERCOMP name="ch3" id="62501aac3a687188" memberName="ch3" virtualName=""
             explicitFocusOrder="0" pos="142 0% 14.75% 100%" sourceFile="MixerStrip.cpp"
             constructorParams="controller, 2"/>
  <JUCERCOMP name="ch4" id="8abf6913990e9d94" memberName="ch4" virtualName=""
             explicitFocusOrder="0" pos="203 0% 14.75% 100%" sourceFile="MixerStrip.cpp"
             constructorParams="controller, 3"/>
  <JUCERCOMP name="ch5" id="8d925570f6433a1b" memberName="ch5" virtualName=""
             explicitFocusOrder="0" pos="264 0% 14.75% 100%" sourceFile="MixerStrip.cpp"
             constructorParams="controller, 4"/>
  <JUCERCOMP name="ch6" id="d4eeb1caf95d7015" memberName="ch6" virtualName=""
             explicitFocusOrder="0" pos="325 0% 14.75% 100%" sourceFile="MixerStrip.cpp"
             constructorParams="controller, 5"/>
  <JUCERCOMP name="" id="2082ceb4984fc266" memberName="ch1" virtualName=""
             explicitFocusOrder="0" pos="22 0% 14.75% 100%" sourceFile="MixerStrip.cpp"
             constructorParams="controller, 0"/>
  <LABEL name="new label" id="cd1a578364492782" memberName="muteLabel"
         virtualName="" explicitFocusOrder="0" pos="-24 70.909% 53 16"
         textCol="ffffffff" outlineCol="ffffff" edTextCol="ff000000" edBkgCol="0"
         labelText="Mute" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="86863f7a16ba1202" memberName="levelLabel"
         virtualName="" explicitFocusOrder="0" pos="-32 3.182% 62 16"
         textCol="ffffffff" edTextCol="ff000000" edBkgCol="0" labelText="Level"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="478a06f0333b831e" memberName="reverbLabel"
         virtualName="" explicitFocusOrder="0" pos="-32 15% 62 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Reverb" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="9b7e2b4d22f37ff4" memberName="delayLabel"
         virtualName="" explicitFocusOrder="0" pos="-32 31.364% 53 16"
         textCol="ffffffff" edTextCol="ff000000" edBkgCol="0" labelText="Delay"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="ebac225cecd469fb" memberName="panLabel"
         virtualName="" explicitFocusOrder="0" pos="-32 48.636% 53 16"
         textCol="ffffffff" outlineCol="ffffff" edTextCol="ff000000" edBkgCol="0"
         labelText="Pan&#10;" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
