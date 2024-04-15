//
//  ChordsEngine.hpp
//  Chords
//
//  Created by Laura on 12/4/24.
//

#ifndef ChordsEngine_hpp
#define ChordsEngine_hpp

#include <stdio.h>
#include "ofxMusicTheory.h"

using namespace MusicTheory;

class ChordsEngine {
  
public:
    
    deque<NotePtr> currentChord;
    std::vector<deque<NotePtr>> chords;
    std::vector<ScalePtr>modes;
    int currentMode;
    
    void setup();
    void setupChords(ScalePtr scale);
    void setupModes(NotePtr root);
    void decreaseMode();
    void increaseMode();

    string currentChordName();
    std::vector<int> noteIndexesChordFromNoteNumber(int note);

    void setCurrentChord(int index, int voices);

};

#endif /* ChordsEngine_hpp */
