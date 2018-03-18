#ifndef _STONE_WT
#define _STONE_WT

#include <ostream>

class Stonewt {
public:
  enum Mode {STONE, LBS_INT, LBS_W_FRACT};

private:
  enum {Lbs_per_stn = 14};

  Mode mode;
  double pounds;
  void getStones(int& stone, double& lbs) const;
public:
  Stonewt(double lbs, Mode m = LBS_W_FRACT);
  Stonewt(int stn, double lbs);
  
  Stonewt();
  ~Stonewt();

  void mode_STONE() {mode = STONE;}
  void mode_LBS_INT() {mode = LBS_INT;}
  void mode_LBS_W_FRACT() {mode = LBS_W_FRACT;}

  friend Stonewt operator+(const Stonewt& s1, const Stonewt& s2);
  friend Stonewt operator-(const Stonewt& s1, const Stonewt& s2);
  friend Stonewt operator*(double n, const Stonewt& s);
  friend std::ostream& operator<<(std::ostream& os, const Stonewt& s);
};

#endif
