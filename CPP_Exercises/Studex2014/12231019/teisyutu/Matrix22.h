#ifndef VECTOR2C_H
#define VECTOR2C_H

class Matrix22{
private:
   double x[2][2];
public:
  Matrix22(void);
  Matrix22(double x0);
  Matrix22 add(Matrix22 u);
  Matrix22 sub(Matrix22 u);
  Matrix22 mul(Matrix22 u);
  void scan(void);
  void print(void);
};
#endif
