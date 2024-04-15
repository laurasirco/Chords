#include "ofApp.h"

using namespace MusicTheory;

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    numVoices = 2;
    
    chordsEngine.setup();
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
    
    // GUI -----------------------------------
    gui.setup("panel");
    gui.add( soundEngine.gain.set("gain", 0, -48, 12) );

    gui.setPosition(20, 20);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //Check GPIO Interface
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofClear(0);
    
    ofDrawBitmapString(chordsEngine.currentChordName(), 10, 500);
    
    gui.draw();
    
    drawChordButtons();
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
    //Check Keyboard Interface
    if(key == 'q'){
        setCurrentChord(0);
        soundEngine.triggerOn();
    }
    if(key == 'w'){
        setCurrentChord(1);
        soundEngine.triggerOn();
    }
    if(key == 'e'){
        setCurrentChord(2);
        soundEngine.triggerOn();
    }
    if(key == 'r'){
        setCurrentChord(3);
        soundEngine.triggerOn();
    }
    if(key == 'a'){
        setCurrentChord(4);
        soundEngine.triggerOn();
    }
    if(key == 's'){
        setCurrentChord(5);
        soundEngine.triggerOn();
    }
    if(key == 'd'){
        setCurrentChord(6);
        soundEngine.triggerOn();
    }
    
    if(key == '1'){
        chordsEngine.decreaseMode();
    }
    if(key == '2'){
        chordsEngine.increaseMode();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    //Check Keyboard Interface
    if(key != '1' || key != '2')
        soundEngine.triggerOff();
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    int intersection = -1;
    
    for(int i = 0; i < chordButtons.size(); i++){
        if(chordButtons[i].inside(x, y) == true){
            intersection = i;
            setCurrentChord(intersection);
            
            break;
        }
    }
    
    if(intersection != -1){
        soundEngine.triggerOn();
    }
}

void ofApp::setCurrentChord(int chord){

    chordsEngine.setCurrentChord(chord, numVoices);
    
    for(int i = 0; i < numVoices; i++){
        chordsEngine.currentChord[i]->toInt() >> soundEngine.polysynth.voices[i].in("pitch");
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
    soundEngine.triggerOff();
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
