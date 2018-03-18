// Book:        C++ Primer Plus
// Chapter:     4
// Exercise:    1

#include <iostream>
#include <string>

int main(void) {
  std::string name;
  std::string surname;

  std::cout << "Jak masz na imię? ";
  std::getline(std::cin, name);
  std::cout << "Jak się nazywasz? ";
  std::getline(std::cin, surname);

  unsigned int note, age;
  std::cout << "Na jaką ocenę zasługujesz? ";
  std::cin >> note;
  std::cout << "Ile masz lat? ";
  std::cin >> age;

  std::cout << "Nazwisko: " + surname + ", " + name << std::endl;
  std::cout << "Ocena: " << note - 1 << std::endl;
  std::cout << "Wiek: " << age << std::endl;

  return 0;
}
