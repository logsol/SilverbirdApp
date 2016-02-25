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
#include "Drums.h"
#include "Mods.h"
#include "TrackParameters.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Portrait::Portrait (Controller* controller)
    : View (controller)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (sequencerTabs = new TabbedComponent (TabbedButtonBar::TabsAtBottom));
    sequencerTabs->setTabBarDepth (25);
    sequencerTabs->addTab (TRANS("Drums"), Colour (0xf1383838), new Drums (controller), true);
    sequencerTabs->addTab (TRANS("Mods"), Colour (0xf1383838), new Mods (controller), true);
    sequencerTabs->setCurrentTabIndex (0);

    addAndMakeVisible (component2 = new HistoryComponent());
    addAndMakeVisible (trackTabs = new TabbedComponent (TabbedButtonBar::TabsAtTop));
    trackTabs->setTabBarDepth (26);
    trackTabs->addTab (TRANS("Kick"), Colour (0xf1383838), new TrackParameters (controller, 0), true);
    trackTabs->addTab (TRANS("Snare"), Colour (0xf1383838), new TrackParameters (controller, 1), true);
    trackTabs->addTab (TRANS("Hihat"), Colour (0xf1383838), new TrackParameters (controller, 2), true);
    trackTabs->addTab (TRANS("Perc1"), Colour (0xf1383838), new TrackParameters (controller, 3), true);
    trackTabs->addTab (TRANS("Perc2"), Colour (0xf1383838), new TrackParameters (controller, 4), true);
    trackTabs->addTab (TRANS("Tones"), Colour (0xf1383838), new TrackParameters (controller, 5), true);
    trackTabs->addTab (TRANS("Global"), Colour (0xff454545), new TrackParameters (controller, -1), true);
    trackTabs->setCurrentTabIndex (0);

    addAndMakeVisible (component = new MixerComponent (controller));
    addAndMakeVisible (transport = new Transport (controller));

    //[UserPreSize]
    //[/UserPreSize]

    setSize (320, 480);


    //[Constructor] You can add your own custom stuff here..
//    setSize (320, 480);
    Rectangle<int> area = getParentMonitorArea();
    setSize (area.getWidth(), area.getHeight());
    //[/Constructor]
}

Portrait::~Portrait()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    sequencerTabs = nullptr;
    component2 = nullptr;
    trackTabs = nullptr;
    component = nullptr;
    transport = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Portrait::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff262626));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void Portrait::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    sequencerTabs->setBounds (5, proportionOfHeight (0.2063f), getWidth() - 10, proportionOfHeight (0.5146f));
    component2->setBounds (5 + roundFloatToInt ((getWidth() - 10) * 0.4516f), proportionOfHeight (0.7229f) - 26, proportionOfWidth (0.5594f), 26);
    trackTabs->setBounds (5, 20, getWidth() - 10, proportionOfHeight (0.1604f));
    component->setBounds (5, proportionOfHeight (0.7229f), getWidth() - 10, proportionOfHeight (0.1854f));
    transport->setBounds (5, getHeight() - 5 - proportionOfHeight (0.0729f), proportionOfWidth (0.9750f), proportionOfHeight (0.0729f));
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
                 parentClasses="public View" constructorParams="Controller* controller"
                 variableInitialisers="View (controller)" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="320"
                 initialHeight="480">
  <BACKGROUND backgroundColour="ff262626"/>
  <TABBEDCOMPONENT name="seqtabs" id="24d28c4cbe1b57cb" memberName="sequencerTabs"
                   virtualName="" explicitFocusOrder="0" pos="5 20.625% 10M 51.458%"
                   orientation="bottom" tabBarDepth="25" initialTab="0">
    <TAB name="Drums" colour="f1383838" useJucerComp="1" contentClassName=""
         constructorParams="controller" jucerComponentFile="Drums.cpp"/>
    <TAB name="Mods" colour="f1383838" useJucerComp="1" contentClassName=""
         constructorParams="controller" jucerComponentFile="Mods.cpp"/>
  </TABBEDCOMPONENT>
  <JUCERCOMP name="" id="b82ece55084724b2" memberName="component2" virtualName=""
             explicitFocusOrder="0" pos="45.161% 72.292%r 55.937% 26" posRelativeX="309379987650ac71"
             sourceFile="HistoryComponent.cpp" constructorParams=""/>
  <TABBEDCOMPONENT name="new tabbed component" id="299c842daf4e2362" memberName="trackTabs"
                   virtualName="" explicitFocusOrder="0" pos="5 20 10M 16.042%"
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
    <TAB name="Global" colour="ff454545" useJucerComp="1" contentClassName=""
         constructorParams="controller, -1" jucerComponentFile="TrackParameters.cpp"/>
  </TABBEDCOMPONENT>
  <JUCERCOMP name="" id="309379987650ac71" memberName="component" virtualName=""
             explicitFocusOrder="0" pos="5 72.292% 10M 18.542%" sourceFile="MixerComponent.cpp"
             constructorParams="controller"/>
  <JUCERCOMP name="" id="8ba4a7c2e5920bea" memberName="transport" virtualName=""
             explicitFocusOrder="0" pos="5 5Rr 97.5% 7.292%" sourceFile="Transport.cpp"
             constructorParams="controller"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
