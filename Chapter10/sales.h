#ifndef _SALES_H
#define _SALES_H

namespace SALES {

class Sales {
public:
  Sales();
  Sales(const double *ar, int n);

  void show() const;

private:
  double getAvg() const;
  double getMax() const;
  double getMin() const;

  static const int QUARTERS = 4;
  double m_Sales[QUARTERS];

  size_t m_Count;
};

}

#endif
