/*
  ==============================================================================

    Button.cpp
    Created: 26 Feb 2016 4:14:05pm
    Author:  Karl

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "SbButton.h"

//==============================================================================
SbButton::SbButton(const String &name) : TextButton(name)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

    setColour(ColourIds::buttonOnColourId, Colour(0xff, 0xeb, 0x86));

}

SbButton::~SbButton()
{
}
