import("filter.lib");
import("music.lib");

/*
faust -cn Delay -i -a architecture/juce-audiosource.cpp delay.dsp > ../Source/DelayAudioSource.cpp

delLength = hslider("[1]time", 50, 1, 100, 1) : *(0.001) : *(SR) : smooth(tau2pole(flexi));
feedback = hslider("[2]feedback", 0, 0, 0.99, 0.001) : smooth(tau2pole(flexi));
flexi = hslider("[3]flex", 0.2, 0.01, 1, 0.01);
*/

delLength = 500 : *(0.001) : *(SR);
feedback = 0.3;

del = +~(fdelay2(65536,delLength)*feedback*-1);

process = del,del;