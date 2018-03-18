#include <iostream>
#include <cstring>
#include "golf.h"

bool setgolf(Golf& g, const char *name, int hc) {
  if (name != nullptr && strlen(name) != 0) {
    strncpy(g.fullname, name, Len - 1);
    g.handicap = hc;

    return true;
  } else {
    return false;
  }
}

bool setgolf(Golf& g) {
  std::cout << "Enter Player's name: ";
  if (std::cin.getline(g.fullname, Len - 1) && strlen(g.fullname) != 0) {
    std::cout << "Enter Player's handicap: ";
    std::cin >> g.handicap;
    std::cin.get();

    return true;
  } else {
    return false;
  }
}

void handicap(Golf& g, int hc) {
  g.handicap = hc;
}

void showgolf(const Golf& g) {
  std::cout << "Player:   " << g.fullname << std::endl;
  std::cout << "Handicap: " << g.handicap << std::endl;
}
