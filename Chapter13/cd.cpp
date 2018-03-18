#include <iostream>
#include <cstring>
#include "cd.h"

CD::CD(char *s1, char *s2, int n, double x) : selections(n), playtime(x) {
  strncpy(performers, s1, 49);
  strncpy(label, s2, 19);
}

CD::CD() : selections(0), playtime(0.0) {
  performers[0] = '\0';
  label[0] = '\0';
}

CD::CD(const CD& disc) {
  selections = disc.selections;
  playtime = disc.playtime;

  strcpy(performers, disc.performers);
  strcpy(label, disc.label);
}

CD::~CD() {

}

CD& CD::operator=(const CD& disc) {
  if (&disc != this) {
    selections = disc.selections;
    playtime = disc.playtime;

    strcpy(performers, disc.performers);
    strcpy(label, disc.label);
  }
  return *this;
}

void CD::Report() const {
  using std::cout;
  using std::endl;

  cout << "Artist: " << performers << endl;
  cout << "Label:  " << label << endl;
  cout << "Disc info: " << selections << " songs, " << playtime << " hour." << endl;
}
