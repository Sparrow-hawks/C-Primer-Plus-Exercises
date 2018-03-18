#include <iostream>
#include <cstring>
#include "port.h"

Port::Port(const char *br, const char *st, int b) : bottles(b) {
  brand = new char [strlen(br) + 1];

  strcpy(brand, br);
  strcpy(style, st);
}

Port::Port(const Port& p) {
  brand = new char [strlen(p.brand) + 1];

  strcpy(brand, p.brand);
  strcpy(style, p.style);

  bottles = p.bottles;
}

Port::~Port() {
  delete [] brand;
}

Port& Port::operator=(const Port& p) {
  if (&p != this) {
    delete brand;
    brand = new char [strlen(p.brand) + 1];

    strcpy(brand, p.brand);
    strcpy(style, p.style);

    bottles = p.bottles;
  }

  return *this;
}

Port& Port::operator+=(int b) {
  bottles += b;

  return *this;
}

Port& Port::operator-=(int b) {
  if (bottles >= b)
    bottles -= b;
  else
    bottles = 0;

  return *this;
}

void Port::Show() const {
  std::cout << "Brand:   " << brand << std::endl;
  std::cout << "Type:    " << style << std::endl;
  std::cout << "Bottles: " << bottles << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Port& p) {
  os << p.brand << ", " << p.style << ", " << p.bottles;

  return os;
}


VintagePort::VintagePort() : Port(), year(0) {
  nickname = new char[1];
  nickname[0] = '\0';
}

VintagePort::VintagePort(const char *br, int b, const char *nn, int y) :
  Port(br), year(y) {
  Port::operator+=(b);
  nickname = new char[strlen(nn) + 1];
  strcpy(nickname, nn);
  year = y;
}

VintagePort::VintagePort(const VintagePort& vp) : Port(vp){
  nickname = new char [strlen(vp.nickname) + 1];
  strcpy(nickname, vp.nickname);
  year = vp.year;
}

VintagePort::~VintagePort() {
  delete [] nickname;
}

VintagePort& VintagePort::operator=(const VintagePort& vp) {
  if (&vp != this) {
    delete [] nickname;
    nickname = new char [strlen(vp.nickname) + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
  }
  return *this;
}

void VintagePort::Show() const {
  Port::Show();
  std::cout << "Nickname: " << nickname << std::endl;
  std::cout << "Year: " << year << std::endl;
}

std::ostream& operator<<(std::ostream& os, const VintagePort& vp) {
  os << Port(vp) << ", " << vp.nickname << ", " << vp.year;

  return os;
}
