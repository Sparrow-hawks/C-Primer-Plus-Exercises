// Book:      C++ Primer Plus
// Chapter:   8
// Exercise:  1

#include <iostream>

void display(const char *str, size_t count = 0);

int main(void) {

  char *msg = (char*)"Hello World!";

  display(msg);
  display(msg, 5);

  return 0;
}

void display(const char *str, size_t count) {
  if (!count)
    std::cout << str;
  else
    while(count--)
      std::cout << str;
  std::cout << std::endl;
}
