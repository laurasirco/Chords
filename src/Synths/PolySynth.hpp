//
//  PolySynth.hpp
//  Chords
//
//  Created by Laura on 4/4/24.
//

#include <stdio.h>
#include "ofMain.h"
#include "ofxPDSP.h"

#pragma once


class PolySynth : public pdsp::Patchable {

public:
    
    void triggerOnAllVoices();
    void triggerOffAllVoices();
    void triggerOnSelectedVoices(std::vector<int> selectedVoices);
    void setPitchForVoice(int pitch, int voice);
    
    class Voice : public pdsp::Patchable { // internal class ----------------------
        //friend class PolySynth;
        
    public:
        Voice(){}
        Voice(const Voice& other){}
        
        void setup(PolySynth & ui, int v);
        
        void triggerOn();
        void triggerOff();
    private:
        pdsp::PatchNode     pitch_ctrl;
        pdsp::ADSR              env;
        pdsp::Amp           amp;
        pdsp::VAOscillator  osc;
        pdsp::Saturator1    drive; // distort the signal
        pdsp::VAFilter      filter; // 24dB multimode filter
        pdsp::TriggerControl    trigger;

     
    }; // end Voice class -------------------------------------------------------

    // public API --------------------------------------------------------------
    void setup( int numVoices );

    ofParameterGroup    ui;
    std::vector<Voice>  voices;
    
private: // --------------------------------------------------------------------
    pdsp::Parameter     cutoff;
    pdsp::Parameter     reso;
    pdsp::Parameter     modAttack;
    pdsp::Parameter     modRelease;
    pdsp::ParameterAmp  modAmt;
    
    pdsp::Parameter     pw;
    pdsp::Parameter     pwmSpeed;
    pdsp::ParameterAmp  pwmAmt;
    

};



