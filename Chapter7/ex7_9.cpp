// Book:      C++ Primer Plus
// Chapter:   7
// Exercise:  9

#include <iostream>
#include <cstring>

using namespace std;

const int SLEN = 30;
struct Student {
  char fullname[SLEN];
  char hobby[SLEN];
  int ooplevel;
};

// Funkcja getinfo() ma dwa parametry: wskaźnik pierwszego elementu tablicy
// struktur student oraz liczbę int określającą liczbę elementów w tablicy.
// Funkcja pobiera i zapisuje dane o studentach. Wprowadzanie danych kończy
// się, kiedy tablica jest pełna lub podane zostanie puste nazwisko studenta.
// Funkcja zwraca liczbę studentów wpisanych do tablicy
int getinfo(Student pa[], int n);

// Funkcja display1() pobiera jako parametr strukturę student i pokazuje jej
// zawartość.
void display1(Student st);

// Funkcja display2() pobiera jako parametr adres struktury student i pokazuje
// zawartość tej struktury.
void display2(const Student *ps);

// Funkcja display3() pobiera jako parametry adres pierwszego elementu tablicy
// ze strukturami student oraz liczbę elementów w tablicy, po czym wyświetla
// zawartość wskazanych struktur.
void display3(const Student pa[], int n);

int main(void) {
  cout << "Podaj wielkość grupy: ";
  
  int class_size;
  cin >> class_size;
  while (cin.get() != '\n')
    continue;
  
  Student *ptr_stu = new Student[class_size];
  
  int entered = getinfo(ptr_stu, class_size);
  for (int i = 0; i < entered; ++i) {
    display1(ptr_stu[i]);
    display2(&ptr_stu[i]);
  }
  display3(ptr_stu, entered);
  
  delete[] ptr_stu;
  
  cout << "Do widzenia!" << std::endl;
  
  return 0;
}

int getinfo(Student pa[], int n) {
  cout << "Podaj dane studentów: " << endl;
  int count = 0;
  for (count = 0; count < n; ++count) {
    cout << "Student [" << count << "] - nazwisko: ";
    cout.flush();
    
    cin.getline(pa[count].fullname, SLEN);
    if (!strlen(pa[count].fullname)) {
      cout << "Nie wprowadzono żadnego nazwiska - koniec" << endl;
      break;
    }
    
    cout << "Student [" << count << "] - hobby:    ";
    cout.flush();
    
    cin.getline(pa[count].hobby, SLEN);
    
    cout << "Student [" << count << "] - level:    ";
    cout.flush();
    
    cin >> pa[count].ooplevel;
    cin.get();
  }
  return count;
}

void display1(Student st) {
  std::cout << st.fullname << " " << st.hobby << " " << st.ooplevel << std::endl;
}

void display2(const Student *ps) {
  std::cout << ps->fullname << " " << ps->hobby << " " << ps->ooplevel << std::endl;
}

void display3(const Student pa[], int n) {
  for (int i = 0; i < n; ++i) {
    std::cout << i << ". " << pa[i].fullname << " " << pa[i].hobby << " " << pa[i].ooplevel << std::endl;
  }
}
