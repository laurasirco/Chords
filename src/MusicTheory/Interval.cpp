//
//  Interval.cpp
//  Chords
//
//  Created by Laura on 14/5/24.
//

#include "Interval.hpp"

Interval::Interval(int halfsteps) : halfsteps(halfsteps) {}

  bool Interval::operator==(const Interval &lhs) const {
    return halfsteps == lhs.halfsteps;
  }

  Interval Interval::operator+(const Interval &lhs) const {
    return Interval{halfsteps + lhs.halfsteps};
  }

  Interval Interval::operator-(const Interval &lhs) const {
    return Interval{halfsteps - lhs.halfsteps};
  }

//  const Interval 0 = Interval(0);
//  const Interval 1 = Interval(1);
//  const Interval 1 = Interval(2);
//  const Interval Interval::m3 = Interval(3);
//  const Interval Interval::M3 = Interval(4);
//  const Interval 5 = Interval(5);
//  const Interval 6 = Interval(6);
//  const Interval 7 = Interval(7);
//  const Interval 9 = Interval(8);
//  const Interval 9 = Interval(9);
//  const Interval 10 = Interval(10);
//  const Interval 10 = Interval(11);
//  const Interval Interval::P8 = Interval(12);
