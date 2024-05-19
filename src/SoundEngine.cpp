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
    engine.setDeviceID(2);
    engine.setup( 44100, 512, 3);
    
    engine.sequencer.setTempo(120.0);
    engine.sequencer.play();
    engine.sequencer.setMaxBars(4.0);
    
    triggered = false;
    recording = true;
}

void SoundEngine::triggerOn(std::vector<Note> pitches, std::vector<int> activeVoices){
    if(!triggered){
        if(activeVoices.size() > 0){
            triggerOnSelectedVoices(activeVoices);
        }
        else{
            polysynth.triggerOnAllVoices();
        }
        triggered = true;
        
        if(recording){
            addEventToSequence(true, pitches, activeVoices);
        }
    }
}

void SoundEngine::triggerOff(std::vector<Note> pitches, std::vector<int> activeVoices){
    if(triggered){
        polysynth.triggerOffAllVoices();
        triggered = false;
        
        if(recording){
            addEventToSequence(false, pitches, activeVoices);
        }
    }
}

void SoundEngine::triggerOnSelectedVoices(std::vector<int> selectedVoices){
    polysynth.triggerOffAllVoices();
    polysynth.triggerOnSelectedVoices(selectedVoices);
}

void SoundEngine::addEventToSequence(bool trigger, std::vector<Note> pitches, std::vector<int> activeVoices){
    
    if(activeVoices.size() > 0){
        std::vector<Note> selectedPitches;
        for(int i = 0; i < activeVoices.size(); i++)
            selectedPitches.push_back(pitches[i]);
        sequence.addEvent(engine.sequencer.meter_playhead(), trigger, selectedPitches);
//        cout << trigger << ", " << selectedPitches.size() << ", " << engine.sequencer.meter_playhead() << endl;

    }
    else{
        sequence.addEvent(engine.sequencer.meter_playhead(), trigger, pitches);
//        cout << trigger << ", " << pitches.size() << ", " << engine.sequencer.meter_playhead() << endl;

    }
    
}
