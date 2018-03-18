#ifndef _CD_H
#define _CD_H

class CD {
private:
  char performers[50];
  char label[20];
  int selections;     // Number of songs
  double playtime;    // CD length

protected:


public:
  CD(char *s1, char *s2, int n, double x);
  CD(const CD& cd);
  CD();
  virtual ~CD();

  virtual void Report() const; // All of disc informations;
  CD& operator=(const CD& cd);
};

#endif
