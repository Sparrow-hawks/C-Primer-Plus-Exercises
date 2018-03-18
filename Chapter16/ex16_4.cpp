// Book:      C++ Primer Plus
// Chapter:   16
// Exercise:  4

#include <iostream>
#include <set>
#include <iterator>

int reduce(long ar[], int n);

int main() {

  const size_t N = 12;
  long numbers[N] = {242, 12, 89, 424, 12, 249, 81, 16, 15, 242, 19, 76};

  std::ostream_iterator<long, char> out(std::cout, " ");
  std::copy(numbers, numbers + N, out);
  std::cout << std::endl;

  size_t S = reduce(numbers, N);

  std::copy(numbers, numbers + S, out);
  std::cout << std::endl;

  return 0;
}

int reduce(long ar[], int n) {
  std::set<long> numbers(ar, ar + n);

  std::copy(numbers.begin(), numbers.end(), ar);

  return numbers.size();
}
