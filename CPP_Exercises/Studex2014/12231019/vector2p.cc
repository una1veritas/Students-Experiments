//
// vector2p.cc - 2次元ベクトル型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "vector2p.h"

//
// Vector2::Vector2() - x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
//
Vector2::Vector2(double x0, double y0)
{
	x = x0;
	y = y0;
	printf("\nx0,y0\n");
}

Vector2::Vector2(const Vector2& u)
{
  	x = u.x;
  	y = u.y;
 	 printf("\nconst\n");
}

//
// Vector2::add() - 自身のベクトルとベクトル u との和を求める
//
Vector2 Vector2::add(Vector2 u)
{
	Vector2 ret;

	ret.x = x + u.x;
	ret.y = y + u.y;
	printf("\nadd\n");

	return ret;
}

Vector2 Vector2::sub(Vector2 u)
{
	Vector2 ret;

	ret.x = x - u.x;
	ret.y = y - u.y;

	return ret;
	printf("\nsub\n");
}

double Vector2::nai(Vector2 u)
{
	Vector2 ret;

	ret.x= x * u.x;
	ret.y= y * u.y;
	printf("\nnai\n");

	return ret.x+ret.y;
}

double Vector2::gai(Vector2 u)
{
	Vector2 ret;

	ret.x= x * u.y;
	ret.y= y * u.x;
	printf("\ngai\n");

	return ret.x-ret.y;
}
//
// Vector2::scan() - ベクトルの値を標準入力から自身に入力する
//
void Vector2::scan(void)
{
	scanf("%lf %lf", &x, &y);
	printf("\nscan\n");
}

//
// Vector2::print() - 自身のベクトルの値を標準出力に出力する
//
void Vector2::print(void)
{
	printf("( %f %f )", x, y);
	printf("\nprintf\n");
}
