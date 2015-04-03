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
	printf("constractor read\n");
}
Vector2::Vector2(const Vector2& u)
{
	x = u.x;
	y = u.y;
	printf("constractor read\n");
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
	printf("add\n");
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
	printf("sub\n");
}
//
// Vector2::in() - 自身のベクトルとベクトル u との内積を求める
//
double Vector2::in(Vector2 u)
{
	Vector2 ret;

	ret.x = x * u.x;
	ret.y = y * u.y;

	return ret.x + ret.y;
	printf("in\n");
}
//
// Vector2::out() - 自身のベクトルとベクトル u との外積を求める
//
double Vector2::out(Vector2 u)
{
	Vector2 ret;

	ret.x = x * u.y;
	ret.y = y * u.x;

	return ret.x - ret.y;
	printf("out\n");
}

//
// Vector2::scan() - ベクトルの値を標準入力から自身に入力する
//
void Vector2::scan(void)
{
	scanf("%lf %lf", &x, &y);
	printf("scan\n");
}

//
// Vector2::print() - 自身のベクトルの値を標準出力に出力する
//
void Vector2::print(void)
{
	printf("( %f %f )", x, y);
	printf("printf\n");
}
