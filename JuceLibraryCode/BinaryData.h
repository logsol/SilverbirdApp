/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#ifndef BINARYDATA_H_16951566_INCLUDED
#define BINARYDATA_H_16951566_INCLUDED

namespace BinaryData
{
    extern const char*   Knob_png;
    const int            Knob_pngSize = 24544;

    extern const char*   Bird_png;
    const int            Bird_pngSize = 109461;

    extern const char*   SB_png;
    const int            SB_pngSize = 8159;

    extern const char*   Background_png;
    const int            Background_pngSize = 430557;

    extern const char*   sine_aif;
    const int            sine_aifSize = 529254;

    extern const char*   hihat1_aif;
    const int            hihat1_aifSize = 11532;

    extern const char*   hihat2_aif;
    const int            hihat2_aifSize = 15152;

    extern const char*   hihat3_aif;
    const int            hihat3_aifSize = 37588;

    extern const char*   hihat4_aif;
    const int            hihat4_aifSize = 82748;

    extern const char*   hihat5_aif;
    const int            hihat5_aifSize = 17708;

    extern const char*   kick1_aif;
    const int            kick1_aifSize = 58764;

    extern const char*   kick2_aif;
    const int            kick2_aifSize = 110132;

    extern const char*   kick3_aif;
    const int            kick3_aifSize = 65084;

    extern const char*   kick4_aif;
    const int            kick4_aifSize = 86028;

    extern const char*   kick5_aif;
    const int            kick5_aifSize = 117728;

    extern const char*   snare1_aif;
    const int            snare1_aifSize = 20292;

    extern const char*   snare2_aif;
    const int            snare2_aifSize = 20920;

    extern const char*   snare3_aif;
    const int            snare3_aifSize = 19116;

    extern const char*   snare4_aif;
    const int            snare4_aifSize = 47364;

    extern const char*   snare5_aif;
    const int            snare5_aifSize = 61520;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Number of elements in the namedResourceList array.
    const int namedResourceListSize = 20;

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes) throw();
}

#endif
