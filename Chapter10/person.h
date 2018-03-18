#ifndef _PERSON_H
#define _PERSON_H

#include <string>

class Person {
private:
  static const int LIMIT = 256;
  std::string lname;
  char fname[LIMIT];

public:
  Person();
  Person(const std::string& ln, const char *fn = "HeyYou");

  void show() const;
  void formalShow() const;
};

#endif
