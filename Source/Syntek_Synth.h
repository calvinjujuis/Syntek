#pragma once
#include <JuceHeader.h>

class Syntek_Synth : public juce::MPESynthesiser
{
public:
	Syntek_Synth();
	~Syntek_Synth();
	
	void prepare(juce::dsp::ProcessSpec& spec);
	void updateAPVTS(juce::AudioProcessorValueTreeState& apvts);

private:
	void _initVoices(int numVoices);

};
