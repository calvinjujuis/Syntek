#include "Syntek_Synth.h"
#include "Syntek_Voice.h"


static constexpr size_t maxNumVoices = 5;

//======================
Syntek_Synth::Syntek_Synth()
{
	_initVoices(maxNumVoices);
}

//======================
Syntek_Synth::~Syntek_Synth()
{
}

//======================
void Syntek_Synth::prepare(juce::dsp::ProcessSpec& spec)
{
	this->setCurrentPlaybackSampleRate(spec.sampleRate);
	
	for(auto* v : voices)
	{
		auto voice = dynamic_cast<Syntek_Voice*>(v);
		voice->prepare(spec);
	}
}


//======================
void Syntek_Synth::_initVoices(int numVoices)
{
	for(size_t i = 0; i <= maxNumVoices; ++i)
	{
		this->addVoice(new Syntek_Voice());
	}
	
	setVoiceStealingEnabled(true);

}

//======================
void Syntek_Synth::updateAPVTS(juce::AudioProcessorValueTreeState& apvts)
{
	for(size_t i = 0; i < getNumVoices(); ++i)
	{
		if (auto* voice = dynamic_cast<Syntek_Voice*>(getVoice(i)))
		{
			voice->updateAPVTS(apvts);
		}
	}

}
