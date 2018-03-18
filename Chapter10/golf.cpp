#include <cstring>
#include <iostream>
#include "golf.h"

Golf::Golf() {
  m_Name[0] = '\0';
  m_HC = 0;
}

Golf::Golf(const char *name, int hc) {
  strncpy(m_Name, name, LEN);
  m_HC = hc;
}

void Golf::handicap(int hc) {
  m_HC = hc;
}

void Golf::show() const {
  std::cout << "Player:   " << m_Name << std::endl;
  std::cout << "Handicap: " << m_HC << std::endl;
}

bool Golf::set() {
  char name[LEN];
  int handicap;

  std::cout << "Enter Player's name: ";
  if (std::cin.getline(name, LEN - 1) && strlen(name) != 0) {
    std::cout << "Enter Players's handicap: ";
    std::cin >> handicap;
    std::cin.get();

    *this = Golf(name, handicap);

    return true;
  } else {
    return false;
  }
}
