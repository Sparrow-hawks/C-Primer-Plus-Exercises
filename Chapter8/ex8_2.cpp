// Book:      C++ Primer Plus
// Chapter:   8
// Exercise:  1

#include <iostream>
#include <cstring>

const size_t max = 80;

struct Candybar {
  char brand[max];
  double weight;
  unsigned int cal;
};

void set(Candybar& candy,
  const char *brand = (char*)"Millennium Munch",
  double weight = 2.85,
  unsigned int cal = 350
);

void show(const Candybar& candy);

int main(void) {

  Candybar cbar1 {};
  Candybar cbar2 {};

  set(cbar1);
  set(cbar2, "Snickers", 3.17, 412);

  show(cbar1);
  show(cbar2);

  return 0;
}

void set(Candybar& candy, const char *brand, double weight, unsigned int cal) {
  strncpy(candy.brand, brand, max - 1);
  candy.weight = weight;
  candy.cal = cal;
}

void show(const Candybar& candy) {
  std::cout << "Candybar data:" << std::endl;
  std::cout << "Brand:    " << candy.brand << std::endl;
  std::cout << "Weight:   " << candy.weight << " g" << std::endl;
  std::cout << "Calories: " << candy.cal << " cal" << std::endl;
}
