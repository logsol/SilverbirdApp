/*
  ==============================================================================

    Controller.cpp
    Created: 9 Mar 2014 3:22:47pm
    Author:  Pannek Karl

  ==============================================================================
*/

#include "Controller.h"
#include "Ui.h"


Controller::Controller() : mixer(this),
                           clock(this)//,
                           //document(String("document")) // sets document root name
{
    int parameterId = 0;
    
    for (int paramNameId = 0; paramNameId < Controller::params::max; ++paramNameId) {
        Parameter* p = new Parameter(parameterId, paramNameId);
        parameters.add(p);
        parameterId++;
    }
    
    for (int trackId = 0; trackId < Mixer::tracks::max; ++trackId) {
        for (int paramNameId = 0; paramNameId < Controller::params::max; ++paramNameId) {
            Parameter* p = new Parameter(parameterId, paramNameId, trackId, mixer.getNumberOfSoundsByTrack(trackId));
            parameters.add(p);
            parameterId++;
        }
    }
    
    //document.addListener(this);
    
    //createDocument();
}

Controller::~Controller()
{
}

void Controller::addClockListener(ClockListener* listener)
{
    clock.addListener(listener);
}

void Controller::removeClockListener(ClockListener* listener)
{
    clock.removeListener(listener);
}

bool Controller::togglePlayPause()
{
    return clock.togglePlayPause();
}

void Controller::setPlayPause(bool play)
{
    clock.setPlayPause(play);
}

void Controller::setBpm(float bpm)
{
    clock.setBpm(bpm);
}

float Controller::getBpm()
{
    return clock.getBpm();
}

void Controller::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    mixer.prepareToPlay(samplesPerBlock, sampleRate);
}

void Controller::processBlock(AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    // Getting the audio data from the mixer
    AudioSourceChannelInfo channelInfo (&buffer, 0, buffer.getNumSamples());
    mixer.getNextAudioBlock(channelInfo);
    
    if (!JUCEApplication::isStandaloneApp()) {
        
        AudioPlayHead::CurrentPositionInfo info;
        getPlayHead()->getCurrentPosition(info);
        if (positionInfo.isPlaying != info.isPlaying) {
            setPlayPause(info.isPlaying);
        }
        if (positionInfo.bpm != info.bpm) {
            setBpm(info.bpm);
        }
        positionInfo = info;
        
        // merging incoming midi (from host) into midiCollector
        MidiBuffer::Iterator iterator(midiMessages);
        MidiMessage result;
        int position;
        
        while (iterator.getNextEvent(result, position)) {
            mixer.midiCollector.addMessageToQueue(result);
        }
    
    }

    float shuffle = getParameter(getParameterId(Controller::params::shuffle));
    
    clock.tick(shuffle, buffer, getSampleRate());
}

AudioProcessorEditor* Controller::createEditor()
{
    ui = new Ui (this);
    return ui;
}

float Controller::getParameter (int index)
{
    return (float) parameters[index]->getValue();
}

void Controller::setParameter (int index, float newValue)
{
    Value value = *parameters[index];
    value.setValue(newValue);
}

int Controller::getParameterId(int paramNameId, int trackId, int cellId)
{
    // trackId -1 means it's global
    
    if (trackId != -1) {
        if (cellId != -1) {
        }
        
        return (trackId + 1) * Controller::params::max + paramNameId;
    }
    
    return paramNameId;
}

Parameter* Controller::getParameterByAttrs(int paramNameId, int trackId, int cellId)
{
    for (int i = 0; i < parameters.size(); ++i) {
        Parameter* parameter = parameters.getUnchecked(i);
        if (parameter && parameter->paramNameId == paramNameId
            && parameter->trackId == trackId
            && parameter->cellId == cellId) {
            return parameter;
        }
    }
    
    return nullptr; // FIXME : should not crash here (create if() everywhere this method is called)
}

const String Controller::getParameterName (int index)
{
    return parameters.getUnchecked(index)->name;
}

const String Controller::getParameterText (int index)
{
    return (String) parameters.getUnchecked(index)->getScaledValue();
}

int Controller::getNumParameters()
{
    return parameters.size();
}

void Controller::getStateInformation (MemoryBlock& destData)
{
    //copyXmlToBinary();
}

void Controller::setStateInformation (const void* data, int sizeInBytes)
{
    //getXmlFromBinary();
}

void Controller::sliderValueChanged(Slider *slider)
{
    onGuiParameterChange(slider->getValueObject());
}

void Controller::buttonClicked (Button* button)
{
    onGuiParameterChange(button->getToggleStateValue());
}

void Controller::onGuiParameterChange (Value& value)
{
    for (int i=0; i < parameters.size(); i++) {
        Parameter* p = parameters.getUnchecked(i);
        if (p->refersToSameSourceAs(value)) {
            setParameterNotifyingHost(p->parameterId, p->getValue());   
            return;
        }
    }
    std::cout << "Warn: Value in none of the parameters." << std::endl;
}

void Controller::setTrackFocus(int trackId)
{
    //gui->setTrackFocus(trackId);
}

Sequencer* Controller::getMidiSequencerByTrackId(int trackId)
{
    return clock.getMidiSequencerByTrackId(trackId);
}

Sequencer* Controller::getModulationSequencerByTrackId(int trackId)
{
    return clock.getModulationSequencerByTrackId(trackId);
}

