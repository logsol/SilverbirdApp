//----------------------------------------------------------
//
// Code generated with Faust 0.9.73 (http://faust.grame.fr)
//----------------------------------------------------------

/* link with  */
#include <math.h>
/************************************************************************

	IMPORTANT NOTE : this file contains two clearly delimited sections : 
	the ARCHITECTURE section (in two parts) and the USER section. Each section 
	is governed by its own copyright and license. Please check individually 
	each section for license and copyright information.
*************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
    FAUST Architecture File
	Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it 
    and/or modify it under the terms of the GNU General Public License 
	as published by the Free Software Foundation; either version 3 of 
	the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License 
	along with this program; If not, see <http://www.gnu.org/licenses/>.

	EXCEPTION : As a special exception, you may create a larger work 
	that contains this FAUST architecture section and distribute  
	that work under terms of your choice, so long as this FAUST 
	architecture section is not modified. 


 ************************************************************************
 ************************************************************************/

#include <libgen.h>
#include <stdlib.h>
#include <iostream>
#include <list>

/************************************************************************
    IMPORTANT NOTE : this file contains two clearly delimited sections :
    the ARCHITECTURE section (in two parts) and the USER section. Each section
    is governed by its own copyright and license. Please check individually
    each section for license and copyright information.
*************************************************************************/

/*******************BEGIN ARCHITECTURE SECTION (part 1/2)****************/

/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.

 ************************************************************************
 ************************************************************************/
 
/******************************************************************************
*******************************************************************************

								FAUST DSP

*******************************************************************************
*******************************************************************************/

#ifndef __dsp__
#define __dsp__

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

class UI;

//----------------------------------------------------------------
//  Signal processor definition
//----------------------------------------------------------------

class dsp {

    protected:

        int fSamplingFreq;

    public:

        dsp() {}
        virtual ~dsp() {}

        virtual int getNumInputs() = 0;
        virtual int getNumOutputs() = 0;
        virtual void buildUserInterface(UI* ui_interface) = 0;
        virtual void init(int samplingRate) = 0;
        virtual void instanceInit(int samplingRate) = 0;
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) = 0;
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { compute(count, inputs, outputs); }
       
};

//----------------------------------------------------------------
//  Generic decorator
//----------------------------------------------------------------

class decorator_dsp : public dsp {

    protected:

        dsp* fDSP;

    public:

        decorator_dsp(dsp* dsp = 0):fDSP(dsp) {}
        virtual ~decorator_dsp() { delete fDSP; }

        virtual int getNumInputs() { return fDSP->getNumInputs(); }
        virtual int getNumOutputs() { return fDSP->getNumOutputs(); }
        virtual void buildUserInterface(UI* ui_interface) { fDSP->buildUserInterface(ui_interface); }
        virtual void init(int samplingRate) { fDSP->init(samplingRate); }
        virtual void instanceInit(int samplingRate) { fDSP->instanceInit(samplingRate); }
        virtual void compute(int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(count, inputs, outputs); }
        virtual void compute(double date_usec, int count, FAUSTFLOAT** inputs, FAUSTFLOAT** outputs) { fDSP->compute(date_usec, count, inputs, outputs); }
       
};

//----------------------------------------------------------------
// On Intel set FZ (Flush to Zero) and DAZ (Denormals Are Zero)
// flags to avoid costly denormals
//----------------------------------------------------------------

#ifdef __SSE__
    #include <xmmintrin.h>
    #ifdef __SSE2__
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8040)
    #else
        #define AVOIDDENORMALS _mm_setcsr(_mm_getcsr() | 0x8000)
    #endif
#else
    #define AVOIDDENORMALS
#endif

#endif
/************************************************************************
    FAUST Architecture File
    Copyright (C) 2003-2016 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 3 of
    the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; If not, see <http://www.gnu.org/licenses/>.

    EXCEPTION : As a special exception, you may create a larger work
    that contains this FAUST architecture section and distribute
    that work under terms of your choice, so long as this FAUST
    architecture section is not modified.


 ************************************************************************
 ************************************************************************/
 
