//
// matrix22_4.cc - 2次正方行列型(C++版)
//	作者: Dewi; 日付: 2014/4/24
//
#include <stdio.h>
#include "matrix22_4.h"

Matrix22::Matrix22(double a, double b, double c, double d)
{
  x[0][0] = a;
  x[0][1] = b;
  x[1][0] = c;
  x[1][1] = d;
}

//
// Matrix22::add() - 自身のmatrixとmatrix u との和を求める
//
Matrix22 Matrix22::add(Matrix22 u)
{
  Matrix22 ret;
  int i = 0, j = 0;

  for(i = 0; i < 2; i++)
    for(j = 0; j < 2; j++)
      ret.x[i][j] = x[i][j] + u.x[i][j];

  return ret;
}

//
// Matrix22::sub() - 自身のmatrixとmatrix u との差を求める
//
Matrix22 Matrix22::sub(Matrix22 u)
{
  Matrix22 ret;
  int i = 0, j = 0;
  
  for(i = 0; i < 2; i++)
    for(j = 0; j < 2; j++)
      ret.x[i][j] = x[i][j] - u.x[i][j];

  return ret;
}

Matrix22 Matrix22::mul(Matrix22 u)
{
  Matrix22 ret;

  ret.x[0][0] = x[0][0] * u.x[0][0] + x[0][1] * u.x[1][0];
  ret.x[0][1] = x[0][0] * u.x[0][1] + x[0][1] * u.x[1][1];
  ret.x[1][0] = x[1][0] * u.x[0][0] + x[1][1] * u.x[1][0];
  ret.x[1][1] = x[1][0] * u.x[0][1] + x[1][1] * u.x[1][1];

  return ret;
}

//
// Matrix22::scan() - matrixの値を標準入力から自身に入力する
//
void Matrix22::scan(void)
{
  scanf("%lf %lf", &x[0][0], &x[0][1]);
  scanf("%lf %lf", &x[1][0], &x[1][1]);
}

//
// Matrix2::print() - 自身のmatrixの値を標準出力に出力する
//
void Matrix22::print(void)
{
  printf("| %6.3f %6.3f |\n", x[0][0], x[0][1]);
  printf("\t| %6.3f %6.3f |", x[1][0], x[1][1]);
}
