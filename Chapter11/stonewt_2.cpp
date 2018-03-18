#include "stonewt_2.h"

StoneWT::StoneWT() {
  m_Pounds = 0;
  m_Mode = POUNDS;
}

StoneWT::StoneWT(double pounds) {
  m_Pounds = pounds;
  m_Mode = POUNDS;
}

StoneWT::StoneWT(unsigned int stones, double pounds) {
  m_Pounds = stones * LBS_PER_STN + pounds;
  m_Mode = STONES;
}

StoneWT::~StoneWT() {
  
}

StoneWT::Weight StoneWT::lbsToStones() const {
  Weight weight {};

  weight.stones = (unsigned int)(m_Pounds) / LBS_PER_STN;
  weight.pounds = (unsigned int)(m_Pounds) % LBS_PER_STN + m_Pounds - (unsigned int)(m_Pounds);

  return weight;
}

void StoneWT::setMode(Mode mode) {
  m_Mode = mode;
}

void StoneWT::setWeight(double pounds) {
  m_Pounds = pounds;
}

bool StoneWT::operator<(const StoneWT& s) const {
  return m_Pounds < s.m_Pounds;
}

bool StoneWT::operator>(const StoneWT& s) const {
  return m_Pounds > s.m_Pounds;
}

bool StoneWT::operator==(const StoneWT &s) const {
  return m_Pounds == s.m_Pounds;
}

std::ostream& operator<<(std::ostream& os, const StoneWT& s) {
  if (s.m_Mode == StoneWT::POUNDS)
    os << s.m_Pounds << " lbs";
  else if (s.m_Mode == StoneWT::STONES) {
    StoneWT::Weight weight = s.lbsToStones();
    os << weight.stones << " stn, " << weight.pounds << " lbs";
  }
  return os;
}
