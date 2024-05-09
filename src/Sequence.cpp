//
//  Sequence.cpp
//  Chords
//
//  Created by Laura on 5/5/24.
//

#include "Sequence.hpp"

void Sequence::addEvent(double t, bool trigger, deque<NotePtr> pitch){
    
    SequenceEvent event;
    event.time = t;
    event.trigger = trigger;
    event.pitches = pitch;
    
    addedTriggerOn = trigger;
    
    events.push_back(event);
    
    vector<SequenceEvent> events_copy = events;
    std::sort(events_copy.begin(), events_copy.end());
    events = events_copy;
}


