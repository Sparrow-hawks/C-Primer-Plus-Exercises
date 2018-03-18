#ifndef _BANKACCOUNT_H_
#define _BANKACCOUNT_H_

#include <string>

class BankAccount {
public:
  BankAccount(const std::string& name, const std::string& number, double balance);
  ~BankAccount();

  void show(void) const;
  void payIn(double amount);
  double payOut(double amount);

private:
  std::string m_Name;
  std::string m_Number;
  double m_Balance;
};

#endif
