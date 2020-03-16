/*
  ==============================================================================
    This file was auto-generated!
    It contains the basic framework code for a JUCE plugin editor.
  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DirtyDistortionAudioProcessorEditor::DirtyDistortionAudioProcessorEditor (DirtyDistortionAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
   
    //JARVIS
    //SLIDERS
    
    /*
    addAndMakeVisible(driveKnob = new Slider("Drive"));
    driveKnob->setSliderStyle(Slider::Rotary);
    driveKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

    addAndMakeVisible(rangeKnob = new Slider("Range"));
    rangeKnob->setSliderStyle(Slider::Rotary);
    rangeKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

    addAndMakeVisible(blendKnob = new Slider("Blend"));
    blendKnob->setSliderStyle(Slider::Rotary);
    blendKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

    addAndMakeVisible(volumeKnob = new Slider("Volume"));
    volumeKnob->setSliderStyle(Slider::Rotary);
    volumeKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);

    driveAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "Drive", *driveKnob);
    rangeAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "Range", *rangeKnob);
    blendAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "Blend", *blendKnob);
    volumeAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(), "Volume", *volumeKnob);
    */
    
    //COLTON
    //BUTTONS
    
    //Sine Button
    addAndMakeVisible (buttonSine1 = new TextButton ("Sine"));
    buttonSine1->setButtonText (TRANS("Sine"));
    
    //Square Button
    addAndMakeVisible (buttonSquare1 = new TextButton ("Square"));
    buttonSquare1->setButtonText (TRANS("Square"));
    
    //Triangle Button
    addAndMakeVisible (buttonTriangle1 = new TextButton ("Triangle"));
    buttonTriangle1->setButtonText (TRANS("Triangle"));
    
    //Image Button Testing
    addAndMakeVisible (imageTest = new ImageButton ("imageTest"));
    addAndMakeVisible (test2 = new ImageButton ("test2"));
    addAndMakeVisible (test3 = new ImageButton ("test3"));
    
    //Adding the Images
    Image normalButton = ImageCache::getFromMemory (pngBinaries::redcircle_jpg, pngBinaries::redcircle_jpgSize);
    Image overButton = ImageCache::getFromMemory (pngBinaries::yellowcircle_png, pngBinaries::yellowcircle_pngSize);
    Image downButton = ImageCache::getFromMemory (pngBinaries::greencircle_png, pngBinaries::greencircle_pngSize);
    
    imageTest->setImages (true, true, true, normalButton, 1.0f, {}, overButton, 1.0f, {}, downButton, 1.0f, {});
    test2->setImages (true, true, true, normalButton, 1.0f, {}, overButton, 1.0f, {}, downButton, 1.0f, {});
    test3->setImages (true, true, true, normalButton, 1.0f, {}, overButton, 1.0f, {}, downButton, 1.0f, {});
    
    //Makes Button Toggle
    imageTest->setClickingTogglesState(true);
    test2->setClickingTogglesState(true);
    test3->setClickingTogglesState(true);
    
    //Doing all the Image Stuff Above but 4real

    addAndMakeVisible (sine1 = new ImageButton ("sine1"));
    addAndMakeVisible (sine2 = new ImageButton ("sine2"));
    addAndMakeVisible (sine3 = new ImageButton ("sine3"));
    addAndMakeVisible (sine4 = new ImageButton ("sine4"));
    
    addAndMakeVisible (square1 = new ImageButton ("square1"));
    addAndMakeVisible (square2 = new ImageButton ("square2"));
    addAndMakeVisible (square3 = new ImageButton ("square3"));
    addAndMakeVisible (square4 = new ImageButton ("square4"));
    
    addAndMakeVisible (triangle1 = new ImageButton ("triangle1"));
    addAndMakeVisible (triangle2 = new ImageButton ("triangle2"));
    addAndMakeVisible (triangle3 = new ImageButton ("triangle3"));
    addAndMakeVisible (triangle4 = new ImageButton ("triangle4"));
    
    //make them all toggle
    sine1->setClickingTogglesState(true);
    sine2->setClickingTogglesState(true);
    sine3->setClickingTogglesState(true);
    sine4->setClickingTogglesState(true);
    
    square1->setClickingTogglesState(true);
    square2->setClickingTogglesState(true);
    square3->setClickingTogglesState(true);
    square4->setClickingTogglesState(true);
    
    triangle1->setClickingTogglesState(true);
    triangle2->setClickingTogglesState(true);
    triangle3->setClickingTogglesState(true);
    triangle4->setClickingTogglesState(true);
    

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    
    //size for osc
    setSize (900, 500);

}

DirtyDistortionAudioProcessorEditor::~DirtyDistortionAudioProcessorEditor()
{
}

//==============================================================================



void DirtyDistortionAudioProcessorEditor::paint (Graphics& g)
{
    
    /*
    
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    //g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);

    g.drawText("Drive", ((getWidth() / 5) * 1) - (100 / 2), ((getHeight() / 2)) + 5, 100, 100, Justification::centred, false);
    g.drawText("Range", ((getWidth() / 5) * 2) - (100 / 2), ((getHeight() / 2)) + 5, 100, 100, Justification::centred, false);
    g.drawText("Blend", ((getWidth() / 5) * 3) - (100 / 2), ((getHeight() / 2)) + 5, 100, 100, Justification::centred, false);
    g.drawText("Volume", ((getWidth() / 5) * 4) - (100 / 2), ((getHeight() / 2)) + 5, 100, 100, Justification::centred, false);
    
    */
}



void DirtyDistortionAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    /*

    //JARVIS
    driveKnob->setBounds( ((getWidth() / 5) * 1) -(100/2), ((getHeight() / 2)) - (100 / 2), 100, 100);
    rangeKnob->setBounds(((getWidth() / 5) * 2) - (100 / 2), ((getHeight() / 2)) - (100 / 2), 100, 100);
    blendKnob->setBounds(((getWidth() / 5) * 3) - (100 / 2), ((getHeight() / 2)) - (100 / 2), 100, 100);
    volumeKnob->setBounds(((getWidth() / 5) * 4) - (100 / 2), ((getHeight() / 2)) - (100 / 2), 100, 100);

    */
    
    //COLTON
    //0.0 IS TOP LEFT, 1.0 IS BOTTOM RIGHT
    //FIRST TWO VARIABLES ARE LOCATION, SECOND TWO ARE SIZE OF BUTTON
    
    /*
    buttonSine1->setBounds (proportionOfWidth (0.4160f), proportionOfHeight (0.8649f), proportionOfWidth (0.1746f), proportionOfHeight (0.0811f));
    buttonSquare1->setBounds (proportionOfWidth (0.04366f), proportionOfHeight (0.173409f), proportionOfWidth (0.1746f), proportionOfHeight (0.0811f));
    buttonTriangle1->setBounds (proportionOfWidth (0.4160f), proportionOfHeight (1.02447f), proportionOfWidth (0.1746f), proportionOfHeight (0.0811f));
    */
    
    //Image Proportion Location Editing
    imageTest->setBoundsRelative(0.00f, 0.10f, 0.10f, 0.10f);
    test2->setBoundsRelative(0.15f, 0.10f, 0.10f, 0.10f);
    test3->setBoundsRelative(0.25f, 0.10f, 0.10f, 0.10f);
}