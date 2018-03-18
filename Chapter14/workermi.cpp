#include "workermi.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/******************************************************************************
 * Worker class                                                               *
 *****************************************************************************/
Worker::~Worker() {

}

void Worker::Data() const {
  cout << "Name & Surname: " << fullname << endl;
  cout << "ID number: " << id << endl;
}

void Worker::Get() {
  getline(cin, fullname);
  cout << "Enter ID number: ";
  cin >> id;
  while (cin.get() != '\n')
    continue;
}

void Waiter::Set() {
  cout << "Enter waiter name & surname: ";
  Worker::Get();
  Get();
}

void Waiter::Show() const {
  cout << "Category: waiter\n";
  Worker::Data();
  Data();
}

void Waiter::Data() const {
  cout << "Elegance: " << panache << endl;
}

void Waiter::Get() {
  cout << "Enter waiter's elegance level: ";
  cin >> panache;
  while (cin.get() != '\n')
    continue;
}


/******************************************************************************
 * Singer class                                                               *
 *****************************************************************************/
const char *Singer::pv[Singer::Vtypes] = {"other", "alt", "contralto", "soprane",
  "bass", "baritone", "tenor"
};

void Singer::Set() {
  cout << "Enter singer name & surname: ";
  Worker::Get();
  Get();
}

void Singer::Show() const {
  cout << "Category: singer\n";
  Worker::Data();
  Data();
}

void Singer::Data() const {
  cout << "Voice scale: " << pv[voice] << endl;
}

void Singer::Get() {
  cout << "Enter number for singer voice scale:\n";
  int i;
  for (i = 0; i < Vtypes; ++i) {
    cout << i << ": " << pv[i] << "   ";
    if (i % 4 != 0)
      cout << endl;
  }
  if (i % 4 != 0)
    cout << '\n';
  cin >> voice;
  while (cin.get() != '\n')
    continue;
}


/******************************************************************************
 * Singingwaiter class                                                               *
 *****************************************************************************/
void SingingWaiter::Data() const {
  Singer::Data();
  Waiter::Data();
}

void SingingWaiter::Get() {
  Waiter::Get();
  Singer::Get();
}

void SingingWaiter::Set() {
  cout << "Enter name & fullname for singingwaiter: ";
  Worker::Get();
  Get();
}

void SingingWaiter::Show() const {
  cout << "Category: singing waiter\n";
  Worker::Data();
  Data();
}
