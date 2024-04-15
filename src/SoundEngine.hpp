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

class SoundEngine {
    
public:
    pdsp::Engine engine;
    pdsp::ParameterGain gain;
    
    PolySynth polysynth;
    
    void setup(int numVoices);
    void triggerOn();
    void triggerOff();
};

#endif /* SoundEngine_hpp */
