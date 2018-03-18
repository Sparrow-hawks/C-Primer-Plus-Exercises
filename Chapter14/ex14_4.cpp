// Book:      C++ Primer Plus
// Chapter:   14
// Exercise:  4

#include <iostream>
#include <cstring>
#include "person.h"

const int SIZE = 5;

int main() {
  using std::cin;
  using std::cout;
  using std::endl;
  using std::strchr;

  Person *persons[SIZE];

  int ct;
  for (ct = 0; ct < SIZE; ++ct) {
    char choice;
    cout << "Enter person category: \n"
      << "g: gunslinger  p: pokerplayer  \n"
      << "b: baddude  q: quit\n";
    cin >> choice;
    while (strchr("gpbq", choice) == NULL) {
      cout << "Enter q, p, b or q: ";
      cin >> choice;
    }
    if (choice == 'q')
      break;
    switch(choice) {
      case 'g': persons[ct] = new Gunslinger;
        break;
      case 'p': persons[ct] = new PokerPlayer;
        break;
      case 'b': persons[ct] = new BadDude;
      break;
    }
    cin.get();
    persons[ct]->Set();
  }

  cout << "\n*** PERSONS ***\n";
  for (int i = 0; i < ct; ++i) {
    cout << endl;
    persons[i]->Show();
  }

  for (int i = 0; i < ct; ++i) {
    delete persons[i];
  }

  cout << "\n*** END ***" << std::endl;

  return 0;
}
