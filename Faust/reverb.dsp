import("music.lib");
import("filter.lib");

monoFreeverb(fb1,fb2,damp,spread) = _ <: par(i,8,lpcf(combtuningL(i),fb1,damp)) :> seq(i,4,allpass_comb(1024,allpasstuningL(i),-fb2))
with{
	lpcf(dt,fb,damp) = (+:delay(2048,dt))~ (*(1-damp) : (+ ~ *(damp)) : *(fb));
	origSR = 44100;
	cTuning = (1116,1188,1277,1356,1422,1491,1557,1617);
	combtuningL(i) = take(i+1,cTuning)*SR/origSR : int : +(spread);
	aTuning = (556,441,341,225);
	allpasstuningL(i) = take(i+1,aTuning)*SR/origSR : int;
};

fb1 = 0.7;
fb2 = 0.7;
damp = 0.5;
spread = 0.5;
process = monoFreeverb(fb1,fb2,damp,0),monoFreeverb(fb1,fb2,damp,spread);