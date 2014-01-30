/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#ifndef BINARYDATA_H_16951566_INCLUDED
#define BINARYDATA_H_16951566_INCLUDED

namespace BinaryData
{
    extern const char*   _909norm_wav;
    const int            _909norm_wavSize = 17084;

    extern const char*   Frecker_aif;
    const int            Frecker_aifSize = 230454;

    extern const char*   Background_png;
    const int            Background_pngSize = 430557;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Number of elements in the namedResourceList array.
    const int namedResourceListSize = 3;

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes) throw();
}

#endif
