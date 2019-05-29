/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DelayAudioProcessorEditor::DelayAudioProcessorEditor (DelayAudioProcessor& p, AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), valueTreeState(vts), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setOpaque(true); // self explanatory
    
    setResizeLimits (320, 175, 420, 175); // sets desired resize limits
    setResizable (true, true); // self explanatory
    
    bgImage = ImageCache::getFromMemory(BinaryData::bgImage_png, BinaryData::bgImage_pngSize); // background image
    
    // SPACE STONE SLIDER
    wetSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag); // sets the style of slider as a rotating knob controlled by vertical dragging
    wetSlider.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::royalblue); // sets the colour of slider to blue
    wetSlider.setColour(Slider::ColourIds::thumbColourId, Colours::white); // sets the slider thumb colour to white
    
    wetSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, false, 60, 15); // creates text box to show/edit value below slider
    wetSlider.setNumDecimalPlacesToDisplay(2); // only displays two decimal places
    wetSlider.setTextValueSuffix("%"); // shows the text box value as a percentage
    wetSlider.setColour(Slider::ColourIds::textBoxBackgroundColourId, Colours::black); // sets background of textbox to opaque black
    wetSlider.setColour(Slider::ColourIds::textBoxOutlineColourId, Colours::transparentBlack); // removes the textbox border
    wetSlider.setColour(Slider::ColourIds::textBoxTextColourId, Colours::slateblue); // sets text colour to purple

    addAndMakeVisible(wetSlider); // makes slider visible

    wetAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment (valueTreeState, "wet", wetSlider)); // attaching the slider to the plugin processor
    
    wetLabel.setText ("Space", dontSendNotification); // sets label text
    wetLabel.setJustificationType(Justification::centredTop); // centres label
    addAndMakeVisible (wetLabel); // makes label for slider visible
    
    
    // TIME STONE SLIDER
    timeSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag); // sets the style of slider as a rotating knob controlled by vertical dragging
    timeSlider.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::green); // sets the colour of slider to green
    timeSlider.setColour(Slider::ColourIds::thumbColourId, Colours::white); // sets the slider thumb colour to white
    
    timeSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, false, 80, 15); // creates text box to show/edit value below slider
    timeSlider.setNumDecimalPlacesToDisplay(2); // only displays two decimal places
    timeSlider.setTextValueSuffix("ms"); // shows the text box value as unit of time
    timeSlider.setColour(Slider::ColourIds::textBoxBackgroundColourId, Colours::black); // sets background of textbox to opaque black
    timeSlider.setColour(Slider::ColourIds::textBoxOutlineColourId, Colours::transparentBlack); // removes the textbox border
    timeSlider.setColour(Slider::ColourIds::textBoxTextColourId, Colours::slateblue); // sets text colour to purple
    
    addAndMakeVisible(timeSlider); // makes slider visible
    
    timeAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment (valueTreeState, "time", timeSlider)); // attaching the slider to the plugin processor
    
    timeLabel.setText ("Time", dontSendNotification); // sets label text
    timeLabel.setJustificationType(Justification::centredTop); // centres label
    addAndMakeVisible (timeLabel); // makes label for slider visible
    
    
    // POWER STONE SLIDER
    feedbackSlider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag); // sets the style of slider as a rotating knob controlled by vertical dragging
    feedbackSlider.setColour(Slider::ColourIds::rotarySliderFillColourId, Colours::darkviolet); // sets the colour of slider to purple
    feedbackSlider.setColour(Slider::ColourIds::thumbColourId, Colours::white); // sets the slider thumb colour to white
    
    feedbackSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, false, 60, 15); // creates text box to show/edit value below slider
    feedbackSlider.setNumDecimalPlacesToDisplay(2); // only displays two decimal places
    feedbackSlider.setTextValueSuffix("%"); // shows the text box value as a percentage
    feedbackSlider.setColour(Slider::ColourIds::textBoxBackgroundColourId, Colours::black); // sets background of textbox to opaque black
    feedbackSlider.setColour(Slider::ColourIds::textBoxOutlineColourId, Colours::transparentBlack); // removes the textbox border
    feedbackSlider.setColour(Slider::ColourIds::textBoxTextColourId, Colours::slateblue); // sets text colour to purple
    
    addAndMakeVisible(feedbackSlider); // makes slider visible
    
    feedbackAttachment.reset(new juce::AudioProcessorValueTreeState::SliderAttachment (valueTreeState, "feedback", feedbackSlider)); // attaching the slider to the plugin processor
    
    feedbackLabel.setText ("Power", dontSendNotification); // sets label text
    feedbackLabel.setJustificationType(Justification::centredTop); // centres label
    addAndMakeVisible (feedbackLabel); // makes label for slider visible
}

DelayAudioProcessorEditor::~DelayAudioProcessorEditor()
{
}

//==============================================================================
void DelayAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId)); // default background
    g.drawImageWithin(bgImage, 0, 0, getWidth(), getHeight(), RectanglePlacement::fillDestination);
}

void DelayAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    auto r = getLocalBounds(); // takes local bounds and stores it in a variable
    
    auto leftSection = r.removeFromLeft(getWidth()/3); // dividing window to have a left section
    auto rightSection = r.removeFromRight(getWidth()/3); // dividing window to have a right section
    
    
    wetSlider.setBounds(leftSection.removeFromTop(getHeight()*0.8f).reduced(10.0f)); // setting the position of the mix slider to the left
    wetLabel.setBounds(leftSection); // setting the position of the mix label to below the slider
    wetLabel.setFont(Font("Arial", 14.0f, Font::plain)); // sets label typeface, size
    
    
    timeSlider.setBounds(r.removeFromTop(getHeight()*0.8f).reduced(10.0f)); // setting the position of the time slider to the middle
    timeLabel.setBounds(r); // setting the position of the time label to below the slider
    timeLabel.setFont(Font("Arial", 14.0f, Font::plain)); // sets label typeface, size
    
    feedbackSlider.setBounds(rightSection.removeFromTop(getHeight()*0.8f).reduced(10.0f)); // setting the position of the feedback slider to the right
    feedbackLabel.setBounds(rightSection); // setting the position of the feedback label to below the slider
    feedbackLabel.setFont(Font("Arial", 14.0f, Font::plain)); // sets label typeface, size
}
