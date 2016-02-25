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
#include "Controller.h"
//[/Headers]

#include "SizeTest.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
SizeTest::SizeTest ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (component = new Portrait (new Controller()));
    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("iPhone 4")));
    label->setFont (Font (15.00f, Font::plain));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (component2 = new Portrait (new Controller()));
    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("iPhone 5")));
    label2->setFont (Font (15.00f, Font::plain));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (component3 = new Portrait (new Controller()));
    addAndMakeVisible (label3 = new Label ("new label",
                                           TRANS("iPhone 5")));
    label3->setFont (Font (15.00f, Font::plain));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (2000, 900);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

SizeTest::~SizeTest()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    component = nullptr;
    label = nullptr;
    component2 = nullptr;
    label2 = nullptr;
    component3 = nullptr;
    label3 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SizeTest::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff747474));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void SizeTest::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    component->setBounds (8, 40, 320, 480);
    label->setBounds (104, 8, 150, 24);
    component2->setBounds (336, 40, 320, 568);
    label2->setBounds (416, 8, 150, 24);
    component3->setBounds (664, 40, 375, 667);
    label3->setBounds (744, 8, 150, 24);
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

<JUCER_COMPONENT documentType="Component" className="SizeTest" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="0" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="2000" initialHeight="900">
  <BACKGROUND backgroundColour="ff747474"/>
  <JUCERCOMP name="" id="3b67dad788548edb" memberName="component" virtualName=""
             explicitFocusOrder="0" pos="8 40 320 480" sourceFile="Portrait.cpp"
             constructorParams="new Controller()"/>
  <LABEL name="new label" id="e06d7ccde3a34ade" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="104 8 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="iPhone 4" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <JUCERCOMP name="" id="5844317463a6bacd" memberName="component2" virtualName=""
             explicitFocusOrder="0" pos="336 40 320 568" sourceFile="Portrait.cpp"
             constructorParams="new Controller()"/>
  <LABEL name="new label" id="f90a4ecd280b9633" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="416 8 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="iPhone 5" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <JUCERCOMP name="" id="c528a953a56111e1" memberName="component3" virtualName=""
             explicitFocusOrder="0" pos="664 40 375 667" sourceFile="Portrait.cpp"
             constructorParams="new Controller()"/>
  <LABEL name="new label" id="cab9a8c4e5b409c9" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="744 8 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="iPhone 5" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
