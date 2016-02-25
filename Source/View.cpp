/*
  ==============================================================================

    View.cpp
    Created: 24 Feb 2016 4:15:35pm
    Author:  Karl

  ==============================================================================
*/

#include "View.h"

//==============================================================================


View::View(SilverbirdAudioProcessor* controller) : AudioProcessorEditor (controller), controller(controller)
{
    customLook.setDefaultSansSerifTypefaceName("Arial");
    LookAndFeel::setDefaultLookAndFeel(&customLook);
}

View::~View()
{
}

void View::setTrackFocus(int trackId)
{
    if (trackTabs != nullptr) {
        trackTabs->setCurrentTabIndex(trackId);
    }
}