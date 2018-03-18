// Book:      C++ Primer Plus
// Chapter:   16
// Exercise:  5

#include <iostream>
#include <set>
#include <iterator>
#include <string>

template<typename T>
int reduce(T ar[], int n);

int main() {

  const size_t N = 12;
  long numbers[N] = {242, 12, 89, 424, 12, 249, 81, 16, 15, 242, 19, 76};
  std::string words[N] = {"Sheldon", "Cooper", "Howard", "Wolowitz", "Leonard", "Hofstadter",
    "Penny", "Amy", "Bernardette", "Sheldon", "Howard", "Leonard"};

  std::ostream_iterator<long, char> out(std::cout, " ");
  std::copy(numbers, numbers + N, out);
  std::cout << std::endl;

  size_t S = reduce(numbers, N);

  std::copy(numbers, numbers + S, out);
  std::cout << std::endl;

  std::ostream_iterator<std::string, char> out_s(std::cout, "; ");
  std::copy(words, words + N, out_s);
  std::cout << std::endl;

  S = reduce(words, N);

  std::copy(words, words + S, out_s);
  std::cout << std::endl;

  return 0;
}

template<typename T>
int reduce(T ar[], int n) {
  std::set<T> numbers(ar, ar + n);

  std::copy(numbers.begin(), numbers.end(), ar);

  return numbers.size();
}
