#include <iostream>
#include <iomanip>
#include <cassert>
#include "winec_2.h"

Wine::Wine() : Pair(ArrayInt(), ArrayInt()), m_Label(std::string()) {

}

Wine::Wine(const char *l, int y) : Pair(ArrayInt(y), ArrayInt(y)),  m_Label(l) {

}

Wine::Wine(const char *l, int y, const int yr[], const int bot[]) :
  Pair(ArrayInt(yr, y), ArrayInt(bot, y)), m_Label(l) {
}

Wine::~Wine() {

}

void Wine::GetBottles() {
  std::cout << "Podaj dane o " << m_Label << " dla " << Pair::first().size() << " roczników:" << std::endl;

  for (size_t i = 0; i < Pair::first().size(); ++i) {
    std::cout << "Podaj rocznik: ";
    std::cin >> Pair::first()[i];
    std::cout << "Podaj liczbę butelek: ";
    std::cin >> Pair::second()[i];
  }
}

const std::string& Wine::label() const {
  return m_Label;
}

void Wine::Show() const {
  std::cout << "Wino: " << m_Label << std::endl;
  std::cout << std::setw(10) << "Rocznik" << "\t" << "Butelki" << std::endl;
  for (size_t i = 0; i < Pair::first().size(); ++i) {
    std::cout << std::setw(10) << Pair::first()[i] << "\t" << Pair::second()[i] << std::endl;
  }
}

int Wine::sum() const {
  return Pair::second().sum();
}