#ifndef FAUST_UI_H
#define FAUST_UI_H

#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif

/*******************************************************************************
 * UI : Faust User Interface
 * This abstract class contains only the method that the faust compiler can
 * generate to describe a DSP interface.
 ******************************************************************************/

class UI
{

    public:

        UI() {}

        virtual ~UI() {}

        // -- widget's layouts

        virtual void openTabBox(const char* label) = 0;
        virtual void openHorizontalBox(const char* label) = 0;
        virtual void openVerticalBox(const char* label) = 0;
        virtual void closeBox() = 0;

        // -- active widgets

        virtual void addButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone) = 0;
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) = 0;

        // -- passive widgets

        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) = 0;

        // -- metadata declarations

        virtual void declare(FAUSTFLOAT*, const char*, const char*) {}
};

//----------------------------------------------------------------
//  Generic decorator
//----------------------------------------------------------------

class DecoratorUI : public UI
{
    protected:
    
        UI* fUI;

    public:
    
        DecoratorUI(UI* ui = 0):fUI(ui)
        {}

        virtual ~DecoratorUI() { delete fUI; }

        // -- widget's layouts
        virtual void openTabBox(const char* label)          { fUI->openTabBox(label); }
        virtual void openHorizontalBox(const char* label)   { fUI->openHorizontalBox(label); }
        virtual void openVerticalBox(const char* label)     { fUI->openVerticalBox(label); }
        virtual void closeBox()                             { fUI->closeBox(); }

        // -- active widgets
        virtual void addButton(const char* label, FAUSTFLOAT* zone)         { fUI->addButton(label, zone); }
        virtual void addCheckButton(const char* label, FAUSTFLOAT* zone)    { fUI->addCheckButton(label, zone); }
        virtual void addVerticalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step)
            { fUI->addVerticalSlider(label, zone, init, min, max, step); }
        virtual void addHorizontalSlider(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) 	
            { fUI->addHorizontalSlider(label, zone, init, min, max, step); }
        virtual void addNumEntry(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT init, FAUSTFLOAT min, FAUSTFLOAT max, FAUSTFLOAT step) 			
            { fUI->addNumEntry(label, zone, init, min, max, step); }

        // -- passive widgets	
        virtual void addHorizontalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max) 
            { fUI->addHorizontalBargraph(label, zone, min, max); }
        virtual void addVerticalBargraph(const char* label, FAUSTFLOAT* zone, FAUSTFLOAT min, FAUSTFLOAT max)
            { fUI->addVerticalBargraph(label, zone, min, max); }

        virtual void declare(FAUSTFLOAT* zone, const char* key, const char* val) { fUI->declare(zone, key, val); }

};

#endif
/************************************************************************
 ************************************************************************
    FAUST Architecture File
	Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 3 of
	the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
	along with this program; If not, see <http://www.gnu.org/licenses/>.

 ************************************************************************
 ************************************************************************/
 
#ifndef __meta__
#define __meta__

struct Meta
{
    virtual void declare(const char* key, const char* value) = 0;
    virtual ~Meta() {};
};

#endif
/************************************************************************
 ************************************************************************
    FAUST Architecture File
	Copyright (C) 2003-2011 GRAME, Centre National de Creation Musicale
    ---------------------------------------------------------------------
    This Architecture section is free software; you can redistribute it
    and/or modify it under the terms of the GNU General Public License
	as published by the Free Software Foundation; either version 3 of
	the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
	along with this program; If not, see <http://www.gnu.org/licenses/>.

 ************************************************************************
 ************************************************************************/
 
#ifndef __misc__
#define __misc__

#include <algorithm>
#include <map>
#include <string.h>
#include <stdlib.h>


using std::max;
using std::min;

struct XXXX_Meta : std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

struct MY_Meta : Meta, std::map<const char*, const char*>
{
    void declare(const char* key, const char* value) { (*this)[key]=value; }
};

inline int lsr(int x, int n)	{ return int(((unsigned int)x) >> n); }
inline int int2pow2(int x)		{ int r=0; while ((1<<r)<x) r++; return r; }

