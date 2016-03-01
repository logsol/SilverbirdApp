/*
  ==============================================================================

    Synth.cpp
    Created: 10 Feb 2014 12:08:13am
    Author:  Pannek Karl

  ==============================================================================
*/

#include "Source.h"
#include "Sound.h"
#include "Controller.h"
#include "BinaryData.h"

Source::Source(int trackId, String name, MidiMessageCollector& midiCollector, Controller* controller) :
    midiCollector (midiCollector),
    name (name),
    trackId (trackId),
    sampler(trackId, this, controller),
    controller(controller)
{
    configure(trackId);
    
    
    for (int modTrackId=0; modTrackId < Mixer::mods::max; modTrackId++) {
        modulations.add(0.5);
    }
    
    jassert(modulations.size() == Mixer::mods::max);
}

Source::~Source() {
}

void Source::configure(int trackId)
{
    
    switch (trackId) {
        {
        case Mixer::tracks::kick:
            const int numKicks = 23;
            MemoryInputStream* kicks[numKicks] = {
                //new MemoryInputStream (BinaryData::sine_aif, BinaryData::sine_aifSize, false),
                new MemoryInputStream (BinaryData::kick_01_aif, BinaryData::kick_01_aifSize, false),
                new MemoryInputStream (BinaryData::kick_02_aif, BinaryData::kick_02_aifSize, false),
                new MemoryInputStream (BinaryData::kick_03_aif, BinaryData::kick_03_aifSize, false),
                new MemoryInputStream (BinaryData::kick_04_aif, BinaryData::kick_04_aifSize, false),
                new MemoryInputStream (BinaryData::kick_05_aif, BinaryData::kick_05_aifSize, false),
                new MemoryInputStream (BinaryData::kick_06_aif, BinaryData::kick_06_aifSize, false),
                new MemoryInputStream (BinaryData::kick_07_aif, BinaryData::kick_07_aifSize, false),
                new MemoryInputStream (BinaryData::kick_08_aif, BinaryData::kick_08_aifSize, false),
                new MemoryInputStream (BinaryData::kick_09_aif, BinaryData::kick_09_aifSize, false),
                new MemoryInputStream (BinaryData::kick_10_aif, BinaryData::kick_10_aifSize, false),
                new MemoryInputStream (BinaryData::kick_11_aif, BinaryData::kick_11_aifSize, false),
                new MemoryInputStream (BinaryData::kick_12_aif, BinaryData::kick_12_aifSize, false),
                new MemoryInputStream (BinaryData::kick_13_aif, BinaryData::kick_13_aifSize, false),
                new MemoryInputStream (BinaryData::kick_14_aif, BinaryData::kick_14_aifSize, false),
                new MemoryInputStream (BinaryData::kick_15_aif, BinaryData::kick_15_aifSize, false),
                new MemoryInputStream (BinaryData::kick_16_aif, BinaryData::kick_16_aifSize, false),
                new MemoryInputStream (BinaryData::kick_17_aif, BinaryData::kick_17_aifSize, false),
                new MemoryInputStream (BinaryData::kick_18_aif, BinaryData::kick_18_aifSize, false),
                new MemoryInputStream (BinaryData::kick_19_aif, BinaryData::kick_19_aifSize, false),
                new MemoryInputStream (BinaryData::kick_20_aif, BinaryData::kick_10_aifSize, false),
                new MemoryInputStream (BinaryData::kick_21_aif, BinaryData::kick_21_aifSize, false),
                new MemoryInputStream (BinaryData::kick_22_aif, BinaryData::kick_22_aifSize, false),
                new MemoryInputStream (BinaryData::kick_23_aif, BinaryData::kick_23_aifSize, false)
            };
            setup(Mixer::tracks::kick, 36, numKicks, kicks);
            break;
        }
        {
        case Mixer::tracks::snare:
            const int numSnares = 24;
            MemoryInputStream* snares[numSnares] = {
                new MemoryInputStream (BinaryData::snare_01_aif, BinaryData::snare_01_aifSize, false),
                new MemoryInputStream (BinaryData::snare_02_aif, BinaryData::snare_02_aifSize, false),
                new MemoryInputStream (BinaryData::snare_03_aif, BinaryData::snare_03_aifSize, false),
                new MemoryInputStream (BinaryData::snare_04_aif, BinaryData::snare_04_aifSize, false),
                new MemoryInputStream (BinaryData::snare_05_aif, BinaryData::snare_05_aifSize, false),
                new MemoryInputStream (BinaryData::snare_06_aif, BinaryData::snare_06_aifSize, false),
                new MemoryInputStream (BinaryData::snare_07_aif, BinaryData::snare_07_aifSize, false),
                new MemoryInputStream (BinaryData::snare_08_aif, BinaryData::snare_08_aifSize, false),
                new MemoryInputStream (BinaryData::snare_09_aif, BinaryData::snare_09_aifSize, false),
                new MemoryInputStream (BinaryData::snare_10_aif, BinaryData::snare_10_aifSize, false),
                new MemoryInputStream (BinaryData::snare_11_aif, BinaryData::snare_11_aifSize, false),
                new MemoryInputStream (BinaryData::snare_12_aif, BinaryData::snare_12_aifSize, false),
                new MemoryInputStream (BinaryData::snare_13_aif, BinaryData::snare_13_aifSize, false),
                new MemoryInputStream (BinaryData::snare_14_aif, BinaryData::snare_14_aifSize, false),
                new MemoryInputStream (BinaryData::snare_15_aif, BinaryData::snare_15_aifSize, false),
                new MemoryInputStream (BinaryData::snare_16_aif, BinaryData::snare_16_aifSize, false),
                new MemoryInputStream (BinaryData::snare_17_aif, BinaryData::snare_17_aifSize, false),
                new MemoryInputStream (BinaryData::snare_18_aif, BinaryData::snare_18_aifSize, false),
                new MemoryInputStream (BinaryData::snare_19_aif, BinaryData::snare_19_aifSize, false),
                new MemoryInputStream (BinaryData::snare_20_aif, BinaryData::snare_20_aifSize, false),
                new MemoryInputStream (BinaryData::snare_21_aif, BinaryData::snare_21_aifSize, false),
                new MemoryInputStream (BinaryData::snare_22_aif, BinaryData::snare_22_aifSize, false),
                new MemoryInputStream (BinaryData::snare_23_aif, BinaryData::snare_23_aifSize, false),
                new MemoryInputStream (BinaryData::snare_24_aif, BinaryData::snare_24_aifSize, false)
            };
            setup(Mixer::tracks::snare, 38, numSnares, snares);
            break;
        }
        {
        case Mixer::tracks::hihat:
            const int numHihats = 23;
            MemoryInputStream* hihats[numHihats] = {
                new MemoryInputStream (BinaryData::hihat_01_aif, BinaryData::hihat_01_aifSize, false),
                new MemoryInputStream (BinaryData::hihat_02_aif, BinaryData::hihat_02_aifSize, false),
                new MemoryInputStream (BinaryData::hihat_03_aif, BinaryData::hihat_03_aifSize, false),
                new MemoryInputStream (BinaryData::hihat_04_aif, BinaryData::hihat_04_aifSize, false),
                new MemoryInputStream (BinaryData::hihat_05_aif, BinaryData::hihat_05_aifSize, false),
                new MemoryInputStream (BinaryData::hihat_06_aif, BinaryData::hihat_06_aifSize, false),
                new MemoryInputStream (BinaryData::hihat_07_aif, BinaryData::hihat_07_aifSize, false),
                new MemoryInputStream (BinaryData::hihat_08_aif, BinaryData::hihat_08_aifSize, false),
                new MemoryInputStream (BinaryData::hihat_09_aif, BinaryData::hihat_09_aifSize, false),
                new MemoryInputStream (BinaryData::hihat_10_aif, BinaryData::hihat_10_aifSize, false),
                new MemoryInputStream (BinaryData::hihat_11_aif, BinaryData::hihat_11_aifSize, false),
                new MemoryInputStream (BinaryData::hihat_12_aif, BinaryData::hihat_12_aifSize, false),
                new MemoryInputStream (BinaryData::hihat_13_aif, BinaryData::hihat_13_aifSize, false),
                new MemoryInputStream (BinaryData::hihat_14_aif, BinaryData::hihat_14_aifSize, false),
                new MemoryInputStream (BinaryData::hihat_15_aif, BinaryData::hihat_15_aifSize, false),
                new MemoryInputStream (BinaryData::hihat_16_aif, BinaryData::hihat_16_aifSize, false),
                new MemoryInputStream (BinaryData::hihat_17_aif, BinaryData::hihat_17_aifSize, false),
                new MemoryInputStream (BinaryData::hihat_18_aif, BinaryData::hihat_18_aifSize, false),
                new MemoryInputStream (BinaryData::hihat_19_aif, BinaryData::hihat_19_aifSize, false),
                new MemoryInputStream (BinaryData::hihat_20_aif, BinaryData::hihat_20_aifSize, false),
                new MemoryInputStream (BinaryData::hihat_21_aif, BinaryData::hihat_21_aifSize, false),
                new MemoryInputStream (BinaryData::hihat_22_aif, BinaryData::hihat_22_aifSize, false),
                new MemoryInputStream (BinaryData::hihat_23_aif, BinaryData::hihat_23_aifSize, false)
                
            };
            setup(Mixer::tracks::hihat, 42, numHihats, hihats);
            break;
        }
        {
        case Mixer::tracks::perc1:
            const int numPerc1s = 26;
            MemoryInputStream* perc1s[numPerc1s] = {
                new MemoryInputStream (BinaryData::perc1_01_aif, BinaryData::perc1_01_aifSize, false),
                new MemoryInputStream (BinaryData::perc1_02_aif, BinaryData::perc1_02_aifSize, false),
                new MemoryInputStream (BinaryData::perc1_03_aif, BinaryData::perc1_03_aifSize, false),
                new MemoryInputStream (BinaryData::perc1_04_aif, BinaryData::perc1_04_aifSize, false),
                new MemoryInputStream (BinaryData::perc1_05_aif, BinaryData::perc1_05_aifSize, false),
                new MemoryInputStream (BinaryData::perc1_06_aif, BinaryData::perc1_06_aifSize, false),
                new MemoryInputStream (BinaryData::perc1_07_aif, BinaryData::perc1_07_aifSize, false),
                new MemoryInputStream (BinaryData::perc1_08_aif, BinaryData::perc1_08_aifSize, false),
                new MemoryInputStream (BinaryData::perc1_09_aif, BinaryData::perc1_09_aifSize, false),
                new MemoryInputStream (BinaryData::perc1_10_aif, BinaryData::perc1_10_aifSize, false),
                new MemoryInputStream (BinaryData::perc1_11_aif, BinaryData::perc1_11_aifSize, false),
                new MemoryInputStream (BinaryData::perc1_12_aif, BinaryData::perc1_12_aifSize, false),
                new MemoryInputStream (BinaryData::perc1_13_aif, BinaryData::perc1_13_aifSize, false),
                new MemoryInputStream (BinaryData::perc1_14_aif, BinaryData::perc1_14_aifSize, false),
                new MemoryInputStream (BinaryData::perc1_15_aif, BinaryData::perc1_15_aifSize, false),
                new MemoryInputStream (BinaryData::perc1_16_aif, BinaryData::perc1_16_aifSize, false),
                new MemoryInputStream (BinaryData::perc1_17_aif, BinaryData::perc1_17_aifSize, false),
                new MemoryInputStream (BinaryData::perc1_18_aif, BinaryData::perc1_18_aifSize, false),
                new MemoryInputStream (BinaryData::perc1_19_aif, BinaryData::perc1_19_aifSize, false),
                new MemoryInputStream (BinaryData::perc1_20_aif, BinaryData::perc1_20_aifSize, false),
                new MemoryInputStream (BinaryData::perc1_21_aif, BinaryData::perc1_21_aifSize, false),
                new MemoryInputStream (BinaryData::perc1_22_aif, BinaryData::perc1_22_aifSize, false),
                new MemoryInputStream (BinaryData::perc1_23_aif, BinaryData::perc1_23_aifSize, false),
                new MemoryInputStream (BinaryData::perc1_24_aif, BinaryData::perc1_24_aifSize, false),
                new MemoryInputStream (BinaryData::perc1_25_aif, BinaryData::perc1_25_aifSize, false),
                new MemoryInputStream (BinaryData::perc1_26_aif, BinaryData::perc1_26_aifSize, false)
            };
            setup(Mixer::tracks::perc1, 45, numPerc1s, perc1s);
            break;
        }
        {
        case Mixer::tracks::perc2:
            const int numPerc2s = 29;
            MemoryInputStream* perc2s[numPerc2s] = {
                new MemoryInputStream (BinaryData::perc2_01_aif, BinaryData::perc2_01_aifSize, false),
                new MemoryInputStream (BinaryData::perc2_02_aif, BinaryData::perc2_02_aifSize, false),
                new MemoryInputStream (BinaryData::perc2_03_aif, BinaryData::perc2_03_aifSize, false),
                new MemoryInputStream (BinaryData::perc2_04_aif, BinaryData::perc2_04_aifSize, false),
                new MemoryInputStream (BinaryData::perc2_05_aif, BinaryData::perc2_05_aifSize, false),
                new MemoryInputStream (BinaryData::perc2_06_aif, BinaryData::perc2_06_aifSize, false),
                new MemoryInputStream (BinaryData::perc2_07_aif, BinaryData::perc2_07_aifSize, false),
                new MemoryInputStream (BinaryData::perc2_08_aif, BinaryData::perc2_08_aifSize, false),
                new MemoryInputStream (BinaryData::perc2_09_aif, BinaryData::perc2_09_aifSize, false),
                new MemoryInputStream (BinaryData::perc2_10_aif, BinaryData::perc2_10_aifSize, false),
                new MemoryInputStream (BinaryData::perc2_11_aif, BinaryData::perc2_11_aifSize, false),
                new MemoryInputStream (BinaryData::perc2_12_aif, BinaryData::perc2_12_aifSize, false),
                new MemoryInputStream (BinaryData::perc2_13_aif, BinaryData::perc2_13_aifSize, false),
                new MemoryInputStream (BinaryData::perc2_14_aif, BinaryData::perc2_14_aifSize, false),
                new MemoryInputStream (BinaryData::perc2_15_aif, BinaryData::perc2_15_aifSize, false),
                new MemoryInputStream (BinaryData::perc2_16_aif, BinaryData::perc2_16_aifSize, false),
                new MemoryInputStream (BinaryData::perc2_17_aif, BinaryData::perc2_17_aifSize, false),
                new MemoryInputStream (BinaryData::perc2_18_aif, BinaryData::perc2_18_aifSize, false),
                new MemoryInputStream (BinaryData::perc2_19_aif, BinaryData::perc2_19_aifSize, false),
                new MemoryInputStream (BinaryData::perc2_20_aif, BinaryData::perc2_20_aifSize, false),
                new MemoryInputStream (BinaryData::perc2_21_aif, BinaryData::perc2_21_aifSize, false),
                new MemoryInputStream (BinaryData::perc2_22_aif, BinaryData::perc2_22_aifSize, false),
                new MemoryInputStream (BinaryData::perc2_23_aif, BinaryData::perc2_23_aifSize, false),
                new MemoryInputStream (BinaryData::perc2_24_aif, BinaryData::perc2_24_aifSize, false),
                new MemoryInputStream (BinaryData::perc2_25_aif, BinaryData::perc2_25_aifSize, false),
                new MemoryInputStream (BinaryData::perc2_26_aif, BinaryData::perc2_26_aifSize, false),
                new MemoryInputStream (BinaryData::perc2_27_aif, BinaryData::perc2_27_aifSize, false),
                new MemoryInputStream (BinaryData::perc2_28_aif, BinaryData::perc2_28_aifSize, false),
                new MemoryInputStream (BinaryData::perc2_29_aif, BinaryData::perc2_29_aifSize, false)
            };
            setup(Mixer::tracks::perc2, 48, numPerc2s, perc2s);
            break;
        }
        {
        case Mixer::tracks::tones:
            const int numTones = 30;
            MemoryInputStream* tones[numTones] = {
                new MemoryInputStream (BinaryData::tones_01_aif, BinaryData::tones_01_aifSize, false),
                new MemoryInputStream (BinaryData::tones_02_aif, BinaryData::tones_02_aifSize, false),
                new MemoryInputStream (BinaryData::tones_03_aif, BinaryData::tones_03_aifSize, false),
                new MemoryInputStream (BinaryData::tones_04_aif, BinaryData::tones_04_aifSize, false),
                new MemoryInputStream (BinaryData::tones_05_aif, BinaryData::tones_05_aifSize, false),
                new MemoryInputStream (BinaryData::tones_06_aif, BinaryData::tones_06_aifSize, false),
                new MemoryInputStream (BinaryData::tones_07_aif, BinaryData::tones_07_aifSize, false),
                new MemoryInputStream (BinaryData::tones_08_aif, BinaryData::tones_08_aifSize, false),
                new MemoryInputStream (BinaryData::tones_09_aif, BinaryData::tones_09_aifSize, false),
                new MemoryInputStream (BinaryData::tones_10_aif, BinaryData::tones_10_aifSize, false),
                new MemoryInputStream (BinaryData::tones_11_aif, BinaryData::tones_11_aifSize, false),
                new MemoryInputStream (BinaryData::tones_12_aif, BinaryData::tones_12_aifSize, false),
                new MemoryInputStream (BinaryData::tones_13_aif, BinaryData::tones_13_aifSize, false),
                new MemoryInputStream (BinaryData::tones_14_aif, BinaryData::tones_14_aifSize, false),
                new MemoryInputStream (BinaryData::tones_15_aif, BinaryData::tones_15_aifSize, false),
                new MemoryInputStream (BinaryData::tones_16_aif, BinaryData::tones_16_aifSize, false),
                new MemoryInputStream (BinaryData::tones_17_aif, BinaryData::tones_17_aifSize, false),
                new MemoryInputStream (BinaryData::tones_18_aif, BinaryData::tones_18_aifSize, false),
                new MemoryInputStream (BinaryData::tones_19_aif, BinaryData::tones_19_aifSize, false),
                new MemoryInputStream (BinaryData::tones_20_aif, BinaryData::tones_20_aifSize, false),
                new MemoryInputStream (BinaryData::tones_21_aif, BinaryData::tones_21_aifSize, false),
                new MemoryInputStream (BinaryData::tones_22_aif, BinaryData::tones_22_aifSize, false),
                new MemoryInputStream (BinaryData::tones_23_aif, BinaryData::tones_23_aifSize, false),
                new MemoryInputStream (BinaryData::tones_24_aif, BinaryData::tones_24_aifSize, false),
                new MemoryInputStream (BinaryData::tones_25_aif, BinaryData::tones_25_aifSize, false),
                new MemoryInputStream (BinaryData::tones_26_aif, BinaryData::tones_26_aifSize, false),
                new MemoryInputStream (BinaryData::tones_27_aif, BinaryData::tones_27_aifSize, false),
                new MemoryInputStream (BinaryData::tones_28_aif, BinaryData::tones_28_aifSize, false),
                new MemoryInputStream (BinaryData::tones_29_aif, BinaryData::tones_29_aifSize, false),
                new MemoryInputStream (BinaryData::tones_30_aif, BinaryData::tones_30_aifSize, false)
            };
            setup(Mixer::tracks::tones, 52, numTones, tones);
            break;
        }
        {
        default:
            break;
        }
    }
}

