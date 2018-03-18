// Book:        C++ Primer Plus
// Chapter:     4
// Exercise:    4

#include <iostream>
#include <string>

int main(void) {

  std::string name, surname, result;

  std::cout << "Podaj imię: ";
  std::getline(std::cin, name);
  std::cout << "Podaj nazwisko: ";
  std::getline(std::cin, surname);

  result = surname + ", " + name;

  std::cout << "Oto informacje zestawione w jeden napis: "
    << result << std::endl;

  return 0;
}
