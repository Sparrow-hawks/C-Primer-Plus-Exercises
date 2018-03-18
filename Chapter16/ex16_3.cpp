// Book:      C++ Primer Plus
// Chapter:   16
// Exercise:  3

#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>
#include <vector>

int main() {
  using namespace std;

  string filename_IN1, filename_IN2, word;
  cout << "Enter name of first file: ";
  cin >> filename_IN1;
  cout << "Enter name of second file: ";
  cin >> filename_IN2;

  vector<string> F1, F2;

  ifstream file;

  file.open(filename_IN1.c_str(), ifstream::in);
  if (file.good()) {
    while(file >> word)
      F1.push_back(word);
    file.close();
  }

  file.open(filename_IN2.c_str(), ifstream::in);
  if (file.good()) {
    while(file >> word)
      F2.push_back(word);
    file.close();
  }

  std::cout << "File: " << filename_IN1 << " has: " << F1.size() << " words.\n";
  std::cout << "File: " << filename_IN2 << " has: " << F2.size() << " words.\n";

  set<string> A(F1.begin(), F1.end());
  set<string> B(F2.begin(), F2.end());

  ostream_iterator<string, char> out(cout, " ");
  cout << "Set A: ";
  copy(A.begin(), A.end(), out);
  cout << endl;
  cout << "Set B: ";
  copy(B.begin(), B.end(), out);
  cout << endl;

  cout << "Sum of sets A & B: \n";
  set_union(A.begin(), A.end(), B.begin(), B.end(), out);
  cout << endl;

  cout << "Intersection of sets A & B:\n";
  set_intersection(A.begin(), A.end(), B.begin(), B.end(), out);
  cout << endl;

  cout << "Diffrence of sets A & B:\n";
  set_difference(A.begin(), A.end(), B.begin(), B.end(), out);
  cout << endl;

  set<string> C;
  cout << "Set C:\n";
  set_union(A.begin(), A.end(), B.begin(), B.end(), insert_iterator<set<string>>(C, C.begin()));
  copy(C.begin(), C.end(), out);
  cout << endl;

  string s3("brudny");
  C.insert(s3);
  cout << "Set C after insert:\n";
  copy(C.begin(), C.end(), out);
  cout << endl;

  cout << "Display range:\n";
  copy(C.lower_bound("duch"), C.upper_bound("monstrum"), out);
  cout << endl;

  return 0;
}
