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
    addAndMakeVisible (transport = new Transport (controller));
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

    addAndMakeVisible (sequencerTabs = new TabbedComponent (TabbedButtonBar::TabsAtLeft));
    sequencerTabs->setTabBarDepth (25);
    sequencerTabs->addTab (TRANS("Drums"), Colour (0xf1383838), new Drums (controller), true);
    sequencerTabs->addTab (TRANS("Mods"), Colour (0xf1383838), new Mods (controller), true);
    sequencerTabs->setCurrentTabIndex (0);

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
    /*
    shuffleSlider->addListener(controller);
    shuffleSlider->getValueObject().referTo(*p);
    shuffleSlider->setDoubleClickReturnValue(true, p->getDefaultValue());
*/
    p = controller->getParameterByAttrs(Controller::params::level);
    masterSlider->addListener(controller);
    masterSlider->getValueObject().referTo(*p);
    masterSlider->setDoubleClickReturnValue(true, p->getDefaultValue());
    masterSlider->setSliderStyle(Slider::LinearBarVertical);

/*
    Slider* volumeSliders [Mixer::tracks::max] = {
        kickVolumeSlider,
        snareVolumeSlider,
        hihatVolumeSlider,
        perc1VolumeSlider,
        perc2VolumeSlider,
        tonesVolumeSlider
    };
 */
/*
    Button* muteButtons [Mixer::tracks::max] = {
        kickMuteButton,
        snareMuteButton,
        hihatMuteButton,
        perc1MuteButton,
        perc2MuteButton,
        tonesMuteButton
    };
 */

    for (int i = 0; i < Mixer::tracks::max; i++) {
        p = controller->getParameterByAttrs(Controller::params::level, i);
        /*
        volumeSliders[i]->addListener(controller);
        volumeSliders[i]->getValueObject().referTo(*p);
        volumeSliders[i]->setDoubleClickReturnValue(true, p->getDefaultValue());
        volumeSliders[i]->setSliderStyle(Slider::LinearBarVertical);


        p = controller->getParameterByAttrs(Controller::params::mute, i);
        muteButtons[i]->addListener(controller);
        muteButtons[i]->getToggleStateValue().referTo(*p);
        muteButtons[i]->setClickingTogglesState(true);
         */
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

    transport = nullptr;
    trackTabs = nullptr;
    sequencerTabs = nullptr;
    masterSlider = nullptr;
    label = nullptr;
    save = nullptr;
    load = nullptr;
    redo = nullptr;
    undo = nullptr;


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

    transport->setBounds (-5, 445, 328, 40);
    trackTabs->setBounds (proportionOfWidth (0.0188f), 33, proportionOfWidth (0.9594f), 92);
    sequencerTabs->setBounds (0, 127, proportionOfWidth (0.9750f), 236);
    masterSlider->setBounds (5, 264, 16, 99);
    label->setBounds (-2, 247, 30, 16);
    save->setBounds (102, 385, 54, 24);
    load->setBounds (38, 385, 54, 24);
    redo->setBounds (230, 385, 54, 24);
    undo->setBounds (166, 385, 54, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Gui2::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == masterSlider)
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

    if (buttonThatWasClicked == save)
    {
        //[UserButtonCode_save] -- add your button handler code here..
        controller->saveDocument();
        //[/UserButtonCode_save]
    }
    else if (buttonThatWasClicked == load)
    {
        //[UserButtonCode_load] -- add your button handler code here..
        controller->loadDocument();
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
void Gui2::setTrackFocus(int trackId)
{
    trackTabs->setCurrentTabIndex(trackId);
}
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
  <JUCERCOMP name="" id="8ba4a7c2e5920bea" memberName="transport" virtualName=""
             explicitFocusOrder="0" pos="-5 445 328 40" sourceFile="Transport.cpp"
             constructorParams="controller"/>
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
  <TABBEDCOMPONENT name="seqtabs" id="24d28c4cbe1b57cb" memberName="sequencerTabs"
                   virtualName="" explicitFocusOrder="0" pos="0 127 97.5% 236" orientation="left"
                   tabBarDepth="25" initialTab="0">
    <TAB name="Drums" colour="f1383838" useJucerComp="1" contentClassName=""
         constructorParams="controller" jucerComponentFile="Drums.cpp"/>
    <TAB name="Mods" colour="f1383838" useJucerComp="1" contentClassName=""
         constructorParams="controller" jucerComponentFile="Mods.cpp"/>
  </TABBEDCOMPONENT>
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
  <TEXTBUTTON name="save" id="ae6f6f001f0e0f94" memberName="save" virtualName=""
              explicitFocusOrder="0" pos="102 385 54 24" buttonText="Save"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="load" id="d073f4931f861d5b" memberName="load" virtualName=""
              explicitFocusOrder="0" pos="38 385 54 24" buttonText="Load" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="redo" id="550f5d2f473463e8" memberName="redo" virtualName=""
              explicitFocusOrder="0" pos="230 385 54 24" buttonText="Redo"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="undo" id="734eb6d517ff5b27" memberName="undo" virtualName=""
              explicitFocusOrder="0" pos="166 385 54 24" buttonText="Undo"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
