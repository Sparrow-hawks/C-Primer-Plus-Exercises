// Book:      C++ Primer plus
// Chapter:   17
// Exercise:  7

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <memory>
#include <cstring>

class Store {
private:
  std::ofstream& m_Out;
public:
  Store(std::ofstream& out);

  void operator()(const std::string& s);
};

Store::Store(std::ofstream& out) : m_Out(out){

}

void Store::operator()(const std::string& s) {
  size_t size = s.size();

  m_Out.write((char*)&size, sizeof (std::size_t));
  m_Out.write(s.data(), size);
}

void ShowStr(const std::string& s);
void GetStrs(std::ifstream& in, std::vector<std::string>& v);

int main() {
  using namespace std;

  vector<string> vostr;
  string temp;

  cout << "Enter strings (Empty row for end):\n";
  while(getline(cin, temp) && temp[0] != '\0')
    vostr.push_back(temp);
  cout << "Your input data:\n";
  for_each(vostr.begin(), vostr.end(), ShowStr);

  // Store in file
  ofstream fout("strings.dat", ios_base::out | ios_base::binary);
  for_each(vostr.begin(), vostr.end(), Store(fout));
  fout.close();

  // Read file
  vector<string> vistr;
  ifstream fin("strings.dat", ios_base::in | ios_base::binary);
  if (!fin.is_open()) {
    cerr << "Can't open file for reading.\n";
    exit(EXIT_FAILURE);
  }

  GetStrs(fin, vistr);
  cout << "\nStrings red from file:\n";
  for_each(vistr.begin(), vistr.end(), ShowStr);

  return 0;
}

void ShowStr(const std::string& s) {
  std::cout << s << std::endl;
}

void GetStrs(std::ifstream& in, std::vector<std::string>& v) {
  size_t size;

  while (in) {
    in.read((char*)&size, sizeof(size_t));

    std::unique_ptr<char[]> ptr (new char[size + 1]);

    in.read(&ptr[0], size);

    ptr[size] = '\0';

    v.push_back(std::string(&ptr[0]));
  }
}
