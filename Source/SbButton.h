/*
  ==============================================================================

    Button.h
    Created: 26 Feb 2016 4:14:05pm
    Author:  Karl

  ==============================================================================
*/

#ifndef SBBUTTON_H_INCLUDED
#define SBBUTTON_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class SbButton    : public TextButton
{
public:
    SbButton (const String &name);
    ~SbButton();

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SbButton)
};


#endif  // SBBUTTON_H_INCLUDED
