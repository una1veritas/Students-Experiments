#include <stdio.h>
#include "mat2.h"

Matrix2::Matrix2(double aa, double ab, double ba, double bb)
{
  a[0][0] = aa;
  a[0][1] = ab;
  a[1][0] = ba;
  a[1][1] = bb;
}

Matrix2::Matrix2(const Matrix2 &m)
{
  a[0][0] = m.a[0][0];
  a[0][1] = m.a[0][1];
  a[1][0] = m.a[1][0];
  a[1][1] = m.a[1][1];
}

Matrix2 Matrix2::add(Matrix2 u)
{
  Matrix2 ret;

  ret.a[0][0] = a[0][0] + u.a[0][0];
  ret.a[0][1] = a[0][1] + u.a[0][1];
  ret.a[1][0] = a[1][0] + u.a[1][0];
  ret.a[1][1] = a[1][1] + u.a[1][1];

  return ret;
}

Matrix2 Matrix2::sub(Matrix2 u)
{
  Matrix2 ret;

  ret.a[0][0] = a[0][0] - u.a[0][0];
  ret.a[0][1] = a[0][1] - u.a[0][1];
  ret.a[1][0] = a[1][0] - u.a[1][0];
  ret.a[1][1] = a[1][1] - u.a[1][1];

  return ret;
}

Matrix2 Matrix2::mul(Matrix2 u)
{
  Matrix2 ret;

  ret.a[0][0] = a[0][0] * u.a[0][0] + a[0][1] * u.a[1][0];
  ret.a[0][1] = a[0][0] * u.a[0][1] + a[0][1] * u.a[1][1];
  ret.a[1][0] = a[1][0] * u.a[0][0] + a[1][1] * u.a[1][0];
  ret.a[1][1] = a[1][1] * u.a[0][1] + a[1][1] * u.a[1][1];

  return ret;
}

void Matrix2::scan(void)
{
  scanf("%lf %lf", &a[0][0], &a[0][1]);
  scanf("%lf %lf", &a[1][0], &a[1][1]);
}

void Matrix2::print(void)
{
  printf("| %f %f |\n| %f %f |\n", a[0][0],a[0][1],a[1][0],a[1][1]);
}
