// Book:      C++ Primer Plus
// Chapter:   14
// Exercise:  3

#include <iostream>
#include <cstring>
#include "workermi.h"
#include "queueTp.h"

const int SIZE = 5;

int main() {

  using std::cin;
  using std::cout;
  using std::endl;
  using std::strchr;

  Worker *worker;
  QueueTp<Worker*> lolas;
  int ct;
  for (ct = 0; ct < SIZE; ++ct) {
    char choice;
    cout << "Enter worker category:\n"
      << "w: waiter  s: singer  "
      << "p: singer waiter  q: quit\n";
    cin >> choice;
    while (strchr("wspq", choice) == NULL) {
      cout << "Enter w, s, p or q: ";
      cin >> choice;
    }
    if (choice == 'q')
      break;
    switch (choice) {
      case 'w':
        worker = new Waiter;
        break;
      case 's':
        worker = new Singer;
        break;
      case 'p':
        worker = new SingingWaiter;
        break;
    }
    cin.get();
    worker->Set();
    lolas.push(worker);
  }

  cout << "\nNumber of workers: " << lolas.size() << std::endl;
  cout << "\nWorkers list:\n";

  while (!lolas.empty()) {
    worker = lolas.first();
    lolas.pop();
    cout << endl;
    worker->Show();
    delete worker;
  }

  cout << "End.\n";

  return 0;
}
