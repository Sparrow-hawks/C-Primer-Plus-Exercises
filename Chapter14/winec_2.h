#ifndef _WINEC_H
#define _WINEC_H

#include "pair.h"
#include <valarray>
#include <string>

class Wine : private Pair<std::valarray<int>, std::valarray<int> >{
private:
  const std::string m_Label;

public:
  Wine();
  Wine (const char *l, int y, const int yr[], const int bot[]);
  Wine (const char *l, int y);
  ~Wine();

  const std::string& label() const;
  int sum() const;
  void GetBottles();
  void Show() const;

};

#endif
