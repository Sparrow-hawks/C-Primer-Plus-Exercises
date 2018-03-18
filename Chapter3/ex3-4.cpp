// Book:      C++ Primer Plus
// Chapter:   3
// Exercise:  4

#include <iostream>

int main(void) {

  const int secInMinute {60};
  const int secInHour {3600};
  const int secInDay {86400};

  long long numberOfSeconds;
  std::cout << "Podaj liczbę sekund: ";
  std::cin >> numberOfSeconds;

  long long seconds = numberOfSeconds;
  int days = seconds / secInDay;

  seconds = seconds % secInDay;

  int hours = seconds / secInHour;

  seconds = seconds % secInHour;

  int minutes = seconds / secInMinute;

  seconds = seconds % secInMinute;
  

  std::cout << numberOfSeconds << " sekund = "
    << days << " dni, "
    << hours << " godzin, "
    << minutes << " minut, "
    << seconds << " sekund" << std::endl;

  return 0;
}
