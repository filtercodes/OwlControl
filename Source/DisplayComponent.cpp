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
    
    setParameterValue(0, 0.1);
    setParameterValue(1, 0.9);
    setParameterValue(2, 0.3);
    setParameterValue(3, 0.4);
    setParameterValue(4, 0.6);
}

DisplayComponent::~DisplayComponent(){
    DisplayLabel = nullptr;
}

void DisplayComponent::setParameterValue(int pid, float value){
    int x = 15;
    int y = 64-10;
    x += pid * 20;
    while(value > 1.0/6){
        oled->rectFill(x, y, 18, 5);         
        value -= 1.0/6;
        y -= 9;
    }
    int fraction = value*6*5;
    if(fraction > 0){
        oled->rectFill(x, y+5-fraction, 18, fraction);
    }
    
 //   oled->
  //  oled->circle(80,34,24, 0xff0000ff, XOR);
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
