//
// enshu5.cc - 2次元ベクトル型と2次正方行列型(C++版)テストプログラム
//	作者: Dewi; 日付: 2014/4/24
//
#include <stdio.h>
#include "enshu5.h"

Vector2::Vector2(void)	
{
        x = 0;
	y = 0;
}

//
// Vector2::Vector2() - x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
//
Vector2::Vector2(double x0, double y0)
{
	x = x0;
	y = y0;
}

// copy constructor
Vector2::Vector2(const Vector2 & v)
{
	x = v.x;
	y = v.y;
}

//
// Vector2::add() - 自身のベクトルとベクトル u との和を求める
//
Vector2 Vector2::add(Vector2 u)
{
	Vector2 ret;

	ret.x = x + u.x;
	ret.y = y + u.y;

	return ret;
}

//
// Vector2::sub() - 自身のベクトルとベクトル u との差を求める
//
Vector2 Vector2::sub(Vector2 u)
{
	Vector2 ret;

	ret.x = x - u.x;
	ret.y = y - u.y;

	return ret;
}

//
// Vector2::scan() - ベクトルの値を標準入力から自身に入力する
//
void Vector2::scan(void)
{
	scanf("%lf %lf", &x, &y);
}

//
// Vector2::print() - 自身のベクトルの値を標準出力に出力する
//
void Vector2::print(void)
{
	printf("( %f %f )", x, y);
}



Matrix22::Matrix22(void)	
{
        x[0][0] = 0;
	x[0][1] = 0;
	x[1][0] = 0;
	x[1][1] = 0;
}

Matrix22::Matrix22(double a, double b, double c, double d)
{
  x[0][0] = a;
  x[0][1] = b;
  x[1][0] = c;
  x[1][1] = d;
}

Matrix22::Matrix22(const Matrix22 & v)
{
  x[0][0] = v.x[0][0];
  x[0][1] = v.x[0][1];
  x[1][0] = v.x[1][0];
  x[1][1] = v.x[1][1];
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
// Matrix22::print() - 自身のmatrixの値を標準出力に出力する
//
void Matrix22::print(void)
{
  printf("| %6.3f %6.3f |\n", x[0][0], x[0][1]);
  printf("\t| %6.3f %6.3f |", x[1][0], x[1][1]);
}
