/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SyntekAudioProcessorEditor::SyntekAudioProcessorEditor (SyntekAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Harmonics
    addAndMakeVisible (h1Slider);
    h1Slider.setSliderStyle (juce::Slider::SliderStyle::LinearHorizontal);
    h1Slider.setRange (0.0f, 1.0f, 0.05f);
//    h1Slider.setTextValueSuffix (" Hz");
    
    addAndMakeVisible (h1Label);
    h1Label.setText ("H1", juce::dontSendNotification);
    h1Label.attachToComponent (&h1Slider, true);
    
    addAndMakeVisible (h2Slider);
    h2Slider.setSliderStyle (juce::Slider::SliderStyle::LinearHorizontal);
    h2Slider.setRange (0.0f, 1.0f, 0.05f);
//    h2Slider.setTextValueSuffix (" Hz");
    
    addAndMakeVisible (h2Label);
    h2Label.setText ("H2", juce::dontSendNotification);
    h2Label.attachToComponent (&h2Slider, true);
    
    addAndMakeVisible (h3Slider);
    h3Slider.setSliderStyle (juce::Slider::SliderStyle::LinearHorizontal);
    h3Slider.setRange (0.0f, 1.0f, 0.05f);
//    h3Slider.setTextValueSuffix (" Hz");
    
    addAndMakeVisible (h3Label);
    h3Label.setText ("H3", juce::dontSendNotification);
    h3Label.attachToComponent (&h3Slider, true);
    
    addAndMakeVisible (h4Slider);
    h4Slider.setSliderStyle (juce::Slider::SliderStyle::LinearHorizontal);
    h4Slider.setRange (0.0f, 1.0f, 0.05f);
//    h4Slider.setTextValueSuffix (" Hz");
    
    addAndMakeVisible (h4Label);
    h4Label.setText ("H4", juce::dontSendNotification);
    h4Label.attachToComponent (&h4Slider, true);
    
    addAndMakeVisible (h5Slider);
    h5Slider.setSliderStyle (juce::Slider::SliderStyle::LinearHorizontal);
    h5Slider.setRange (0.0f, 1.0f, 0.05f);
//    h5Slider.setTextValueSuffix (" Hz");
    
    addAndMakeVisible (h5Label);
    h5Label.setText ("H5", juce::dontSendNotification);
    h5Label.attachToComponent (&h5Slider, true);
    
    addAndMakeVisible (h6Slider);
    h6Slider.setSliderStyle (juce::Slider::SliderStyle::LinearHorizontal);
    h6Slider.setRange (0.0f, 1.0f, 0.05f);
//    h6Slider.setTextValueSuffix (" Hz");
    
    addAndMakeVisible (h6Label);
    h6Label.setText ("H6", juce::dontSendNotification);
    h6Label.attachToComponent (&h6Slider, true);
    
    addAndMakeVisible (h7Slider);
    h7Slider.setSliderStyle (juce::Slider::SliderStyle::LinearHorizontal);
    h7Slider.setRange (0.0f, 1.0f, 0.05f);
//    h7Slider.setTextValueSuffix (" Hz");
    
    addAndMakeVisible (h7Label);
    h7Label.setText ("H7", juce::dontSendNotification);
    h7Label.attachToComponent (&h7Slider, true);
    
    addAndMakeVisible (h8Slider);
    h8Slider.setSliderStyle (juce::Slider::SliderStyle::LinearHorizontal);
    h8Slider.setRange (0.0f, 1.0f, 0.05f);
//    h8Slider.setTextValueSuffix (" Hz");
    
    addAndMakeVisible (h8Label);
    h8Label.setText ("H8", juce::dontSendNotification);
    h8Label.attachToComponent (&h8Slider, true);
    
//    addAndMakeVisible (h1Slider);
//    h1Slider.setSliderStyle (juce::Slider::SliderStyle::LinearHorizontal);
//    h1Slider.setRange (0.0f, 1.0f, 0.05f);
//    h1Slider.setTextValueSuffix (" Hz");
//    
//    addAndMakeVisible (h1Label);
//    h1Label.setText ("H9", juce::dontSendNotification);
//    h1Label.attachToComponent (&h1Slider, true);
//    
//    addAndMakeVisible (h2Slider);
//    h2Slider.setSliderStyle (juce::Slider::SliderStyle::LinearHorizontal);
//    h2Slider.setRange (0.0f, 1.0f, 0.05f);
//    h2Slider.setTextValueSuffix (" Hz");
//    
//    addAndMakeVisible (h2Label);
//    h2Label.setText ("H10", juce::dontSendNotification);
//    h2Label.attachToComponent (&h2Slider, true);
//    
//    addAndMakeVisible (h3Slider);
//    h3Slider.setSliderStyle (juce::Slider::SliderStyle::LinearHorizontal);
//    h3Slider.setRange (0.0f, 1.0f, 0.05f);
//    h3Slider.setTextValueSuffix (" Hz");
//    
//    addAndMakeVisible (h3Label);
//    h3Label.setText ("H11", juce::dontSendNotification);
//    h3Label.attachToComponent (&h3Slider, true);
//    
//    addAndMakeVisible (h4Slider);
//    h4Slider.setSliderStyle (juce::Slider::SliderStyle::LinearHorizontal);
//    h4Slider.setRange (0.0f, 1.0f, 0.05f);
//    h4Slider.setTextValueSuffix (" Hz");
//    
//    addAndMakeVisible (h4Label);
//    h4Label.setText ("H12", juce::dontSendNotification);
//    h4Label.attachToComponent (&h4Slider, true);
//    
//    addAndMakeVisible (h1Slider);
//    h1Slider.setSliderStyle (juce::Slider::SliderStyle::LinearHorizontal);
//    h1Slider.setRange (0.0f, 1.0f, 0.05f);
//    h1Slider.setTextValueSuffix (" Hz");
//    
//    addAndMakeVisible (h1Label);
//    h1Label.setText ("H13", juce::dontSendNotification);
//    h1Label.attachToComponent (&h1Slider, true);
//    
//    addAndMakeVisible (h2Slider);
//    h2Slider.setSliderStyle (juce::Slider::SliderStyle::LinearHorizontal);
//    h2Slider.setRange (0.0f, 1.0f, 0.05f);
//    h2Slider.setTextValueSuffix (" Hz");
//    
//    addAndMakeVisible (h2Label);
//    h2Label.setText ("H14", juce::dontSendNotification);
//    h2Label.attachToComponent (&h2Slider, true);
//    
//    addAndMakeVisible (h3Slider);
//    h3Slider.setSliderStyle (juce::Slider::SliderStyle::LinearHorizontal);
//    h3Slider.setRange (0.0f, 1.0f, 0.05f);
//    h3Slider.setTextValueSuffix (" Hz");
//    
//    addAndMakeVisible (h3Label);
//    h3Label.setText ("H15", juce::dontSendNotification);
//    h3Label.attachToComponent (&h3Slider, true);
//    
//    addAndMakeVisible (h4Slider);
//    h4Slider.setSliderStyle (juce::Slider::SliderStyle::LinearHorizontal);
//    h4Slider.setRange (0.0f, 1.0f, 0.05f);
//    h4Slider.setTextValueSuffix (" Hz");
//    
//    addAndMakeVisible (h4Label);
//    h4Label.setText ("H16", juce::dontSendNotification);
//    h4Label.attachToComponent (&h4Slider, true);
    
    h1Attachment.reset(new SliderAttachment(audioProcessor.apvts, "H1", h1Slider));
    h2Attachment.reset(new SliderAttachment(audioProcessor.apvts, "H2", h2Slider));
    h3Attachment.reset(new SliderAttachment(audioProcessor.apvts, "H3", h3Slider));
    h4Attachment.reset(new SliderAttachment(audioProcessor.apvts, "H4", h4Slider));
    h5Attachment.reset(new SliderAttachment(audioProcessor.apvts, "H5", h5Slider));
    h6Attachment.reset(new SliderAttachment(audioProcessor.apvts, "H6", h6Slider));
    h7Attachment.reset(new SliderAttachment(audioProcessor.apvts, "H7", h7Slider));
    h8Attachment.reset(new SliderAttachment(audioProcessor.apvts, "H8", h8Slider));
//    h9Attachment.reset(new SliderAttachment(audioProcessor.apvts, "H9", h9Slider));
//    h10Attachment.reset(new SliderAttachment(audioProcessor.apvts, "H10", h10Slider));
//    h11Attachment.reset(new SliderAttachment(audioProcessor.apvts, "H11", h11Slider));
//    h12Attachment.reset(new SliderAttachment(audioProcessor.apvts, "H12", h12Slider));
//    h13Attachment.reset(new SliderAttachment(audioProcessor.apvts, "H13", h13Slider));
//    h14Attachment.reset(new SliderAttachment(audioProcessor.apvts, "H14", h14Slider));
//    h15Attachment.reset(new SliderAttachment(audioProcessor.apvts, "H15", h15Slider));
//    h16Attachment.reset(new SliderAttachment(audioProcessor.apvts, "H16", h16Slider));
//
    // ADSR
    attackSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    attackSlider.setRange(0.0f, 5.0f, 0.01f); // Adjust range as needed
    attackSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
    attackLabel.setText("Attack", juce::dontSendNotification);
    attackLabel.attachToComponent (&attackSlider, false);

    decaySlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    decaySlider.setRange(0.0f, 5.0f, 0.01f); // Adjust range as needed
    decaySlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
    decayLabel.setText("Decay", juce::dontSendNotification);
    decayLabel.attachToComponent (&decaySlider, false);

    sustainSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    sustainSlider.setRange(0.0f, 1.0f, 0.01f); // Sustain is often a level, not time
    sustainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
    sustainLabel.setText("Sustain", juce::dontSendNotification);
    sustainLabel.attachToComponent (&sustainSlider, false);

    releaseSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    releaseSlider.setRange(0.0f, 5.0f, 0.01f); // Adjust range as needed
    releaseSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
    releaseLabel.setText("Release", juce::dontSendNotification);
    releaseLabel.attachToComponent (&releaseSlider, false);

    addAndMakeVisible(attackSlider);
    addAndMakeVisible(decaySlider);
    addAndMakeVisible(sustainSlider);
    addAndMakeVisible(releaseSlider);

    addAndMakeVisible(attackLabel);
    addAndMakeVisible(decayLabel);
    addAndMakeVisible(sustainLabel);
    addAndMakeVisible(releaseLabel);

    attackAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.apvts, "ATTACK 1", attackSlider));
    decayAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.apvts, "DECAY 1", decaySlider));
    sustainAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.apvts, "SUSTAIN 1", sustainSlider));
    releaseAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment(audioProcessor.apvts, "RELEASE 1", releaseSlider));

    // Add controls for the filters
    highPassFreqSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    highPassFreqSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
    highPassFreqSliderAttachment.reset(new SliderAttachment(audioProcessor.apvts, "HPFREQ", highPassFreqSlider));
    addAndMakeVisible(highPassFreqSlider);
    
    highPassFreqLabel.setText("HPF", juce::dontSendNotification);
    highPassFreqLabel.attachToComponent(&highPassFreqSlider, false);

    lowPassFreqSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    lowPassFreqSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 20);
    lowPassFreqSliderAttachment.reset(new SliderAttachment(audioProcessor.apvts, "LPFREQ", lowPassFreqSlider));
    addAndMakeVisible(lowPassFreqSlider);
    
    lowPassFreqLabel.setText("LPF", juce::dontSendNotification);
    lowPassFreqLabel.attachToComponent(&lowPassFreqSlider, false);

    
    setSize (800, 250);
}

