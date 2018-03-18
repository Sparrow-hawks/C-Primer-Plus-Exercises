// Book:      C++ Primer Plus
// Chapter:   9
// Exercise:  2

#include <iostream>
#include <string>

void strcount(const std::string& str);

int main() {

  std::string input;
  std::cout << "Enter row:\n";
  while (std::getline(std::cin, input) && input != "") {
    strcount(input);

    std::cout << "Enter next row (Empty row ends):\n";
    std::cout.flush();
  }
  std::cout << "Goodbye" << std::endl;

  return 0;
}

void strcount(const std::string& str) {
  static int total = 0;

  std::cout << "\"" << str << "\" contain ";

  total += str.length();

  std::cout << str.length() << " letters\n";
  std::cout << "Together " << total << " letters\n";
}
