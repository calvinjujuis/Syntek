#pragma once
#include <JuceHeader.h>
#include "Soundwave.h"

class Syntek_Osc;

class Syntek_Voice : public juce::MPESynthesiserVoice
{
public:
	Syntek_Voice();
	~Syntek_Voice();
	
	void prepare(const juce::dsp::ProcessSpec& spec);
	void noteStarted() override;
	void notePitchbendChanged() override;
	void noteStopped(bool allowTailOff) override;
	void notePressureChanged() override ;
	void noteTimbreChanged() override ;
	void noteKeyStateChanged() override ;
	void renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples) override;

	void updateAPVTS(juce::AudioProcessorValueTreeState& apvts);
private:
	std::unique_ptr<Syntek_Osc> oscillator;
	std::unique_ptr<juce::ADSR> env;
    std::unique_ptr<Soundwave> soundwave;
};
