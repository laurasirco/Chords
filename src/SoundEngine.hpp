//
//  SoundEngine.hpp
//  Chords
//
//  Created by Laura on 12/4/24.
//

#ifndef SoundEngine_hpp
#define SoundEngine_hpp

#include <stdio.h>
#include "ofxMidi.h"
#include "ofxPDSP.h"
#include "PolySynth.hpp"
#include "Sequence.hpp"
#include "ofxMusicTheory.h"

using namespace MusicTheory;

class SoundEngine {
    
public:
    pdsp::Engine engine;
    pdsp::ParameterGain gain;
    
    PolySynth polysynth;
    bool triggered;
    bool recording;
    bool eventAdded;
    
    Sequence sequence;
    
    void setup(int numVoices);
    
    void triggerOn(deque<NotePtr> pitches, std::vector<int> activeVoices);
    void triggerOff(deque<NotePtr> pitches, std::vector<int> activeVoices);
    
    void addEventToSequence(bool trigger, deque<NotePtr> pitches, std::vector<int> activeVoices);
private:
    void triggerOnSelectedVoices(std::vector<int> selectedVoices);

};

#endif /* SoundEngine_hpp */
