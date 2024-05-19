//
//  ChordsEngine.hpp
//  Chords
//
//  Created by Laura on 12/4/24.
//

#ifndef ChordsEngine_hpp
#define ChordsEngine_hpp

#include <stdio.h>
#include "Note.hpp"
#include "Scale.hpp"


class ChordsEngine {
  
public:
    ChordsEngine();
    std::vector<Note> currentChord;
    std::vector<std::vector<Note>> chords;
    std::vector<Scale> modes;
    Note root;
    int currentMode;
    int numVoices;
    std::vector<int> activeVoices;
    
    void setup(int voices);
    void setupChords(Scale mode);
    void setupModes(Note root);
    void decreaseMode();
    void increaseMode();
    void increaseMode(int step);
    void setActiveVoices(std::vector<int> voices);

    std::string currentChordName();
    std::vector<int> noteIndexesChordFromNoteNumber(int note);

    void setCurrentChord(int index, int voices);

private:
    std::vector<Note> trimChordToVoices(std::vector<Note> chord, int voices);
};

#endif /* ChordsEngine_hpp */
