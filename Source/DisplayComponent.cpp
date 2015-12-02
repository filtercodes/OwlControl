//
//  DisplayComponent.cpp
//  OwlControl
//
//  Created by Stefan Miletic on 18/11/2015.
//  Copyright (c) 2015 __MyCompanyName__. All rights reserved.
//

#include "DisplayComponent.h"

DisplayComponent::DisplayComponent(){

    addAndMakeVisible (DisplayLabel = new Label (String::empty,
                                                    "Parameter!"));
    DisplayLabel->setFont (Font (15.00f, Font::plain));
    DisplayLabel->setJustificationType (Justification::centred);
    DisplayLabel->setColour (Label::textColourId, Colours::black);
    DisplayLabel->setColour (TextEditor::textColourId, Colours::black);
    DisplayLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    
    setSize (LCDWIDTH, LCDHEIGHT);
    oled = new MicroOLED(LCDWIDTH, LCDHEIGHT);
    oled->begin();
    oled->setColor(BLACK);
    oled->rectFill(0, 0, LCDWIDTH, LCDHEIGHT);
    oled->setColor(WHITE);
  //  setParameterValue(0, 0.2);
  //  setParameterValue(1, 0.6);
  //  setParameterValue(2, 0.9);    
}

DisplayComponent::~DisplayComponent(){
    DisplayLabel = nullptr;
}

void DisplayComponent::setParameterValue(int pid, float value){
    int x = 15;
    int y = 64-8;
    x += pid * 20;
    static const int bars = 6;
    static const int width = 18;
    static const int height = 4;
    static const int gap = 1;
    static const int vdistance = height+gap;
    static const float step = 1.0/bars;
    oled->rectFill(x, y-bars*vdistance, width, 9*vdistance, BLACK, NORM);
    while(value > step){
        oled->rectFill(x, y, width, height);         
        value -= step;
        y -= vdistance;
    }
    int fraction = value*vdistance;
    if(fraction > 0){
        oled->rectFill(x, y-fraction, width, fraction, WHITE, NORM);
    }
    repaint(); // mark for redraw.
}
void DisplayComponent::stringWrite(int line, int pos, String str1){
    static const int maxchars = 16;
    static const int width = 7;
    int x = 2 + pos*width;
    int y = 2;
    if(line == 1)
        y += 10;
    oled->rectFill(x, y, (maxchars-pos)*width, 10, BLACK, NORM);
    int end = std::min(maxchars-pos, str1.length());
    for(int i=0; i < end; i++){
        oled->drawChar(x, y, str1[i], WHITE, NORM);
        x += width;
    }   
    repaint(); // mark for redraw.
    
}

void DisplayComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

  g.drawImageAt(oled->getImage(), 0, 0);
   //  g.fillAll (Colour (0xff000000));
   //  g.setColour (Colour (0xff6f6f6f));
    
   //  g.setPixel	(64, 128);

    // oled->setGraphicsContext(&g);
    
   // g.setColour (Colours::white);
  //  g.fillPath ();
 //   g.setColour (Colour (0xff6f6f6f));
  //  g.strokePath (25, float (5.200f));
    
    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}  

void DisplayComponent::drawPixel(Graphics& g, int x, int y, int colour, int mode){
    g.setColour(Colour(colour));
    // todo: mode
    drawx4Pixel(g, x, y);
}

void DisplayComponent::drawx4Pixel(Graphics& g, int x, int y ){
    x *= 2;
    y *= 2;
    g.setPixel(x,   y);
    g.setPixel(x+1, y);
    g.setPixel(x,   y+1);
    g.setPixel(x+1, y+1);
    
}
