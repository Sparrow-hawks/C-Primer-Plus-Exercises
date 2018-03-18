//Book:       C++ Primer Plus
//Chapter:    11
//Exercise:   5

#include <iostream>
#include "stonwt_1.h"

using std::cout;
using std::endl;

int main() {
  Stonewt incognito = 275;
  Stonewt wolfe(285.7);
  Stonewt taft(21, 8);

  incognito.mode_LBS_INT();
  cout << "Celebrite weight " << incognito << endl;
  wolfe.mode_LBS_W_FRACT();
  cout << "Detective weight " << wolfe << endl;
  cout << "President weight " << taft << endl;

  incognito = 267.8;
  taft = 325;
  cout << "After dinner celebrite weight " << incognito << endl;
  cout << "After dinner president weight " << taft << endl;

  Stonewt temp = wolfe + taft;
  cout << "Detective + President weight " << temp << endl;

  cout << "Celebrite weight * 1.5 " << 1.5 * incognito << endl;
  
  return 0;
}
