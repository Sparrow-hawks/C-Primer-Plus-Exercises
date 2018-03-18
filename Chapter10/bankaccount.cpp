#include <iostream>
#include "bankaccount.h"

BankAccount::BankAccount(const std::string& name, const std::string& number, double balance) :
  m_Name {name}, m_Number {number}, m_Balance {balance} {

}

BankAccount::~BankAccount() {

}

void BankAccount::payIn(double amount) {
  m_Balance += amount;
}

double BankAccount::payOut(double amount) {
  if (amount >= m_Balance) {
    amount = m_Balance;
  }
  m_Balance -= amount;

  return amount;
}

void BankAccount::show(void) const {
  std::cout << "Bank account details: " << std::endl;
  std::cout << "Owner name:      " << m_Name << std::endl;
  std::cout << "Account number:  " << m_Number << std::endl;
  std::cout << "Account balance: " << m_Balance << " $" << std::endl;
}
