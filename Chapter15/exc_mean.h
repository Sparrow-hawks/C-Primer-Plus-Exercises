#ifndef _EXC_MEAN_H
#define _EXC_MEAN_H

#include <iostream>
#include <stdexcept>
#include <string>

class bad_hmean : public std::logic_error {
private:
  double v1;
  double v2;

public:
  bad_hmean(double a = 0, double b = 0) : std::logic_error("Wrong arguments: a = -b\n"), v1(a), v2(b) {}
};

class bad_gmean : public std::logic_error {
public:
  double v1;
  double v2;
  bad_gmean(double a = 0, double b = 0) : std::logic_error("Wrong arugments: a & b must be > 0\n"), v1(a), v2(b) {}
};

#endif
