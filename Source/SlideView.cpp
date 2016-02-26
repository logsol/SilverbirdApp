/*
  ==============================================================================

    SlideView.cpp
    Created: 26 Feb 2016 2:48:38pm
    Author:  Karl

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "SlideView.h"

//==============================================================================
SlideView::SlideView(Controller* controller) : BaseComponent(controller)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
}

SlideView::~SlideView()
{
}

void SlideView::slideTo(int i)
{
    jassert(isPositiveAndBelow(i, slides.size()));
    
    if(i == current) {
        return;
    }
    
    Component* toHide = slides[current];
    Component* toShow = slides[i];
    
    if(toHide == nullptr || toShow == nullptr){
        std::cout << "component is null" << std::endl;
        return;
    }
    
    float direction = i < current ? 1.0 : -1.0;
    
    float originalX = toHide->getX();
    Rectangle<int> toHideBounds = toHide->getBounds();
    toHideBounds.setPosition(direction * getWidth(), toHide->getY());
    animator.animateComponent(toHide, toHideBounds, 1.0, animationTimeMs, false, 1.0, 0.0);
    

    //hard reset
    toShow->setBounds(-direction * getWidth(), toHide->getY(), toHideBounds.getWidth(), toHideBounds.getHeight());
    
    // animate
    Rectangle<int> toShowBounds = toShow->getBounds();
    toShowBounds.setPosition(originalX, toHideBounds.getY());
    animator.animateComponent(toShow, toShowBounds, 1.0, animationTimeMs, false, 1.0, 0.0);
    
    current = i;
    
    if(animationTimeMs == 0) {
        toShow->setVisible(true);
        toHide->setVisible(false);
    }
}
