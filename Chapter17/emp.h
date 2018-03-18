#ifndef _EMP_H
#define _EMP_H

#include <iostream>
#include <string>
#include <fstream>

enum {Employee = 1, Manager, Fink, Highfink};

class abstr_emp {
private:
  std::string fname; // abstr_emp object's first name
  std::string lname; // abstr_emp object's last name
  std::string job;

protected:
  std::string readString(std::fstream& in);
  void writeString(std::fstream& out, const std::string& s) const;

public:
  abstr_emp();
  abstr_emp(const std::string &fn, const std::string& ln, const std::string& j);

  virtual void ShowAll() const; // Displays all data
  virtual void SetAll();        // Ask user about data
  virtual void WriteAll(std::fstream& out) const;     // Store data in file
  virtual void ReadAll(std::fstream& in);       // Read data from file

  friend std::ostream& operator<<(std::ostream& os, const abstr_emp& e); // Only name & surname

  virtual ~abstr_emp() = 0;     // Virtual base class
};

class employee : public abstr_emp {
public:
  employee();
  employee(const std::string& fn, const std::string& ln, const std::string& j);

  virtual void ShowAll() const;
  virtual void SetAll();
  virtual void WriteAll(std::fstream& out) const;     // Store data in file
  virtual void ReadAll(std::fstream& in);       // Read data from file
};

class manager : virtual public abstr_emp {
private:
  int inchargeof;   //Number of management abstr_emp
protected:
  int InChargeOf() const {return inchargeof;} // output
  int& InChargeOf() {return inchargeof;}      // input
public:
  manager();
  manager(const std::string& fn, const std::string& ln, const std::string& j, int ico = 0);
  manager(const abstr_emp& e, int ico);
  manager(const manager& m);

  virtual void ShowAll() const;
  virtual void SetAll();
  virtual void WriteAll(std::fstream& out) const;     // Store data in file
  virtual void ReadAll(std::fstream& in);       // Read data from file
};

class fink : virtual public abstr_emp {
private:
  std::string reportsto; // To who finker sends report?

protected:
  const std::string ReportsTo() const {return reportsto;}
  std::string& ReportsTo() {return reportsto;}

public:
  fink();
  fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo);
  fink(const abstr_emp& e, const std::string& rpo);
  fink(const fink& e);

  virtual void ShowAll() const;
  virtual void SetAll();
  virtual void WriteAll(std::fstream& out) const;     // Store data in file
  virtual void ReadAll(std::fstream& in);       // Read data from file
};

class highfink : public manager, public fink {
public:
  highfink();
  highfink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo, int ico);
  highfink(const abstr_emp& e, const std::string& rpo, int ico);
  highfink(const fink& f, int ico);
  highfink(const manager& m, const std::string& rpo);
  highfink(const highfink& h);

  virtual void ShowAll() const;
  virtual void SetAll();
  virtual void WriteAll(std::fstream& out) const;     // Store data in file
  virtual void ReadAll(std::fstream& in);       // Read data from file
};

#endif
