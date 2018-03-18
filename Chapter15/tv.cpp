#include <iostream>
#include "tv.h"

bool Tv::volup() {
  if (volume < MaxVal) {
    ++volume;
    return true;
  } else
    return false;
}

bool Tv::voldown() {
  if (volume > MinVal) {
    --volume;
    return true;
  } else
    return false;
}

void Tv::chanup() {
  if (channel < maxchannel)
    channel++;
  else
    channel = 1;
}

void Tv::chandown() {
  if (channel > 1)
    channel--;
  else
    channel = maxchannel;
}

void Tv::settings() const {
  using std::cout;
  using std::endl;

  cout << "TV is " << (state == Off ? "OFF" : "ON") << endl;
  if (state == On) {
    cout << "Volume:  " << volume << endl;
    cout << "Channel: " << channel << endl;
    cout << "Mode:    " << (mode == Antenna ? "Antenna" : "Cable") << endl;
    cout << "Source:  " << (input == TV ? "TV" : "DVD") << endl;
  }
}

void Remote::show_mode() const {
  using std::cout;
  using std::endl;

  cout << "Remote mode: " << (mode == Interactive ? "Interactive" : "Normal") << endl;
}
