// Book:      C++ Primer Plus
// Chapter:   12
// Exercise:  5

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"

const int MIN_PER_HR = 60;
bool newcustomer(double x);

int main() {
  using std::cin;
  using std::cout;
  using std::endl;
  using std::ios_base;

  std::srand(std::time(0));

  cout << "Case study: ATM\n";
  cout << "Enter queue max length: ";
  int qs;
  cin >> qs;
  Queue line(qs);

  cout << "Enter simulation time (in hours): ";
  int hours;
  cin >> hours;

  // Simulation with minute resolution
  long cyclelimit = MIN_PER_HR * hours;

  long turnaways = 0;   // Clients sent back
  long customers = 0;   // Clients adopted
  long served = 0;      // Clients served
  long sum_line = 0;    // Total waiting clients
  int wait_time = 0;    // Time to ATM free
  long line_wait = 0;   // Total waiting time;

  double perhour = 120;
  do {

    double min_per_cust = MIN_PER_HR / perhour--;
    // Simulation begin

    Item temp;
    turnaways = 0;
    customers = 0;
    served = 0;
    sum_line = 0;
    wait_time = 0;
    line_wait = 0;
    for (int cycle = 0; cycle < cyclelimit; cycle++) {
      if (newcustomer(min_per_cust)) {
        if (line.isfull())
          turnaways++;
        else {
          customers++;
          temp.set(cycle);        // Time of arrival
          line.enqueue(temp);     // Client join to queue
        }
      }
      if (wait_time <= 0 && !line.isempty()) {
        line.dequeue(temp);         // Next to served
        wait_time = temp.ptime();   // Serve time = wait_time
        line_wait += cycle - temp.when();
        served++;
      }
      if (wait_time > 0)
        wait_time--;
      sum_line += line.queuecount();
    }
  } while (line_wait / served > 1.0);

  // Results
  if (customers > 0) {
    cout << "Average clients number:      " << perhour << endl;
    cout << "Number of adopted clients:   " << customers << endl;
    cout << "Number of served clients:    " << served << endl;
    cout << "Number of send back clients: " << turnaways << endl;
    cout << "Average queue length: ";
    cout.precision(2);
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.setf(ios_base::showpoint);
    cout << (double) sum_line / cyclelimit << endl;
    cout << "Average wait time: "
      << (double) line_wait / served << " minutes\n";
  } else {
    cout << "No customers!\n";
  }
  cout << "Goodbye!\n";

  return 0;
}

bool newcustomer(double x) {
  return (std::rand() * x / RAND_MAX < 1);
}
