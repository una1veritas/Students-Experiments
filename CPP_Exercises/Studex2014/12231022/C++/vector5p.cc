//
// vector3p.cc - 2次元ベクトル型(C++版)
//	作者:工藤慎也; 日付: ４/１７
//
#include <stdio.h>
#include "vector5p.h"


//
//足し算
//

Vector2 Vector2::add(Vector2 u)
{
	Vector2 ret;

	ret.x = x + u.x;
	ret.y = y + u.y;

	return ret;
}

Matrix4 Matrix4::add(Matrix4 u)
{
	Matrix4 ret;

	ret.x[0][0] = x[0][0] + u.x[0][0];
        ret.x[0][1] = x[0][1] + u.x[0][1];
        ret.x[1][0] = x[1][0] + u.x[1][0];
        ret.x[1][1] = x[1][1] + u.x[1][1];

	return ret;
}

//
//引き算
//

Vector2 Vector2::sub(Vector2 u)
{
	Vector2 ret;

	ret.x = x - u.x;
	ret.y = y - u.y;

	return ret;
}

Matrix4 Matrix4::sub(Matrix4 u)
{
	Matrix4 ret;

	ret.x[0][0] = x[0][0] - u.x[0][0];
        ret.x[0][1] = x[0][1] - u.x[0][1];
        ret.x[1][0] = x[1][0] - u.x[1][0];
        ret.x[1][1] = x[1][1] - u.x[1][1];

	return ret;
}

//
//乗算（内積）
//
Matrix4 Matrix4::mul(Matrix4 u)
{
	Matrix4 a;
	
 	a.x[0][0] = x[0][0] * u.x[0][0] + x[0][1] * u.x[1][0];
        a.x[0][1] = x[0][0] * u.x[0][1] + x[0][1] * u.x[1][1];
        a.x[1][0] = x[1][0] * u.x[0][0] + x[1][1] * u.x[1][0];
        a.x[1][1] = x[1][0] * u.x[0][1] + x[1][1] * u.x[1][1];

	return a;
}

double Vector2::inp(Vector2 u)
{
	double a;
	
	a = x*u.x + y*u.y;

	return a;
}

//
//外積（ベクトルのみ）
//

double Vector2::oup(Vector2 u)
{
	double b;
	
	b = x*u.y - y*u.x;

	return b;
}

//
// 入力
//
void Matrix4::scan(void)
{
	scanf("%lf %lf %lf %lf", &x[0][0], &x[0][1], &x[1][0], &x[1][1]);
}

void Vector2::scan(void)
{
	scanf("%lf %lf", &x, &y);
}
//
// Vector2::print() - 自身のベクトルの値を標準出力に出力する
//
void Matrix4::print(void)
{
	printf(" %f %f \n %f %f ", x[0][0], x[0][1], x[1][0], x[1][1]);
}

void Vector2::print(void)
{
	printf("( %f %f )", x, y);
}
