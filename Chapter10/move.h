#ifndef _MOVE_H_
#define _MOVE_H_

class Move {
public:
  Move(double a = 0, double b = 0);

  void show() const;
  Move add(const Move& m) const;
  void reset(double a = 0, double b = 0);

private:
  double x;
  double y;
};

#endif
