// Book:      C++ Prime Plus
// Chapter:   16
// Exercise:  6

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>

class Customer {
private:
  long arrive;
  int processtime;

public:
  Customer() {arrive = processtime = 0;}

  void set(long when);

  long when() const {return arrive;}
  int ptime() const {return processtime;}
};

void Customer::set(long when) {
  processtime = std::rand() % 3 + 1;
  arrive = when;
}

const int MIN_PER_HR = 60;
bool newcustomer(double x);

int main() {
  using std::cin;
  using std::cout;
  using std::endl;
  using std::ios_base;

  std::srand(std::time(0));

  cout << "Study case: Bank's ATM\n";
  cout << "Enter max queue length: ";
  int qs;
  cin >> qs;

  std::queue<Customer> line;

  cout << "Enter simulation time (in hours): ";
  int hours;
  cin >> hours;

  long cyclelimit = MIN_PER_HR * hours;

  cout << "Enter average clients per hour: ";
  double perhour;
  cin >> perhour;
  double min_per_cust;
  min_per_cust = MIN_PER_HR / perhour;

  Customer temp;
  long turnaways = 0;
  long customers = 0;
  long served = 0;
  long sum_line = 0;
  int wait_time = 0;
  long line_wait = 0;

  for (int cycle = 0; cycle < cyclelimit; ++cycle) {
    if (newcustomer(min_per_cust)) {
      if (line.size() == qs)
        ++turnaways;
      else {
        ++customers;
        temp.set(cycle);
        line.push(temp);
      }
    }
    if (wait_time <= 0 && !line.empty()) {
      temp = line.front();
      wait_time = temp.ptime();
      line_wait += cycle - temp.when();
      line.pop();
      ++served;
    }
    if (wait_time > 0)
      --wait_time;
    sum_line += line.size();
  }

  if (customers > 0) {
    cout << "Customers:        " << customers << endl;
    cout << "Served:           " << served << endl;
    cout << "Turned back:      " << turnaways << endl;
    cout << "Avg queue length: ";
    cout.precision(2);
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout.setf(ios_base::showpoint);
    cout << (double) sum_line / cyclelimit << endl;
    cout << "Avg wait time:    "
      << (double) line_wait / served << " minutes\n";
  } else
    cout << "No clients!\n";

  cout << "*** READY ***" << std::endl;

  return 0;
}

bool newcustomer(double x) {
  return (std::rand() * x / RAND_MAX < 1);
}