void Controller::saveDocument()
{
    /*
    document.removeAllChildren(&undoManager);
    
    ValueTree meta(String("meta"));
    document.addChild(meta, -1, &undoManager);
    meta.setProperty(String("version"), ProjectInfo::versionString, &undoManager);
    meta.setProperty(String("preset"), "", &undoManager);

    
    ValueTree global(String("global"));
    document.addChild(global, -1, &undoManager);
    
    ValueTree parameters(String("parameters"));
    global.addChild(parameters, -1, &undoManager);
    
    ValueTree parameter(String("parameter"));
    parameters.addChild(parameter, -1, &undoManager);
    parameter.setProperty("name", "Global Bpm", &undoManager);
    parameter.setProperty("value", getBpm(), &undoManager);
    
    
    
    for (int j=0; j<this->parameters.size(); j++) {
        
        ValueTree parameter(String("parameter"));
        parameters.addChild(parameter, -1, &undoManager);
        
        Parameter* p = this->parameters.getUnchecked(j);
        
        if (!p->isGlobal()) {
            continue;
        }
        
        parameter.setProperty("name", p->getName(), &undoManager);
        parameter.setProperty("value", p->getValue(), &undoManager);
    }
    
    ValueTree tracks(String("tracks"));
    global.addChild(tracks, -1, &undoManager);
    
    for (int trackId=0; trackId < Mixer::tracks::max; trackId++) {
        
        ValueTree track(String("track"));
        tracks.addChild(track, -1, &undoManager);
        
        ValueTree parameters(String("parameters"));
        track.addChild(parameters, -1, &undoManager);
    
        String name = mixer.getNameByTrackId(trackId);
        track.setProperty(String("id"), trackId, &undoManager);
        track.setProperty(String("name"), name, &undoManager);
        
        for (int j=0; j<Controller::params::max; j++) {
            
            ValueTree parameter(String("parameter"));
            parameters.addChild(parameter, -1, &undoManager);
            
            Parameter* p = this->parameters.getUnchecked(getParameterId(j, trackId));
            
            parameter.setProperty("name", p->getName(), &undoManager);
            parameter.setProperty("value", p->getValue(), &undoManager);
            
            
        }
        
        
    }
    
    ValueTree sequencer(String("sequencer"));
    document.addChild(sequencer, -1, &undoManager);
    
    ValueTree patterns(String("patterns"));
    sequencer.addChild(patterns, -1, &undoManager);
    
    ValueTree pattern(String("pattern"));
    patterns.addChild(pattern, -1, &undoManager);
    pattern.setProperty(String("id"), "A", &undoManager);

    
    ValueTree velocities(String("velocities"));
    pattern.addChild(velocities, -1, &undoManager);
    
    ValueTree tracks2(String("tracks"));
    velocities.addChild(tracks2, -1, &undoManager);
    
    for (int trackId=0; trackId < Mixer::tracks::max; trackId++) {
        ValueTree track(String("track"));
        
        String name = mixer.getNameByTrackId(trackId);
        
        track.setProperty(String("id"), trackId, &undoManager);
        track.setProperty(String("name"), name, &undoManager);
        
        ValueTree cells(String("cells"));
        track.addChild(cells, -1, &undoManager);
        
        for (int cellId=0; cellId < this->sequencer.getNumCells(); cellId++) {
            ValueTree cell(String("cell"));
            cell.setProperty(String("position"), cellId, &undoManager);
            cell.setProperty(String("velocity"), this->sequencer.getCells(trackId).getUnchecked(cellId), &undoManager);
            
            cells.addChild(cell, -1, &undoManager);
        }
        
        tracks2.addChild(track, -1, &undoManager);
    }
    
    ValueTree modulations(String("modulations"));
    pattern.addChild(modulations, -1, &undoManager);
    
    std::cout << "-------- -------- -------- -------- --------- --------" << std::endl;
    //std::cout << document.toXmlString() << std::endl;
    
    bool isIos = (SystemStats::getOperatingSystemType() == SystemStats::OperatingSystemType::iOS);
    
    if (!isIos) {
        std::cout << "save in non ios system not implemented yet";
        return;
    }

    // begin ios save experiment

    File home(getenv("HOME"));
    File documents(home.getChildFile("Documents"));
    File startup(documents.getChildFile("startup.xml"));

    if(!startup.existsAsFile()) {
        startup.create();
    }
    
    DirectoryIterator di(documents, true, "*", File::TypesOfFileToFind::findFilesAndDirectories);
    
    startup.replaceWithText(document.toXmlString());
     */
}

void Controller::loadDocument()
{
    File home(getenv("HOME"));
    File documents(home.getChildFile("Documents"));
    File startup(documents.getChildFile("startup.xml"));
    
    if (!startup.existsAsFile()) {
        return;
    }

    XmlDocument myDocument (startup);
    XmlElement xml (*myDocument.getDocumentElement());
    document = document.fromXml(xml);
}

void Controller::createDocument()
{
    
}

float Controller::getParameterValue(int paramNameId, int trackId)
{
    return parameters.getUnchecked(getParameterId(paramNameId, trackId))->getValue();
}

float Controller::getParameterValueScaled(int paramNameId, int trackId)
{
    return parameters.getUnchecked(getParameterId(paramNameId, trackId))->getScaledValue();
}

void Controller::resetStepModulations()
{
    mixer.resetStepModulations();
}

void Controller::addStepModulationValue(int paramId, float value, int trackId)
{
    mixer.addStepModulationValue(paramId, value, trackId);
}

/*
void Controller::valueTreePropertyChanged (ValueTree& treeWhosePropertyHasChanged, const Identifier& property)
{
    std::cout << "valueTreePropertyChanged" << &property << std::endl;
}
 */


//==============================================================================
// This creates new instances of the plugin..

AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Controller();
}
