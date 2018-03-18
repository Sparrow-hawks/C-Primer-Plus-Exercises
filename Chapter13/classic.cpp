#include <iostream>
#include <cstring>
#include "classic.h"

Classic::Classic(char *s1, char *s2, char *s3, int n, double x) : CD(s2, s3, n, x) {
  strncpy(discMainSong, s1, 49);
}

Classic::Classic() : CD() {
  discMainSong[0] = '\0';
}

Classic::~Classic() {

}

Classic::Classic(const Classic& cl) : CD(cl) {
  strcpy(discMainSong, cl.discMainSong);
}

Classic& Classic::operator=(const Classic& cl) {
  if (&cl != this) {
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
