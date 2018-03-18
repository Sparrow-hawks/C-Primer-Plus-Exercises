// Book:      C++ Primer Plus
// Chapter:   6
// Exercise:  8

#include <iostream>
#include <fstream>
#include <string>

int main(void) {
  std::string filename;

  std::cout << "Wprowadź nazwę pliku: ";
  std::cin >> filename;

  std::ifstream file;

  unsigned int characterCount = 0;

  file.open(filename);
  if (file.is_open()) {
    char ch;
    while (file.get(ch)) {
        ++characterCount;
    }
    std::cout << "Liczba znaków w pliku: " << characterCount << std::endl;
  } else {
    std::cerr << "Błąd otwarcia pliku." << std::endl;
  }

  return 0;
}
