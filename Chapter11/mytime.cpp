#include "mytime.h"

Time::Time() {
  hours = minutes = 0;
}

Time::Time(int h, int m) {
  hours = h;
  minutes = m;
}

void Time::AddMin(int m) {
  minutes += m;
  hours += minutes / 60;
  minutes %= 60;
}

void Time::AddHr(int h) {
  hours += h;
}

void Time::Reset(int h, int m) {
  hours = h;
  minutes = m;
}

Time Time::operator*(double m) const {
  long totalminutes = hours * m * 60 + minutes * m;

  return Time(totalminutes / 60, totalminutes % 60);
}

Time operator+(const Time& t1, const Time& t2) {
  int minutes = t1.minutes + t2.minutes;
  int hours = t1.hours + t2.hours + minutes / 60;

  minutes %= 60;

  return Time(hours, minutes);
}

Time operator-(const Time& t1, const Time& t2) {
  int tot1, tot2, hours, minutes;

  tot1 = t2.minutes + 60 * t2.hours;
  tot2 = t1.minutes + 60 * t1.hours;

  minutes = (tot2 - tot1) % 60;
  hours = (tot2 - tot1) / 60;

  return Time(hours, minutes);
}

Time operator*(double m, const Time& t) {
  long totalminutes = t.hours * m * 60 + t.minutes * m;

  return Time(totalminutes / 60, totalminutes % 60);
}

ostream& operator<<(ostream& os, const Time& t) {
  os << t.hours << " hours, " << t.minutes << " minut";

  return os;
}
