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
#include "Mixer.h"
#include "CustomLook.h"
//[/Headers]

#include "Gui2.h"
#include "TrackParameters.h"
#include "Drums.h"
#include "Mods.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Gui2::Gui2 (Controller* controller)
    : AudioProcessorEditor (controller), controller(controller)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    setName ("Gui2");
    addAndMakeVisible (kickVolumeSlider = new Slider ("kickVolume"));
    kickVolumeSlider->setRange (0, 1, 0);
    kickVolumeSlider->setSliderStyle (Slider::LinearBar);
    kickVolumeSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    kickVolumeSlider->setColour (Slider::thumbColourId, Colour (0xffffeb86));
    kickVolumeSlider->addListener (this);

    addAndMakeVisible (snareVolumeSlider = new Slider ("snareVolume"));
    snareVolumeSlider->setRange (0, 1, 0);
    snareVolumeSlider->setSliderStyle (Slider::LinearBar);
    snareVolumeSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    snareVolumeSlider->setColour (Slider::thumbColourId, Colour (0xffffeb86));
    snareVolumeSlider->addListener (this);

    addAndMakeVisible (hihatVolumeSlider = new Slider ("hihatVolume"));
    hihatVolumeSlider->setRange (0, 1, 0);
    hihatVolumeSlider->setSliderStyle (Slider::LinearBar);
    hihatVolumeSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    hihatVolumeSlider->setColour (Slider::thumbColourId, Colour (0xffffeb86));
    hihatVolumeSlider->setColour (Slider::rotarySliderFillColourId, Colour (0x7f0000ff));
    hihatVolumeSlider->addListener (this);

    addAndMakeVisible (label7 = new Label ("new label",
                                           TRANS("Kick")));
    label7->setFont (Font (15.00f, Font::plain));
    label7->setJustificationType (Justification::centredLeft);
    label7->setEditable (false, false, false);
    label7->setColour (Label::textColourId, Colours::white);
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label8 = new Label ("new label",
                                           TRANS("Snare")));
    label8->setFont (Font (15.00f, Font::plain));
    label8->setJustificationType (Justification::centredLeft);
    label8->setEditable (false, false, false);
    label8->setColour (Label::textColourId, Colours::white);
    label8->setColour (TextEditor::textColourId, Colours::black);
    label8->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label9 = new Label ("new label",
                                           TRANS("Hihat")));
    label9->setFont (Font (15.00f, Font::plain));
    label9->setJustificationType (Justification::centredLeft);
    label9->setEditable (false, false, false);
    label9->setColour (Label::textColourId, Colours::white);
    label9->setColour (TextEditor::textColourId, Colours::black);
    label9->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (trackTabs = new TabbedComponent (TabbedButtonBar::TabsAtTop));
    trackTabs->setTabBarDepth (26);
    trackTabs->addTab (TRANS("Kick"), Colour (0xf1383838), new TrackParameters (controller, 0), true);
    trackTabs->addTab (TRANS("Snare"), Colour (0xf1383838), new TrackParameters (controller, 1), true);
    trackTabs->addTab (TRANS("Hihat"), Colour (0xf1383838), new TrackParameters (controller, 2), true);
    trackTabs->addTab (TRANS("Perc1"), Colour (0xf1383838), new TrackParameters (controller, 3), true);
    trackTabs->addTab (TRANS("Perc2"), Colour (0xf1383838), new TrackParameters (controller, 4), true);
    trackTabs->addTab (TRANS("Tones"), Colour (0xf1383838), new TrackParameters (controller, 5), true);
    trackTabs->addTab (TRANS("Global"), Colour (0xff6a6a6a), new TrackParameters (controller, -1), true);
    trackTabs->setCurrentTabIndex (0);

    addAndMakeVisible (shuffleSlider = new Slider ("Shuffle"));
    shuffleSlider->setRange (0, 1, 0);
    shuffleSlider->setSliderStyle (Slider::LinearBar);
    shuffleSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    shuffleSlider->addListener (this);

    addAndMakeVisible (label10 = new Label ("new label",
                                            TRANS("Shuffle")));
    label10->setFont (Font (13.00f, Font::plain));
    label10->setJustificationType (Justification::centred);
    label10->setEditable (false, false, false);
    label10->setColour (Label::textColourId, Colour (0xfff3f3f3));
    label10->setColour (TextEditor::textColourId, Colours::black);
    label10->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (perc1VolumeSlider = new Slider ("perc1Volume"));
    perc1VolumeSlider->setRange (0, 1, 0);
    perc1VolumeSlider->setSliderStyle (Slider::LinearBar);
    perc1VolumeSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    perc1VolumeSlider->setColour (Slider::thumbColourId, Colour (0xffffeb86));
    perc1VolumeSlider->addListener (this);

    addAndMakeVisible (perc2VolumeSlider = new Slider ("perc2Volume"));
    perc2VolumeSlider->setRange (0, 1, 0);
    perc2VolumeSlider->setSliderStyle (Slider::LinearBar);
    perc2VolumeSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    perc2VolumeSlider->setColour (Slider::thumbColourId, Colour (0xffffeb86));
    perc2VolumeSlider->addListener (this);

    addAndMakeVisible (tonesVolumeSlider = new Slider ("tonesVolume"));
    tonesVolumeSlider->setRange (0, 1, 0);
    tonesVolumeSlider->setSliderStyle (Slider::LinearBar);
    tonesVolumeSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    tonesVolumeSlider->setColour (Slider::thumbColourId, Colour (0xffffeb86));
    tonesVolumeSlider->addListener (this);

    addAndMakeVisible (label12 = new Label ("new label",
                                            TRANS("Perc1")));
    label12->setFont (Font (15.00f, Font::plain));
    label12->setJustificationType (Justification::centredLeft);
    label12->setEditable (false, false, false);
    label12->setColour (Label::textColourId, Colours::white);
    label12->setColour (TextEditor::textColourId, Colours::black);
    label12->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label13 = new Label ("new label",
                                            TRANS("Perc2")));
    label13->setFont (Font (15.00f, Font::plain));
    label13->setJustificationType (Justification::centredLeft);
    label13->setEditable (false, false, false);
    label13->setColour (Label::textColourId, Colours::white);
    label13->setColour (TextEditor::textColourId, Colours::black);
    label13->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label14 = new Label ("new label",
                                            TRANS("Tones")));
    label14->setFont (Font (15.00f, Font::plain));
    label14->setJustificationType (Justification::centredLeft);
    label14->setEditable (false, false, false);
    label14->setColour (Label::textColourId, Colours::white);
    label14->setColour (TextEditor::textColourId, Colours::black);
    label14->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (sequencerTabs = new TabbedComponent (TabbedButtonBar::TabsAtLeft));
    sequencerTabs->setTabBarDepth (25);
    sequencerTabs->addTab (TRANS("Drums"), Colour (0xf1383838), new Drums (controller), true);
    sequencerTabs->addTab (TRANS("Mods"), Colour (0xf1383838), new Mods (controller), true);
    sequencerTabs->setCurrentTabIndex (0);

    addAndMakeVisible (kickMuteButton = new TextButton ("kickMute"));
    kickMuteButton->setButtonText (TRANS("M"));
    kickMuteButton->addListener (this);
    kickMuteButton->setColour (TextButton::buttonColourId, Colour (0xffcecece));
    kickMuteButton->setColour (TextButton::buttonOnColourId, Colour (0xffffeb86));

    addAndMakeVisible (snareMuteButton = new TextButton ("snareMute"));
    snareMuteButton->setButtonText (TRANS("M"));
    snareMuteButton->addListener (this);
    snareMuteButton->setColour (TextButton::buttonColourId, Colour (0xffcecece));
    snareMuteButton->setColour (TextButton::buttonOnColourId, Colour (0xffffeb86));

    addAndMakeVisible (hihatMuteButton = new TextButton ("hihatMute"));
    hihatMuteButton->setButtonText (TRANS("M"));
    hihatMuteButton->addListener (this);
    hihatMuteButton->setColour (TextButton::buttonColourId, Colour (0xffcecece));
    hihatMuteButton->setColour (TextButton::buttonOnColourId, Colour (0xffffeb86));

    addAndMakeVisible (perc2MuteButton = new TextButton ("perc2Mute"));
    perc2MuteButton->setButtonText (TRANS("M"));
    perc2MuteButton->addListener (this);
    perc2MuteButton->setColour (TextButton::buttonColourId, Colour (0xffcecece));
    perc2MuteButton->setColour (TextButton::buttonOnColourId, Colour (0xffffeb86));

    addAndMakeVisible (tonesMuteButton = new TextButton ("tonesMute"));
    tonesMuteButton->setButtonText (TRANS("M"));
    tonesMuteButton->addListener (this);
    tonesMuteButton->setColour (TextButton::buttonColourId, Colour (0xffcecece));
    tonesMuteButton->setColour (TextButton::buttonOnColourId, Colour (0xffffeb86));

    addAndMakeVisible (perc1MuteButton = new TextButton ("perc1Mute"));
    perc1MuteButton->setButtonText (TRANS("M"));
    perc1MuteButton->addListener (this);
    perc1MuteButton->setColour (TextButton::buttonColourId, Colour (0xffcecece));
    perc1MuteButton->setColour (TextButton::buttonOnColourId, Colour (0xffffeb86));

    addAndMakeVisible (transport = new Transport (controller));
    addAndMakeVisible (masterSlider = new Slider ("Master"));
    masterSlider->setRange (0, 1, 0);
    masterSlider->setSliderStyle (Slider::LinearBar);
    masterSlider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    masterSlider->setColour (Slider::thumbColourId, Colour (0xffffeb86));
    masterSlider->setColour (Slider::trackColourId, Colour (0x7fffffff));
    masterSlider->setColour (Slider::rotarySliderFillColourId, Colour (0x7f0000ff));
    masterSlider->setColour (Slider::rotarySliderOutlineColourId, Colour (0x66000000));
    masterSlider->addListener (this);

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Master")));
    label->setFont (Font (7.90f, Font::plain));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (Label::textColourId, Colours::white);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (320, 480);


    //[Constructor] You can add your own custom stuff here..


    if (JUCEApplication::isStandaloneApp()) {
        //setSize(1076, 611);
    }

    CustomLook customLook;
    customLook.setDefaultSansSerifTypefaceName("Arial");
    LookAndFeel::setDefaultLookAndFeel(&customLook);

    Parameter* p;

    p = controller->getParameterByAttrs(Controller::params::shuffle);
    shuffleSlider->addListener(controller);
    shuffleSlider->getValueObject().referTo(*p);
    shuffleSlider->setDoubleClickReturnValue(true, p->getDefaultValue());

    p = controller->getParameterByAttrs(Controller::params::level);
    masterSlider->addListener(controller);
    masterSlider->getValueObject().referTo(*p);
    masterSlider->setDoubleClickReturnValue(true, p->getDefaultValue());
    masterSlider->setSliderStyle(Slider::LinearBarVertical);


    Slider* volumeSliders [Mixer::tracks::max] = {
        kickVolumeSlider,
        snareVolumeSlider,
        hihatVolumeSlider,
        perc1VolumeSlider,
        perc2VolumeSlider,
        tonesVolumeSlider
    };

    Button* muteButtons [Mixer::tracks::max] = {
        kickMuteButton,
        snareMuteButton,
        hihatMuteButton,
        perc1MuteButton,
        perc2MuteButton,
        tonesMuteButton
    };

    for (int i = 0; i < Mixer::tracks::max; i++) {
        p = controller->getParameterByAttrs(Controller::params::level, i);
        volumeSliders[i]->addListener(controller);
        volumeSliders[i]->getValueObject().referTo(*p);
        volumeSliders[i]->setDoubleClickReturnValue(true, p->getDefaultValue());
        volumeSliders[i]->setSliderStyle(Slider::LinearBarVertical);

        p = controller->getParameterByAttrs(Controller::params::mute, i);
        muteButtons[i]->addListener(controller);
        muteButtons[i]->getToggleStateValue().referTo(*p);
        muteButtons[i]->setClickingTogglesState(true);
    }

    if(!JUCEApplication::isStandaloneApp()) {
        transport->setVisible(false);
    }



    //[/Constructor]
}

