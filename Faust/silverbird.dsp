import("music.lib");
import("filter.lib");
import("effect.lib");

dist = +(offset) : *(pregain) : clip(-1,1) : cubic : dcblocker
with {
	drive = 0.8;
	offset = 0.05;
	pregain = pow(10,drive*2);
	clip(lo,hi) = min(hi) : max(lo);
	cubic(x) = x - x*x*x/3;
};


filter = +~(delay(2048,delLength)*(-a1))
with{
	a1 = hslider("a1",0,-1,0.999,0.001) : smooth(0.999);
	delLength = hslider("delLength",1,1,2000,1);
};

dist2 = dist,dist;
filter2 = filter,filter;

distortions = dist2,dist2,dist2,  dist2,dist2,dist2;
filters = filter2,filter2,filter2,  filter2,filter2,filter2;

fxReverb = _ <: par(i,8,lpcf(combtuningL(i),fb1,damp)) :> seq(i,4,allpass_comb(1024,allpasstuningL(i),-fb2))
with{
	fb1 = 0.7;
	fb2 = 0.7;
	damp = 0.5;
	spread = 0.5;
	lpcf(dt,fb,damp) = (+:delay(2048,dt))~ (*(1-damp) : (+ ~ *(damp)) : *(fb));
	origSR = 44100;
	cTuning = (1116,1188,1277,1356,1422,1491,1557,1617);
	combtuningL(i) = take(i+1,cTuning)*SR/origSR : int : +(spread);
	aTuning = (556,441,341,225);
	allpasstuningL(i) = take(i+1,aTuning)*SR/origSR : int;
};

fxDelay = +~(fdelay2(65536,delLength)*feedback*-1)
with {
	delLength = 500 : *(0.001) : *(SR);
	feedback = 0.3;
};


compressor = _ <: _*(amp_follower_ud(att,rel) : linear2db : outminusindb : kneesmooth : visualizer : db2linear)*gain 
with{
	ratio = 2;
	thresh = -30;
	att = 20;
	rel = 20;
	kneeAtt = 10;
	gain = 40 : db2linear;
	outminusindb(level) = max(level-thresh,0)*(1/ratio-1);
	kneesmooth = smooth(tau2pole(kneeAtt));
	visualizer = hbargraph("[1]Compressor Level [unit:dB]",-50,10);
};

pan = *(0.4),*(0.6); 
gain = *(0.5), *(0.5);
channelStrip = gain : pan;

process = _,_,_,_, _,_,_,_, _,_,_,_ : distortions : filters 
		  <: 
		  ((_,_,_,_, _,_,_,_, _,_,_,_) :> fxReverb,fxReverb : channelStrip), 
		  ((_,_,_,_, _,_,_,_, _,_,_,_) :> fxDelay,fxDelay : channelStrip), 
		  (_,_,_,_, _,_,_,_, _,_,_,_ : channelStrip,channelStrip,channelStrip,channelStrip,channelStrip,channelStrip)
		  :> _,_ : compressor,compressor;