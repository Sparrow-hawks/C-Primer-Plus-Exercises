// Book:        C++ Primer Plus
// Chapter:     4
// Exercise:    3

#include <iostream>
#include <cstring>

int main(void) {

  const unsigned int Size {80};

  char name[Size];
  char surname[Size];
  char result[Size];

  std::cout << "Podaj imię: ";
  std::cin.getline(name, Size);
  std::cout << "Podaj nazwisko: ";
  std::cin.getline(surname, Size);

  strcpy(result, surname);
  strcat(result, ", ");
  strcat(result, name);

  std::cout << "Oto informacje zestawione w jeden napis: ";
  std::cout << result << std::endl;

  return 0;
}
