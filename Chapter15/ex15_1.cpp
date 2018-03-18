// Book:      C++ Primer Plus
// Chapter:   15
// Exercise:  1

#include <iostream>
#include "tv.h"

int main() {
  using std::cout;

  Tv s42;
  cout << "Initial TV42 settings: \n";
  s42.settings();
  s42.onoff();
  s42.chanup();
  cout << "\nNew TV42 settings: \n";
  s42.settings();

  Remote grey;

  grey.set_chan(s42, 10);
  grey.volup(s42);
  grey.volup(s42);
  cout << "\nTV42 settings after remote use:\n";
  s42.settings();

  Tv s58(Tv::On);
  s58.set_mode();
  grey.set_chan(s58, 28);
  cout << "\nTV58 settings:\n";
  s58.settings();

  cout << "\nRemote default mode:\n";
  grey.show_mode();
  s58.set_remote_mode(grey);
  cout << "\nTV58 switch remote mode:\n";
  grey.show_mode();

  return 0;
}
