#ifndef _CLASSIC_H
#define _CLASSIC_H

#include "cd_2.h"

class Classic : public CD {
private:

  char *discMainSong;
public:
  Classic(char *s1, char *s2, char *s3, int n, double x);
  Classic();
  Classic(const Classic& cl);
  ~Classic();

  Classic& operator=(const Classic& cl);

  void Report() const;
};

#endif
