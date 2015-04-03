
#ifndef VECTOR2P_H
#define VECTOR2P_H

class Mtrix{
 private:
  double x1;
  double y1;
  double x2;
  double y2;
  
 public:
  Mtrix(void){}
  Mtrix(double x1_0, double y1_0, double x2_0, double y2_0);
  Mtrix add(Mtrix u);
  Mtrix sub(Mtrix u);
  Mtrix mul(Mtrix u);
  void print(void);
  void scan(void);
};

#endif