SyntekAudioProcessorEditor::~SyntekAudioProcessorEditor()
{
}

//==============================================================================
void SyntekAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
//    g.drawFittedText ("Hello Worldddd!", getLocalBounds(), juce::Justification::centred, 1);
}

void SyntekAudioProcessorEditor::resized()
{
    // Harmonics
    int sliderWidth = 200;
    int sliderHeight = 12;
    int sliderStartX = 30;
    int sliderStartY = 30;
    int sliderSpacing = 12; // The vertical space between each slider

    h1Slider.setBounds (sliderStartX, sliderStartY, sliderWidth, sliderHeight);
    h2Slider.setBounds (sliderStartX, sliderStartY + sliderHeight + sliderSpacing, sliderWidth, sliderHeight);
    h3Slider.setBounds (sliderStartX, sliderStartY + 2 * (sliderHeight + sliderSpacing), sliderWidth, sliderHeight);
    h4Slider.setBounds (sliderStartX, sliderStartY + 3 * (sliderHeight + sliderSpacing), sliderWidth, sliderHeight);
    h5Slider.setBounds (sliderStartX, sliderStartY + 4 * (sliderHeight + sliderSpacing), sliderWidth, sliderHeight);
    h6Slider.setBounds (sliderStartX, sliderStartY + 5 * (sliderHeight + sliderSpacing), sliderWidth, sliderHeight);
    h7Slider.setBounds (sliderStartX, sliderStartY + 6 * (sliderHeight + sliderSpacing), sliderWidth, sliderHeight);
    h8Slider.setBounds (sliderStartX, sliderStartY + 7 * (sliderHeight + sliderSpacing), sliderWidth, sliderHeight);
    
    // ADSR
    int knobStartX = sliderStartX + sliderWidth + 40; // Start to the right of the harmonic sliders
    int knobDiameter = 80; // Diameter of the knobs
    int knobSpacing = 20; // Horizontal space between each knob

    attackSlider.setBounds(knobStartX, sliderStartY, knobDiameter, knobDiameter);
    decaySlider.setBounds(knobStartX + (knobDiameter + knobSpacing), sliderStartY, knobDiameter, knobDiameter);
    sustainSlider.setBounds(knobStartX + 2 * (knobDiameter + knobSpacing), sliderStartY, knobDiameter, knobDiameter);
    releaseSlider.setBounds(knobStartX + 3 * (knobDiameter + knobSpacing), sliderStartY, knobDiameter, knobDiameter);

    attackLabel.setBounds(attackLabel.getX() + attackSlider.getWidth() / 5, attackLabel.getY(), attackLabel.getWidth(), attackLabel.getHeight());
    decayLabel.setBounds(decaySlider.getX() + decaySlider.getWidth() / 5, decayLabel.getY(), decayLabel.getWidth(), decayLabel.getHeight());
    sustainLabel.setBounds(sustainSlider.getX() + sustainSlider.getWidth() / 5, sustainLabel.getY(), sustainLabel.getWidth(), sustainLabel.getHeight());
    releaseLabel.setBounds(releaseSlider.getX() + releaseSlider.getWidth() / 5, releaseLabel.getY(), releaseLabel.getWidth(), releaseLabel.getHeight());
    
    
    // Filters
    highPassFreqSlider.setBounds(knobStartX, sliderStartY + 100, 80, 80);
    lowPassFreqSlider.setBounds(knobStartX + 100, sliderStartY + 100, 80, 80);
    
    highPassFreqLabel.setBounds(knobStartX + highPassFreqSlider.getWidth() / 3, highPassFreqSlider.getY() + highPassFreqSlider.getHeight() / 1.5, highPassFreqLabel.getWidth(), highPassFreqSlider.getHeight());
    
    lowPassFreqLabel.setBounds(knobStartX + 100 + highPassFreqSlider.getWidth() / 3, lowPassFreqSlider.getY() + highPassFreqSlider.getHeight() / 1.5, highPassFreqLabel.getWidth(), highPassFreqSlider.getHeight());
    
    //
//    soundwave.setBounds(0, getHeight() - 100, getWidth(), 100);
}
