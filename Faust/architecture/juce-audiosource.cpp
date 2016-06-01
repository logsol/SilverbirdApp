
#include "FaustDependencies.h"

<<includeIntrinsic>>

<<includeclass>>

class mydspAudioSource : public MixerAudioSource {
public:

	mydspAudioSource ();
    
    void getNextAudioBlock (const AudioSourceChannelInfo& info) override;

    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;

    void releaseResources() override;
    
    float fSamplingFreq;

protected:
    ScopedPointer<mydsp> dsp;
};

mydspAudioSource::mydspAudioSource ()
{
    dsp = new mydsp();
}

void mydspAudioSource::getNextAudioBlock (const AudioSourceChannelInfo& info)  
{
	MixerAudioSource::getNextAudioBlock(info);

	dsp->compute(info.numSamples, info.buffer->getArrayOfWritePointers(), info.buffer->getArrayOfWritePointers());
};

void mydspAudioSource::prepareToPlay (int samplesPerBlockExpected, double sampleRate)  
{
	dsp->init((int) sampleRate);
};

void mydspAudioSource::releaseResources()  
{

};
