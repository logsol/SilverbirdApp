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

#include "Stepper.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Stepper::Stepper (Controller* controller, int trackId, bool isModulationTrack)
    : controller(controller),
      trackId(trackId),
      isModulationTrack(isModulationTrack)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (stepperLabel = new Label ("stepper",
                                                 TRANS("Snare")));
    stepperLabel->setFont (Font ("Charcoal CY", 15.50f, Font::plain));
    stepperLabel->setJustificationType (Justification::centredLeft);
    stepperLabel->setEditable (false, false, false);
    stepperLabel->setColour (Label::textColourId, Colour (0xff7e7e7e));
    stepperLabel->setColour (TextEditor::textColourId, Colours::black);
    stepperLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (400, 60);


    //[Constructor] You can add your own custom stuff here..

    controller->addClockListener(this);

    stepperLabel->setText(controller->mixer.getNameByTrackId(trackId, isModulationTrack), dontSendNotification);
    stepperLabel->setInterceptsMouseClicks(false, false);

    //[/Constructor]
}

Stepper::~Stepper()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    stepperLabel = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    controller->removeClockListener(this);
    //[/Destructor]
}

//==============================================================================
void Stepper::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xe5000000));

    //[UserPaint] Add your own custom painting code here..

    int numCells = controller->sequencer.getNumCells();

    Array<float> cells = isModulationTrack
        ? controller->sequencer.getModulationCells(trackId)
        : controller->sequencer.getCells(trackId);

    float cellWidth = (float) getWidth() / (float) numCells;

    for (int i=0; i<numCells; i++) {


        float base = isBipolar()
            ? getHeight() * 0.5
            : getHeight() - cells.getUnchecked(i) * getHeight();

        float value = isBipolar()
            ? -cells.getUnchecked(i) * getHeight() + getHeight() * 0.5
            : cells.getUnchecked(i) * getHeight();

        // default value color
        g.setColour (Colour (0xffffeb86));

        if (cursor == i) {
            // active background colour
            g.setColour (Colour (0xe5333333));

            // painting Active BACKGROUND
            g.fillRect(
                       (float) i * cellWidth,
                       (float) 0,
                       (float) cellWidth,
                       (float) getHeight()
                       );

            // active value colour
            g.setColour (Colour (0xffbfab46));
        }

        // Windows patch (wont draw negative values)
        if (value < 0){
            float oldBase = base;
            base = oldBase + value;
            value = std::abs(value);
        }

        // painting Active VALUE
        g.fillRect(
           (float) i * cellWidth,
           (float) base,
           (float) cellWidth,
           (float) value
        );

        if(i==0) continue;

        g.setColour (Colour (0x55666666));
        if(i%4==0) g.setColour (Colour (0xbb888888));

        g.drawLine(i * cellWidth, 0, i * cellWidth, getHeight());
    }

    g.setColour (Colour (0xff777777));
    g.drawRect(0, 0, getWidth(), getHeight());

    if(isBipolar()) {
        g.setColour (Colour (0xdd666666));
        g.drawLine(0, getHeight() * 0.5, getWidth(), getHeight() * 0.5);
    }

    //[/UserPaint]
}

void Stepper::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    stepperLabel->setBounds (-2, 2, 120, 13);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Stepper::mouseDown (const MouseEvent& e)
{
    //[UserCode_mouseDown] -- Add your code here...





    int numCells = controller->sequencer.getNumCells();

    float cellWidth = getWidth() / numCells;
    int cellId = fmax(0, fmin(numCells, floor(e.getPosition().getX() / cellWidth)));

    float value = fmin(1, fmax(0, ((float) getHeight() - (float) e.getPosition().getY()) / (float) getHeight()));

    updateSequencer(cellId, value);

    repaint();



    //[/UserCode_mouseDown]
}

void Stepper::mouseDrag (const MouseEvent& e)
{
    //[UserCode_mouseDrag] -- Add your code here...
    mouseDown(e);
    //[/UserCode_mouseDrag]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void Stepper::clockStep(int cursor)
{
    this->cursor = cursor;

    const MessageManagerLock l;

    repaint();
}

void Stepper::setComponentID (const String& newID)
{
    /*
    Component::setComponentID(newID);
    stepperLabel->setText(newID, dontSendNotification);
     */
}

bool Stepper::isBipolar()
{
    return false;
}

void Stepper::updateSequencer(int cellId, float value)
{
    if (isModulationTrack) {
        controller->sequencer.setModulationCell(trackId, cellId, value);
    } else {
        controller->sequencer.setCell(trackId, cellId, value);
    }
}

// FIXME: it might be better to use some sort of ValueListener here similar to ButtonListener as its a component change
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Stepper" componentName=""
                 parentClasses="public Component, public ClockListener" constructorParams="Controller* controller, int trackId, bool isModulationTrack"
                 variableInitialisers="controller(controller),&#10;trackId(trackId),&#10;isModulationTrack(isModulationTrack)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="400" initialHeight="60">
  <METHODS>
    <METHOD name="mouseDrag (const MouseEvent&amp; e)"/>
    <METHOD name="mouseDown (const MouseEvent&amp; e)"/>
  </METHODS>
  <BACKGROUND backgroundColour="e5000000"/>
  <LABEL name="stepper" id="d5d914557b2ab44f" memberName="stepperLabel"
         virtualName="" explicitFocusOrder="0" pos="-2 2 120 13" textCol="ff7e7e7e"
         edTextCol="ff000000" edBkgCol="0" labelText="Snare" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Charcoal CY"
         fontsize="15.5" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
