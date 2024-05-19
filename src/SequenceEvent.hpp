//
//  SequenceEvent.hpp
//  Chords
//
//  Created by Laura on 5/5/24.
//

#ifndef SequenceEvent_hpp
#define SequenceEvent_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Note.hpp"

class SequenceEvent {
public:
    double time;
    bool trigger;
    std::vector<Note> pitches;
    
    bool operator< (const SequenceEvent &other) const {
            return time < other.time;
    }
};

#endif /* SequenceEvent_hpp */
