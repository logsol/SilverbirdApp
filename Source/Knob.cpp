/*
  ==============================================================================

    Knob.cpp
    Created: 4 Feb 2014 2:40:35am
    Author:  Pannek Karl

  ==============================================================================
*/

#include "Knob.h"

Knob::Knob(const String &name, const int &_singleImageWidth, const int &_singleImageHeight)
: Slider(name)
, singleImageWidth(_singleImageWidth)
, singleImageHeight(_singleImageHeight)
{
    setSliderStyle (Slider::RotaryVerticalDrag);
    setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
    setSize(singleImageWidth, singleImageHeight);
    setRange (0.0, 100.0, 0.1);
    setScrollWheelEnabled(false);
    setPopupMenuEnabled (false);
}

Knob::~Knob()
{
    deleteAllChildren();
}

//==============================================================================
void Knob::paint(Graphics& g)
{
    Image knobImage = ImageCache::getFromMemory (BinaryData::Knob_png, BinaryData::Knob_pngSize);
    
    
        double range = getMaximum() - getMinimum();
        int numImagePics = knobImage.getWidth() / singleImageWidth;
        int imageOffset = singleImageWidth * (int)((numImagePics-1) * getValue()/range);
    
    
        g.drawImage(knobImage,
                    0, 0, singleImageWidth, singleImageHeight,
                    imageOffset, 0, singleImageWidth, singleImageHeight,
                    false);
    
}

//==============================================================================
