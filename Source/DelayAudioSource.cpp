//----------------------------------------------------------
//
// Code generated with Faust 0.9.73 (http://faust.grame.fr)
//----------------------------------------------------------

/* link with  */
#include <math.h>

#include "FaustDependencies.h"


#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif  


#ifndef FAUSTCLASS 
#define FAUSTCLASS Delay
#endif

class Delay : public dsp {
  private:
	float 	fConst0;
	int 	iConst1;
	int 	iConst2;
	float 	fConst3;
	int 	iConst4;
	float 	fConst5;
	float 	fConst6;
	int 	iConst7;
	float 	fConst8;
	float 	fConst9;
	int 	iConst10;
	float 	fConst11;
	int 	iConst12;
	int 	IOTA;
	float 	fRec0[131072];
	float 	fRec1[131072];
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("filter.lib/name", "Faust Filter Library");
		m->declare("filter.lib/author", "Julius O. Smith (jos at ccrma.stanford.edu)");
		m->declare("filter.lib/copyright", "Julius O. Smith III");
		m->declare("filter.lib/version", "1.29");
		m->declare("filter.lib/license", "STK-4.3");
		m->declare("filter.lib/reference", "https://ccrma.stanford.edu/~jos/filters/");
		m->declare("music.lib/name", "Music Library");
		m->declare("music.lib/author", "GRAME");
		m->declare("music.lib/copyright", "GRAME");
		m->declare("music.lib/version", "1.0");
		m->declare("music.lib/license", "LGPL with exception");
		m->declare("math.lib/name", "Math Library");
		m->declare("math.lib/author", "GRAME");
		m->declare("math.lib/copyright", "GRAME");
		m->declare("math.lib/version", "1.0");
		m->declare("math.lib/license", "LGPL with exception");
	}

	virtual int getNumInputs() 	{ return 2; }
	virtual int getNumOutputs() 	{ return 2; }
	static void classInit(int samplingFreq) {
	}
	virtual void instanceInit(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		fConst0 = (0.5f * min(192000, max(1, fSamplingFreq)));
		iConst1 = int((fConst0 - 0.49999499999999997f));
		iConst2 = (1 + iConst1);
		fConst3 = (0 - (iConst2 - fConst0));
		iConst4 = (2 + iConst1);
		fConst5 = (fConst0 - iConst4);
		fConst6 = ((0 - fConst3) * (0 - (0.5f * fConst5)));
		iConst7 = int((1 + int((iConst1 & 65535))));
		fConst8 = (fConst0 - iConst1);
		fConst9 = (0 - fConst5);
		iConst10 = int((1 + int((int(iConst2) & 65535))));
		fConst11 = (0.5f * fConst3);
		iConst12 = int((1 + int((int(iConst4) & 65535))));
		IOTA = 0;
		for (int i=0; i<131072; i++) fRec0[i] = 0;
		for (int i=0; i<131072; i++) fRec1[i] = 0;
	}
	virtual void init(int samplingFreq) {
		classInit(samplingFreq);
		instanceInit(samplingFreq);
	}
	virtual void buildUserInterface(UI* interface) {
		interface->openVerticalBox("0x00");
		interface->closeBox();
	}
	virtual void compute (int count, FAUSTFLOAT** input, FAUSTFLOAT** output) {
		FAUSTFLOAT* input0 = input[0];
		FAUSTFLOAT* input1 = input[1];
		FAUSTFLOAT* output0 = output[0];
		FAUSTFLOAT* output1 = output[1];
		for (int i=0; i<count; i++) {
			fRec0[IOTA&131071] = ((float)input0[i] - (0.3f * ((fConst6 * fRec0[(IOTA-iConst7)&131071]) + (fConst8 * ((fConst9 * fRec0[(IOTA-iConst10)&131071]) + (fConst11 * fRec0[(IOTA-iConst12)&131071]))))));
			output0[i] = (FAUSTFLOAT)fRec0[(IOTA-0)&131071];
			fRec1[IOTA&131071] = ((float)input1[i] - (0.3f * ((fConst6 * fRec1[(IOTA-iConst7)&131071]) + (fConst8 * ((fConst9 * fRec1[(IOTA-iConst10)&131071]) + (fConst11 * fRec1[(IOTA-iConst12)&131071]))))));
			output1[i] = (FAUSTFLOAT)fRec1[(IOTA-0)&131071];
			// post processing
			IOTA = IOTA+1;
		}
	}
};



class DelayAudioSource : public MixerAudioSource {
public:

	DelayAudioSource ();
    
    void getNextAudioBlock (const AudioSourceChannelInfo& info) override;

    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;

    void releaseResources() override;
    
    float fSamplingFreq;

protected:
    ScopedPointer<Delay> dsp;
};

DelayAudioSource::DelayAudioSource ()
{
    dsp = new Delay();
}

void DelayAudioSource::getNextAudioBlock (const AudioSourceChannelInfo& info)  
{
	MixerAudioSource::getNextAudioBlock(info);

	dsp->compute(info.numSamples, info.buffer->getArrayOfWritePointers(), info.buffer->getArrayOfWritePointers());
};

void DelayAudioSource::prepareToPlay (int samplesPerBlockExpected, double sampleRate)  
{
	dsp->init((int) sampleRate);
};

void DelayAudioSource::releaseResources()  
{

};
