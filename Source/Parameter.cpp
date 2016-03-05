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
    // set trackid -1 to global true
    global = trackId < 0;
    
    createName();
    
    setValue(getDefaultValue());
}

Parameter::~Parameter()
{
}

String Parameter::createName()
{
    String paramName = getParamName();
    
    if (global) {
        name = "Global " + paramName;
        return name;
    }
    
    name = Mixer::getNameByTrackId(trackId) + " " + paramName;
    
    return name;
}

float Parameter::getScaledValue()
{
    float value = getValue();
    
    return scale(paramNameId, global, value, numSoundsTrack);
}

float Parameter::scale(int paramNameId, bool isGlobal, float value, int numSoundsTrack)
{
    switch (paramNameId) {
            
        case Controller::params::shuffle:
            return value;
            break;
            
        case Controller::params::level:
            return value;
            break;
            
        case Controller::params::pan:
            return value;
            break;
            
        case Controller::params::mute:
            return round(value);
            break;
            
        case Controller::params::reverb:
            return value;
            break;
            
            
        case Controller::params::delay:
            return value;
            break;
            
        case Controller::params::sample:
            if(!isGlobal && numSoundsTrack == -1) {
                std::cout << "Warn: calling scale() without numSounds!" << std::endl;
            }
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

std::string Parameter::getDisplayValue()
{
    float value = getValue();
    
    switch (paramNameId) {
            
        case Controller::params::shuffle: {
            return std::to_string((int) floor(value * 100));
        }
            
        case Controller::params::level: {
            return std::to_string((int) floor(value * 100));
        }
            
        case Controller::params::pan: {
            int panning = 50 - floor(value * 100);
            return panning == 0 ? "C" : std::to_string(abs(panning)) + (panning > 0 ? "L" : "R");
        }
            
        case Controller::params::mute: {
            return std::to_string((int) round(value));
        }
            
        case Controller::params::reverb: {
            return std::to_string((int) floor(value * 100));
        }
            
        case Controller::params::delay: {
            return std::to_string((int) floor(value * 100));
        }
            
        case Controller::params::sample: {
            if(!global && numSoundsTrack == -1) {
                std::cout << "Warn: calling getDisplayValue() without numSounds!" << std::endl;
            }
            return std::to_string(global
            ? (int) floor(Mixer::SelectAllOffset * (value - 0.5))
            : (int) round(numSoundsTrack * value));
        }
            
        case Controller::params::pitch: {
            return std::to_string((int) round((value-0.5) * 24.0));
        }
            
        case Controller::params::attack: {
            return std::to_string(global
            ? (int) floor((value - 0.5) * 100)
            : (int) floor(value * 100));
        }
            
        case Controller::params::decay: {
            return std::to_string(global
            ? (int) floor((value - 0.5) * 100)
            : (int) floor(value * 100));
        }
            
        case Controller::params::distort: {
            return std::to_string(global
            ? (int) floor((value - 0.5) * 100)
            : (int) floor(value * 100));
        }
            
        case Controller::params::cutoff: {
            return std::to_string(global
            ? (int) floor((value - 0.5) * 100)
            : (int) floor(value * 100));
        }
            
        default: {
            return std::to_string(value);
        }
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
            defaultValue = global
                ? 1.0f
                : 0.7f; // 0.25 for clipping free..
            break;
            
        case Controller::params::pan:
            defaultValue = 0.5;
            break;
            
        case Controller::params::mute:
            defaultValue = 0.0;
            break;
            
        case Controller::params::reverb:
            defaultValue = 0.0;
            break;
            
        case Controller::params::delay:
            defaultValue = 0.0;
            break;
            
        case Controller::params::sample:
            defaultValue = global
            ? floor((Mixer::SelectAllOffset - 1) * 0.5) / (Mixer::SelectAllOffset - 1)
            : 0; //floor((numSoundsTrack - 1) * 0.5) / (numSoundsTrack - 1); //estimates center
            break;
            
        case Controller::params::pitch:
            defaultValue = 0.5;
            break;
            
        case Controller::params::attack:
            defaultValue = global
                ? 0.5
                : 0;
            break;
            
        case Controller::params::decay:
            defaultValue = global
                ? 0.5
                : 1;
            break;
            
        case Controller::params::distort:
            defaultValue = global
                ? 0.5
                : 0;
            break;
            
        case Controller::params::cutoff:
            defaultValue = global
                ? 0.5
                : 1;
            break;
            
        default:
            defaultValue = 0;
            break;
    }
    
    return defaultValue;
}

String Parameter::getParamName()
{
    String paramName;
    switch (paramNameId) {
            
        case Controller::params::shuffle:
            paramName = "Shuffle";
            break;
            
        case Controller::params::level:
            paramName = "Level";
            break;
            
        case Controller::params::pan:
            paramName = "Pan";
            break;
            
        case Controller::params::mute:
            paramName = "Mute";
            break;
            
        case Controller::params::reverb:
            paramName = "Reverb";
            break;
            
        case Controller::params::delay:
            paramName = "Delay";
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
    
    return paramName;
}

String Parameter::getName()
{
    return name;
}

bool Parameter::isGlobal()
{
    return global;
}