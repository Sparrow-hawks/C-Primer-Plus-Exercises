// Book:      C++ Primer Plus
// Chapter:   16
// Exercise:  1

#include <iostream>
#include <string>

bool isPalindrome(std::string& s);

int main() {

  std::string word;
  std::cout << "Enter word: ";
  while(std::cin >> word && word != "Quit") {
    std::cout << (isPalindrome(word) ? "It is a palindrome." : "It isn't a palindrome.") << std::endl;
    std::cout << "Enter next word (Quit - for exit): ";
  }

  return 0;
}

bool isPalindrome(std::string& s) {
  auto it1 = s.begin();
  auto it2 = s.rbegin();

  bool result = true;
  for (size_t i = 0; i < s.size() / 2; ++i, ++it1, ++it2) {
    if (*it1 != *it2)
      result = false;
  }
  return result;
}
