// Book:      C++ Primer plus
// Chapter:   17
// Exercise:  1

#include <iostream>

int main() {
  std::cout << "Enter text ('$' - quit): ";

  size_t count = 0;
  char c;
  while (std::cin.get(c) && c != '$') {
    ++count;
  }
  if (c == '$')
    std::cin.putback(c);
  std::cout << "Entered: " << count << " chars." << std::endl;

  return 0;
}
