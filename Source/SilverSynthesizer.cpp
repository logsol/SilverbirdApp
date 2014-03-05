/*
  ==============================================================================

    SilverSynthesizer.cpp
    Created: 10 Feb 2014 12:08:13am
    Author:  Pannek Karl

  ==============================================================================
*/

#include "SilverSynthesizer.h"

SilverSynthesizer::SilverSynthesizer() {
    AiffAudioFormat aifFormat;
    
	

    
    //clearSounds();
    
    for (int i = 6; --i >= 0;)
    {
        SilverSamplerVoice* sv = new SilverSamplerVoice();
        addVoice (sv);
    }
    
    addKicks (36);
    // 38 42
}
SilverSynthesizer::~SilverSynthesizer() {
}

int SilverSynthesizer::getCurrentSelection(int midiNoteNumber) {
    return 1;
}

void SilverSynthesizer::addKicks(int midiNoteNumber) {
    
    AiffAudioFormat aifFormat;
    ScopedPointer<AudioFormatReader> sampleReader;
    
    clearSounds();
    
    const int numSamples = 5;
    
    MemoryInputStream *kicks[numSamples] = {
        new MemoryInputStream (BinaryData::kick1_aif, BinaryData::kick1_aifSize, false),
        new MemoryInputStream (BinaryData::kick2_aif, BinaryData::kick2_aifSize, false),
        new MemoryInputStream (BinaryData::kick3_aif, BinaryData::kick3_aifSize, false),
        new MemoryInputStream (BinaryData::kick4_aif, BinaryData::kick4_aifSize, false),
        new MemoryInputStream (BinaryData::kick5_aif, BinaryData::kick5_aifSize, false)
    };
    
    //    snares[0] = new MemoryInputStream (BinaryData::snare1_aif, BinaryData::snare1_aifSize, false);
    //    snares[1] = new MemoryInputStream (BinaryData::snare2_aif, BinaryData::snare2_aifSize, false);
    //    snares[2] = new MemoryInputStream (BinaryData::snare3_aif, BinaryData::snare3_aifSize, false);
    //    snares[3] = new MemoryInputStream (BinaryData::snare4_aif, BinaryData::snare4_aifSize, false);
    //    snares[4] = new MemoryInputStream (BinaryData::snare5_aif, BinaryData::snare5_aifSize, false);
    //
    //    hihats[0] = new MemoryInputStream (BinaryData::hihat1_aif, BinaryData::hihat1_aifSize, false);
    //    hihats[1] = new MemoryInputStream (BinaryData::hihat2_aif, BinaryData::hihat2_aifSize, false);
    //    hihats[2] = new MemoryInputStream (BinaryData::hihat3_aif, BinaryData::hihat3_aifSize, false);
    //    hihats[3] = new MemoryInputStream (BinaryData::hihat4_aif, BinaryData::hihat4_aifSize, false);
    //    hihats[4] = new MemoryInputStream (BinaryData::hihat5_aif, BinaryData::hihat5_aifSize, false);
    
    
    for(int i = 0; i < numSamples; i++) {
        sampleReader = aifFormat.createReaderFor (kicks[i], true);
        addSound (new SilverSamplerSound ("kick", midiNoteNumber, i, *sampleReader));
    }
}

void SilverSynthesizer::noteOn (const int midiChannel,
                          const int midiNoteNumber,
                          const float velocity)
{
    const ScopedLock sl (lock);
    
    for (int i = sounds.size(); --i >= 0;)
    {
        SilverSamplerSound* const sound = (ReferenceCountedObjectPtr<SilverSamplerSound>) sounds.getUnchecked(i);
        
        if (sound->appliesToNote (midiNoteNumber)
            && sound->appliesToChannel (midiChannel)
            && sound->appliesToSelection(getCurrentSelection(midiNoteNumber)))
        {
            // If hitting a note that's still ringing, stop it first (it could be
            // still playing because of the sustain or sostenuto pedal).
            for (int j = voices.size(); --j >= 0;)
            {
                SynthesiserVoice* const voice = voices.getUnchecked (j);
                
                if (voice->getCurrentlyPlayingNote() == midiNoteNumber
                    && voice->isPlayingChannel (midiChannel))
                    stopVoice (voice, true);
            }
            
            startVoice (findFreeVoice (sound, shouldStealNotes),
                        sound, midiChannel, midiNoteNumber, velocity);
        }
    }
    
}