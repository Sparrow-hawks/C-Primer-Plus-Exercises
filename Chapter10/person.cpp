#include <iostream>
#include <cstring>
#include "person.h"

Person::Person() : lname {""} {
  fname[0] = '\0';
}

Person::Person(const std::string& ln, const char *fn) : lname {ln} {
  strncpy(fname, fn, LIMIT);
}

void Person::show() const {
  std::cout << "Person: "<< fname << ", " << lname;
}

void Person::formalShow() const {
  std::cout << "Person: " << lname << ", " << fname;
}
