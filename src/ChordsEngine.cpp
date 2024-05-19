//
//  ChordsEngine.cpp
//  Chords
//
//  Created by Laura on 12/4/24.
//

#include "ChordsEngine.hpp"

ChordsEngine::ChordsEngine(){
    root = Note(NoteType::C);
    setup(7);
}

void ChordsEngine::setup(int voices){
    
    setupModes(root);
    setupChords(modes[0]);
    
    currentMode = 0;
    currentChord = chords[0];
    numVoices = voices;
    activeVoices.push_back(0);
    activeVoices.push_back(1);
    activeVoices.push_back(2);
    activeVoices.push_back(3);
    activeVoices.push_back(4);
    activeVoices.push_back(5);
    activeVoices.push_back(6);

}

void ChordsEngine::setupChords(Scale mode){
    chords.clear();
    
    for (std::size_t i=0; i < 7; i++) {
        
        std::vector<int> indexes = noteIndexesChordFromNoteNumber(int(i));
        
        std::vector<Note> chord;
        for(int j = 0; j < indexes.size(); j++){
            
            int index = indexes[j];
        
            Note note = Note(0);
            int interval = 0;
            if(index > 13){
                index = index - 14;
                interval = mode.intervals[index];
                note = root + interval;
                note.octave += 2;
            }
            else if(index > 6){
                index = index - 7;
                interval = mode.intervals[index];
                note = root + interval;
                note.octave += 1;
            }
            else{
                interval = mode.intervals[index];
                note = root + interval;
            }
            chord.push_back(note);
        }

        chords.push_back(chord);
    }
}

void ChordsEngine::setupModes(Note root){
    
    root = root;
    
    for(int i = 0; i < 7; i++){
        switch (i) {
            case 0:
                modes.push_back(Scale::ioian);
                break;
            case 1:
                modes.push_back(Scale::dorian);
                break;
            case 2:
                modes.push_back(Scale::phrygian);
                break;
            case 3:
                modes.push_back(Scale::lydian);
                break;
            case 4:
                modes.push_back(Scale::mixolydian);
                break;
            case 5:
                modes.push_back(Scale::aeolian);
                break;
            case 6:
                modes.push_back(Scale::locrian);
                break;
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

std::string ChordsEngine::currentChordName(){
    
//    vector<string> analyse = Chord::analyse(trimChordToVoices(currentChord, 3), true, false, false);
//    if(analyse.size() > 0)
//        return analyse[0];
    
    return "";
}

void ChordsEngine::increaseMode(int step){
    if(step == 1)
        increaseMode();
    else if(step == -1)
        decreaseMode();
}

void ChordsEngine::increaseMode(){
    currentMode++;
    if(currentMode > 6)
        currentMode = 6;
    
    setupChords(modes[currentMode]);
    
}

void ChordsEngine::decreaseMode(){
    currentMode--;
    if(currentMode < 0)
        currentMode = 0;
    
    setupChords(modes[currentMode]);
}

void ChordsEngine::setCurrentChord(int index, int voices){
    currentChord = trimChordToVoices(chords[index], voices);
    
    numVoices = voices;
}

std::vector<Note> ChordsEngine::trimChordToVoices(std::vector<Note> chord, int voices){
    std::vector<Note> trimmedChord;
    
    for(int i = 0; i < voices; i++){
        trimmedChord.push_back(chord[i]);
    }
    
    return trimmedChord;
}

void ChordsEngine::setActiveVoices(std::vector<int> voices){
    for(int i = 0; i < voices.size(); i++){
        std::vector<int>::iterator it = std::find(activeVoices.begin(), activeVoices.end(), voices[i]);
        if(it != activeVoices.end()){
            activeVoices.erase(it);
        }
        else{
            activeVoices.push_back(voices[i]);
        }
    }
    
    std::vector<int> activeVoicesCopy = activeVoices;
    std::sort(activeVoicesCopy.begin(), activeVoicesCopy.end());
    activeVoices = activeVoicesCopy;
}

