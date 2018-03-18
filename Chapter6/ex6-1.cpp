// Book:      C++ Primer Plus
// Chapter:   6
// Exercise:  1

#include <iostream>
#include <cctype>

int main(void) {

  char ch;
  while (std::cin.get(ch) && ch != '@') {
    if (!isdigit(ch)) {
      if (isupper(ch))
        std::cout.put(tolower(ch));
      else if (islower(ch))
        std::cout.put(toupper(ch));
      else
        std::cout.put(ch);
    }
  }

  return 0;
}
