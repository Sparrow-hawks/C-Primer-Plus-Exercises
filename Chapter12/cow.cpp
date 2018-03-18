#include <iostream>
#include <cstring>
#include "cow.h"

#ifndef DNDEBUG
  unsigned int Cow::counter = 0;
#endif

// Default constructor
Cow::Cow() {
#ifndef DNDEBUG
  std::cerr << "Default Constructor, objects: " << ++counter << std::endl;
#endif

  name[0] = '\0';
  hobby = new char[1];
  hobby[0] = '\0';
  weight = 0;
}

// Second constructor
Cow::Cow(const char *nm, const char *ho, double wt) {
#ifndef DNDEBUG
  std::cerr << "Second Constructor, objects:" << ++counter <<  std::endl;
#endif

  strncpy(name, nm, 19);
  name[19] = '\0';

  size_t len = strlen(ho) + 1;
  hobby = new char[len];
  strncpy(hobby, ho, len);

  weight = wt;
}

// Destructor
Cow::~Cow() {
#ifndef DNDEBUG
  std::cerr << "Destructor, objects: " << --counter << std::endl;
#endif

  delete [] hobby;
}

// Copy constructor
Cow::Cow(const Cow& c) {
#ifndef DNDEBUG
  std::cerr << "Copy constructor, objects: " << ++counter << std::endl;
#endif

  strcpy(name, c.name);

  size_t len = strlen(c.hobby);
  hobby = new char [len + 1];
  strcpy(hobby, c.hobby);

  weight = c.weight;
}

// Assigment operator
Cow& Cow::operator=(const Cow& c) {
#ifndef DNDEBUG
  std::cerr << "Assigment operator" << std::endl;
#endif

  if (this != &c) {
    delete [] hobby;

    hobby = new char [strlen(c.hobby) + 1];
    strcpy(hobby, c.hobby);

    strcpy(name, c.name);

    weight = c.weight;
  }

  return *this;
}

void Cow::ShowCow() const {
  std::cout << "Name: " << name << ", Hobby: " << hobby << ", weight: " << weight << "." << std::endl;
}
