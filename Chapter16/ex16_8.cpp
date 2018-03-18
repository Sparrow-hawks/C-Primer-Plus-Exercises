// Book:      C++ Primer Plus
// Chapter:   16
// Exercise:  8

#include <iostream>
#include <list>
#include <string>

std::list<std::string> enter();
void show(const std::list<std::string>& data);

int main() {

  std::cout << "Sheldon's friends:\n";
  std::list<std::string> Sheldon = enter();

  std::cout << "Leonard's friends:\n";
  std::list<std::string> Leonard = enter();

  // Merge lists
  std::list<std::string> guests(Sheldon);
  guests.insert(guests.end(), Leonard.begin(), Leonard.end());
  guests.sort();
  guests.unique();

  std::cout << "Sheldon & Leonard friends:\n";
  show(guests);

  return 0;
}

std::list<std::string> enter() {
  std::list<std::string> result;

  std::cout << "Enter name (Quit - for exit!): ";
  std::string name;
  while(std::cin >> name && name != "Quit") {
    result.push_back(name);
    std::cout << "Enter name (Quit - for exit!): ";
  }
  return result;
}

void show(const std::list<std::string>& data) {
  size_t number = 0;
  for (auto name : data)
    std::cout << ++number << ". " << name << std::endl;
}
