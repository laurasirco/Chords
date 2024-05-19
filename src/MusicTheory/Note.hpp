//
//  Note.hpp
//  Chords
//
//  Created by Laura on 14/5/24.
//

#ifndef Note_hpp
#define Note_hpp

#include <stdio.h>
#include "Interval.hpp"

enum NoteType {
    C,
    DFlat,
    D,
    EFlat,
    E,
    F,
    GFlat,
    G,
    AFlat,
    A,
    BFlat,
    B
};

class Note {
public:
    Note();
    Note(int midiNoteNumber);
    Note(NoteType noteType, int octave = 4);
    ~Note();
    
    int getMIDINoteNumber();
    int getPianoKeyIndex();
    double getFrequency(double base = 440.0);
    
    NoteType type;
    int octave;
    
    bool operator==(Note &lhs);
    Note operator+(const Interval &lhs);
    Note operator-(const Interval &lhs);
    Note operator+(const int &lhs);
    Note operator-(const int &lhs);
};

#endif /* Note_hpp */
