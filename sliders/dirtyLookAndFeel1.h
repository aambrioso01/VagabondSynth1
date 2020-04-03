/*
    Made by Vagabond VST's

    
    This class is for our first custom slider
*/
#pragma once
#ifndef DIRTYLOOKANDFEEL
#define DIRTYLOOKANDFEEL



#include <JuceHeader.h>
#include "../resources/pngBinaries.h"

class DirtyLookAndFeel1 : public LookAndFeel_V4
{
    public:
        DirtyLookAndFeel1();
        
        void drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos, float rotaryStartAngle, float rotaryEndAngle, Slider& slider) override;
        
    private:
        Image image_knob1_strip_png;
      
};



#endif // !DIRTYLOOKANDFEEL