#include "Syntek_Voice.h"
#include "Syntek_Osc.h"

//======================
Syntek_Voice::Syntek_Voice()
{
	oscillator = std::make_unique<Syntek_Osc>();
	env = std::make_unique<juce::ADSR>();
    soundwave = std::make_unique<Soundwave>();
	
}

//======================
Syntek_Voice::~Syntek_Voice()
{
	
}

//======================
void Syntek_Voice::prepare(const juce::dsp::ProcessSpec& spec)
{
	oscillator->prepareToPlay(spec.sampleRate);
	env->setSampleRate(spec.sampleRate);
}

//======================
void Syntek_Voice::noteStarted()
{
	auto freqHz = (float)getCurrentlyPlayingNote().getFrequencyInHertz();
	
	oscillator->setFrequency(freqHz);
	
	env->noteOn();
}

//======================
void Syntek_Voice::notePitchbendChanged()
{
	
}

//======================
void Syntek_Voice::noteStopped(bool allowTailOff)
{
	env->noteOff();
}

//======================
void Syntek_Voice::notePressureChanged()
{
	
}

//======================
void Syntek_Voice::noteTimbreChanged()
{
	
}

//======================
void Syntek_Voice::noteKeyStateChanged()
{
	
}

//======================
void Syntek_Voice::renderNextBlock(juce::AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
	if( ! env->isActive() )
		return;
	
	auto buffWrite =  outputBuffer.getArrayOfWritePointers();
	int endSample = startSample + numSamples;
	
	for(int sampleIndex = startSample; sampleIndex < endSample; ++sampleIndex)
	{
		float oscSample = oscillator->getNextSample();
		oscSample *= 0.5f;
		oscSample *= env->getNextSample();
		
		for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
		{
			buffWrite[channel][sampleIndex] += oscSample;
		}
	}
}

//=========================
void Syntek_Voice::updateAPVTS(juce::AudioProcessorValueTreeState &apvts)
{
    auto harmonic1 = apvts.getRawParameterValue("H1")->load();
    auto harmonic2 = apvts.getRawParameterValue("H2")->load();
    auto harmonic3 = apvts.getRawParameterValue("H3")->load();
    auto harmonic4 = apvts.getRawParameterValue("H4")->load();
    auto harmonic5 = apvts.getRawParameterValue("H5")->load();
    auto harmonic6 = apvts.getRawParameterValue("H6")->load();
    auto harmonic7 = apvts.getRawParameterValue("H7")->load();
    auto harmonic8 = apvts.getRawParameterValue("H8")->load();

	auto atk1 = apvts.getRawParameterValue("ATTACK 1")->load();
	auto dec1 = apvts.getRawParameterValue("DECAY 1")->load();
	auto sus1 = apvts.getRawParameterValue("SUSTAIN 1")->load();
	auto rel1 = apvts.getRawParameterValue("RELEASE 1")->load();
    
    std::vector harmonics = { harmonic1, harmonic2, harmonic3, harmonic4, harmonic5,  harmonic6, harmonic7, harmonic8};
    oscillator->setHarmonics(harmonics);
    
    soundwave->setHarmonics(harmonics);
    
	juce::ADSR::Parameters newParameters { atk1, dec1, sus1, rel1 };
    env->setParameters(newParameters);
}


