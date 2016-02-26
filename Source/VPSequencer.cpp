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
#include "BaseComponent.h"
//[/Headers]

#include "VPSequencer.h"
#include "Drums.h"
#include "Mods.h"
#include "TrackParameters.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
VPSequencer::VPSequencer (Controller* controller)
    : BaseComponent (controller)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (sequencerTabs = new TabbedComponent (TabbedButtonBar::TabsAtBottom));
    sequencerTabs->setTabBarDepth (25);
    sequencerTabs->addTab (TRANS("Drums"), Colour (0xf1383838), new Drums (controller), true);
    sequencerTabs->addTab (TRANS("Modulate"), Colour (0xf1383838), new Mods (controller), true);
    sequencerTabs->setCurrentTabIndex (0);

    addAndMakeVisible (trackTabs = new TabbedComponent (TabbedButtonBar::TabsAtTop));
    trackTabs->setTabBarDepth (26);
    trackTabs->addTab (TRANS("Kick"), Colour (0xf1383838), new TrackParameters (controller, 0), true);
    trackTabs->addTab (TRANS("Snare"), Colour (0xf1383838), new TrackParameters (controller, 1), true);
    trackTabs->addTab (TRANS("Hihat"), Colour (0xf1383838), new TrackParameters (controller, 2), true);
    trackTabs->addTab (TRANS("Perc1"), Colour (0xf1383838), new TrackParameters (controller, 3), true);
    trackTabs->addTab (TRANS("Perc2"), Colour (0xf1383838), new TrackParameters (controller, 4), true);
    trackTabs->addTab (TRANS("Tones"), Colour (0xf1383838), new TrackParameters (controller, 5), true);
    trackTabs->addTab (TRANS("All"), Colour (0xff454545), new TrackParameters (controller, -1), true);
    trackTabs->setCurrentTabIndex (0);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (320, 420);


    //[Constructor] You can add your own custom stuff here..
//    setSize (320, 480);

    //[/Constructor]
}

VPSequencer::~VPSequencer()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    sequencerTabs = nullptr;
    trackTabs = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void VPSequencer::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void VPSequencer::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    sequencerTabs->setBounds (0, proportionOfHeight (1.0000f) - proportionOfHeight (0.7786f), getWidth() - 0, proportionOfHeight (0.7786f));
    trackTabs->setBounds (0, 0, getWidth() - 0, proportionOfHeight (0.2214f));
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

<JUCER_COMPONENT documentType="Component" className="VPSequencer" componentName=""
                 parentClasses="public BaseComponent" constructorParams="Controller* controller"
                 variableInitialisers="BaseComponent (controller)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="1"
                 initialWidth="320" initialHeight="420">
  <BACKGROUND backgroundColour="262626"/>
  <TABBEDCOMPONENT name="seqtabs" id="24d28c4cbe1b57cb" memberName="sequencerTabs"
                   virtualName="" explicitFocusOrder="0" pos="0 100%r 0M 77.857%"
                   orientation="bottom" tabBarDepth="25" initialTab="0">
    <TAB name="Drums" colour="f1383838" useJucerComp="1" contentClassName=""
         constructorParams="controller" jucerComponentFile="Drums.cpp"/>
    <TAB name="Modulate" colour="f1383838" useJucerComp="1" contentClassName=""
         constructorParams="controller" jucerComponentFile="Mods.cpp"/>
  </TABBEDCOMPONENT>
  <TABBEDCOMPONENT name="new tabbed component" id="299c842daf4e2362" memberName="trackTabs"
                   virtualName="" explicitFocusOrder="0" pos="0 0 0M 22.143%" orientation="top"
                   tabBarDepth="26" initialTab="0">
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
    <TAB name="All" colour="ff454545" useJucerComp="1" contentClassName=""
         constructorParams="controller, -1" jucerComponentFile="TrackParameters.cpp"/>
  </TABBEDCOMPONENT>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
