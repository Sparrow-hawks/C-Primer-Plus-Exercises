#include <iostream>
#include "emp.h"

using std::cout;
using std::endl;
using std::cin;

//***************************************************************************//
//        ABSTR_EMP CLASS
//***************************************************************************//

abstr_emp::abstr_emp() : fname("Empty"), lname("Empty"), job("None") {

}

abstr_emp::abstr_emp(const std::string& fn, const std::string& ln, const std::string& j) :
  fname(fn), lname(ln), job(j) {

}

abstr_emp::~abstr_emp() {

}

void abstr_emp::ShowAll() const {
  cout << "First name: " << fname << endl;
  cout << "Last name:  " << lname << endl;
  cout << "Job:        " << job << endl;
}

void abstr_emp::SetAll() {
  cout << "Enter first name: ";
  cin >> fname;
  cout << "Enter last name: ";
  cin >> lname;
  cout << "Enter job: ";
  cin >> job;
}

std::ostream& operator<<(std::ostream& os, const abstr_emp& emp) {
  os << emp.fname << " " << emp.lname;

  return os;
}


//*****************************************************************************
//        EMPLOYEE CLASS
//*****************************************************************************

employee::employee() : abstr_emp() {

}

employee::employee(const std::string& fn, const std::string& ln, const std::string& j) :
  abstr_emp(fn, ln, j) {

}

void employee::ShowAll() const {
  abstr_emp::ShowAll();
}

void employee::SetAll() {
  abstr_emp::SetAll();
}


//*****************************************************************************
//        MANAGER CLASS
//*****************************************************************************

manager::manager() : abstr_emp(), inchargeof(0) {

}

manager::manager(const std::string& fn, const std::string& ln, const std::string& j, int ico) :
  abstr_emp(fn, ln, j), inchargeof(ico) {

}

manager::manager(const abstr_emp& e, int ico) :
  abstr_emp(e), inchargeof(ico) {

}

manager::manager(const manager& m) :
  abstr_emp(m), inchargeof(m.inchargeof) {

}

void manager::ShowAll() const {
  abstr_emp::ShowAll();
  cout << "Manager charge: " << InChargeOf() << endl;
}

void manager::SetAll() {
  abstr_emp::SetAll();
  cout << "How many employee inchagere: ";
  cin >> inchargeof;
  while (cin.get() != '\n')
    continue;
}


//*****************************************************************************
//        FINK CLASS
//*****************************************************************************

fink::fink() : abstr_emp(), reportsto ("None") {

}

fink::fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo) :
  abstr_emp(fn, ln, j), reportsto(rpo) {

}

fink::fink(const abstr_emp& e, const std::string& rpo) :
  abstr_emp(e), reportsto(rpo) {

}

fink::fink(const fink& e) :
  abstr_emp(e), reportsto(e.reportsto) {

}

void fink::ShowAll() const {
  abstr_emp::ShowAll();
  cout << "Finker reports to: " << ReportsTo() << endl;
}

void fink::SetAll() {
  abstr_emp::SetAll();
  cout << "To whom fink sends reports: ";
  cin >> reportsto;
}


//*****************************************************************************
//        HIGHFINK CLASS
//*****************************************************************************

highfink::highfink() : abstr_emp(), manager(), fink() {

}

highfink::highfink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo, int ico) :
  abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo) {

  }

highfink::highfink(const abstr_emp& e, const std::string& rpo, int ico) :
  abstr_emp(e), manager(e, ico), fink(e, rpo) {

}

highfink::highfink(const manager& m, const std::string& rpo) :
  abstr_emp(m), manager(m), fink(m, rpo) {

}

highfink::highfink(const fink& f, int ico) :
  abstr_emp(f), manager(f, ico), fink(f) {

}

highfink::highfink(const highfink& h) :
  abstr_emp(h), manager(h), fink(h) {

}

void highfink::ShowAll() const {
  abstr_emp::ShowAll();
  cout << "Manager charge: " << InChargeOf() << endl;
  cout << "Finker reports to: " << ReportsTo() << endl;
}

void highfink::SetAll() {
  abstr_emp::SetAll();
  cout << "How many employee inchagere: ";
  cin >> manager::InChargeOf();
  while (cin.get() != '\n')
    continue;
  cout << "To whom fink sends reports: ";
  cin >> fink::ReportsTo();
}
