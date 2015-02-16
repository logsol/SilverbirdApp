/*
  ==============================================================================

    Parameter.cpp
    Created: 11 Feb 2015 9:54:27pm
    Author:  Karl

  ==============================================================================
*/

#include "Parameter.h"
#include "Controller.h"
#include "Mixer.h"

Parameter::Parameter(int parameterId, int paramNameId, int trackId, int numSoundsTrack, int cellId)
  : parameterId(parameterId),
    paramNameId(paramNameId),
    trackId(trackId),
    numSoundsTrack(numSoundsTrack),
    cellId(cellId)
{
    isGlobal = trackId < 0;
    
    createName();
    
    setValue(getDefaultValue());
}

Parameter::~Parameter()
{
}

String Parameter::createName()
{
    String paramName;
    switch (paramNameId) {
            
        case Controller::params::shuffle:
            paramName = "Shuffle";
            break;
            
        case Controller::params::level:
            paramName = "Level";
            break;
            
        case Controller::params::mute:
            paramName = "Mute";
            break;
            
        case Controller::params::sample:
            paramName = "Sample";
            break;
            
        case Controller::params::pitch:
            paramName = "Pitch";
            break;
            
        case Controller::params::attack:
            paramName = "Attack";
            break;
            
        case Controller::params::decay:
            paramName = "Decay";
            break;
            
        case Controller::params::distort:
            paramName = "Distort";
            break;
            
        case Controller::params::cutoff:
            paramName = "Cutoff";
            break;
            
        default:
            paramName = "<Unknown>";
            break;
    }
    
    if (isGlobal) {
        name = "Global " + paramName;
        return name;
    }
    
    name = Mixer::getNameByTrackId(trackId) + " " + paramName;
    name = name.substring(0, 1).toUpperCase() + name.substring(1);
    
    return name;
}

float Parameter::getScaledValue()
{
    float value = getValue();
    
    switch (paramNameId) {
            
        case Controller::params::shuffle:
            return value;
            break;
            
        case Controller::params::level:
            return value;
            break;
            
        case Controller::params::mute:
            return round(value);
            break;
            
        case Controller::params::sample:
            return isGlobal
                ? floor(Mixer::SelectAllOffset * (value - 0.5))
                : floor(numSoundsTrack * value);
            break;
            
        case Controller::params::pitch:
            return (round(value * 24.0) / 24.0 - 0.5) * 2;
            break;
            
        case Controller::params::attack:
            return isGlobal
                ? value - 0.5
                : value;
            break;
            
        case Controller::params::decay:
            return isGlobal
                ? value - 0.5
                : value;
            break;
            
        case Controller::params::distort:
            return isGlobal
                ? value - 0.5
                : value;
            break;
            
        case Controller::params::cutoff:
            return isGlobal
                ? value - 0.5
                : value;
            break;
            
        default:
            return value;
            break;
    }
}

float Parameter::getDefaultValue()
{
    float defaultValue;
    
    switch (paramNameId) {
            
        case Controller::params::shuffle:
            defaultValue = 0;
            break;
            
        case Controller::params::level:
            defaultValue = isGlobal
                ? 0.83
                : 0.8;
            break;
            
        case Controller::params::mute:
            defaultValue = 0.0;
            break;
            
        case Controller::params::sample:
            defaultValue = isGlobal
            ? floor((Mixer::SelectAllOffset - 1) * 0.5) / (Mixer::SelectAllOffset - 1)
            : floor((numSoundsTrack - 1) * 0.5) / (numSoundsTrack - 1);
            break;
            
        case Controller::params::pitch:
            defaultValue = 0.5;
            break;
            
        case Controller::params::attack:
            defaultValue = isGlobal
                ? 0.5
                : 0;
            break;
            
        case Controller::params::decay:
            defaultValue = isGlobal
                ? 0.5
                : 1;
            break;
            
        case Controller::params::distort:
            defaultValue = isGlobal
                ? 0.5
                : 0;
            break;
            
        case Controller::params::cutoff:
            defaultValue = isGlobal
                ? 0.5
                : 1;
            break;
            
        default:
            defaultValue = 0;
            break;
    }
    
    return defaultValue;
}