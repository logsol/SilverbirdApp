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

#include "TargetStepper.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TargetStepper::TargetStepper (Controller* controller, int trackId, bool isModulationTrack )
    : BaseComponent(controller)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (component = new BipolarStepper (controller, trackId, isModulationTrack));
    addAndMakeVisible (target1 = new SbButton ("new button"));
    target1->setButtonText (TRANS("label"));
    target1->setConnectedEdges (Button::ConnectedOnRight);
    target1->addListener (this);

    addAndMakeVisible (target2 = new SbButton ("new button"));
    target2->setButtonText (TRANS("label"));
    target2->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    target2->addListener (this);

    addAndMakeVisible (target3 = new SbButton ("new button"));
    target3->setButtonText (TRANS("label"));
    target3->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    target3->addListener (this);

    addAndMakeVisible (target4 = new SbButton ("new button"));
    target4->setButtonText (TRANS("label"));
    target4->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    target4->addListener (this);

    addAndMakeVisible (target5 = new SbButton ("new button"));
    target5->setButtonText (TRANS("label"));
    target5->setConnectedEdges (Button::ConnectedOnLeft | Button::ConnectedOnRight);
    target5->addListener (this);

    addAndMakeVisible (target6 = new SbButton ("new button"));
    target6->setButtonText (TRANS("label"));
    target6->setConnectedEdges (Button::ConnectedOnLeft);
    target6->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (400, 100);


    //[Constructor] You can add your own custom stuff here..

    buttons.add(target1);
    buttons.add(target2);
    buttons.add(target3);
    buttons.add(target4);
    buttons.add(target5);
    buttons.add(target6);
    
    jassert(buttons.size() == Mixer::tracks::max);

    for (int i=0; i<Mixer::tracks::max; i++) {
        buttons[i]->setClickingTogglesState(true);
        buttons[i]->setButtonText(Mixer::getNameByTrackId(i));
    }

    sequencer = isModulationTrack
    ? controller->getModulationSequencerByTrackId(trackId)
    : controller->getMidiSequencerByTrackId(trackId);

    //[/Constructor]
}

TargetStepper::~TargetStepper()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    buttons.clear();
    //[/Destructor_pre]

    component = nullptr;
    target1 = nullptr;
    target2 = nullptr;
    target3 = nullptr;
    target4 = nullptr;
    target5 = nullptr;
    target6 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void TargetStepper::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TargetStepper::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    component->setBounds (0, 0, proportionOfWidth (1.0000f), proportionOfHeight (0.6000f));
    target1->setBounds (proportionOfWidth (0.0650f), 60, proportionOfWidth (0.1500f), proportionOfHeight (0.2200f));
    target2->setBounds (proportionOfWidth (0.2100f), 60 + 0, proportionOfWidth (0.1500f), proportionOfHeight (0.2200f));
    target3->setBounds (proportionOfWidth (0.3550f), 60 + 0, proportionOfWidth (0.1500f), proportionOfHeight (0.2200f));
    target4->setBounds (proportionOfWidth (0.5000f), 60 + 0, proportionOfWidth (0.1500f), proportionOfHeight (0.2200f));
    target5->setBounds (proportionOfWidth (0.6450f), 60 + 0, proportionOfWidth (0.1500f), proportionOfHeight (0.2200f));
    target6->setBounds (proportionOfWidth (0.7900f), 60 + 0, proportionOfWidth (0.1500f), proportionOfHeight (0.2200f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void TargetStepper::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    ModulationSequencer* modSequencer = dynamic_cast<ModulationSequencer*>(sequencer);
    
    if (modSequencer == nullptr) {
        std::cout << "Could not cast modSequencer" << std::endl;
        return;
    }
    
    for (int i=0; i<Mixer::tracks::max; i++) {
        modSequencer->setModulationTargetEnabled(i, buttons[i]->getToggleState());
    }

    
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == target1)
    {
        //[UserButtonCode_target1] -- add your button handler code here..
        
        // @see beginning of this method
        
        //[/UserButtonCode_target1]
    }
    else if (buttonThatWasClicked == target2)
    {
        //[UserButtonCode_target2] -- add your button handler code here..
        //[/UserButtonCode_target2]
    }
    else if (buttonThatWasClicked == target3)
    {
        //[UserButtonCode_target3] -- add your button handler code here..
        //[/UserButtonCode_target3]
    }
    else if (buttonThatWasClicked == target4)
    {
        //[UserButtonCode_target4] -- add your button handler code here..
        //[/UserButtonCode_target4]
    }
    else if (buttonThatWasClicked == target5)
    {
        //[UserButtonCode_target5] -- add your button handler code here..
        //[/UserButtonCode_target5]
    }
    else if (buttonThatWasClicked == target6)
    {
        //[UserButtonCode_target6] -- add your button handler code here..
        //[/UserButtonCode_target6]
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

<JUCER_COMPONENT documentType="Component" className="TargetStepper" componentName=""
                 parentClasses="public BaseComponent" constructorParams="Controller* controller, int trackId, bool isModulationTrack "
                 variableInitialisers="BaseComponent(controller)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="400" initialHeight="100">
  <BACKGROUND backgroundColour="ffffff"/>
  <JUCERCOMP name="" id="15249f1dc21a48d1" memberName="component" virtualName=""
             explicitFocusOrder="0" pos="0 0 100% 60%" sourceFile="BipolarStepper.cpp"
             constructorParams="controller, trackId, isModulationTrack"/>
  <TEXTBUTTON name="new button" id="5a08c1874ed5e265" memberName="target1"
              virtualName="SbButton" explicitFocusOrder="0" pos="6.5% 60 15% 22%"
              buttonText="label" connectedEdges="2" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="94b31ccaf44bc2aa" memberName="target2"
              virtualName="SbButton" explicitFocusOrder="0" pos="21% 0 15% 22%"
              posRelativeY="5a08c1874ed5e265" buttonText="label" connectedEdges="3"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="45b2e4ea8069edbb" memberName="target3"
              virtualName="SbButton" explicitFocusOrder="0" pos="35.5% 0 15% 22%"
              posRelativeY="5a08c1874ed5e265" buttonText="label" connectedEdges="3"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="770148221ece5a24" memberName="target4"
              virtualName="SbButton" explicitFocusOrder="0" pos="50% 0 15% 22%"
              posRelativeY="5a08c1874ed5e265" buttonText="label" connectedEdges="3"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="cf8ad7693fd3f376" memberName="target5"
              virtualName="SbButton" explicitFocusOrder="0" pos="64.5% 0 15% 22%"
              posRelativeY="5a08c1874ed5e265" buttonText="label" connectedEdges="3"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="71c93bd00f569780" memberName="target6"
              virtualName="SbButton" explicitFocusOrder="0" pos="79% 0 15% 22%"
              posRelativeY="5a08c1874ed5e265" buttonText="label" connectedEdges="1"
              needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
