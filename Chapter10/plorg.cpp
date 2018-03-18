#include <iostream>
#include <cstring>
#include "plorg.h"

Plorg::Plorg(const char* name) : m_Satiety {50} {
  strncpy(m_Name, name, LEN - 1);
}

void Plorg::show() const {
  std::cout << "Plorg: " << m_Name << ", satiety: " << m_Satiety;
}
