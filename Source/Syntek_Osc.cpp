#include "Syntek_Osc.h"
#include "WaveTable.h"
#include "Soundwave.h"

//===============================
Syntek_Osc::Syntek_Osc()
{
	waveTable = std::make_unique<WaveTable>();
}

//===============================
Syntek_Osc::~Syntek_Osc()
{
	waveTable.release();
}

//===============================
void Syntek_Osc::prepareToPlay(double sampleRate)
{
	mSampleRate = sampleRate;
	jassert(mSampleRate > 0);
}

//==============================
void Syntek_Osc::setFrequency(float freq)
{
	currentFreq = freq;
	currentPhaseIncrement = _calculatePhaseIncrement(currentFreq);
}

void Syntek_Osc::setHarmonics(const std::vector<float> &harmonics)
{
    waveTable->setHarmonics(harmonics);
}

//==============================
float Syntek_Osc::_calculatePhaseIncrement(float freq)
{
	int tableSize = waveTable->getTableSize();
	float tableSizeOverSampleRate =  tableSize / mSampleRate;
	float phaseIncrement = freq * tableSizeOverSampleRate;
	return phaseIncrement;
}

//==============================
float Syntek_Osc::getNextSample()
{
	float index = _getNextSampleIndex();
	float sample = waveTable->getSampleAtIndex(index);
	return sample;
}

//==============================
float Syntek_Osc::_getNextSampleIndex()
{
	float nextSampleIndex = currentIndex;
	
	currentIndex += currentPhaseIncrement;
	
	// wrap around table size
	if(currentIndex >= waveTable->getTableSize())
		currentIndex -= (float)waveTable->getLastIndexInWaveTable();
	
	return nextSampleIndex;

}
