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
    oled->rectFill(10, 10, 110, 50, WHITE, 0);
    oled->setColor(BLACK);
    oled->circle(30, 30, 10);
    oled->drawChar(40, 40, 'h');
}

DisplayComponent::~DisplayComponent(){
    DisplayLabel = nullptr;
}

void DisplayComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

  g.drawImageAt(oled->getImage(), 0, 0);
    // g.fillAll (Colour (0xff000000));
    // g.setColour (Colour (0xff6f6f6f));
    
    // g.setPixel	(64, 128);

    // oled->setGraphicsContext(&g);
    
//    g.setColour (Colours::white);
 //   g.fillPath ();
//    g.setColour (Colour (0xff6f6f6f));
//    g.strokePath (25, float (5.200f));
    
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
