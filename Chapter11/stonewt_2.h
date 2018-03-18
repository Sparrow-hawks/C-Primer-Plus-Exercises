#ifndef _STONEWT_H
#define _STONEWT_H

#include <iostream>

class StoneWT {
public:
  enum Mode {POUNDS, STONES};

  struct Weight {
    unsigned int stones;
    double pounds;
  };

private:
  enum {LBS_PER_STN = 14};
  double m_Pounds;
  Mode m_Mode;

  Weight lbsToStones() const;
public:
  StoneWT(double pounds);
  StoneWT(unsigned int stones, double pounds);
  StoneWT();
  ~StoneWT();

  void setMode(Mode mode);
  void setWeight(double pounds);

  bool operator<(const StoneWT& s) const;
  bool operator>(const StoneWT& s) const;
  bool operator==(const StoneWT& s) const;

  bool operator!=(const StoneWT& s) const {return !(*this == s);}
  bool operator<=(const StoneWT& s) const {return !(*this > s);}
  bool operator>=(const StoneWT& s) const {return !(*this < s);}

  friend std::ostream& operator<<(std::ostream& os, const StoneWT& s);
};

#endif
