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

#include "Ui.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Ui::Ui (Controller* controller)
    : AudioProcessorEditor(controller),
      controller(controller)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    setName ("Ui");
    addAndMakeVisible (portrait = new Portrait (controller));

    //[UserPreSize]
    //[/UserPreSize]

    setSize (320, 480);


    //[Constructor] You can add your own custom stuff here..
    LookAndFeel::setDefaultLookAndFeel(&customLook);
    Rectangle<int> area = getParentMonitorArea();
    setSize (area.getWidth(), area.getHeight());

    startTimer(200);

    //[/Constructor]
}

Ui::~Ui()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    portrait = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Ui::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff202020));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void Ui::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    portrait->setBounds (0, 0, proportionOfWidth (1.0000f), proportionOfHeight (1.0000f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void Ui::timerCallback()
{
    int currentOrientation = Desktop::getInstance().getCurrentOrientation();

    if(currentOrientation != lastOrientation) {
        lastOrientation = currentOrientation;

        Rectangle<int> area = getParentMonitorArea();
        setSize (area.getWidth(), area.getHeight());
        getParentComponent()->setBounds(0, 0, area.getWidth(), area.getHeight());
    }
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Ui" componentName="Ui" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="Controller* controller" variableInitialisers="AudioProcessorEditor(controller),&#10;controller(controller)"
                 snapPixels="8" snapActive="1" snapShown="0" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="320" initialHeight="480">
  <BACKGROUND backgroundColour="ff202020"/>
  <JUCERCOMP name="" id="400f7bf5047db5bc" memberName="portrait" virtualName=""
             explicitFocusOrder="0" pos="0 0 100% 100%" sourceFile="Portrait.cpp"
             constructorParams="controller"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
