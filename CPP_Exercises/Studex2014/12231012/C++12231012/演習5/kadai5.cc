//
// kadai5 .cc - 2次元正方行列型(C++版)
//	作者: 浦川楓; 日付: 2014/4/17
//
#include <stdio.h>
#include "kadai5.h"

//
// Matrix::Matrix() - x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
//
Matrix::Matrix(double x0, double y0, double x1, double y1)
{
	val[0][0] = x0;
	val[1][0] = x1;
	val[0][1] = y0;
	val[1][1] = y1;
}


Matrix::Matrix(const Matrix &v)
{
  val[0][0] = v.val[0][0];
  val[0][1] = v.val[0][1];
  val[1][0] = v.val[1][0];
  val[1][1] = v.val[1][1];
}

//
// Vector2::Vector2() - x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
//
Vector2::Vector2(double x0, double y0)
{
  x = x0;
  y = y0;
}

Vector2::Vector2(const Vector2 & v)
{
  x =  v.x;
  y =  v.y;
}

//
// Matrix::add() - 自身の行列と行列 u との和を求める
//
Matrix Matrix::add(Matrix u)
{
  Matrix ret;

  ret.val[0][0] = val[0][0] + u.val[0][0];
  ret.val[0][1] = val[0][1] + u.val[0][1];
  ret.val[1][0] = val[1][0] + u.val[1][0];
  ret.val[1][1] = val[1][1] + u.val[1][1];
	
	return ret;
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
// Matrix::sub() - 自身の行列と行列 u との差を求める
//
Matrix Matrix::sub(Matrix u)
{
  Matrix ret;
  
  ret.val[0][0] = val[0][0] - u.val[0][0];
  ret.val[0][1] = val[0][1] - u.val[0][1];
  ret.val[1][0] = val[1][0] - u.val[1][0];
  ret.val[1][1] = val[1][1] - u.val[1][1];
  
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
// Matrix::scan() - 行列の値を標準入力から自身に入力する
//
void Matrix::scan(void)
{
  scanf("%lf %lf %lf %lf", &val[0][0], &val[0][1], &val[1][0], &val[1][1]);
}

//
// Vector2::print() - 自身のベクトルの値を標準出力に出力する
//
void Vector2::print(void)
{
  printf("( %f %f )", x, y);
}

//
// Matrix::print() - 自身の行列の値を標準出力に出力する
//
void Matrix::print(void)
{
  printf("( %f %f \n %f %f )", val[0][0], val[0][1], val[1][0], val[1][1]);
}
