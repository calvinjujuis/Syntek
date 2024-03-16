#include "WaveTable.h"
#include "Constants.h"

//==============================
WaveTable::WaveTable()
{
    setHarmonics(harmonics);
	_generateWave();
}

//==============================
WaveTable::~WaveTable()
{
	
}

void WaveTable::setHarmonics(std::vector<float> newHarmonics)
{
    harmonics = newHarmonics;
    _generateWave();
}

//==============================
void WaveTable::_generateWave()
{
	int tableSize = Syntek_CONSTANTS::TABLE_SIZE;
	waveBuffer.setSize(1, tableSize);
	waveBuffer.clear();
	
	auto* buffWrite = waveBuffer.getWritePointer(0);
    for (auto harmonic = 0; harmonic < Syntek_CONSTANTS::numHarmonics; ++harmonic)
    {
        auto angleDelta = juce::MathConstants<double>::twoPi / (double) (tableSize - 1) * (harmonic + 1);
        auto currentAngle = 0.0;
        for (unsigned int i = 0; i < tableSize; ++i)
        {
            float sample = std::sin(currentAngle);
            buffWrite[i] += sample * harmonics[harmonic];
            currentAngle += angleDelta;
        }
    }
    buffWrite[tableSize] = buffWrite[0];
}


//==============================
float WaveTable::getSampleAtIndex(float index)
{
	jassert(index < Syntek_CONSTANTS::TABLE_SIZE);
	
	int lowIndex  = (int)index;
	int highIndex = lowIndex + 1;
	
	if(highIndex >= Syntek_CONSTANTS::TABLE_SIZE)
		highIndex = 0;
	
	float spillOver         = index - lowIndex;
	float inverseSpillOver  = 1.f   - spillOver;
	
	float sample1 = waveBuffer.getSample(0, lowIndex) * spillOver;
	float sample2 = waveBuffer.getSample(0, highIndex) * inverseSpillOver;
	
	float sample = (sample1 + sample2) / 2.f;
	
	return sample;
}


//=================================
int WaveTable::getTableSize()
{
	int tableSize = waveBuffer.getNumSamples();
	return tableSize;
}

//=================================
int WaveTable::getLastIndexInWaveTable()
{
	return waveBuffer.getNumSamples() - 1;
}
