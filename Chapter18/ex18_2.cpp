// Book:      C++ Primer Plus
// Chapter:   18
// Exercise:  2

#include <iostream>
#include <string>

class Cpmv {
public:
  struct Info {
    std::string qcode;
    std::string zcode;
  };
private:
  Info *p;

public:
  Cpmv();
  Cpmv(std::string q, std::string z);
  Cpmv(const Cpmv& cp);
  Cpmv(Cpmv && mv);
  ~Cpmv();

  Cpmv& operator=(const Cpmv& cp);
  Cpmv& operator=(Cpmv&& mv);
  Cpmv operator+(const Cpmv& obj) const;
  void Display() const;
};

Cpmv::Cpmv() {
  std::cout << "Default constructor!\n";
  p = nullptr;
}

Cpmv::Cpmv(std::string q, std::string z) {
  std::cout << "Constructor (" << q << ", " << z << ")!\n";

  p = new Info;

  p->qcode = q;
  p->zcode = z;

}

Cpmv::Cpmv(const Cpmv& cp) {
  std::cout << "Copy constructor!\n";

  p = new Info;

  p->qcode = cp.p->qcode;
  p->zcode = cp.p->zcode;
}

Cpmv::Cpmv(Cpmv&& cp) {
  std::cout << "Move constructor!\n";

  p = cp.p;

  cp.p = nullptr;
}

Cpmv::~Cpmv() {
  std::cout << "Destructor!\n";

  delete p;
}

Cpmv& Cpmv::operator=(const Cpmv& cp) {
  std::cout << "Copy assigment!\n";

  if (this != &cp) {
    delete p;

    p = new Info;

    p->qcode = cp.p->qcode;
    p->zcode = cp.p->zcode;
  }
  return *this;
}

Cpmv& Cpmv::operator=(Cpmv&& cp) {
  std::cout << "Move assigment!\n";

  if (this != &cp) {
    delete p;

    p = cp.p;

    cp.p = nullptr;
  }
  return *this;
}

Cpmv Cpmv::operator+(const Cpmv& obj) const {
  return Cpmv(p->qcode + obj.p->qcode, p->zcode + obj.p->zcode);
}

void Cpmv::Display() const {
  std::cout << "ZCODE: " << p->zcode << std::endl;
  std::cout << "QCODE: " << p->qcode << std::endl;
}

int main() {

  Cpmv cp1;
  Cpmv cp2;
  Cpmv cp3;

  Cpmv cp4("QRA", "ZAL");
  Cpmv cp5("QRB", "ZAP");
  Cpmv cp6(cp4);

  cp1 = cp4;
  cp5 = (cp4 + cp6);

  cp2 = std::move(cp4);

  return 0;
}