long lopt(char* argv[], const char* name, long def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return atoi(argv[i+1]);
	return def;
}

bool isopt(char* argv[], const char* name)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return true;
	return false;
}

const char* lopts(char* argv[], const char* name, const char* def)
{
	int	i;
	for (i = 0; argv[i]; i++) if (!strcmp(argv[i], name)) return argv[i+1];
	return def;
}

#endif


#include "JuceHeader.h"

/**************************BEGIN USER SECTION **************************/
/******************************************************************************
*******************************************************************************

							       VECTOR INTRINSICS

*******************************************************************************
*******************************************************************************/


#ifndef FAUSTFLOAT
#define FAUSTFLOAT float
#endif  


#ifndef FAUSTCLASS 
#define FAUSTCLASS Reverberation
#endif

class Reverberation : public dsp {
  private:
	float 	fRec9[2];
	int 	IOTA;
	float 	fVec0[2048];
	int 	iConst0;
	int 	iConst1;
	int 	iConst2;
	float 	fRec8[2];
	float 	fRec11[2];
	float 	fVec1[2048];
	int 	iConst3;
	int 	iConst4;
	float 	fRec10[2];
	float 	fRec13[2];
	float 	fVec2[2048];
	int 	iConst5;
	int 	iConst6;
	float 	fRec12[2];
	float 	fRec15[2];
	float 	fVec3[2048];
	int 	iConst7;
	int 	iConst8;
	float 	fRec14[2];
	float 	fRec17[2];
	float 	fVec4[2048];
	int 	iConst9;
	int 	iConst10;
	float 	fRec16[2];
	float 	fRec19[2];
	float 	fVec5[2048];
	int 	iConst11;
	int 	iConst12;
	float 	fRec18[2];
	float 	fRec21[2];
	float 	fVec6[2048];
	int 	iConst13;
	int 	iConst14;
	float 	fRec20[2];
	float 	fRec23[2];
	float 	fVec7[2048];
	int 	iConst15;
	int 	iConst16;
	float 	fRec22[2];
	float 	fVec8[1024];
	int 	iConst17;
	float 	fRec6[2];
	float 	fVec9[1024];
	int 	iConst18;
	float 	fRec4[2];
	float 	fVec10[1024];
	int 	iConst19;
	float 	fRec2[2];
	float 	fVec11[1024];
	int 	iConst20;
	float 	fRec0[2];
	float 	fRec33[2];
	float 	fVec12[2048];
	int 	iConst21;
	float 	fRec32[2];
	float 	fRec35[2];
	float 	fVec13[2048];
	int 	iConst22;
	float 	fRec34[2];
	float 	fRec37[2];
	float 	fVec14[2048];
	int 	iConst23;
	float 	fRec36[2];
	float 	fRec39[2];
	float 	fVec15[2048];
	int 	iConst24;
	float 	fRec38[2];
	float 	fRec41[2];
	float 	fVec16[2048];
	int 	iConst25;
	float 	fRec40[2];
	float 	fRec43[2];
	float 	fVec17[2048];
	int 	iConst26;
	float 	fRec42[2];
	float 	fRec45[2];
	float 	fVec18[2048];
	int 	iConst27;
	float 	fRec44[2];
	float 	fRec47[2];
	float 	fVec19[2048];
	int 	iConst28;
	float 	fRec46[2];
	float 	fVec20[1024];
	float 	fRec30[2];
	float 	fVec21[1024];
	float 	fRec28[2];
	float 	fVec22[1024];
	float 	fRec26[2];
	float 	fVec23[1024];
	float 	fRec24[2];
  public:
	static void metadata(Meta* m) 	{ 
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
		m->declare("filter.lib/name", "Faust Filter Library");
		m->declare("filter.lib/author", "Julius O. Smith (jos at ccrma.stanford.edu)");
		m->declare("filter.lib/copyright", "Julius O. Smith III");
		m->declare("filter.lib/version", "1.29");
		m->declare("filter.lib/license", "STK-4.3");
		m->declare("filter.lib/reference", "https://ccrma.stanford.edu/~jos/filters/");
	}

