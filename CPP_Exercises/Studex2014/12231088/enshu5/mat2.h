#ifndef MAT2_H
#define MAT2_H

class Matrix2{

 private:
  double a[2][2];

 public:
  Matrix2(void){a[0][0] = 0; a[0][1] = 0; a[1][0] = 0; a[1][1] = 0;}
  Matrix2(double aa, double ab, double ba, double bb);
  Matrix2(const Matrix2 &m);
  Matrix2 add(Matrix2 m);
  Matrix2 sub(Matrix2 m);
  Matrix2 mul(Matrix2 m);
  void scan(void);
  void print(void);

};

#endif
