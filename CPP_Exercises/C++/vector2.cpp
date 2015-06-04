//
// vector2p.cc - 2次元ベクトル型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "vector2.h"

//
// Vector2::Vector2() - x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
//
Vector2::Vector2(const double x0, const double y0)
{
#ifdef MESSAGE_OUT
	printf("this is Vector2::Vector2(const double , const double): ");
#endif

	x = x0;
	y = y0;
}

Vector2::Vector2(const Vector2 & v) {
#ifdef MESSAGE_OUT
	printf("this is Vector2::Vector2(const Vector2 &): ");
#endif
	x = v.x;
	y = v.y;
}

//
// Vector2::add() - 自身のベクトルとベクトル u との和を求める
//
Vector2 Vector2::add(const Vector2 & u)
{
	Vector2 ret;

	ret.x = x + u.x;
	ret.y = y + u.y;

	return ret;
}

//
// Vector2::scan() - ベクトルの値を標準入力から自身に入力する
//
void Vector2::scan(void)
{
	scanf("%lf,%lf", &x, &y);
}

//
// Vector2::print() - 自身のベクトルの値を標準出力に出力する
//
void Vector2::print(void) const
{
	printf("( %f, %f )", x, y);
}
