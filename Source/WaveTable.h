#pragma once
#include <JuceHeader.h>

/**
	Class representing a single waveform
	Waveform is stored in a juce::AudioBuffer of floats
	Waveforms (buffers) will always be set to a size that is a power of two
	This class returns samples at a given index
	Handles float interpolation between integer indices
*/
class WaveTable
{
public:
	WaveTable();
	~WaveTable();
	
	
	void prepareToPlay(double sampleRate);
	
	float getSampleAtIndex(float index);
	
	int getTableSize();
	
	// Use THIS function to get tableSize - 1
	int getLastIndexInWaveTable();
    void setHarmonics(std::vector<float> newHarmonics);
	
private:
	juce::AudioBuffer<float> waveBuffer;
    std::vector<float> harmonics = {0.0f, 0.0f, 0.0f, 0.0f};
	
	void _generateWave();

};
