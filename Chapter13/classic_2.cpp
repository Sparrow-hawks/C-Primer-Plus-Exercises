#include <iostream>
#include <cstring>
#include "classic_2.h"

Classic::Classic(char *s1, char *s2, char *s3, int n, double x) : CD(s2, s3, n, x) {
  discMainSong = new char [strlen(s1) + 1];

  strcpy(discMainSong, s1);
}

Classic::Classic() : CD() {
  discMainSong = new char [1];

  discMainSong[0] = '\0';
}

Classic::~Classic() {
  delete [] discMainSong;
}

Classic::Classic(const Classic& cl) : CD(cl) {
  discMainSong = new char [strlen(cl.discMainSong) + 1];

  strcpy(discMainSong, cl.discMainSong);
}

Classic& Classic::operator=(const Classic& cl) {
  if (&cl != this) {
    delete [] discMainSong;

    discMainSong = new char [strlen(cl.discMainSong) + 1];
    strcpy(discMainSong, cl.discMainSong);

    CD::operator=(cl);
  }
  return *this;
}

void Classic::Report() const {
  using std::cout;
  using std::endl;

  cout << "Main song: " << discMainSong << endl;
  CD::Report();
}
