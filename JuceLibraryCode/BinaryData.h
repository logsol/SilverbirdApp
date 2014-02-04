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

    extern const char*   _909norm_wav;
    const int            _909norm_wavSize = 17084;

    extern const char*   Frecker_aif;
    const int            Frecker_aifSize = 230454;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Number of elements in the namedResourceList array.
    const int namedResourceListSize = 6;

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes) throw();
}

#endif
