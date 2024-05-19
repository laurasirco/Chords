//
//  Interval.hpp
//  Chords
//
//  Created by Laura on 14/5/24.
//

#ifndef Interval_hpp
#define Interval_hpp

#include <stdio.h>

struct Interval {
    Interval(int halfsteps);
    int halfsteps;

    bool operator==(const Interval &lhs) const;
    Interval operator+(const Interval &lhs) const;
    Interval operator-(const Interval &lhs) const;

    const static Interval P1; // Unison
    const static Interval m2; // Minor Second
    const static Interval M2; // Major Second
    const static Interval m3; // Minor Third
    const static Interval M3; // Major Third
    const static Interval P4; // Perfect Fourth
    const static Interval d5; // Tritone
    const static Interval P5; // Perfect Fifth
    const static Interval m6; // Minor Sixth
    const static Interval M6; // Major Sixth
    const static Interval m7; // Minor Seventh
    const static Interval M7; // Major Seventh
    const static Interval P8; // Octave
  };

#endif /* Interval_hpp */
