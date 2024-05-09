//
//  Sequence.hpp
//  Chords
//
//  Created by Laura on 5/5/24.
//

#ifndef Sequence_hpp
#define Sequence_hpp

#include <stdio.h>
#include "ofMain.h"
#include "SequenceEvent.hpp"

#endif /* Sequence_hpp */

class Sequence {
  
public:
    void addEvent(double t, bool trigger, deque<NotePtr> pitches);
    std::vector<SequenceEvent> events;
    
    bool addedTriggerOn;
};
