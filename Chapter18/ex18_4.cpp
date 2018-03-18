// Book:      C++ Primer Plus
// Chapter:   18
// Exercise:  4

#include <iostream>
#include <string>
#include <memory>
#include <list>
#include <algorithm>
#include <iterator>

int main() {
  using namespace std;

  list<int> yadayada {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
  list<int> etcetera (yadayada);

  auto outint = [](int n) {std::cout << n << " ";};

  cout << "Original lists:\n";
  for_each(yadayada.begin(), yadayada.end(), outint);
  std::cout << std::endl;
  for_each(etcetera.begin(), etcetera.end(), outint);
  std::cout << std::endl;

  yadayada.remove_if([](int& x){
    return x > 100;
  });
  etcetera.remove_if([](int& x){
    return x > 200;
  });

  std::cout << "Cutted lists:\n";
  for_each(yadayada.begin(), yadayada.end(), outint);
  std::cout << std::endl;
  for_each(etcetera.begin(), etcetera.end(), outint);
  std::cout << std::endl;

  return 0;
}
