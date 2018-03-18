#ifndef _GOLF_H
#define _GOLF_H

class Golf {
public:

  Golf(const char *name, int hc = 10);
  Golf();

  bool set();
  void handicap(int hc);
  void show() const;
private:
  static const unsigned int LEN = 40;

  char m_Name[LEN];
  int m_HC;
};

#endif
