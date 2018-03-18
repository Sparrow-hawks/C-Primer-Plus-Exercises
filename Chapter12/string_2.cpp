#include <cstring>
#include "string_2.h"

using std::cin;
using std::cout;

// Initialisation static const member
int String::num_strings = 0;

// Static method
int String::HowMany() {
  return num_strings;
}

// Class method
String::String(const char *s) {
  len = std::strlen(s);
  str = new char[len + 1];
  std::strcpy(str, s);
  num_strings++;
}

String::String() {
  len = 0;
  str = new char[1];
  str[0] = '\0';
  num_strings++;
}

String::String(const String& s) {
  num_strings++;
  len = s.len;
  str = new char [len + 1];
  std::strcpy(str, s.str);
}

String::~String() {
  --num_strings;
  delete [] str;
}

// Method change all leters to upper
void String::stringup() {
  for (int i = 0; i < len; ++i)
    str[i] = toupper(str[i]);
}

// Method change all letters to lower
void String::stringlow() {
  for (int i = 0; i < len; ++i)
    str[i] = tolower(str[i]);
}

// Count char in string_2
int String::has(char c) {
  int count = 0;

  // We want find '\0' to
  for (int i = 0; i <= len; ++i)
    if (str[i] == c)
      ++count;

  return count;
}

// Operators overload methods
String& String::operator=(const String& s) {
  if (this != &s) {
    delete [] str;
    len = s.len;
    str = new char[len + 1];
    std::strcpy(str, s.str);
  }
  return *this;
}

String& String::operator=(const char* s) {
  delete [] str;
  len = std::strlen(s);
  str = new char[len + 1];
  std::strcpy(str, s);

  return *this;
}

String String::operator+(const String& s) {
  String temp {};

  temp.len = len + s.len;
  temp.str = new char[len + s.len + 1];

  strcpy(temp.str, str);
  strcat(temp.str, s.str);

  return temp;
}

String operator+(const char *s1, const String& s2) {
  String temp {};

  temp.len = strlen(s1) + s2.len;
  temp.str = new char[temp.len + 1];

  strcpy(temp.str, s1);
  strcat(temp.str, s2.str);

  return temp;
}

char& String::operator[](int i) {
  return str[i];
}

const char& String::operator[](int i) const {
  return str[i];
}

bool operator<(const String& s1, const String& s2) {
  return (std::strcmp(s1.str, s2.str) < 0);
}

bool operator>(const String& s1, const String& s2) {
  return s2 < s1;
}

bool operator==(const String& s1, const String& s2) {
  return (std::strcmp(s1.str, s2.str) == 0);
}

// Write String to output
ostream& operator<<(ostream& os, const String& s) {
  os << s.str;
  return os;
}

// Reading string from input
istream& operator>>(istream& is, String& st) {
  char temp[String::CINLIM];
  is.get(temp, String::CINLIM);
  if (is)
    st = temp;
  while (is && is.get() != '\n')
    continue;
  return is;
}
