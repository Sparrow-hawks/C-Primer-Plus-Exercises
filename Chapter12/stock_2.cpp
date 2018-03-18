#include <iostream>
#include <cstring>
#include "stock_2.h"

// Constructors
Stock::Stock() {
  company = new char[1];
  company[0] = '\0';

  shares = 0;
  share_val = 0.0;
  total_val = 0.0;
}

Stock::Stock(const char *co, long n, double pr) {
  company = new char[strlen(co) + 1];
  strcpy(company, co);

  if (n < 0) {
    std::cout << "Number of shares couldn't be less than 0. "
      << "I'm setting shares in " << company << " to 0.\n";
      shares = 0;
  } else {
    shares = n;
  }
  share_val = pr;
  set_tot();
}

// Destructor
Stock::~Stock() {
  delete [] company;
}

// Copy Constructors
Stock::Stock(const Stock& s) {
  company = new char[strlen(s.company) + 1];
  strcpy(company, s.company);

  shares = s.shares;
  share_val = s.share_val;

  set_tot();
}

// Class methods
void Stock::buy(long num, double price) {
  if (num < 0) {
    std::cout << "Number of new shares couldn't be less than 0. "
      << "Transaction interrupted.\n";
  } else {
    shares += num;
    share_val = price;
    set_tot();
  }
}

void Stock::sell(long num, double price) {
  using std::cout;
  if (num > 0) {
    cout << "Number of selling shares couldn't be odd. "
      << "Transaction rejected.\n";
  } else if (num > shares) {
    cout << "You can't sell more shares than You have! "
      << "Transaction interrupted.\n";
  } else {
    shares -=num;
    share_val = price;
    set_tot();
  }
}

void Stock::update(double price) {
  share_val = price;
  set_tot();
}

std::ostream& operator<<(std::ostream& os, const Stock& s) {
  using std::ios_base;

  ios_base::fmtflags orig = os.setf(ios_base::fixed, ios_base::floatfield);
  std::streamsize prec = os.precision(3);

  os << "Company: " << s.company
    << " Number of shares: " << s.shares << '\n'
    << " Share price: " << s.share_val << "$ ";
    os.precision(2);
    os << "Total share value: " << s.total_val << "$ ";

  os.setf(orig, ios_base::floatfield);
  os.precision(prec);

  return os;
}

const Stock& Stock::topval(const Stock& s) const {
  if (s.total_val > total_val)
    return s;
  else
    return *this;
}
