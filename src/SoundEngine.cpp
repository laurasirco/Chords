//
//  SoundEngine.cpp
//  Chords
//
//  Created by Laura on 12/4/24.
//

#include "SoundEngine.hpp"

void SoundEngine::setup(int numVoices){
    
    polysynth.setup(numVoices);
    
    for(int i = 0; i < numVoices; i++){
        polysynth.voices[i] >> gain.ch(0);
        polysynth.voices[i] >> gain.ch(1);
    }
    
    gain.ch(0) >> engine.audio_out(0);
    gain.ch(1) >> engine.audio_out(1);
    
    gain.enableSmoothing(50.f);
    
//    engine.listDevices();
    engine.setDeviceID(3);
    engine.setup( 44100, 512, 3);
}

void SoundEngine::triggerOn(){
    polysynth.triggerOnAllVoices();
}

void SoundEngine::triggerOff(){
    polysynth.triggerOffAllVoices();
}
