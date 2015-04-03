// vector2p.cc - 2次元ベクトル型(C++版)
//	作者: (市川　舞); 日付: (2014/04/17)
#include <stdio.h>
#include "vector2p.h"

// Vector2::Vector2() - x0,y0を与えて定数(x0, y0)を得るコンストラクタ
Vector2::Vector2(double x0, double y0)
{
	x = x0;
	y = y0;
}

// Vector2::Vector2() - コピーコンストラクタ
Vector2::Vector2(const Vector2 & v)
{
	x = v.x;
	y = v.y;
}

// Vector2::add() - 自身のベクトルとベクトルuとの和を求める
Vector2 Vector2::add(Vector2 u)
{
	Vector2 ret;

	ret.x = x + u.x;
	ret.y = y + u.y;

	return ret;
}

// Vector2::sub() - 自身のベクトルとベクトルuとの差を求める
Vector2 Vector2::sub(Vector2 u)
{
	Vector2 ret;

	ret.x = x - u.x;
	ret.y = y - u.y;

	return ret;
}

// Vector2::scan() - ベクトルの値を標準入力から自身に入力する
void Vector2::scan(void)
{
	scanf("%lf %lf", &x, &y);
}

// Vector2::print() - 自身のベクトルの値を標準出力に出力する
void Vector2::print(void)
{
	printf("( %f %f )", x, y);
}
