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
    Parameter(int parameterId, int paramNameId, int trackId = -1, int numSoundsTrack = 0, int cellId = -1);
    ~Parameter();
    
    int parameterId;
    int paramNameId;
    bool global;
    String name;
    int trackId;
    int numSoundsTrack;
    int cellId;
    
    float getScaledValue();
    float getDisplayValue();
    float getDefaultValue();
    
    static float scale(int paramNameId, bool isGlobal, float value, int numSoundsTrack = -1);
    
    String getName();
    bool isGlobal();
    
protected:
    String createName();
    String getParamName();
};

#endif  // PARAMETER_H_INCLUDED
