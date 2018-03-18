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
  Queue line_1(qs);
  Queue line_2(qs);

  cout << "Enter simulation time (in hours): ";
  int hours;
  cin >> hours;

  // Simulation with minute resolution
  long cyclelimit = MIN_PER_HR * hours;

  cout << "Enter average customer number per hour: ";
  double perhour;
  cin >> perhour;

  double min_per_cust;   // Average time distance betwen clients
  min_per_cust = MIN_PER_HR / perhour;

  Item temp;            // New client data
  long turnaways = 0;   // Clients sent back
  long customers = 0;   // Clients adopted
  long served = 0;      // Clients served
  long sum_line = 0;    // Total waiting clients
  int wait_time_1 = 0;    // Time to ATM free
  int wait_time_2 = 0;
  long line_wait = 0;   // Total waiting time;

  // Simulation begin
  for (int cycle = 0; cycle < cyclelimit; cycle++) {
    if (newcustomer(min_per_cust)) {
      // New client arrived
      if (line_1.isfull() && line_2.isfull())
        turnaways++;
      else {
        customers++;
        temp.set(cycle);
        if (line_1.queuecount() <= line_2.queuecount())
          line_1.enqueue(temp);
        else
          line_2.enqueue(temp);
      }
    }
    if (wait_time_1 <= 0 && !line_1.isempty()) {
      line_1.dequeue(temp);         // Next to served
      wait_time_1 = temp.ptime();   // Serve time = wait_time
      line_wait += cycle - temp.when();
      served++;
    }
    if (wait_time_2 <= 0 && !line_2.isempty()) {
      line_2.dequeue(temp);         // Next to served
      wait_time_2 = temp.ptime();   // Serve time = wait_time
      line_wait += cycle - temp.when();
      served++;
    }
    if (wait_time_1 > 0)
      wait_time_1--;
    if (wait_time_2 > 0)
      wait_time_2--;
    sum_line += line_1.queuecount() + line_2.queuecount();
  }

  // Results
  if (customers > 0) {
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
