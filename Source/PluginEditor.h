/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Soundwave.h"

//==============================================================================
/**
*/
class SyntekAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    SyntekAudioProcessorEditor (SyntekAudioProcessor&);
    ~SyntekAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:

    SyntekAudioProcessor& audioProcessor;
    
//    Soundwave soundwave;
    
    // Harmonics components
    juce::Slider h1Slider;
    juce::Label  h1Label;
    
    juce::Slider h2Slider;
    juce::Label  h2Label;
    
    juce::Slider h3Slider;
    juce::Label  h3Label;
    
    juce::Slider h4Slider;
    juce::Label  h4Label;
    
    juce::Slider h5Slider;
    juce::Label  h5Label;
    
    juce::Slider h6Slider;
    juce::Label  h6Label;
    
    juce::Slider h7Slider;
    juce::Label  h7Label;
    
    juce::Slider h8Slider;
    juce::Label  h8Label;
    
    using SliderAttachment = juce::AudioProcessorValueTreeState::SliderAttachment;
    std::unique_ptr<SliderAttachment> h1Attachment;
    std::unique_ptr<SliderAttachment> h2Attachment;
    std::unique_ptr<SliderAttachment> h3Attachment;
    std::unique_ptr<SliderAttachment> h4Attachment;
    std::unique_ptr<SliderAttachment> h5Attachment;
    std::unique_ptr<SliderAttachment> h6Attachment;
    std::unique_ptr<SliderAttachment> h7Attachment;
    std::unique_ptr<SliderAttachment> h8Attachment;
    
    // ADSR components
    juce::Slider attackSlider;
    juce::Slider decaySlider;
    juce::Slider sustainSlider;
    juce::Slider releaseSlider;

    // Labels for ADSR sliders
    juce::Label attackLabel;
    juce::Label decayLabel;
    juce::Label sustainLabel;
    juce::Label releaseLabel;

    // Slider attachments for ADSR
    std::unique_ptr<SliderAttachment> attackAttachment;
    std::unique_ptr<SliderAttachment> decayAttachment;
    std::unique_ptr<SliderAttachment> sustainAttachment;
    std::unique_ptr<SliderAttachment> releaseAttachment;

    juce::Slider highPassFreqSlider;
    juce::Slider lowPassFreqSlider;
    
    juce::Label highPassFreqLabel;
    juce::Label lowPassFreqLabel;
    
    std::unique_ptr<SliderAttachment> highPassFreqSliderAttachment;
    std::unique_ptr<SliderAttachment> lowPassFreqSliderAttachment;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SyntekAudioProcessorEditor)
};
