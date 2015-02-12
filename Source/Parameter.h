/*
  ==============================================================================

    Parameter.h
    Created: 11 Feb 2015 9:54:27pm
    Author:  Karl

  ==============================================================================
*/

#ifndef PARAMETER_H_INCLUDED
#define PARAMETER_H_INCLUDED

#include "JuceHeader.h"

class Parameter : public Value
{
public:
    Parameter(int parameterId, int paramNameId, int trackId = -1, int cellId = -1);
    ~Parameter();
    
    int parameterId;
    int paramNameId;
    bool isGlobal;
    String name;
    int trackId;
    int cellId;
    
protected:
    String createName();
};

#endif  // PARAMETER_H_INCLUDED
