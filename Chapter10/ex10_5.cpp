// Book:      C++ Primer Plus
// Chapter:   10
// Exercise:  5

#include <iostream>
#include <cctype>
#include "stack.h"

int main() {

  Stack stack;
  Item customer;

  std::cout << "Enter A, for add customer, \n"
    << "R, for remove customer, or E, for end.\n";

  double totals = 0;
  char ch;
  while(std::cin >> ch && toupper(ch) != 'E') {
    while (std::cin.get() != '\n')
      continue;
    if (!isalpha(ch)) {
      std::cout << '\a';
      continue;
    }
    switch(ch) {
      case 'A':
      case 'a':
        if (stack.isfull()) {
          std::cout << "Stack is full!" << std::endl;
        } else {
          std::cout << "Enter customer name: ";
          std::cin.getline(customer.fullname, 34);
          std::cout << "Enter customer's payment: ";
          std::cin >> customer.payment;
          std::cin.get();

          stack.push(customer);
        }
        break;
      case 'R':
      case 'r':
        if (stack.isempty()) {
          std::cout << "Stack is empty!" << std::endl;
        } else {
          stack.pop(customer);

          totals += customer.payment;
          std::cout << "Customer's name: " << customer.fullname << std::endl;
          std::cout << "Customer's payment: " << customer.payment << std::endl;
          std::cout << "Totals: " << totals << std::endl;
        }
    }

    std::cout << "Enter A, for add customer, \n"
      << "R, for remove customer, or E, for end.\n";
  }
  std::cout << "Goodbye!" << std::endl;

  return 0;
}
