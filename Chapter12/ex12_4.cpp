// Book:      C++ Primer Plus
// Chapter:   12
// Exercise:  4

#include <iostream>
#include <cctype>
#include "stack.h"

int main() {
  using namespace std;
  Stack st;
  char ch;
  unsigned long po;
  cout << "Press E, for declaration enter, \n"
    << "P, for declaration process, or Q, for quit.\n";
  while (cin >> ch && toupper(ch) != 'Q') {
    while (cin.get() != '\n')
      continue;
    if (!isalpha(ch)) {
      cout << '\a';
      continue;
    }
    switch(ch) {
      case 'E':
      case 'e':
        cout << "Enter new declaration number: ";
        cin >> po;
        if (st.isfull())
          cout << "Stack full!\n";
        else
          st.push(po);
        break;
      case 'P':
      case 'p':
        if (st.isempty())
          cout << "Stack empty!\n";
        else {
          st.pop(po);
          cout << "Declaration number: " << po << " poped\n";
        }
        break;
    }
    cout << "Press E, for declaration enter, \n"
      << "P, for declaration process, or Q, for quit.\n";
  }
  cout << "Goodbye!" << std::endl;

  return 0;
}
