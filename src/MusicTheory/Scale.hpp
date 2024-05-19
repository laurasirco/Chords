//
//  Scale.hpp
//  Chords
//
//  Created by Laura on 14/5/24.
//

#ifndef Scale_hpp
#define Scale_hpp

#include <stdio.h>
#include <vector>
#include "Interval.hpp"
#include "Note.hpp"

class Scale {
public:
    Scale(std::vector<int> intervals);
    std::vector<int> intervals;
    std::vector<Note> getNotes(NoteType key, int octave);
    
    const static Scale major;
    const static Scale minor;
    
    const static Scale ioian;
    const static Scale dorian;
    const static Scale phrygian;
    const static Scale lydian;
    const static Scale mixolydian;
    const static Scale aeolian;
    const static Scale locrian;
};

#endif /* Scale_hpp */
