// Book:      C++ Primer Plus
// Chapter:   8
// Exercise:  7

#include <iostream>

template <typename T>
void showarray(T arr[], int n);

template <typename T>
void showarray(T *arr[], int n);

template <typename T>
T sumarray(T arr[], int n);

template <typename T>
T sumarray(T *arr[], int n);

struct Debts {
  char name[50];
  double amount;
};

int main() {
  int things[6] = {13, 31, 103, 301, 310, 130};

  Debts mr_E[3] = {
    {"Ima Wolfe", 2400.0},
    {"Ura Foxe", 1300.0},
    {"Iby Stout", 1800.0}
  };

  double *pd[3];
  for (int i = 0; i < 3; ++i)
    pd[i] = &mr_E[i].amount;

  std::cout << "Counting things Mr's E. :\n";

  showarray(things, 6);

  std::cout << "Sum of Mr's E. things: ";
  std::cout << sumarray(things, 6) << std::endl;

  std::cout << "Counting debts Mr's E. :\n";

  showarray(pd, 3);

  std::cout << "Sum of Mr's E. debts: ";
  std::cout << sumarray(pd, 3) << std::endl;

  return 0;
}

template <typename T>
void showarray(T arr[], int n) {
  std::cout << "Template A\n";
  for (int i = 0; i < n; ++i)
    std::cout << arr[i] << ' ';
  std::cout << std::endl;
}

template <typename T>
void showarray(T *arr[], int n) {
  std::cout << "Template B\n";
  for (int i = 0; i < n; ++i)
    std::cout << *arr[i] << ' ';
  std::cout << std::endl;
}

template <typename T>
T sumarray(T arr[], int n) {
  T result = arr[0];
  for (int i = 1; i < n; ++i)
    result += arr[i];
  return result;
}

template <typename T>
T sumarray(T *arr[], int n) {
  T result = *arr[0];
  for (int i = 1; i < n; ++i)
    result += *arr[i];
  return result;
}
