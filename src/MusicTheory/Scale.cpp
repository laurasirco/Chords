//
//  Scale.cpp
//  Chords
//
//  Created by Laura on 14/5/24.
//

#include "Scale.hpp"

Scale::Scale(std::vector<int> intervals) {
    this->intervals = intervals;
}

std::vector<Note> Scale::getNotes(NoteType key, int octave) {
  std::vector<Note> notes;
  notes.reserve(this->intervals.size());

  Note root = Note(key, octave);
  for (int i = 0; i < this->intervals.size(); i++) {
    int current = this->intervals[i];
    notes.push_back(root + current);
  }

  return notes;
}

std::vector<int> majorIntervals = {0, 2, 4, 5, 7, 9, 11};
const Scale Scale::major = Scale(majorIntervals);

std::vector<int> minorIntervals = {0, 2, 3, 5, 7, 8, 10};
const Scale Scale::minor = Scale(minorIntervals);

std::vector<int> ioianIntervals = {0, 2, 4, 5, 7, 9, 11};
const Scale Scale::ioian = Scale(ioianIntervals);

std::vector<int> dorianIntervals = {0, 2, 3, 5, 7, 9, 10};
const Scale Scale::dorian = Scale(dorianIntervals);

std::vector<int> phrygianIntervals = {0, 1, 3, 5, 7, 8, 10};
const Scale Scale::phrygian = Scale(phrygianIntervals);

std::vector<int> lydianIntervals = {0, 2, 4, 6, 7, 9, 11};
const Scale Scale::lydian = Scale(lydianIntervals);

std::vector<int> mixolydianIntervals = {0, 2, 4, 5, 7, 9, 10};
const Scale Scale::mixolydian = Scale(mixolydianIntervals);

std::vector<int> aeolianIntervals = {0, 2, 3, 5, 7, 8, 10};
const Scale Scale::aeolian = Scale(aeolianIntervals);

std::vector<int> locrianIntervals = {0, 1, 3, 5, 6, 8, 10};
const Scale Scale::locrian = Scale(locrianIntervals);
