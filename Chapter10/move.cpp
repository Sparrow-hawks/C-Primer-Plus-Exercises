#include <iostream>
#include "move.h"

Move::Move(double a, double b) : x {a}, y{b} {

}

void Move::show() const {
  std::cout << "X: " << x << " Y: " << y;
}

void Move::reset(double a, double b) {
  x = a;
  y = b;
}

Move Move::add(const Move& m) const {
  return Move(m.x + x, m.y + y);
}
