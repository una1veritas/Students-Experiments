//
// vector2p.cc - 2次元ベクトル型(C++版)
//	作者: Yuya Uekama(あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "vector2p5.h"

//
// Vector2::Vector2() - x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
//
Vector2::Vector2(double x0, double y0)
{
	x = x0;
	y = y0;
	printf("コンストラクタ\n( %f %f )", x, y);
}

Vector2::Vector2()
{
	x = 0;
	y = 0;
	printf("デフォルトコンストラクタ\n( %f %f )\n", x, y);
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

Vector2 Vector2::sub(Vector2 u)
{
	Vector2 ret;

	ret.x = x - u.x;
	ret.y = y - u.y;
	return ret;
}

Vector2 Vector2::mul(Vector2 u)
{
	Vector2 ret;

	ret.x = x * u.x + x * u.y;
	ret.y = y * u.x + y * u.y;

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
	printf("( %f %f )\n", x , y);
}



//
Matrix22::Matrix22(double x0[2][2])
{
	x[0][0] = x0[0][0];
	x[0][1] = x0[0][1];
	x[1][0] = x0[1][0];
	x[1][1] = x0[1][1];
	printf("コンストラクタ\n( %f %f )\n( %f %f )\n", x[0][0], x[0][1], x[1][0], x[1][1]);
}

Matrix22::Matrix22()
{
	x[0][0] = 0;
	x[0][1] = 0;
	x[1][0] = 0;
	x[1][1] = 0;
	printf("デフォルトコンストラクタ\n( %f %f )\n( %f %f )\n", x[0][0], x[0][1], x[1][0], x[1][1]);
}


//
// Vector2::add() - 自身のベクトルとベクトル u との和を求める
//
Matrix22 Matrix22::add(Matrix22 u)
{
	Matrix22 ret;

	ret.x[0][0] = x[0][0] + u.x[0][0];
	ret.x[0][1] = x[0][1] + u.x[0][1];
	ret.x[1][0] = x[1][0] + u.x[1][0];
	ret.x[1][1] = x[1][1] + u.x[1][1];
	

	return ret;
}

Matrix22 Matrix22::sub(Matrix22 u)
{
	Matrix22 ret;

	ret.x[0][0] = x[0][0] - u.x[0][0];
	ret.x[0][1] = x[0][1] - u.x[0][1];
	ret.x[1][0] = x[1][0] - u.x[1][0];
	ret.x[1][1] = x[1][1] - u.x[1][1];

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
// Vector2::scan() - ベクトルの値を標準入力から自身に入力する
//
void Matrix22::scan(void)
{
	scanf("%lf %lf %lf %lf", &x[0][0], &x[0][1], &x[1][0], &x[1][1]);
}

//
// Vector2::print() - 自身のベクトルの値を標準出力に出力する
//
void Matrix22::print(void)
{
	printf("( %f %f )\n( %f %f )\n", x[0][0], x[0][1], x[1][0], x[1][1]);
}

