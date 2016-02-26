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

#include "Portrait.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Portrait::Portrait (Controller* controller)
    : SlideView(controller)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (transport = new VPNavigate (controller));
    addAndMakeVisible (vpSequencer = new VPSequencer (controller));

    //[UserPreSize]
    //[/UserPreSize]

    setSize (320, 480);


    //[Constructor] You can add your own custom stuff here..
    vpSetup = new VPSetup (controller);
    vpMixer = new VPMixer(controller);

    vpSetup->setBounds(vpSequencer->getBounds());
    vpMixer->setBounds(vpSequencer->getBounds());

    // slide order
    slides.add(vpSetup);
    slides.add(vpSequencer);
    slides.add(vpMixer);

    current = slides.indexOf(vpSequencer);

    if(animationTimeMs == 0) {
        vpSetup->setVisible(false);
        vpMixer->setVisible(false);
    }
    addChildComponent(vpSetup);
    addChildComponent(vpMixer);
    //[/Constructor]
}

Portrait::~Portrait()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    transport = nullptr;
    vpSequencer = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Portrait::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void Portrait::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    transport->setBounds (5, getHeight() - 5 - proportionOfHeight (0.0789f), getWidth() - 10, proportionOfHeight (0.0789f));
    vpSequencer->setBounds (5, 20, getWidth() - 10, proportionOfHeight (0.8469f));
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

<JUCER_COMPONENT documentType="Component" className="Portrait" componentName=""
                 parentClasses="public SlideView" constructorParams="Controller* controller"
                 variableInitialisers="SlideView(controller)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="320"
                 initialHeight="480">
  <BACKGROUND backgroundColour="0"/>
  <JUCERCOMP name="" id="8ba4a7c2e5920bea" memberName="transport" virtualName=""
             explicitFocusOrder="0" pos="5 5Rr 10M 7.917%" sourceFile="VPNavigate.cpp"
             constructorParams="controller"/>
  <JUCERCOMP name="" id="63321eff4af9bbe1" memberName="vpSequencer" virtualName=""
             explicitFocusOrder="0" pos="5 20 10M 84.792%" sourceFile="VPSequencer.cpp"
             constructorParams="controller"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
