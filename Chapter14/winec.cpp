#include <iostream>
#include <iomanip>
#include <cassert>
#include "winec.h"

Wine::Wine() : m_Label(nullptr), m_Data(ArrayInt(), ArrayInt()) {

}

Wine::Wine(const char *l, int y) : m_Label(l) , m_Data(ArrayInt(y), ArrayInt(y)){

}

Wine::Wine(const char *l, int y, const int yr[], const int bot[]) :
  m_Label(l), m_Data(ArrayInt(yr, y), ArrayInt(bot, y)) {
}

Wine::~Wine() {

}

void Wine::GetBottles() {
  std::cout << "Podaj dane o " << m_Label << " dla " << m_Data.first().size() << " roczników:" << std::endl;

  for (size_t i = 0; i < m_Data.first().size(); ++i) {
    std::cout << "Podaj rocznik: ";
    std::cin >> m_Data.first()[i];
    std::cout << "Podaj liczbę butelek: ";
    std::cin >> m_Data.second()[i];
  }
}

const char* Wine::label() const {
  return m_Label;
}

void Wine::Show() const {
  std::cout << "Wino: " << m_Label << std::endl;
  std::cout << std::setw(10) << "Rocznik" << "\t" << "Butelki" << std::endl;
  for (size_t i = 0; i < m_Data.first().size(); ++i) {
    std::cout << std::setw(10) << m_Data.first()[i] << "\t" << m_Data.second()[i] << std::endl;
  }
}

int Wine::sum() const {
  return m_Data.second().sum();
}
