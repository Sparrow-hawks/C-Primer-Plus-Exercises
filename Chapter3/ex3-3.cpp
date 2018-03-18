// Book:      C++ Primer Plus
// Chapter:   3
// Exercise:  3

#include <iostream>

int main(void) {

  const double arcMinute {60};
  const double arcSecond {60};

  int deg, minutes, seconds;
  std::cout << "Podaj długość w stopniach, minutach i sekundach:" << std::endl;
  std::cout << "Najpierw podaj stopnie: ";
  std::cin >> deg;
  std::cout << "Następnie podaj minuty stopnia łuku: ";
  std::cin >> minutes;
  std::cout << "Na koniec podaj sekundy łuku: ";
  std::cin >> seconds;

  double decimal = deg + (minutes + seconds / arcSecond) / arcMinute;

  std::cout << deg << " stopni, "
    << minutes << " minut, "
    << seconds << " sekund = "
    << decimal << " stopni" << std::endl;

  return 0;
}
