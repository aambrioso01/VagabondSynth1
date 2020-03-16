/*
  ==============================================================================

    Oscillator.h
    Created: 16 Mar 2020 3:58:37pm
    Author:  Windows

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class Oscillator : public Component, private ComboBox::Listener

{
public:

    Oscillator();
    ~Oscillator();

    void paint (Graphics&) override;
    void resized() override;
    
    void comboBoxChanged(ComboBox*) override;
    
private:
    ComboBox oscMenu;
    
};