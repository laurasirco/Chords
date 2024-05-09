#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxMusicTheory.h"
#include "GuiApp.hpp"
#include "SoundEngine.hpp"
#include "ChordsEngine.hpp"
#include "KeyboardReader.hpp"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    // pdsp modules
    ofxPanel gui;
    ofTrueTypeFont titleFont;
    ofTrueTypeFont bodyFont;
    
    int numVoices;
    int currentChordNumber;
    
    SoundEngine soundEngine;
    ChordsEngine chordsEngine;
    KeyboardReader keyboardReader;
    
    std::vector<ofRectangle> chordButtons;
    shared_ptr<GuiApp> guiApp;
    
private:
    void drawChordButtons();
    void setCurrentChord(int i);
};
