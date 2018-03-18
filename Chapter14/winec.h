#ifndef _WINEC_H
#define _WINEC_H

#include "pair.h"
#include <valarray>
#include <string>

class Wine {
private:
  typedef std::valarray<int> ArrayInt;
  typedef Pair<ArrayInt, ArrayInt> PairArray;

  const char *m_Label;
  PairArray m_Data;

public:
  Wine();
  Wine (const char *l, int y, const int yr[], const int bot[]);
  Wine (const char *l, int y);
  ~Wine();

  const char* label() const;
  int sum() const;
  void GetBottles();
  void Show() const;

};

#endif
