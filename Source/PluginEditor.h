/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class DelayAudioProcessorEditor  : public AudioProcessorEditor //Slider::Listener
{
public:
    DelayAudioProcessorEditor (DelayAudioProcessor&, AudioProcessorValueTreeState&);
    ~DelayAudioProcessorEditor();

   //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

private:
    AudioProcessorValueTreeState& valueTreeState;
    
    // creating sliders
    Slider wetSlider;
    Slider timeSlider;
    Slider feedbackSlider;
    
    // creating APVTS attachments for respective sliders
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> wetAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> timeAttachment;
    std::unique_ptr<AudioProcessorValueTreeState::SliderAttachment> feedbackAttachment;
    
    // creating labels for respective sliders
    Label wetLabel;
    Label timeLabel;
    Label feedbackLabel;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    DelayAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DelayAudioProcessorEditor)
};
