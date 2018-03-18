#ifndef _STOCK_2_H
#define _STOCK_2_H

#include <iostream>

class Stock {
private:
  enum {CLIM = 80};
  char *company;
  int shares;
  double share_val;
  double total_val;
  void set_tot() {total_val = shares * share_val;}

  Stock& operator=(const Stock& s) {return *this;}

public:
  Stock();
  Stock(const char *co, long n = 0, double pr = 0.0);
  Stock(const Stock& s);
  ~Stock();

  void buy(long num, double price);
  void sell(long num, double price);
  void update(double price);

  const Stock& topval(const Stock& s) const;

  friend std::ostream& operator<<(std::ostream& os, const Stock& s);
};

#endif