void Source::setup(int index, int note, int numSounds, MemoryInputStream* streams[])
{
    sampler.clearSounds();
    
    AiffAudioFormat aifFormat;
    ScopedPointer<AudioFormatReader> sampleReader;
    
    for(int i = 0; i < numSounds; i++) {
        sampleReader = aifFormat.createReaderFor (streams[i], true);
        sampler.addSound(new Sound ("sound", note, i, *sampleReader, 0.9, 0.2));
    }
}

void Source::updateSampleRate(int sampleRate) {
    sampler.setCurrentPlaybackSampleRate(sampleRate);
}

void Source::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    midiCollector.reset (sampleRate);
    updateSampleRate(sampleRate);
    this->sampleRate = sampleRate;
}

void Source::releaseResources()
{
}

void Source::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{
    // calculations
    float trackCutoff  = controller->getParameterValueScaled(Controller::params::cutoff, trackId);
    float trackDistort = controller->getParameterValueScaled(Controller::params::distort, trackId);
    float trackLevel   = controller->getParameterValueScaled(Controller::params::level, trackId);
    float trackMute    = controller->getParameterValueScaled(Controller::params::mute, trackId);
    
    float globalCutoff = controller->getParameterValueScaled(Controller::params::cutoff);
    float globalDistort = controller->getParameterValueScaled(Controller::params::distort);
    
    float modulationCutoff = Parameter::scale(Controller::params::cutoff, true, modulations[Mixer::mods::cutoff]);
    
    float cutoff = fmax(0, fmin(1, trackCutoff + globalCutoff + modulationCutoff));
    float distort = 1 - fmax(0, fmin(0.93, trackDistort + globalDistort));
    float level = trackLevel * !trackMute;
    
    // setup
    bufferToFill.clearActiveBufferRegion();
    midiCollector.removeNextBlockOfMessages (incomingMidi, bufferToFill.numSamples);

    // render sampler
    sampler.renderNextBlock(*bufferToFill.buffer, incomingMidi, 0, bufferToFill.numSamples);
    
    // dsp: distortion
    float* outL = bufferToFill.buffer->getWritePointer (0, 0);
    float* outR = bufferToFill.buffer->getWritePointer (1, 0);

    for (int i=bufferToFill.numSamples; i>=0; --i) {
        outL[i] = foldback(outL[i], distort);
        outR[i] = foldback(outR[i], distort);
    }

    // dsp: filter
    filterL.setCoefficients(IIRCoefficients::makeLowPass(sampleRate, MidiMessage::getMidiNoteInHertz(cutoff * 128)));
    filterR.setCoefficients(IIRCoefficients::makeLowPass(sampleRate, MidiMessage::getMidiNoteInHertz(cutoff * 128)));
    filterL.processSamples(bufferToFill.buffer->getWritePointer(0), bufferToFill.buffer->getNumSamples());
    filterR.processSamples(bufferToFill.buffer->getWritePointer(1), bufferToFill.buffer->getNumSamples());
                               
    // dsp: level
    bufferToFill.buffer->applyGainRamp(0, bufferToFill.numSamples, lastLevel, level);
    lastLevel = level;
}

/*
 * fold back distortion
 *
 * Type : distortion
 * References : Posted by hellfire[AT]upb[DOT]de
 *
 * http://musicdsp.org/archive.php?classid=4#203
 */
float Source::foldback(float in, float threshold)
{
    if (in>threshold || in<-threshold)
    {
        in= fabs(fabs(fmod(in - threshold, threshold*4)) - threshold*2) - threshold;
    }
    return in;
}

int Source::getNumberOfSounds()
{
    return sampler.getNumberOfSounds();
}

void Source::resetStepModulations()
{
    for (int i=0; i<modulations.size(); i++) {
        modulations.set(i, 0.5);
    }
}

void Source::addStepModulationValue(int modTrackId, float value)
{
    jassert(isPositiveAndBelow(modTrackId, modulations.size()));
    
    float cache = modulations[modTrackId];
    
    modulations.set(modTrackId, cache + value - 0.5);
}
