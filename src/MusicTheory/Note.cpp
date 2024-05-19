//
//  Note.cpp
//  Chords
//
//  Created by Laura on 14/5/24.
//

#include "Note.hpp"
#include <math.h>

Note::Note(){
    type = NoteType::C;
    octave = 3;
}

  Note::~Note() {
  }

  Note::Note(int midiNoteNumber) {
    octave = (midiNoteNumber / 12) - 1;
    type = NoteType(midiNoteNumber - ((octave + 1) * 12));
  }

  Note::Note(NoteType noteType, int octave) {
    type = noteType;
    this->octave = octave;
  }
  
  int Note::getMIDINoteNumber() {
    return type + ((octave + 1) * 12);
  }

  double Note::getFrequency(double base) {
    double fn = powf(2.0, float(getMIDINoteNumber() - 69) / 12.0);
    return fn * base;
  }

  bool Note::operator==(Note &lhs) {
    return getMIDINoteNumber() == lhs.getMIDINoteNumber();
  }

  Note Note::operator+(const Interval &lhs) {
    return Note(getMIDINoteNumber() + lhs.halfsteps);
  }

  Note Note::operator-(const Interval &lhs) {
    return Note(getMIDINoteNumber() - lhs.halfsteps);
  }

  Note Note::operator+(const int &lhs) {
    return Note(getMIDINoteNumber() + lhs);
  }

  Note Note::operator-(const int &lhs) {
    return Note(getMIDINoteNumber() - lhs);
  }
