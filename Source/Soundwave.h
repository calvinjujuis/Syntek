#pragma once

#include <JuceHeader.h>

class Soundwave : public juce::Component, public juce::AsyncUpdater
{
public:
    Soundwave() {}
    virtual ~Soundwave() {}

    void paint(juce::Graphics& g) override
    {
//        juce::ScopedLock sl(lock);
        bool isZeros = std::all_of(timeDomainWaveform.begin(), timeDomainWaveform.end(), [](float i) { return i==0; });
        
        if (! isZeros)
        {
            juce::Path path;
            auto width = getLocalBounds().getWidth();
            auto height = getLocalBounds().getHeight();

            if (!timeDomainWaveform.empty())
            {
                auto maxYValue = *std::max_element(timeDomainWaveform.begin(), timeDomainWaveform.end());
                auto minYValue = *std::min_element(timeDomainWaveform.begin(), timeDomainWaveform.end());
                auto amplitude = maxYValue - minYValue;

                for (size_t i = 0; i < timeDomainWaveform.size(); ++i)
                {
                    float normalizedSample = (timeDomainWaveform[i] - minYValue) / amplitude;
                    float x = static_cast<float>(i) / timeDomainWaveform.size() * width;
                    float y = height - normalizedSample * height;
                    if (i == 0)
                        path.startNewSubPath(x, y);
                    else
                        path.lineTo(x, y);
                }
            }
            
            g.fillAll(juce::Colours::black);
            g.setColour(juce::Colours::white);
            g.strokePath(path, juce::PathStrokeType(1.0f));
        }
    }
    

    void setHarmonics(const std::vector<float> newWaveform)
    {
//        {
//            const juce::ScopedLock sl(lock);
            waveform = newWaveform;
            generateWaveform();
//        }
//
//        juce::MessageManager::callAsync([this]() { repaint(); });
        triggerAsyncUpdate();
   }

   void handleAsyncUpdate() override
   {
       repaint();
   }

private:
//    juce::CriticalSection lock;
    
    std::vector<float> waveform;
    
    std::vector<float> timeDomainWaveform;
    
    void generateWaveform()
    {
        int numSamples = 512;
        timeDomainWaveform.resize(numSamples, 0.0f);

        auto sampleRate = 44100.0;
        auto fundamentalFrequency = 440.0;

        for (size_t harmonicIndex = 0; harmonicIndex < waveform.size(); ++harmonicIndex)
        {
            auto amplitude = waveform[harmonicIndex];
            auto frequency = fundamentalFrequency * (harmonicIndex + 1);

            for (int sampleIndex = 0; sampleIndex < numSamples; ++sampleIndex)
            {
                auto t = static_cast<double>(sampleIndex) / sampleRate;
                timeDomainWaveform[sampleIndex] += amplitude * std::sin(2.0 * juce::MathConstants<double>::pi * frequency * t);
            }
        }
    }

};
