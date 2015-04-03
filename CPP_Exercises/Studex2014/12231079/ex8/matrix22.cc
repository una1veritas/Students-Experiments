//
// vector2p.cc - 2次元ベクトル型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "matrix22.h"

Matrix22::Matrix22(void)
{
  x[0][0] = 0;
  x[0][1] = 0;
  x[1][0] = 0;
  x[1][1] = 0;
}

Matrix22::Matrix22(const Matrix22& m)
{
  x[0][0] = m.x[0][0];
  x[0][1] = m.x[0][1];
  x[1][0] = m.x[1][0];
  x[1][1] = m.x[1][1];
}

Matrix22::Matrix22(double m00, double m01, double m10, double m11)
{
  x[0][0] = m00;
  x[0][1] = m01;
  x[1][0] = m10;
  x[1][1] = m11;
}

Matrix22 Matrix22::add(Matrix22 m)
{
  Matrix22 reg;
  reg.x[0][0] = x[0][0] + m.x[0][0];
  reg.x[0][1] = x[0][1] + m.x[0][1];
  reg.x[1][0] = x[1][0] + m.x[1][0];
  reg.x[1][1] = x[1][1] + m.x[1][1];
  return reg;
}

Matrix22 Matrix22::sub(Matrix22 m)
{
  Matrix22 reg;
  reg.x[0][0] = x[0][0] - m.x[0][0];
  reg.x[0][1] = x[0][1] - m.x[0][1];
  reg.x[1][0] = x[1][0] - m.x[1][0];
  reg.x[1][1] = x[1][1] - m.x[1][1];
  return reg;
}

Matrix22 Matrix22::mul(Matrix22 m)
{
  Matrix22 reg;
  reg.x[0][0] = x[0][0] * m.x[0][0] + x[0][1] * m.x[1][0];
  reg.x[0][1] = x[0][0] * m.x[0][1] + x[0][1] * m.x[1][1];
  reg.x[1][0] = x[1][0] * m.x[0][0] + x[1][1] * m.x[1][0];
  reg.x[1][1] = x[1][0] * m.x[0][1] + x[1][1] * m.x[1][1];
  return reg;
}

void Matrix22::scan(void)
{
  scanf("%lf %lf %lf %lf", &x[0][0], &x[0][1], &x[1][0], &x[1][1]);
}

void Matrix22::print(void)
{
  printf("\n\n%lf %lf \n%lf %lf\n", x[0][0], x[0][1], x[1][0], x[1][1]);
}
