// Book:      C++ Primer Plus
// Chapter:   16
// Exercise:  9

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using std::vector;
using std::list;
using std::cout;
using std::endl;
using std::cin;

int main() {
  srand(time(0));

  size_t size = 0;
  cout << "Enter size of array: ";
  cin >> size;

  vector<int> vi0;
  for (size_t i = 0; i < size; ++i)
    vi0.push_back(rand());

  vector<int> vi (vi0);
  list<int> li (vi0.begin(), vi0.end());

  clock_t start, end;

  cout << "Sorting vector:\n";
  start = clock();
  std::sort(vi.begin(), vi.end());
  end = clock();
  cout << "Execution time: " << std::fixed << std::setprecision(4) << (double)(end - start) / CLOCKS_PER_SEC << " [s]." << endl;

  cout << "Sorting list:\n";
  start = clock();
  li.sort();
  end = clock();
  cout << "Execution time: " << std::fixed << std::setprecision(4) << (double)(end - start) / CLOCKS_PER_SEC << " [s]." << endl;

  std::copy(vi0.begin(), vi0.end(), li.begin());

  cout << "Sorting list with copy to vector:\n";
  start = clock();
  std::copy(li.begin(), li.end(), vi.begin());
  std::sort(vi.begin(), vi.end());
  std::copy(vi.begin(), vi.end(), li.begin());
  end = clock();
  cout << "Execution time: " << std::fixed << std::setprecision(4) << (double)(end - start) / CLOCKS_PER_SEC << " [s]." << endl;

  return 0;
}
