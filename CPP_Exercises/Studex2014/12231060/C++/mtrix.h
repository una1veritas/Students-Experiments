#ifndef MTRIX_H
#define MTRIX_H

class Mtrix{
 private:
  double x1, y1, x2, y2;
  
 public:
  Mtrix(void)
    Mtrix(double x1_0, double y1_0, double x2_0, double y2_0)
    Mtrix add(Mtrix u);
  Mtrix sub(Mtrix u);
  Mtrix mul(Mtrix u);
  void print(void);
  void scan(void);
}
