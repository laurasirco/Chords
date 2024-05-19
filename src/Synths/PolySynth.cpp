//
//  PolySynth.cpp
//  Chords
//
//  Created by Laura on 4/4/24.
//

#include "PolySynth.hpp"

void PolySynth::setup(int numVoices ){
    
    voices.resize( numVoices );
    
    for( std::size_t i=0; i<voices.size(); ++i ){
        voices[i].setup( *this, i );
    }
    
    ui.setName("synth parameters");
    ui.add(pw.set("pulse width", 0.5f, 0.0f, 1.0f) );
    ui.add(pwmAmt.set("pwm amount", 0.3f, 0.0f, 0.5f) );
    ui.add(pwmSpeed.set("pwm speed (hz)", 0.5f, 0.005f, 1.5f));
    cutoff.enableSmoothing(200.0f);
    ui.add(cutoff.set("cutoff pitch", 82, 20, 136));
    ui.add(reso.set("resonance", 0.0f, 0.0f, 1.0f) );
    ui.add(modAttack.set("mod env attack", 400, 0, 1200) );
    ui.add(modRelease.set("mod env release", 900, 0, 1200));
    ui.add(modAmt.set("mod env amount", 48, 0, 84));
    
}

void PolySynth::triggerOnAllVoices(){
    for(int i = 0; i < voices.size(); i++){
        voices[i].triggerOn();
    }
}

void PolySynth::triggerOffAllVoices(){
    for(int i = 0; i < voices.size(); i++){
        voices[i].triggerOff();
    }
}

void PolySynth::triggerOnSelectedVoices(std::vector<int> selectedVoices){
    
    for(int i = 0; i < selectedVoices.size(); i++){
        voices[selectedVoices[i]].triggerOn();
    }
    
}

void PolySynth::setPitchForVoice(int pitch, int voice){
    cout << "voice: " << voice << ", pitch: " << pitch << endl;
    pitch >> voices[voice].in("pitch");
}

void PolySynth::Voice::setup( PolySynth & ui, int v ){
    
    addModuleInput("pitch", osc.in_pitch());
    addModuleOutput("signal", amp);

    osc.out_sine() * 1.0f  >> amp;
    trigger.out_trig() >> env;
    env.set(4000.0f, 50.0f, 1.0f, 8000.0f) >> amp.in_mod();
    200.0f >> filter.in_cutoff();
    0.3f  >> filter.in_reso();
    

}

void PolySynth::Voice::triggerOn(){
    trigger.trigger(1.0f);
}

void PolySynth::Voice::triggerOff(){
    trigger.off();
}

