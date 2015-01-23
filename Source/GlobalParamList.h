/*
  ==============================================================================

    GlobalParamList.h
    Created: 21 Jan 2015 9:43:33pm
    Author:  Karl

  ==============================================================================
*/

#ifndef GLOBALPARAMLIST_H_INCLUDED
#define GLOBALPARAMLIST_H_INCLUDED

struct globalParamList {
    int sample = 0;
    float pitch = 0;
    float decay = 1;
    float distort = 0;
    float cutoff = 1;
    float shuffle = 0;
    float master = 1;
};

#endif  // GLOBALPARAMLIST_H_INCLUDED
