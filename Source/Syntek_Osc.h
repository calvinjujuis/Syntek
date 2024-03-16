#pragma once
#include <JuceHeader.h>

class WaveTable;

class Syntek_Osc
{
public:

	Syntek_Osc();
	~Syntek_Osc();
	
	void prepareToPlay(double sampleRate);
	
	void setFrequency(float freq);
    void setHarmonics(const std::vector<float> &harmonics);
	float getNextSample();
	
private:
	std::unique_ptr<WaveTable> waveTable;
	double mSampleRate = -1;
	float currentIndex = 0.f;
	float currentPhaseIncrement = 0.f;
	float currentFreq = 0.f;
	
	float _calculatePhaseIncrement(float freq);
	float _getNextSampleIndex();
};
