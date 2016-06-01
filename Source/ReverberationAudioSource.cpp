//----------------------------------------------------------
//
// Code generated with Faust 0.9.73 (http://faust.grame.fr)
//----------------------------------------------------------

/* link with  */

#include "FaustDependencies.h"


#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif  


#ifndef FAUSTCLASS 
#define FAUSTCLASS Reverberation
#endif

class Reverberation : public dsp {
  private:
	int 	IOTA;
	float 	fVec0[2048];
	float 	fRec6[2];
	float 	fRec7[2];
	float 	fVec1[1024];
	float 	fRec8[2];
	float 	fRec9[2];
	float 	fVec2[1024];
	float 	fRec10[2];
	float 	fRec11[2];
	float 	fVec3[1024];
	float 	fRec12[2];
	float 	fRec13[2];
	float 	fVec4[128];
	float 	fRec4[2];
	float 	fVec5[64];
	float 	fRec2[2];
	float 	fVec6[12];
	float 	fRec0[2];
  public:
	static void metadata(Meta* m) 	{ 
		m->declare("effect.lib/exciter_name", "Harmonic Exciter");
		m->declare("effect.lib/exciter_author", "Priyanka Shekar (pshekar@ccrma.stanford.edu)");
		m->declare("effect.lib/exciter_copyright", "Copyright (c) 2013 Priyanka Shekar");
		m->declare("effect.lib/exciter_version", "1.0");
		m->declare("effect.lib/exciter_license", "MIT License (MIT)");
		m->declare("math.lib/name", "Math Library");
		m->declare("math.lib/author", "GRAME");
		m->declare("math.lib/copyright", "GRAME");
		m->declare("math.lib/version", "1.0");
		m->declare("math.lib/license", "LGPL with exception");
		m->declare("effect.lib/name", "Faust Audio Effect Library");
		m->declare("effect.lib/author", "Julius O. Smith (jos at ccrma.stanford.edu)");
		m->declare("effect.lib/copyright", "Julius O. Smith III");
		m->declare("effect.lib/version", "1.33");
		m->declare("effect.lib/license", "STK-4.3");
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
	}

	virtual int getNumInputs() 	{ return 2; }
	virtual int getNumOutputs() 	{ return 2; }
	static void classInit(int samplingFreq) {
	}
	virtual void instanceInit(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		IOTA = 0;
		for (int i=0; i<2048; i++) fVec0[i] = 0;
		for (int i=0; i<2; i++) fRec6[i] = 0;
		for (int i=0; i<2; i++) fRec7[i] = 0;
		for (int i=0; i<1024; i++) fVec1[i] = 0;
		for (int i=0; i<2; i++) fRec8[i] = 0;
		for (int i=0; i<2; i++) fRec9[i] = 0;
		for (int i=0; i<1024; i++) fVec2[i] = 0;
		for (int i=0; i<2; i++) fRec10[i] = 0;
		for (int i=0; i<2; i++) fRec11[i] = 0;
		for (int i=0; i<1024; i++) fVec3[i] = 0;
		for (int i=0; i<2; i++) fRec12[i] = 0;
		for (int i=0; i<2; i++) fRec13[i] = 0;
		for (int i=0; i<128; i++) fVec4[i] = 0;
		for (int i=0; i<2; i++) fRec4[i] = 0;
		for (int i=0; i<64; i++) fVec5[i] = 0;
		for (int i=0; i<2; i++) fRec2[i] = 0;
		for (int i=0; i<12; i++) fVec6[i] = 0;
		for (int i=0; i<2; i++) fRec0[i] = 0;
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
			float fTemp0 = (0.2f * ((float)input0[i] + (float)input1[i]));
			float fTemp1 = (fTemp0 + (0.764f * fRec6[1]));
			fVec0[IOTA&2047] = fTemp1;
			fRec6[0] = fVec0[(IOTA-1122)&2047];
			fRec7[0] = fVec0[IOTA&2047];
			float fTemp2 = (fTemp0 + (0.783f * fRec8[1]));
			fVec1[IOTA&1023] = fTemp2;
			fRec8[0] = fVec1[(IOTA-1010)&1023];
			fRec9[0] = fVec1[IOTA&1023];
			float fTemp3 = (fTemp0 + (0.805f * fRec10[1]));
			fVec2[IOTA&1023] = fTemp3;
			fRec10[0] = fVec2[(IOTA-900)&1023];
			fRec11[0] = fVec2[IOTA&1023];
			float fTemp4 = ((0.827f * fRec12[1]) + fTemp0);
			fVec3[IOTA&1023] = fTemp4;
			fRec12[0] = fVec3[(IOTA-777)&1023];
			fRec13[0] = fVec3[IOTA&1023];
			float fTemp5 = (fRec7[1] + (fRec9[1] + (fRec11[1] + ((0.7f * fRec4[1]) + fRec13[1]))));
			fVec4[IOTA&127] = fTemp5;
			fRec4[0] = fVec4[(IOTA-124)&127];
			float 	fRec5 = (0 - (0.7f * fVec4[IOTA&127]));
			float fTemp6 = (fRec4[1] + (fRec5 + (0.7f * fRec2[1])));
			fVec5[IOTA&63] = fTemp6;
			fRec2[0] = fVec5[(IOTA-41)&63];
			float 	fRec3 = (0 - (0.7f * fVec5[IOTA&63]));
			float fTemp7 = (fRec2[1] + (fRec3 + (0.7f * fRec0[1])));
			fVec6[0] = fTemp7;
			fRec0[0] = fVec6[11];
			float 	fRec1 = (0 - (0.7f * fVec6[0]));
			float fTemp8 = (fRec1 + fRec0[1]);
			output0[i] = (FAUSTFLOAT)fTemp8;
			output1[i] = (FAUSTFLOAT)(0 - fTemp8);
			// post processing
			fRec0[1] = fRec0[0];
			for (int i=11; i>0; i--) fVec6[i] = fVec6[i-1];
			fRec2[1] = fRec2[0];
			fRec4[1] = fRec4[0];
			fRec13[1] = fRec13[0];
			fRec12[1] = fRec12[0];
			fRec11[1] = fRec11[0];
			fRec10[1] = fRec10[0];
			fRec9[1] = fRec9[0];
			fRec8[1] = fRec8[0];
			fRec7[1] = fRec7[0];
			fRec6[1] = fRec6[0];
			IOTA = IOTA+1;
		}
	}
};



class ReverberationAudioSource : public MixerAudioSource {
public:

	ReverberationAudioSource ();
    
    void getNextAudioBlock (const AudioSourceChannelInfo& info) override;

    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;

    void releaseResources() override;
    
    float fSamplingFreq;

protected:
    ScopedPointer<Reverberation> dsp;
};

ReverberationAudioSource::ReverberationAudioSource ()
{
    dsp = new Reverberation();
}

void ReverberationAudioSource::getNextAudioBlock (const AudioSourceChannelInfo& info)  
{
	MixerAudioSource::getNextAudioBlock(info);

	dsp->compute(info.numSamples, info.buffer->getArrayOfWritePointers(), info.buffer->getArrayOfWritePointers());
};

void ReverberationAudioSource::prepareToPlay (int samplesPerBlockExpected, double sampleRate)  
{
	dsp->init((int) sampleRate);
};

void ReverberationAudioSource::releaseResources()  
{

};
