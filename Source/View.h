/*
  ==============================================================================

    View.h
    Created: 24 Feb 2016 4:15:35pm
    Author:  Karl

  ==============================================================================
*/

#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED

#include "JuceHeader.h"
#include "Processor.h"
#include "CustomLook.h"
class Controller;


//==============================================================================
/*
*/
class View  : public AudioProcessorEditor
{
public:
    View(SilverbirdAudioProcessor* controller);
    ~View();
    
    void setTrackFocus(int trackId);

protected:

    SilverbirdAudioProcessor* controller;
    ScopedPointer<TabbedComponent> trackTabs;
    
    CustomLook customLook;
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (View)
};


#endif  // VIEW_H_INCLUDED
