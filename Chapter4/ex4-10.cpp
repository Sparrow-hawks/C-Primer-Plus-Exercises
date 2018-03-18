// Book:        C++ Primer Plus
// Chapter:     4
// Exercise:    10

#include <iostream>
#include <string>
#include <array>

int main(void) {

  std::array<double, 3> results {};
  std::cout << "Podaj swoje 3 najlepsze rezultaty w sprincie na 100 m: ";
  std::cin >> results.at(0) >> results.at(1) >> results.at(2);

  std::cout << "Twoje najlepsze wyniki: " << std::endl;
  std::cout << "1. " << results[0] << " [s]\n";
  std::cout << "2. " << results[1] << " [s]\n";
  std::cout << "3. " << results[2] << " [s]\n";

  std::cout << "Twoja średnia wynosi: ";
  std::cout << (results[0] + results[1] + results[2]) / results.size() << " [s]\n";

  return 0;
}
