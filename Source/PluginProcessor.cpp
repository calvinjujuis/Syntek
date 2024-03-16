/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "Syntek_Synth.h"
#include "Constants.h"

//==============================================================================
SyntekAudioProcessor::SyntekAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ), apvts(*this, nullptr, "Parameters", _createParameters())
#endif
{
	synth = std::make_unique<Syntek_Synth>();
	apvts.state.addListener(this);
}

SyntekAudioProcessor::~SyntekAudioProcessor()
{
	apvts.state.removeListener(this);
}

//==============================================================================
const juce::String SyntekAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SyntekAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SyntekAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SyntekAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double SyntekAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SyntekAudioProcessor::getNumPrograms()
{
    return 1;
}

int SyntekAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SyntekAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String SyntekAudioProcessor::getProgramName (int index)
{
    return {};
}

void SyntekAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void SyntekAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
	juce::dsp::ProcessSpec spec{ sampleRate, (juce::uint32)samplesPerBlock, 2 };
	synth->prepare(spec);
	updateAPVTS();
    
    filterChain.get<0>().setType(juce::dsp::StateVariableTPTFilterType::highpass);
    filterChain.get<1>().setType(juce::dsp::StateVariableTPTFilterType::lowpass);

    filterChain.get<0>().setCutoffFrequency(20000.0f);
    filterChain.get<1>().setCutoffFrequency(20.0f);

    filterChain.prepare({sampleRate, (juce::uint32)samplesPerBlock, static_cast<juce::uint32>(getTotalNumOutputChannels())});

}

void SyntekAudioProcessor::releaseResources()
{

}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SyntekAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else

    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
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

//==================================
void SyntekAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

	if(mustUpdateAPVTS.get())
		updateAPVTS();
	
	synth->renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
    
    auto block = juce::dsp::AudioBlock<float>(buffer);
    auto context = juce::dsp::ProcessContextReplacing<float>(block);

    filterChain.get<0>().setCutoffFrequency(*apvts.getRawParameterValue("HPFREQ"));
    filterChain.get<1>().setCutoffFrequency(*apvts.getRawParameterValue("LPFREQ"));
    filterChain.process(context);

}

//==============================================================================
bool SyntekAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* SyntekAudioProcessor::createEditor()
{
    return new SyntekAudioProcessorEditor (*this);
}

//==============================================================================
void SyntekAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void SyntekAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SyntekAudioProcessor();
}

//=====================================================
void SyntekAudioProcessor::updateAPVTS()
{
	synth->updateAPVTS(apvts);
	mustUpdateAPVTS = false;
}

//=====================================================
juce::AudioProcessorValueTreeState& SyntekAudioProcessor::getValueTree()
{
	return apvts;
}


//=====================================================
juce::AudioProcessorValueTreeState::ParameterLayout SyntekAudioProcessor::_createParameters()
{
	std::vector<std::unique_ptr<juce::RangedAudioParameter>> params;
    
    // Harmonics
    for (int i = 1; i <= Syntek_CONSTANTS::numHarmonics; ++i)
    {
        juce::String paramID = "H" + juce::String(i);
        juce::String paramName = "Harmonic" + juce::String(i);
        params.push_back(std::make_unique<juce::AudioParameterFloat>(paramID, paramName, juce::NormalisableRange<float>(0.0f, 1.0f, 0.01f), 0.0f));
    }
	
	// ADSR Params
	params.push_back(std::make_unique<juce::AudioParameterFloat>("ATTACK 1", "Attack 1", juce::NormalisableRange<float>(0.0f, 3.0f, 0.01f), 0.00f));
	params.push_back(std::make_unique<juce::AudioParameterFloat>("DECAY 1", "Decay 1", juce::NormalisableRange<float>(0.0f, 3.0f, 0.01), 0.0f));
	params.push_back(std::make_unique<juce::AudioParameterFloat>("SUSTAIN 1", "Sustain 1", juce::NormalisableRange<float>(0.0f, 3.0f, 0.01f), 1.0f));
	params.push_back(std::make_unique<juce::AudioParameterFloat>("RELEASE 1", "Release 1", juce::NormalisableRange<float>(0.0f, 3.0f, 0.01f), 0.0f));
    
    // Filters
    params.push_back(std::make_unique<juce::AudioParameterFloat>("HPFREQ", "High Pass Frequency", juce::NormalisableRange<float> { 20.0f, 20000.0f, 1.0f, 0.25f }, 20.0f));
    params.push_back(std::make_unique<juce::AudioParameterFloat>("LPFREQ", "Low Pass Frequency", juce::NormalisableRange<float> { 20.0f, 20000.0f, 1.0f, 0.25f }, 20000.0f));

    
	return { params.begin(), params.end() };
}


//=====================================
void SyntekAudioProcessor::valueTreePropertyChanged(juce::ValueTree& treeWhosePropertyHasChanged, const juce::Identifier& property)
{
	mustUpdateAPVTS = true;
}
