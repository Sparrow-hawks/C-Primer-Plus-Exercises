// Book:      C++ Primer plus
// Chapter:   17
// Exercise:  5

#include <iostream>
#include <list>
#include <string>
#include <fstream>

std::list<std::string> enter(const std::string& filename);
void show(const std::list<std::string>& data);
void save(const std::list<std::string>& data, const std::string& filename);

int main() {

  std::list<std::string> Sheldon = enter("sheldon.dat");
  std::cout << "Sheldon's friends:\n";
  show(Sheldon);

  std::list<std::string> Leonard = enter("leonard.dat");
  std::cout << "Leonard's friends:\n";
  show(Leonard);

  // Merge lists
  std::list<std::string> guests(Sheldon);
  guests.insert(guests.end(), Leonard.begin(), Leonard.end());
  guests.sort();
  guests.unique();

  std::cout << "Sheldon & Leonard friends:\n";
  show(guests);
  save(guests, "sheleo.dat");

  return 0;
}

std::list<std::string> enter(const std::string& filename) {
  std::list<std::string> result;

  std::ifstream in (filename.c_str(), std::ios_base::in);
  std::string name;
  if (in.is_open()) {
    while (std::getline(in, name) && name.size() != 0)
      result.push_back(name);
    in.close();
  } else {
    std::cerr << "[ERROR] Can't open file: " << filename << std::endl;
    exit(EXIT_FAILURE);
  }

  return result;
}

void show(const std::list<std::string>& data) {
  size_t number = 0;
  for (auto name : data)
    std::cout << ++number << ". " << name << std::endl;
}

void save(const std::list<std::string>& data, const std::string& filename) {
  std::ofstream out (filename.c_str(), std::ios_base::out);

  if (out.is_open()) {
    for (auto name : data) {
      out << name << std::endl;
    }
    out.close();
  } else {
    std::cerr << "[ERROR] Can't open file: " << filename << std::endl;
    exit(EXIT_FAILURE);
  }
}
