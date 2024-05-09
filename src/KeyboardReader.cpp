//
//  KeyboardReader.cpp
//  Chords
//
//  Created by Laura on 2/5/24.
//

#include "KeyboardReader.hpp"

void KeyboardReader::keyPressed(int key){
    keyIsDown[key] = true;
}

void KeyboardReader::keyReleased(int key){
    keyIsDown[key] = false;
}

int KeyboardReader::checkModeKeys(){
    
    if(keyIsDown['1']){
        return -1;
    }
    if(keyIsDown['2']){
        return 1;
    }
    
    return 0;
}

int KeyboardReader::checkChordsKeys(){
    
        if(keyIsDown['q']){
            return 0;
        }
        if(keyIsDown['w']){
            return 1;
        }
        if(keyIsDown['e']){
            return 2;
        }
        if(keyIsDown['r']){
            return 3;
        }
        if(keyIsDown['a']){
            return 4;
        }
        if(keyIsDown['s']){
            return 5;
        }
        if(keyIsDown['d']){
            return 6;
        }
    
    return -1;
}

bool KeyboardReader::checkVoiceModifier(){
    if(keyIsDown['v']){
        return true;
    }
    
    return false;
}

std::vector<int> KeyboardReader::checkPerformKeys(){
    
    std::vector<int> perform;
        
    if(keyIsDown['q']){
        perform.push_back(0);
    }
    if(keyIsDown['w']){
        perform.push_back(1);
    }
    if(keyIsDown['e']){
        perform.push_back(2);
    }
    if(keyIsDown['r']){
        perform.push_back(3);
    }
    if(keyIsDown['a']){
        perform.push_back(4);
    }
    if(keyIsDown['s']){
        perform.push_back(5);
    }
    if(keyIsDown['d']){
        perform.push_back(6);
    }
    
    return perform;
}
