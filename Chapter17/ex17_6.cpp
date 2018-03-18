// Book:      C++ Primer Plus
// Chapter:   17
// Exercise:  6

#include <iostream>
#include <memory>
#include <fstream>
#include <vector>
#include "emp.h"

class Application {
private:
  std::vector<abstr_emp*> pc;
  const char *dbName;

  int getOption();
  void showOptions();
  void showAddOptions();

  bool readDatabase();
  void editDatabase();
  void writeDatabase();
  void expandDatabase();
  void createDatabase();
  void showDatabase() const;

public:
  Application() : dbName ("database.bin") {};
  ~Application();

  void run();
};

void Application::showDatabase() const {
  for(auto emp : pc)
    emp->ShowAll();
}

Application::~Application() {
  for (size_t i = 0; i < pc.size(); ++i)
    delete pc[i];
}

void Application::editDatabase(){
  size_t size, select;
  if ((size = pc.size()) != 0) {
    std::cout << "Select person: [1 - " << size + 1 << "]: ";
    select = getOption();
    if (select < size + 1) {
      // TODO Only possible to change user data, but not person type!
      pc[select - 1]->SetAll();
    } else {
      std::cout << "Wrong choice!\n";
    }
  } else {
    std::cout << "Database is empty!\n";
  }
}

void Application::expandDatabase() {
  showAddOptions();

  int choice;
  while((choice = getOption()) != 5) {
    abstr_emp* emp = nullptr;
    switch(choice) {
      case 1:
        emp = new employee;
        break;
      case 2:
        emp = new manager;
        break;
      case 3:
        emp = new fink;
        break;
      case 4:
        emp = new highfink;
        break;
      default:
        std::cout << "Wrong choice! Try again\n";
        break;
    }
    if (emp != nullptr) {
      emp->SetAll();
      pc.push_back(emp);
    }
    showAddOptions();
  }
}

void Application::createDatabase() {
  pc.clear();

  expandDatabase();
}

int Application::getOption() {
  int option;
  while (!(std::cin >> option)) {
    std::cin.clear();
    while (std::cin.get() != '\n')
      continue;
  }
  return option;
}

void Application::writeDatabase() {
  if (pc.empty()) {
    std::cout << "There is nothing to write!\n";
  }

  std::fstream out;

  out.open(dbName, std::ios_base::out | std::ios_base::binary);
  if (out.is_open()) {
    for (auto emp : pc)
      emp->WriteAll(out);
    out.close();
  } else {
    std::cerr << "[ERROR]: Can't create db file!\n";
  }
}

bool Application::readDatabase() {
  std::fstream in;

  in.open(dbName, std::ios_base::in | std::ios_base::binary);
  if (in.is_open()) {
    pc.clear();
    while (in) {
      int classtype = 0;
      if (in.read((char*)&classtype, sizeof(int))) {
        abstr_emp* emp = nullptr;
        switch(classtype) {
          case Employee:
            emp = new employee;
            break;
          case Manager:
            emp = new manager;
            break;
          case Fink:
            emp = new fink;
            break;
          case Highfink:
            emp = new highfink;
            break;
          default:
            std::cerr << "[ERROR: " << classtype << "] Database file corrupted!\n";
            std::cerr << "[OFFSET: " << in.tellg() << "]\n";
            exit(EXIT_FAILURE);
            break;
        }
        if (emp != nullptr) {
          emp->ReadAll(in);
          pc.push_back(emp);
        }
      }
    }
    in.close();
  } else
    return false;

  return true;
}

void Application::showOptions() {
  std::cout << "1. Show database    2. Edit database\n"
            << "3. Add to database  4. Exit\n";
}

void Application::showAddOptions() {
  std::cout << "1. Add Employee   2. Add Manager\n"
            << "3. Add Fink       3. Add Highfink\n"
            << "5. Exit\n";
}


void Application::run() {
  std::cout << "*** WELCOME *** " << std::endl;

  if (!readDatabase())
    createDatabase();

  showDatabase();
  showOptions();
  int choice;
  while((choice = getOption()) != 4) {
    switch(choice) {
      case 1:
        showDatabase();
        break;
      case 2:
        editDatabase();
        break;
      case 3:
        expandDatabase();
        break;
      default:
        std::cout << "Wrong choice! Try again\n";
        break;
    }
    showOptions();
  }
  writeDatabase();

  std::cout << "*** GOODBYE *** " << std::endl;
}

int main(int argc, char* argv[]) {

  std::unique_ptr<Application> app(new Application);
  app->run();

  return 0;
}
