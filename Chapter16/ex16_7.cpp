// Book:      C++ Primer Plus
// Chapter:   16
// Exercise:  7

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <cstdlib>

std::vector<int> Lotto(int max, int howMany);

int main() {

  std::cout << "*** LOTTO ***" << std::endl;

  int range, howMany;
  std::cout << "Range: ";
  std::cin >> range;
  std::cout << "How many numbers to choose: ";
  std::cin >> howMany;

  std::vector<int> winners = Lotto(range, howMany);

  std::cout << "Winners: ";
  for (auto number : winners)
    std::cout << number << " ";
  std::cout << std::endl;

  std::cout << "*** END ***" << std::endl;

  return 0;
}

std::vector<int> Lotto(int max, int howMany) {
  srand(std::chrono::system_clock::now().time_since_epoch().count());

  std::vector<int> result(max);
  for(size_t i = 1; i <= max; ++i)
    result[i - 1] = i;

  std::random_shuffle(result.begin(), result.end()) ;

  result.resize(howMany);

  return result;
}
