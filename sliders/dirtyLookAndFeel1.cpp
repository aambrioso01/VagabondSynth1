
#include "DirtyLookAndFeel1.h"

DirtyLookAndFeel1::DirtyLookAndFeel1()
{
    //load image from pngBinaries.h
    image_knob1_strip_png = ImageCache::getFromMemory(pngBinaries::knob1_strip_png, pngBinaries::knob1_strip_pngSize);
}


void DirtyLookAndFeel1::drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos, const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider)
{
    //checks if knob1 image is valid
    if(image_knob1_strip_png.isValid())
    {
        //calculate rotation of knob
        const double rotation = (slider.getValue()
            - slider.getMinimum())
            / (slider.getMaximum()
                - slider.getMinimum());

        const float knob1_width = image_knob1_strip_png.getWidth();
        const float knob1_height = image_knob1_strip_png.getHeight();

        const int frames = knob1_height / knob1_width;
        const int frameId = (int)ceil(rotation * ((double)frames - 1.0));
        const float radius = jmin(width / 2.0f, height / 2.0f);
        const float centerX = x + width * 0.5f;
        const float centerY = y + height * 0.5f;
        const float rx = centerX - radius - 1.0f;
        const float ry = centerY - radius;
        
        
        //attempt transform
        //g.addTransform(AffineTransform::rotation(1.7));

        g.drawImage(image_knob1_strip_png, (int)rx, (int)ry, 2 * (int)radius, 2 * (int)radius, 0, frameId * knob1_width, knob1_width, knob1_width);
        
        //g.drawImageTransformed(image_knob1_png, AffineTransform::rotation(0));
    }
    else{
        static const float textPpercent = 0.35f;
        Rectangle<float> text_bounds(1.0f + width * (1.0f - textPpercent) / 2.0f,
            0.5f * height, width * textPpercent, 0.5f * height);

        g.setColour(Colours::white);

        g.drawFittedText(String("No Image"), text_bounds.getSmallestIntegerContainer(),
            Justification::horizontallyCentred | Justification::centred, 1);
    }

    
    
}