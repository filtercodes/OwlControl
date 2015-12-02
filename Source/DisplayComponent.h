//
//  DisplayComponent.h
//  OwlControl
//
//  Created by Stefan Miletic on 18/11/2015.
//  Copyright (c) 2015 __MyCompanyName__. All rights reserved.
//

#ifndef OwlControl_DisplayComponent_h
#define OwlControl_DisplayComponent_h

#include "JuceHeader.h"
//#include "juce_component.h"
//#include "juce_PixelFormats.h"
#include "SparkFunMicroOLED.h"

/* #include "juce_Drawable.h"
#include "juce_DrawableComposite.h"
#include "juce_DrawableText.h"
#include "juce_gui_basics.h"   */

class DisplayComponent  : public Component
//                          public DrawableComposite,
//                          public DrawableText,
//                          public DrawableShape
{
public:
    DisplayComponent ();
    ~DisplayComponent();
    
    void paint (Graphics& g);
    void setBoundingBox (const RelativeParallelogram& newBoundingBox); 
    void draw (Graphics& g, float opacity,
               const AffineTransform& transform = AffineTransform::identity) const;
    
    
    // Text functions //
    
    void setText (const String& newText);
    void setColour (Colour newColour);
 //   void setFont (const Font& newFont, bool applySizeAndScale);
    void setPixel(Graphics& g, int x, int y );
    void drawx4Pixel(Graphics& g, int x, int y);
    void drawPixel(Graphics& g, int x, int y, int colour, int mode);
    
private:
    ScopedPointer<Label>DisplayLabel;
    ScopedPointer<MicroOLED> oled;
    
};

#endif
