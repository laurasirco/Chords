#include "ofApp.h"

using namespace MusicTheory;

//--------------------------------------------------------------
void ofApp::setup(){
    
    numVoices = 7;
    currentChordNumber = -1;
    
    chordsEngine.setup(numVoices);
    soundEngine.setup(numVoices);
        
    for(int i = 0; i < numVoices; i++){
        chordsEngine.currentChord[i]->toInt() >> soundEngine.polysynth.voices[i].in("pitch");
    }
    
    
    // graphic setup---------------------------
    ofSetVerticalSync(true);
    ofDisableAntiAliasing();
    ofBackground(0);
    ofSetColor(ofColor(0,100,100));
    ofNoFill();
    ofSetLineWidth(1.0f);
    ofSetFrameRate(24);
    
    //Fonts
    ofTrueTypeFont::setGlobalDpi(72);
    titleFont.load("SourceCodePro-ExtraLight.ttf", 40, true, true);
    bodyFont.load("SourceCodePro-ExtraLight.ttf", 24, true, true);
    
    // GUI -----------------------------------
    gui.setup("panel");
    gui.add( soundEngine.gain.set("gain", 0, -48, 12) );

    gui.setPosition(20, 20);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //Check GPIO Interface
    
    int chord = keyboardReader.checkChordsKeys();
    int step = keyboardReader.checkModeKeys();
    chordsEngine.increaseMode(step);
//    chordsEngine.activeVoices = keyboardReader.checkPerformKeys();
    
    // voice modifier active
    if(keyboardReader.checkVoiceModifier()){
        std::vector<int> voices = keyboardReader.checkPerformKeys();
        chordsEngine.setActiveVoices(voices);
    }
    else{
        if(chord != -1){
            setCurrentChord(chord);
            soundEngine.triggerOn(chordsEngine.currentChord, chordsEngine.activeVoices);
        }
        else{
            soundEngine.triggerOff(chordsEngine.currentChord, chordsEngine.activeVoices);
        }
        
        //chord changed
        if(chord != -1 && chord != currentChordNumber){
            soundEngine.triggerOff(chordsEngine.currentChord, chordsEngine.activeVoices);
            setCurrentChord(chord);
            soundEngine.triggerOn(chordsEngine.currentChord, chordsEngine.activeVoices);
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofClear(0);
    
    ofSetColor(255);
        
    ofPushMatrix();
        ofRectangle bounds = titleFont.getStringBoundingBox(chordsEngine.currentChordName(), 0, 0);
        ofTranslate(256 - bounds.width/2, 256 - bounds.height/2, 0);
        titleFont.drawString(chordsEngine.currentChordName(), 0, 0 );
    ofPopMatrix();
    
    string mode = "Mode: " + to_string(chordsEngine.currentMode);
    
    bodyFont.drawString(mode, 20, 30);
    
    string voices = "Voices: ";
    
    for(int i = 0; i < chordsEngine.activeVoices.size(); i++){
        voices += to_string(chordsEngine.activeVoices[i]);
        voices += " ";
    }
    
    bodyFont.drawString(voices, 20, 60);
    
    float tempo = roundf(soundEngine.engine.sequencer.meter_playhead() * 10) / 10;
    bodyFont.drawString(to_string(tempo), 20, 90);
    
    if(keyboardReader.checkVoiceModifier()){
        bodyFont.drawString("VOICES MODIFIER", 20, 120);
    }
}

void ofApp::drawChordButtons(){
    for(int i = 0; i < chordButtons.size(); i++){
        ofDrawRectangle(chordButtons[i]);
        ofDrawBitmapString(i,
                           chordButtons[i].position.x + (chordButtons[i].width/2),
                           chordButtons[i].position.y + (chordButtons[i].height/2)
                           );
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    keyboardReader.keyPressed(key);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    keyboardReader.keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

void ofApp::setCurrentChord(int chord){

    currentChordNumber = chord;
    chordsEngine.setCurrentChord(chord, numVoices);
    
    for(int i = 0; i < numVoices; i++){
        soundEngine.polysynth.setPitchForVoice(chordsEngine.currentChord[i]->toInt(), i);
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
