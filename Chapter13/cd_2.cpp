#include <iostream>
#include <cstring>
#include "cd_2.h"

CD::CD(char *s1, char *s2, int n, double x) : selections(n), playtime(x) {
  performers = new char [strlen(s1) + 1];
  label = new char [strlen(s2) + 1];

  strcpy(performers, s1);
  strcpy(label, s2);
}

CD::CD() : selections(0), playtime(0.0) {
  performers = new char [1];
  label = new char [1];

  performers[0] = '\0';
  label[0] = '\0';
}

CD::CD(const CD& disc) {
  selections = disc.selections;
  playtime = disc.playtime;

  performers = new char [strlen(disc.performers) + 1];
  label = new char [strlen(disc.label) + 1];

  strcpy(performers, disc.performers);
  strcpy(label, disc.label);
}

CD::~CD() {
  delete [] performers;
  delete [] label;
}

CD& CD::operator=(const CD& disc) {
  if (&disc != this) {
    delete [] performers;
    delete [] label;

    selections = disc.selections;
    playtime = disc.playtime;

    performers = new char [strlen(disc.performers) + 1];
    label = new char [strlen(disc.label) + 1];

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
