/*
  ==============================================================================

    Sound.cpp
    Created: 7 Feb 2014 12:56:34am
    Author:  Pannek Karl

  ==============================================================================
*/

#include "Sound.h"

Sound::Sound (const String& soundName,
                                        const int midiNoteForNormalPitch,
                                        const int soundSelection,
                                        AudioFormatReader& source,
                                        float attackTimeSecs,
                                        float releaseTimeSecs)
: juce::SamplerSound(soundName,
                     source,
                     127,
                     midiNoteForNormalPitch,
                     0, //attackTimeSecs,
                     0, //releaseTimeSecs,
                     10),
name (soundName),
midiRootNote (midiNoteForNormalPitch),
selection (soundSelection)
{
}

Sound::~Sound()
{
}

bool Sound::appliesToNote (const int midiNoteNumber)
{
    return midiNoteNumber == midiRootNote;
}

bool Sound::appliesToSelection (int askedSelection)
{
    return askedSelection == selection;
}
