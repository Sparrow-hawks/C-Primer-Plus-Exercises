#ifndef _EXC_MEAN_H
#define _EXC_MEAN_H

#include <iostream>
#include <stdexcept>
#include <string>

class bad : public std::logic_error {
private:
  double v1;
  double v2;

protected:
  double getV1() const {return v1;}
  double getV2() const {return v2;}

public:
  bad(double a, double b) : std::logic_error("Wrong arguments\n"), v1(a), v2(b) {}
  virtual ~bad() {}

  virtual void show() const = 0;
};

class bad_hmean : public bad {
private:

public:
  bad_hmean(double a = 0, double b = 0) : bad(a, b) {}

  void show() const;
};

inline void bad_hmean::show() const {
  std::cout << "Function hmean() throw exception!\n";
  std::cout << "Arguments: " << bad::getV1() << ", " << bad::getV2() << std::endl;
}

class bad_gmean : public bad {
private:

public:
  bad_gmean(double a = 0, double b = 0) : bad(a, b) {}

  void show() const;
};

inline void bad_gmean::show() const {
  std::cout << "Function gmean() throw exception!\n";
  std::cout << "Arguments: " << bad::getV1() << ", " << bad::getV2() << std::endl;
}

#endif
