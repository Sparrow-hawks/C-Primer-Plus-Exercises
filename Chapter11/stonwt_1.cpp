#include <iostream>
#include "stonwt_1.h"

using std::cout;

Stonewt::Stonewt(double lbs, Mode m) {
  mode = m;
  if (mode == STONE) {
    pounds = lbs / Lbs_per_stn;
  } else if (mode == LBS_W_FRACT) {
    pounds = lbs;
  } else if (mode == LBS_INT) {
    pounds = int(lbs);
  }
}

Stonewt::Stonewt(int stn, double lbs) {
  pounds = stn * Lbs_per_stn + lbs;
  mode = LBS_W_FRACT;
}

Stonewt::Stonewt() {
  pounds = 0; mode = LBS_W_FRACT;
}

Stonewt::~Stonewt() {

}

void Stonewt::getStones(int &stone, double &lbs) const {
  stone = int(pounds) / Lbs_per_stn;
  lbs = int(pounds) % Lbs_per_stn + pounds - int(pounds);
}

Stonewt operator+(const Stonewt& s1, const Stonewt& s2) {
  return Stonewt(s1.pounds + s2.pounds);
}

Stonewt operator-(const Stonewt& s1, const Stonewt& s2) {
  return Stonewt(s1.pounds - s2.pounds);
}

Stonewt operator*(double n, const Stonewt& s) {
  return Stonewt(s.pounds * n);
}

std::ostream& operator<<(std::ostream& os, const Stonewt& s) {
  if (s.mode == Stonewt::STONE) {
    int stones = 0;
    double lbs = 0.0;
    s.getStones(stones, lbs);
    os << "Stones: " << stones << ", pounds: " << lbs;
  } else if (s.mode == Stonewt::LBS_INT) {
    os << "Integer pounds: " << (int) s.pounds;
  } else if (s.mode == Stonewt::LBS_W_FRACT) {
    os << "Pounds: " << s.pounds;
  }

  return os;
}
