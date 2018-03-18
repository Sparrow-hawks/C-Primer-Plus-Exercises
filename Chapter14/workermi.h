#ifndef WORKERMI_H
#define WORKERMI_H

#include <string>

class Worker { // Abstract base class
private:
  std::string fullname;
  long id;
protected:
  virtual void Data() const;
  virtual void Get();

public:
  Worker() : fullname("none"), id(0L) {}
  Worker(const std::string& s, long n) : fullname(s), id(n) {}
  virtual ~Worker();
  // Pure virtual function
  virtual void Set() = 0;
  virtual void Show() const = 0;
};

class Waiter : virtual public Worker {
private:
  int panache;
protected:
  void Data() const;
  void Get();
public:
  Waiter() : Worker(), panache (0) {}
  Waiter(const std::string& s, long n, int p = 0) : Worker (s, n), panache(p) {}
  Waiter(const Worker& wk, int p = 0) : Worker(wk), panache (p) {}
  void Set();
  void Show() const;
};

class Singer : virtual public Worker {
protected:
  enum {other, alt, contralto, soprane, bass, baritone, tenor};
  enum {Vtypes = 7};

  void Data() const;
  void Get();

private:
  static const char *pv[Vtypes];
  int voice;

public:
  Singer() : Worker(), voice (other) {}
  Singer(const std::string& s, long n, int v = other) :
    Worker (s, n), voice (v) {}
  Singer(const Worker& wk, int v = other) :
    Worker (wk), voice (v) {}

  void Set();
  void Show() const;
};

class SingingWaiter : public Singer, public Waiter {
protected:
  void Data() const;
  void Get();

public:
  SingingWaiter() {}
  SingingWaiter(const std::string& s, long n, int p = 0, int v = other) :
    Worker (s, n), Singer(s, n, v), Waiter (s, n, p) {}
  SingingWaiter(const Worker& wk, int p = 0, int v = other) :
    Worker (wk), Singer (wk, v), Waiter (wk, p) {}
  SingingWaiter(const Waiter& wt, int v = other) :
    Worker (wt), Singer(wt, v), Waiter(wt) {}
  SingingWaiter(const Singer& wt, int p = 0) :
    Worker (wt), Singer(wt), Waiter(wt) {}
  void Set();
  void Show() const;
};

#endif /* end of include guard: WORKERMI_H */
