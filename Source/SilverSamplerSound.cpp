/*
  ==============================================================================

    SilverSamplerSound.cpp
    Created: 7 Feb 2014 12:56:34am
    Author:  Pannek Karl

  ==============================================================================
*/

#include "SilverSamplerSound.h"


/*
 ==============================================================================
 
 This file is part of the JUCE library.
 Copyright (c) 2013 - Raw Material Software Ltd.
 
 Permission is granted to use this software under the terms of either:
 a) the GPL v2 (or any later version)
 b) the Affero GPL v3
 
 Details of these licenses can be found at: www.gnu.org/licenses
 
 JUCE is distributed in the hope that it will be useful, but WITHOUT ANY
 WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
 
 ------------------------------------------------------------------------------
 
 To release a closed-source product which uses JUCE, commercial licenses are
 available: visit www.juce.com for more information.
 
 ==============================================================================
 */

SilverSamplerSound::SilverSamplerSound (const String& soundName,
                                        AudioFormatReader& source,
                                        const BigInteger& notes,
                                        const int midiNoteForNormalPitch,
                                        const double attackTimeSecs,
                                        const double releaseTimeSecs,
                                        const double maxSampleLengthSeconds)
: name (soundName),
midiNotes (notes),
midiRootNote (midiNoteForNormalPitch)
{
    sourceSampleRate = source.sampleRate;
    
    if (sourceSampleRate <= 0 || source.lengthInSamples <= 0)
    {
        length = 0;
        attackSamples = 0;
        releaseSamples = 0;
    }
    else
    {
        length = jmin ((int) source.lengthInSamples,
                       (int) (maxSampleLengthSeconds * sourceSampleRate));
        
        data = new AudioSampleBuffer (jmin (2, (int) source.numChannels), length + 4);
        
        source.read (data, 0, length + 4, 0, true, true);
        
        attackSamples = roundToInt (attackTimeSecs * sourceSampleRate);
        releaseSamples = roundToInt (releaseTimeSecs * sourceSampleRate);
    }
}

SilverSamplerSound::~SilverSamplerSound()
{
}

bool SilverSamplerSound::appliesToNote (const int midiNoteNumber)
{
    return midiNotes [midiNoteNumber];
}

bool SilverSamplerSound::appliesToChannel (const int /*midiChannel*/)
{
    return true;
}

