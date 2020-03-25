/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SynthFrameworkAudioProcessor::SynthFrameworkAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
                    //AMBRIOSO
                     attackTime(0.1f),
                     decayTime(0.1f),
                     sustainTime(0.1f),
                     releaseTime(0.1f),
                     state(*this, nullptr)
#endif
{
    NormalisableRange<float> attackParam (0.1f, 5000.0f);
    NormalisableRange<float> decayParam(1.0f, 2000.0f);
    NormalisableRange<float> sustainParam (0.1f, 1.0f);
    NormalisableRange<float> releaseParam(0.1f, 5000.0f);
    
    
    state.createAndAddParameter("attack", "Attack", "Attack", attackParam, 1200.0f, nullptr, nullptr);
    state.createAndAddParameter("decay", "Decay", "Decay", decayParam, 1000.0f, nullptr, nullptr);
    state.createAndAddParameter("sustain", "Sustain", "Sustain", sustainParam, 0.5f, nullptr, nullptr);
    state.createAndAddParameter("release", "Release", "Release", releaseParam, 1200.0f, nullptr, nullptr);
    
    NormalisableRange<float> waveTypeParam(0, 5);
    state.createAndAddParameter("wavetype", "WaveType", "wavetype", waveTypeParam, 0, nullptr, nullptr);
    
    NormalisableRange<float> filterTypeVal(0, 2);
    NormalisableRange<float> filterVal (20.0f, 2000.0f);
    NormalisableRange<float> resVal(1, 5);
    state.createAndAddParameter("filterType", "FilterType", "filterType", filterTypeVal, 0, nullptr, nullptr);
    state.createAndAddParameter("filterCutoff", "FilterCutoff", "filterCutoff", filterVal, 2000.0f, nullptr, nullptr);
    state.createAndAddParameter("filterRes", "FilterRes", "filterRes", resVal, 1, nullptr, nullptr);
    
    
    mySynth.clearVoices();
    
    for (int i = 0; i < 5; i++)
    {
        mySynth.addVoice(new SynthVoice());
    }
    
    mySynth.clearSounds();
    mySynth.addSound(new SynthSound());
    
}

SynthFrameworkAudioProcessor::~SynthFrameworkAudioProcessor()
{
}

//==============================================================================
const String SynthFrameworkAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SynthFrameworkAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SynthFrameworkAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SynthFrameworkAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double SynthFrameworkAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SynthFrameworkAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SynthFrameworkAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SynthFrameworkAudioProcessor::setCurrentProgram (int index)
{
}

const String SynthFrameworkAudioProcessor::getProgramName (int index)
{
    return {};
}

void SynthFrameworkAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void SynthFrameworkAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    
    // prevents samples from previous key press from playing
    ignoreUnused(samplesPerBlock);
    
    // in case sample rate changes unexpectedly, prevents crash
    lastSampleRate = sampleRate;
    mySynth.setCurrentPlaybackSampleRate(lastSampleRate);
    
    
    // for dsp filter module
    dsp::ProcessSpec spec;
    spec.sampleRate = lastSampleRate;
    spec.maximumBlockSize = samplesPerBlock;
    spec.numChannels = getTotalNumOutputChannels();
    
    stateVariableFilter.reset();
    stateVariableFilter.prepare(spec);
    updateFilter();
    
}

void SynthFrameworkAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SynthFrameworkAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

// what happens for each type of filter
void SynthFrameworkAudioProcessor::updateFilter()
{
    int menuChoice = *state.getRawParameterValue("filterType");
    int freq = *state.getRawParameterValue("filterCutoff");
    int res = *state.getRawParameterValue("filterRes");
    
    if (menuChoice == 0)
    {
        stateVariableFilter.state->type = dsp::StateVariableFilter::Parameters<float>::Type::lowPass;
        stateVariableFilter.state->setCutOffFrequency(lastSampleRate, freq, res);
    }
    
    if (menuChoice == 1)
    {
        stateVariableFilter.state->type = dsp::StateVariableFilter::Parameters<float>::Type::highPass;
        stateVariableFilter.state->setCutOffFrequency(lastSampleRate, freq, res);
    }
    
    if (menuChoice == 2)
    {
        stateVariableFilter.state->type = dsp::StateVariableFilter::Parameters<float>::Type::bandPass;
        stateVariableFilter.state->setCutOffFrequency(lastSampleRate, freq, res);
    }
}

void SynthFrameworkAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    for (int i = 0; i < mySynth.getNumVoices(); i++)
    {
        if ((myVoice = dynamic_cast<SynthVoice*>(mySynth.getVoice(i))))
        {
            myVoice->getEnvelopeParams(state.getRawParameterValue("attack"), state.getRawParameterValue("decay"), state.getRawParameterValue("sustain"), state.getRawParameterValue("release"));
            
            myVoice->getOscType(state.getRawParameterValue("wavetype"));
            
            myVoice->getFilterParams(state.getRawParameterValue("filterType"), state.getRawParameterValue("filterCutoff"), state.getRawParameterValue("filterRes"));
        }
    }
    
    
    
    
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
    }
    
    mySynth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
    updateFilter();
    dsp::AudioBlock<float> block (buffer);
    stateVariableFilter.process(dsp::ProcessContextReplacing<float> (block));
}

//==============================================================================
bool SynthFrameworkAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* SynthFrameworkAudioProcessor::createEditor()
{
    return new SynthFrameworkAudioProcessorEditor (*this);
}

//==============================================================================
void SynthFrameworkAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void SynthFrameworkAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SynthFrameworkAudioProcessor();
}
