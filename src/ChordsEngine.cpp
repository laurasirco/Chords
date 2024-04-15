//
//  ChordsEngine.cpp
//  Chords
//
//  Created by Laura on 12/4/24.
//

#include "ChordsEngine.hpp"

void ChordsEngine::setup(){
    
    setupModes(Note::create("C"));
    setupChords(modes[0]);
    
    currentMode = 0;
    currentChord = chords[0];
}

void ChordsEngine::setupChords(ScalePtr scale){
    chords.clear();
    
    for (std::size_t i=0; i < 7; i++) {
        
        std::vector<int> indexes = noteIndexesChordFromNoteNumber(int(i));
        
        deque<NotePtr> chord;
        for(int j = 0; j < indexes.size(); j++){
            
            int index = indexes[j];
        
            NotePtr note;
            if(index > 13){
                index = index - 14;
                note = scale->notes[index]->getOctaveUp()->getOctaveUp();
            }
            else if(index > 6){
                index = index - 7;
                note = scale->notes[index]->getOctaveUp();
            }
            else{
                note = scale->notes[index];
            }
            chord.push_back(note);
        }

        chords.push_back(chord);
    }
}

void ChordsEngine::setupModes(NotePtr root){
    for(int i = 0; i < 7; i++){
        switch (i) {
            case 0:
                modes.push_back(Scale::getIonian(root));
            case 1:
                modes.push_back(Scale::getDorian(root));
            case 2:
                modes.push_back(Scale::getPhrygian(root));
            case 3:
                modes.push_back(Scale::getLydian(root));
            case 4:
                modes.push_back(Scale::getMixolydian(root));
            case 5:
                modes.push_back(Scale::getAeolian(root));
            case 6:
                modes.push_back(Scale::getLocrian(root));
            default:
                break;
        }
    }
}

std::vector<int> ChordsEngine::noteIndexesChordFromNoteNumber(int note){
    
    switch (note) {
        case 0:
            return {0, 2, 4, 6, 8, 10, 12};
            break;
        case 1:
            return {1, 3, 5, 7, 9, 11, 13};
            break;
        case 2:
            return {2, 4, 6, 8, 10, 12, 14};
            break;
        case 3:
            return {3, 5, 7, 9, 11, 13, 15};
            break;
        case 4:
            return {4, 6, 8, 10, 12, 14, 16};
            break;
        case 5:
            return {5, 7, 9, 11, 13, 15, 18};
            break;
        case 6:
            return {6, 8, 10, 12, 14, 16, 19};
            break;
        default:
            return {0, 2, 4, 13, 15, 17, 20};
            break;
    }
}

string ChordsEngine::currentChordName(){
    vector<string> analyse = Chord::analyse(currentChord, true, false, false);
    if(analyse.size() > 0)
        return analyse[0];
    
    return "";
}

void ChordsEngine::increaseMode(){
    currentMode--;
    if(currentMode < 0)
        currentMode = 0;
    
    setupChords(modes[currentMode]);
}

void ChordsEngine::decreaseMode(){
    currentMode++;
    if(currentMode > 6)
        currentMode = 6;
    
    setupChords(modes[currentMode]);
}

void ChordsEngine::setCurrentChord(int index, int voices){
    currentChord = chords[index];
    
    deque<NotePtr> trimmedChord;
    
    for(int i = 0; i < voices; i++){
        trimmedChord.push_back(currentChord[i]);
    }
}
