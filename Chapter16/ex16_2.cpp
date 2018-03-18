// Book:      C++ Primer Plus
// Chapter:   16
// Exercise:  2

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

bool isPalindrome(std::string& s);

int main() {

  std::string line;
  std::cout << "Enter word: ";
  while(std::getline(std::cin, line) && line != "Quit") {
    std::cout << "Text: " << line << " ";
    std::cout << (isPalindrome(line) ? "is a palindrome." : "isn't a palindrome.") << std::endl;
    std::cout << "Enter next word (Quit - for exit): ";
  }

  return 0;
}

bool isPalindrome(std::string& s) {
  size_t it = 0;
  while ((it = s.find_first_of("\t\n ")) != std::string::npos) {
    s.erase(it, 1);
  }

  for (char &letter : s)
    letter = tolower(letter);

  auto it1 = s.begin();
  auto it2 = s.rbegin();

  bool result = true;
  for (size_t i = 0; i < s.size() / 2; ++i, ++it1, ++it2) {
    if (*it1 != *it2)
      result = false;
  }
  return result;
}