Gui2::~Gui2()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    kickVolumeSlider = nullptr;
    snareVolumeSlider = nullptr;
    hihatVolumeSlider = nullptr;
    label7 = nullptr;
    label8 = nullptr;
    label9 = nullptr;
    trackTabs = nullptr;
    shuffleSlider = nullptr;
    label10 = nullptr;
    perc1VolumeSlider = nullptr;
    perc2VolumeSlider = nullptr;
    tonesVolumeSlider = nullptr;
    label12 = nullptr;
    label13 = nullptr;
    label14 = nullptr;
    sequencerTabs = nullptr;
    kickMuteButton = nullptr;
    snareMuteButton = nullptr;
    hihatMuteButton = nullptr;
    perc2MuteButton = nullptr;
    tonesMuteButton = nullptr;
    perc1MuteButton = nullptr;
    transport = nullptr;
    masterSlider = nullptr;
    label = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Gui2::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff222222));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void Gui2::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    kickVolumeSlider->setBounds (22, 384, 35, 41);
    snareVolumeSlider->setBounds (70, 384, 35, 41);
    hihatVolumeSlider->setBounds (118, 384, 35, 41);
    label7->setBounds (22, 367, 40, 15);
    label8->setBounds (66, 367, 48, 15);
    label9->setBounds (113, 367, 48, 15);
    trackTabs->setBounds (proportionOfWidth (0.0188f), 33, proportionOfWidth (0.9594f), 92);
    shuffleSlider->setBounds (55, 458, 59, 17);
    label10->setBounds (1, 458, 47, 16);
    perc1VolumeSlider->setBounds (166, 384, 35, 41);
    perc2VolumeSlider->setBounds (214, 384, 35, 41);
    tonesVolumeSlider->setBounds (262, 384, 35, 41);
    label12->setBounds (163, 367, 45, 15);
    label13->setBounds (210, 367, 48, 15);
    label14->setBounds (256, 367, 51, 15);
    sequencerTabs->setBounds (0, 127, proportionOfWidth (0.9750f), 236);
    kickMuteButton->setBounds (24, 431, 39, 19);
    snareMuteButton->setBounds (72, 431, 39, 19);
    hihatMuteButton->setBounds (116, 431, 39, 19);
    perc2MuteButton->setBounds (212, 431, 39, 19);
    tonesMuteButton->setBounds (260, 431, 39, 19);
    perc1MuteButton->setBounds (164, 431, 39, 19);
    transport->setBounds (104, 447, 224, 40);
    masterSlider->setBounds (5, 264, 16, 99);
    label->setBounds (-2, 247, 30, 16);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Gui2::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == kickVolumeSlider)
    {
        //[UserSliderCode_kickVolumeSlider] -- add your slider handling code here..
        //[/UserSliderCode_kickVolumeSlider]
    }
    else if (sliderThatWasMoved == snareVolumeSlider)
    {
        //[UserSliderCode_snareVolumeSlider] -- add your slider handling code here..
        //[/UserSliderCode_snareVolumeSlider]
    }
    else if (sliderThatWasMoved == hihatVolumeSlider)
    {
        //[UserSliderCode_hihatVolumeSlider] -- add your slider handling code here..
        //[/UserSliderCode_hihatVolumeSlider]
    }
    else if (sliderThatWasMoved == shuffleSlider)
    {
        //[UserSliderCode_shuffleSlider] -- add your slider handling code here..
        //[/UserSliderCode_shuffleSlider]
    }
    else if (sliderThatWasMoved == perc1VolumeSlider)
    {
        //[UserSliderCode_perc1VolumeSlider] -- add your slider handling code here..
        //[/UserSliderCode_perc1VolumeSlider]
    }
    else if (sliderThatWasMoved == perc2VolumeSlider)
    {
        //[UserSliderCode_perc2VolumeSlider] -- add your slider handling code here..
        //[/UserSliderCode_perc2VolumeSlider]
    }
    else if (sliderThatWasMoved == tonesVolumeSlider)
    {
        //[UserSliderCode_tonesVolumeSlider] -- add your slider handling code here..
        //[/UserSliderCode_tonesVolumeSlider]
    }
    else if (sliderThatWasMoved == masterSlider)
    {
        //[UserSliderCode_masterSlider] -- add your slider handling code here..
        //[/UserSliderCode_masterSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void Gui2::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == kickMuteButton)
    {
        //[UserButtonCode_kickMuteButton] -- add your button handler code here..
        //[/UserButtonCode_kickMuteButton]
    }
    else if (buttonThatWasClicked == snareMuteButton)
    {
        //[UserButtonCode_snareMuteButton] -- add your button handler code here..
        //[/UserButtonCode_snareMuteButton]
    }
    else if (buttonThatWasClicked == hihatMuteButton)
    {
        //[UserButtonCode_hihatMuteButton] -- add your button handler code here..
        //[/UserButtonCode_hihatMuteButton]
    }
    else if (buttonThatWasClicked == perc2MuteButton)
    {
        //[UserButtonCode_perc2MuteButton] -- add your button handler code here..
        //[/UserButtonCode_perc2MuteButton]
    }
    else if (buttonThatWasClicked == tonesMuteButton)
    {
        //[UserButtonCode_tonesMuteButton] -- add your button handler code here..
        //[/UserButtonCode_tonesMuteButton]
    }
    else if (buttonThatWasClicked == perc1MuteButton)
    {
        //[UserButtonCode_perc1MuteButton] -- add your button handler code here..
        //[/UserButtonCode_perc1MuteButton]
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

<JUCER_COMPONENT documentType="Component" className="Gui2" componentName="Gui2"
                 parentClasses="public AudioProcessorEditor" constructorParams="Controller* controller"
                 variableInitialisers="AudioProcessorEditor (controller), controller(controller)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="320" initialHeight="480">
  <BACKGROUND backgroundColour="ff222222"/>
  <SLIDER name="kickVolume" id="ae31972216ca91d8" memberName="kickVolumeSlider"
          virtualName="" explicitFocusOrder="0" pos="22 384 35 41" thumbcol="ffffeb86"
          min="0" max="1" int="0" style="LinearBar" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="snareVolume" id="7473f902a9aba960" memberName="snareVolumeSlider"
          virtualName="" explicitFocusOrder="0" pos="70 384 35 41" thumbcol="ffffeb86"
          min="0" max="1" int="0" style="LinearBar" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="hihatVolume" id="8734ecc063a71519" memberName="hihatVolumeSlider"
          virtualName="" explicitFocusOrder="0" pos="118 384 35 41" thumbcol="ffffeb86"
          rotarysliderfill="7f0000ff" min="0" max="1" int="0" style="LinearBar"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="486b2beaa1324a51" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="22 367 40 15" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Kick" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="681d168e20d88e68" memberName="label8" virtualName=""
         explicitFocusOrder="0" pos="66 367 48 15" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Snare" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="fdffc56aa102332a" memberName="label9" virtualName=""
         explicitFocusOrder="0" pos="113 367 48 15" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Hihat" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TABBEDCOMPONENT name="new tabbed component" id="299c842daf4e2362" memberName="trackTabs"
                   virtualName="" explicitFocusOrder="0" pos="1.875% 33 95.938% 92"
                   orientation="top" tabBarDepth="26" initialTab="0">
    <TAB name="Kick" colour="f1383838" useJucerComp="1" contentClassName="TrackParameters"
         constructorParams="controller, 0" jucerComponentFile="TrackParameters.cpp"/>
    <TAB name="Snare" colour="f1383838" useJucerComp="1" contentClassName="TrackParameters"
         constructorParams="controller, 1" jucerComponentFile="TrackParameters.cpp"/>
    <TAB name="Hihat" colour="f1383838" useJucerComp="1" contentClassName="TrackParameters"
         constructorParams="controller, 2" jucerComponentFile="TrackParameters.cpp"/>
    <TAB name="Perc1" colour="f1383838" useJucerComp="1" contentClassName=""
         constructorParams="controller, 3" jucerComponentFile="TrackParameters.cpp"/>
    <TAB name="Perc2" colour="f1383838" useJucerComp="1" contentClassName=""
         constructorParams="controller, 4" jucerComponentFile="TrackParameters.cpp"/>
    <TAB name="Tones" colour="f1383838" useJucerComp="1" contentClassName=""
         constructorParams="controller, 5" jucerComponentFile="TrackParameters.cpp"/>
    <TAB name="Global" colour="ff6a6a6a" useJucerComp="1" contentClassName=""
         constructorParams="controller, -1" jucerComponentFile="TrackParameters.cpp"/>
  </TABBEDCOMPONENT>
  <SLIDER name="Shuffle" id="f2d61c4a72ddf897" memberName="shuffleSlider"
          virtualName="Slider" explicitFocusOrder="0" pos="55 458 59 17"
          min="0" max="1" int="0" style="LinearBar" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="cfbf1f6cb7801bfe" memberName="label10" virtualName=""
         explicitFocusOrder="0" pos="1 458 47 16" textCol="fff3f3f3" edTextCol="ff000000"
         edBkgCol="0" labelText="Shuffle" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="13"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="perc1Volume" id="931a095c7e36a9ad" memberName="perc1VolumeSlider"
          virtualName="" explicitFocusOrder="0" pos="166 384 35 41" thumbcol="ffffeb86"
          min="0" max="1" int="0" style="LinearBar" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="perc2Volume" id="add5fec410a35fb1" memberName="perc2VolumeSlider"
          virtualName="" explicitFocusOrder="0" pos="214 384 35 41" thumbcol="ffffeb86"
          min="0" max="1" int="0" style="LinearBar" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="tonesVolume" id="4518cd8aea8e1fba" memberName="tonesVolumeSlider"
          virtualName="" explicitFocusOrder="0" pos="262 384 35 41" thumbcol="ffffeb86"
          min="0" max="1" int="0" style="LinearBar" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="eb7df0e8715d3628" memberName="label12" virtualName=""
         explicitFocusOrder="0" pos="163 367 45 15" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Perc1" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="e795b2fc234361fa" memberName="label13" virtualName=""
         explicitFocusOrder="0" pos="210 367 48 15" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Perc2" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="f58b8e0d925833a5" memberName="label14" virtualName=""
         explicitFocusOrder="0" pos="256 367 51 15" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Tones" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <TABBEDCOMPONENT name="seqtabs" id="24d28c4cbe1b57cb" memberName="sequencerTabs"
                   virtualName="" explicitFocusOrder="0" pos="0 127 97.5% 236" orientation="left"
                   tabBarDepth="25" initialTab="0">
    <TAB name="Drums" colour="f1383838" useJucerComp="1" contentClassName=""
         constructorParams="controller" jucerComponentFile="Drums.cpp"/>
    <TAB name="Mods" colour="f1383838" useJucerComp="1" contentClassName=""
         constructorParams="controller" jucerComponentFile="Mods.cpp"/>
  </TABBEDCOMPONENT>
  <TEXTBUTTON name="kickMute" id="6f9d4a20ba8d8c20" memberName="kickMuteButton"
              virtualName="" explicitFocusOrder="0" pos="24 431 39 19" bgColOff="ffcecece"
              bgColOn="ffffeb86" buttonText="M" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="snareMute" id="193f3fda240f899b" memberName="snareMuteButton"
              virtualName="" explicitFocusOrder="0" pos="72 431 39 19" bgColOff="ffcecece"
              bgColOn="ffffeb86" buttonText="M" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="hihatMute" id="ee96d9a38008708a" memberName="hihatMuteButton"
              virtualName="" explicitFocusOrder="0" pos="116 431 39 19" bgColOff="ffcecece"
              bgColOn="ffffeb86" buttonText="M" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="perc2Mute" id="6eb4bd4aade5d37e" memberName="perc2MuteButton"
              virtualName="" explicitFocusOrder="0" pos="212 431 39 19" bgColOff="ffcecece"
              bgColOn="ffffeb86" buttonText="M" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="tonesMute" id="4e7c7d3732b16ea3" memberName="tonesMuteButton"
              virtualName="" explicitFocusOrder="0" pos="260 431 39 19" bgColOff="ffcecece"
              bgColOn="ffffeb86" buttonText="M" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="perc1Mute" id="9e2bba0b682a48fd" memberName="perc1MuteButton"
              virtualName="" explicitFocusOrder="0" pos="164 431 39 19" bgColOff="ffcecece"
              bgColOn="ffffeb86" buttonText="M" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <JUCERCOMP name="" id="8ba4a7c2e5920bea" memberName="transport" virtualName=""
             explicitFocusOrder="0" pos="104 447 224 40" sourceFile="Transport.cpp"
             constructorParams="controller"/>
  <SLIDER name="Master" id="fd6791ae3c533bb4" memberName="masterSlider"
          virtualName="Slider" explicitFocusOrder="0" pos="5 264 16 99"
          thumbcol="ffffeb86" trackcol="7fffffff" rotarysliderfill="7f0000ff"
          rotaryslideroutline="66000000" min="0" max="1" int="0" style="LinearBar"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="7db995d0cc268da2" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="-2 247 30 16" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Master" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="7.9000000000000003553" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
