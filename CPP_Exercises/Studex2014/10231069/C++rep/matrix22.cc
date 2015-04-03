//
// matrix22.cc - 2次元正方行列型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "matrix22.h"

//
// Matrix22::Matrix22() - x00,x01,x10,x11 を与えて定数  を得るコンストラクタ
//
Matrix22::Matrix22(double x00, double x01, double x10, double x11)
{
	x[0][0] = x00;
	x[0][1] = x01;
	x[1][0] = x10;
	x[1][1] = x11;

}

//
// Matrix22::add() - 自身の行列と行列 u との和を求める
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

//
// Matrix22::sub() - 自身の行列と行列 u との差を求める
//
Matrix22 Matrix22::sub(Matrix22 u)
{
	Matrix22 ret;

	ret.x[0][0] = x[0][0] - u.x[0][0];
	ret.x[0][1] = x[0][1] - u.x[0][1];
	ret.x[1][0] = x[1][0] - u.x[1][0];
	ret.x[1][1] = x[1][1] - u.x[1][1];

	return ret;
}

//
// Matrix22::mul() - 自身の行列と行列 u との積を求める
//
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
// Matrix22::scan() - 行列の値を標準入力から自身に入力する
//
void Matrix22::scan(void)
{
	scanf("%lf %lf %lf %lf", &x[0][0], &x[0][1], &x[1][0], &x[1][1]);
}
