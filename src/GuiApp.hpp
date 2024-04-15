//
//  GuiApp.hpp
//  Chords
//
//  Created by Laura on 12/4/24.
//

#ifndef GuiApp_hpp
#define GuiApp_hpp
#pragma once

#include <stdio.h>
#include "ofMain.h"
#include "ofxGui.h"

class GuiApp: public ofBaseApp {
public:
    void setup();
    void update();
    void draw();

    ofParameterGroup parameters;
    ofParameter<float> radius;
    ofParameter<ofColor> color;
    ofxPanel gui;
};


#endif /* GuiApp_hpp */
