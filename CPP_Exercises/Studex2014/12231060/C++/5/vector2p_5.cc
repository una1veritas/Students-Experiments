//
// vector2p.cc - 2次元ベクトル型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "vector2p.h"

//
// Vector2::Vector2() - x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
//
Mtrix::Mtrix(double x1_0, double y1_0, double x2_0, double y2_0)
{
  x1 = x1_0; x2 = x2_0;
  y1 = y1_0; y2 = y2_0;
}

//
// Vector2::add() - 自身のベクトルとベクトル u との和を求める
//
Mtrix Mtrix::add(Mtrix u)
{
	Mtrix ret;

	ret.x1 = x1 + u.x1;
	ret.y1 = y1 + u.y1;
	ret.x2 = x2 + u.x2;
	ret.y2 = y2 + u.y2;

	return ret;
}
Mtrix Mtrix:: sub(Mtrix u)
{
  Mtrix ret;


  ret.x1 = x1 - u.x1;
  ret.y1 = y1 - u.y1;
  ret.x2 = x2 - u.x2;
  ret.y2 = y2 - u.y2;

  return ret; 

}
Mtrix Mtrix:: mul(Mtrix u)
{
  Mtrix ret;
  
  ret.x1 = x1 * u.x1 + y1 * u.x2;
  ret.y1 = x2 * u.x1 + y2 * u.x2;
  ret.x2 = x1 * u.y1 + y1 * u.y2;
  ret.y2 = x2 * u.y1 + y2 * u.y2;

  return ret;

}
//
// Vector2::scan() - ベクトルの値を標準入力から自身に入力する
//
void Mtrix::scan(void)
{
  scanf(" %lf %lf %lf %lf", &x1, &y1, &x2, &y2);
}

//
// Vector2::print() - 自身のベクトルの値を標準出力に出力する
//
void Mtrix::print(void)
{
  printf("%f %f\n%f %f", x1, y1, x2, y2);
}

Vector2::Vector2(double x0, double y0)
{
	x = x0;
	y = y0;
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
Vector2 Vector2:: sub(Vector2 u)
{
  Vector2 ret;

  ret.x = x - u.x;
  ret.y = y - u.y;

  return ret; 

}
double Vector2:: cross_product(Vector2 u)
{
 
  
  return x * u.y - y * u.x;
}
double Vector2:: inner_product(Vector2 u)
{
 
  
  return x * u.x + y * u.y;
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
