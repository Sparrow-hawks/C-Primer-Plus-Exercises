// Book:      C++ Primer Plus
// Chapter:   3
// Exercise:  6

#include <iostream>

int main(void) {

  int miles, usgUsed, usgLeft;

  std::cout << "Podaj ile mil pokonałeś: ";
  std::cin >> miles;
  std::cout << "Podaj ile galanów paliwa zużyłeś: ";
  std::cin >> usgUsed;
  std::cout << "Podaj ile galanów paliwa pozostało: ";
  std::cin >> usgLeft;

  float usFuelBurnRatio = float (miles)/usgUsed;
  float range = usgLeft * usFuelBurnRatio;

  std::cout << "średnie zużycie paliwa wynosi: " << usFuelBurnRatio << " m/g" << std::endl;
  std::cout << "Do następnego tankowania pozostało: " << range << " mil" << std::endl;

  return 0;
}
