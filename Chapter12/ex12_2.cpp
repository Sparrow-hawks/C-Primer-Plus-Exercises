// Book:      C++ Primer Plus
// Chapter:   12
// Exercise:  2

#include <iostream>
#include "string_2.h"

using namespace std;

int main() {
  String s1 (" and learn C++.");
  String s2 = "Enter Your name: ";
  String s3;

  cout << s2;
  cin >> s3;
  s2 = "My name is " + s3;
  cout << s2 << ".\n";
  s2 = s2 + s1;
  s2.stringup();
  cout << "String\n" << s2 << "\ncontain " << s2.has('A')
    << " 'A'.\n";
  s1 = "red";

  String rgb[3] = { String(s1), String("green"), String("blue")};
  cout << "Enter name of base color: ";
  String ans;
  bool success = false;
  while (cin >> ans) {
    ans.stringlow();
    for (int i = 0; i < 3; i++) {
      if (ans == rgb[i]) {
        cout << "Correct!\n";
        success = true;
        break;
      }
    }
    if (success)
      break;
    else
      cout << "Try again!\n";
  }
  cout << "Goodbye\n";

  return 0;
}