	virtual int getNumInputs() 	{ return 2; }
	virtual int getNumOutputs() 	{ return 2; }
	static void classInit(int samplingFreq) {
	}
	virtual void instanceInit(int samplingFreq) {
		fSamplingFreq = samplingFreq;
		for (int i=0; i<2; i++) fRec9[i] = 0;
		IOTA = 0;
		for (int i=0; i<2048; i++) fVec0[i] = 0;
		iConst0 = min(192000, max(1, fSamplingFreq));
		iConst1 = int((0.025306122448979593f * iConst0));
		iConst2 = int((iConst1 & 2047));
		for (int i=0; i<2; i++) fRec8[i] = 0;
		for (int i=0; i<2; i++) fRec11[i] = 0;
		for (int i=0; i<2048; i++) fVec1[i] = 0;
		iConst3 = int((0.026938775510204082f * iConst0));
		iConst4 = int((iConst3 & 2047));
		for (int i=0; i<2; i++) fRec10[i] = 0;
		for (int i=0; i<2; i++) fRec13[i] = 0;
		for (int i=0; i<2048; i++) fVec2[i] = 0;
		iConst5 = int((0.02895691609977324f * iConst0));
		iConst6 = int((iConst5 & 2047));
		for (int i=0; i<2; i++) fRec12[i] = 0;
		for (int i=0; i<2; i++) fRec15[i] = 0;
		for (int i=0; i<2048; i++) fVec3[i] = 0;
		iConst7 = int((0.03074829931972789f * iConst0));
		iConst8 = int((iConst7 & 2047));
		for (int i=0; i<2; i++) fRec14[i] = 0;
		for (int i=0; i<2; i++) fRec17[i] = 0;
		for (int i=0; i<2048; i++) fVec4[i] = 0;
		iConst9 = int((0.03224489795918367f * iConst0));
		iConst10 = int((iConst9 & 2047));
		for (int i=0; i<2; i++) fRec16[i] = 0;
		for (int i=0; i<2; i++) fRec19[i] = 0;
		for (int i=0; i<2048; i++) fVec5[i] = 0;
		iConst11 = int((0.03380952380952381f * iConst0));
		iConst12 = int((iConst11 & 2047));
		for (int i=0; i<2; i++) fRec18[i] = 0;
		for (int i=0; i<2; i++) fRec21[i] = 0;
		for (int i=0; i<2048; i++) fVec6[i] = 0;
		iConst13 = int((0.03530612244897959f * iConst0));
		iConst14 = int((iConst13 & 2047));
		for (int i=0; i<2; i++) fRec20[i] = 0;
		for (int i=0; i<2; i++) fRec23[i] = 0;
		for (int i=0; i<2048; i++) fVec7[i] = 0;
		iConst15 = int((0.03666666666666667f * iConst0));
		iConst16 = int((iConst15 & 2047));
		for (int i=0; i<2; i++) fRec22[i] = 0;
		for (int i=0; i<1024; i++) fVec8[i] = 0;
		iConst17 = int((int((int((0.012607709750566893f * iConst0)) - 1)) & 1023));
		for (int i=0; i<2; i++) fRec6[i] = 0;
		for (int i=0; i<1024; i++) fVec9[i] = 0;
		iConst18 = int((int((int((0.01f * iConst0)) - 1)) & 1023));
		for (int i=0; i<2; i++) fRec4[i] = 0;
		for (int i=0; i<1024; i++) fVec10[i] = 0;
		iConst19 = int((int((int((0.007732426303854875f * iConst0)) - 1)) & 1023));
		for (int i=0; i<2; i++) fRec2[i] = 0;
		for (int i=0; i<1024; i++) fVec11[i] = 0;
		iConst20 = int((int((int((0.00510204081632653f * iConst0)) - 1)) & 1023));
		for (int i=0; i<2; i++) fRec0[i] = 0;
		for (int i=0; i<2; i++) fRec33[i] = 0;
		for (int i=0; i<2048; i++) fVec12[i] = 0;
		iConst21 = int((int((0.5f + iConst1)) & 2047));
		for (int i=0; i<2; i++) fRec32[i] = 0;
		for (int i=0; i<2; i++) fRec35[i] = 0;
		for (int i=0; i<2048; i++) fVec13[i] = 0;
		iConst22 = int((int((0.5f + iConst3)) & 2047));
		for (int i=0; i<2; i++) fRec34[i] = 0;
		for (int i=0; i<2; i++) fRec37[i] = 0;
		for (int i=0; i<2048; i++) fVec14[i] = 0;
		iConst23 = int((int((0.5f + iConst5)) & 2047));
		for (int i=0; i<2; i++) fRec36[i] = 0;
		for (int i=0; i<2; i++) fRec39[i] = 0;
		for (int i=0; i<2048; i++) fVec15[i] = 0;
		iConst24 = int((int((0.5f + iConst7)) & 2047));
		for (int i=0; i<2; i++) fRec38[i] = 0;
		for (int i=0; i<2; i++) fRec41[i] = 0;
		for (int i=0; i<2048; i++) fVec16[i] = 0;
		iConst25 = int((int((0.5f + iConst9)) & 2047));
		for (int i=0; i<2; i++) fRec40[i] = 0;
		for (int i=0; i<2; i++) fRec43[i] = 0;
		for (int i=0; i<2048; i++) fVec17[i] = 0;
		iConst26 = int((int((0.5f + iConst11)) & 2047));
		for (int i=0; i<2; i++) fRec42[i] = 0;
		for (int i=0; i<2; i++) fRec45[i] = 0;
		for (int i=0; i<2048; i++) fVec18[i] = 0;
		iConst27 = int((int((0.5f + iConst13)) & 2047));
		for (int i=0; i<2; i++) fRec44[i] = 0;
		for (int i=0; i<2; i++) fRec47[i] = 0;
		for (int i=0; i<2048; i++) fVec19[i] = 0;
		iConst28 = int((int((0.5f + iConst15)) & 2047));
		for (int i=0; i<2; i++) fRec46[i] = 0;
		for (int i=0; i<1024; i++) fVec20[i] = 0;
		for (int i=0; i<2; i++) fRec30[i] = 0;
		for (int i=0; i<1024; i++) fVec21[i] = 0;
		for (int i=0; i<2; i++) fRec28[i] = 0;
		for (int i=0; i<1024; i++) fVec22[i] = 0;
		for (int i=0; i<2; i++) fRec26[i] = 0;
		for (int i=0; i<1024; i++) fVec23[i] = 0;
		for (int i=0; i<2; i++) fRec24[i] = 0;
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
			float fTemp0 = (float)input0[i];
			fRec9[0] = (0.5f * (fRec9[1] + fRec8[1]));
			fVec0[IOTA&2047] = (fTemp0 + (0.7f * fRec9[0]));
			fRec8[0] = fVec0[(IOTA-iConst2)&2047];
			fRec11[0] = (0.5f * (fRec11[1] + fRec10[1]));
			fVec1[IOTA&2047] = (fTemp0 + (0.7f * fRec11[0]));
			fRec10[0] = fVec1[(IOTA-iConst4)&2047];
			fRec13[0] = (0.5f * (fRec13[1] + fRec12[1]));
			fVec2[IOTA&2047] = (fTemp0 + (0.7f * fRec13[0]));
			fRec12[0] = fVec2[(IOTA-iConst6)&2047];
			fRec15[0] = (0.5f * (fRec15[1] + fRec14[1]));
			fVec3[IOTA&2047] = (fTemp0 + (0.7f * fRec15[0]));
			fRec14[0] = fVec3[(IOTA-iConst8)&2047];
			fRec17[0] = (0.5f * (fRec17[1] + fRec16[1]));
			fVec4[IOTA&2047] = (fTemp0 + (0.7f * fRec17[0]));
			fRec16[0] = fVec4[(IOTA-iConst10)&2047];
			fRec19[0] = (0.5f * (fRec19[1] + fRec18[1]));
			fVec5[IOTA&2047] = (fTemp0 + (0.7f * fRec19[0]));
			fRec18[0] = fVec5[(IOTA-iConst12)&2047];
			fRec21[0] = (0.5f * (fRec21[1] + fRec20[1]));
			fVec6[IOTA&2047] = (fTemp0 + (0.7f * fRec21[0]));
			fRec20[0] = fVec6[(IOTA-iConst14)&2047];
			fRec23[0] = (0.5f * (fRec23[1] + fRec22[1]));
			fVec7[IOTA&2047] = ((0.7f * fRec23[0]) + fTemp0);
			fRec22[0] = fVec7[(IOTA-iConst16)&2047];
			float fTemp1 = ((((((((fRec8[0] + fRec10[0]) + fRec12[0]) + fRec14[0]) + fRec16[0]) + fRec18[0]) + fRec20[0]) + fRec22[0]) + (0.7f * fRec6[1]));
			fVec8[IOTA&1023] = fTemp1;
			fRec6[0] = fVec8[(IOTA-iConst17)&1023];
			float 	fRec7 = (0 - (0.7f * fVec8[IOTA&1023]));
			float fTemp2 = ((fRec7 + (0.7f * fRec4[1])) + fRec6[1]);
			fVec9[IOTA&1023] = fTemp2;
			fRec4[0] = fVec9[(IOTA-iConst18)&1023];
			float 	fRec5 = (0 - (0.7f * fVec9[IOTA&1023]));
			float fTemp3 = ((fRec5 + (0.7f * fRec2[1])) + fRec4[1]);
			fVec10[IOTA&1023] = fTemp3;
			fRec2[0] = fVec10[(IOTA-iConst19)&1023];
			float 	fRec3 = (0 - (0.7f * fVec10[IOTA&1023]));
			float fTemp4 = ((fRec3 + (0.7f * fRec0[1])) + fRec2[1]);
			fVec11[IOTA&1023] = fTemp4;
			fRec0[0] = fVec11[(IOTA-iConst20)&1023];
			float 	fRec1 = (0 - (0.7f * fVec11[IOTA&1023]));
			output0[i] = (FAUSTFLOAT)(fRec1 + fRec0[1]);
			fRec33[0] = (0.5f * (fRec33[1] + fRec32[1]));
			float fTemp5 = (float)input1[i];
			fVec12[IOTA&2047] = ((0.7f * fRec33[0]) + fTemp5);
			fRec32[0] = fVec12[(IOTA-iConst21)&2047];
			fRec35[0] = (0.5f * (fRec35[1] + fRec34[1]));
			fVec13[IOTA&2047] = ((0.7f * fRec35[0]) + fTemp5);
			fRec34[0] = fVec13[(IOTA-iConst22)&2047];
			fRec37[0] = (0.5f * (fRec37[1] + fRec36[1]));
			fVec14[IOTA&2047] = ((0.7f * fRec37[0]) + fTemp5);
			fRec36[0] = fVec14[(IOTA-iConst23)&2047];
			fRec39[0] = (0.5f * (fRec39[1] + fRec38[1]));
			fVec15[IOTA&2047] = ((0.7f * fRec39[0]) + fTemp5);
			fRec38[0] = fVec15[(IOTA-iConst24)&2047];
			fRec41[0] = (0.5f * (fRec41[1] + fRec40[1]));
			fVec16[IOTA&2047] = ((0.7f * fRec41[0]) + fTemp5);
			fRec40[0] = fVec16[(IOTA-iConst25)&2047];
			fRec43[0] = (0.5f * (fRec43[1] + fRec42[1]));
			fVec17[IOTA&2047] = ((0.7f * fRec43[0]) + fTemp5);
			fRec42[0] = fVec17[(IOTA-iConst26)&2047];
			fRec45[0] = (0.5f * (fRec45[1] + fRec44[1]));
			fVec18[IOTA&2047] = ((0.7f * fRec45[0]) + fTemp5);
			fRec44[0] = fVec18[(IOTA-iConst27)&2047];
			fRec47[0] = (0.5f * (fRec47[1] + fRec46[1]));
			fVec19[IOTA&2047] = ((0.7f * fRec47[0]) + fTemp5);
			fRec46[0] = fVec19[(IOTA-iConst28)&2047];
			float fTemp6 = (((((((((0.7f * fRec30[1]) + fRec32[0]) + fRec34[0]) + fRec36[0]) + fRec38[0]) + fRec40[0]) + fRec42[0]) + fRec44[0]) + fRec46[0]);
			fVec20[IOTA&1023] = fTemp6;
			fRec30[0] = fVec20[(IOTA-iConst17)&1023];
			float 	fRec31 = (0 - (0.7f * fVec20[IOTA&1023]));
			float fTemp7 = (((0.7f * fRec28[1]) + fRec30[1]) + fRec31);
			fVec21[IOTA&1023] = fTemp7;
			fRec28[0] = fVec21[(IOTA-iConst18)&1023];
			float 	fRec29 = (0 - (0.7f * fVec21[IOTA&1023]));
			float fTemp8 = (((0.7f * fRec26[1]) + fRec28[1]) + fRec29);
			fVec22[IOTA&1023] = fTemp8;
			fRec26[0] = fVec22[(IOTA-iConst19)&1023];
			float 	fRec27 = (0 - (0.7f * fVec22[IOTA&1023]));
			float fTemp9 = (((0.7f * fRec24[1]) + fRec26[1]) + fRec27);
			fVec23[IOTA&1023] = fTemp9;
			fRec24[0] = fVec23[(IOTA-iConst20)&1023];
			float 	fRec25 = (0 - (0.7f * fVec23[IOTA&1023]));
			output1[i] = (FAUSTFLOAT)(fRec24[1] + fRec25);
			// post processing
			fRec24[1] = fRec24[0];
			fRec26[1] = fRec26[0];
			fRec28[1] = fRec28[0];
			fRec30[1] = fRec30[0];
			fRec46[1] = fRec46[0];
			fRec47[1] = fRec47[0];
			fRec44[1] = fRec44[0];
			fRec45[1] = fRec45[0];
			fRec42[1] = fRec42[0];
			fRec43[1] = fRec43[0];
			fRec40[1] = fRec40[0];
			fRec41[1] = fRec41[0];
			fRec38[1] = fRec38[0];
			fRec39[1] = fRec39[0];
			fRec36[1] = fRec36[0];
			fRec37[1] = fRec37[0];
			fRec34[1] = fRec34[0];
			fRec35[1] = fRec35[0];
			fRec32[1] = fRec32[0];
			fRec33[1] = fRec33[0];
			fRec0[1] = fRec0[0];
			fRec2[1] = fRec2[0];
			fRec4[1] = fRec4[0];
			fRec6[1] = fRec6[0];
			fRec22[1] = fRec22[0];
			fRec23[1] = fRec23[0];
			fRec20[1] = fRec20[0];
			fRec21[1] = fRec21[0];
			fRec18[1] = fRec18[0];
			fRec19[1] = fRec19[0];
			fRec16[1] = fRec16[0];
			fRec17[1] = fRec17[0];
			fRec14[1] = fRec14[0];
			fRec15[1] = fRec15[0];
			fRec12[1] = fRec12[0];
			fRec13[1] = fRec13[0];
			fRec10[1] = fRec10[0];
			fRec11[1] = fRec11[0];
			fRec8[1] = fRec8[0];
			IOTA = IOTA+1;
			fRec9[1] = fRec9[0];
		}
	}
};



/***************************END USER SECTION ***************************/

/*******************BEGIN ARCHITECTURE SECTION (part 2/2)***************/

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


//-------------------------------------------------------------------------
// 									MAIN
//-------------------------------------------------------------------------

/********************END ARCHITECTURE SECTION (part 2/2)****************/
