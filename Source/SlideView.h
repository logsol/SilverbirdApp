/*
  ==============================================================================

    SlideView.h
    Created: 26 Feb 2016 2:48:38pm
    Author:  Karl

  ==============================================================================
*/

#ifndef SLIDEVIEW_H_INCLUDED
#define SLIDEVIEW_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "BaseComponent.h"

//==============================================================================
/*
*/
class SlideView    : public BaseComponent
{
public:
    SlideView(Controller* controller);
    ~SlideView();

    void slideTo(int i);
    
protected:
    int animationTimeMs = 0;
    Array<Component*> slides;
    int current;

private:
    ComponentAnimator animator;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SlideView)
};


#endif  // SLIDEVIEW_H_INCLUDED
