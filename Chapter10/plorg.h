#ifndef _PLORG_H_
#define _PLORG_H_


class Plorg {
public:
  Plorg(const char *name = "Plorga");

  inline void setSatiety(unsigned int satiety) {m_Satiety = satiety;}

  void show() const;
private:
  enum {LEN = 20};

  char m_Name[LEN];
  unsigned int m_Satiety;
};

#endif
