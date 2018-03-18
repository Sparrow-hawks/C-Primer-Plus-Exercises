// Book:        C++ Primer Plus
// Chapter:     10
// Exercise:    8

#include <iostream>
#include "list.h"

void show(Item &item);

int main() {

  List list;

  std::cout << "Empty list size: " << list.size() << "." << std::endl;

  for (size_t i = 0; i <= 10; ++i) {
    list.push(2.8 + i);
  }

  std::cout << "Is list full: " << (list.isFull() ? " Yes.\n" : " No.\n");

  std::cout << "Wisitor function (runs on every element in the list): " << std::endl;
  list.visit(show);

  std::cout << "Clear list:" << std::endl;
  while(!list.isEmpty()) {
    list.pop();
  }
  std::cout << "Is list empty: " << (list.isEmpty() ? " Yes.\n" : " No.\n");

  list.pop();

  return 0;

};

void show(Item &item) {
  std::cout << "Visitor see: " << item << "." << std::endl;
}
