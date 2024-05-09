//
//  KeyboardReader.hpp
//  Chords
//
//  Created by Laura on 2/5/24.
//

#ifndef KeyboardReader_hpp
#define KeyboardReader_hpp

#include "ofMain.h"

class KeyboardReader {
    
public:
    void keyPressed(int key);
    void keyReleased(int key);
    
    int checkChordsKeys();
    int checkModeKeys();
    bool checkVoiceModifier();
    std::vector<int> checkPerformKeys();
private:
    bool keyIsDown[255];
};

#endif /* KeyboardReader_hpp */
