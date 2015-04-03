//
// vector2p.cc - 2次元ベクトル型(C++版)
//	作者: 福田真実; 日付: 4/28
//
#include <stdio.h>
#include "vector2p.h"
#include "matrix.h"

//
// Vector2::Vector2() - x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
//
Vector2::Vector2(double x0, double y0)
{
	x = x0;
	y = y0;
	printf("コンストラクタ ( %f %f )\n", x, y);
}

//
// Vector2::Vector2() - コピーコンストラクタ
//
Vector2::Vector2(const Vector2 &v) {
	x = v.x;
	y = v.y;
	printf("コピーコンストラクタ ( %f %f )\n", x, y);
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
double Vector2::in(Vector2 u)
{
	Vector2 ret;

	ret.x = x * u.x;
	ret.y = y * u.y;
	printf("in\n");

	return ret.x+ret.y;
}
double Vector2::out(Vector2 u)
{
	Vector2 ret;

	ret.x = x * u.y;
	ret.y = y * u.x;
	printf("out\n");

	return ret.x-ret.y;
}
// Vector2::scan() - ベクトルの値を標準入力から自身に入力する
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
Matrix::Matrix(double x00, double x01, double x10, double x11) {
	x[0][0] = x00;
	x[0][1] = x01;
	x[1][0] = x10;
	x[1][1] = x11;
}

//
// Matrix::Matrix() - コピーコンストラクタ
//
Matrix::Matrix(const Matrix &y) {
	x[0][0] = y.x[0][0];
	x[0][1] = y.x[0][1];
	x[1][0] = y.x[1][0];
	x[1][1] = y.x[1][1];
}

//
// Matrix::add() - 自身の行列と行列 y との和を求める
//
Matrix Matrix::add(Matrix y) {
	Matrix ret;

	ret.x[0][0] = x[0][0] + y.x[0][0];
	ret.x[0][1] = x[0][1] + y.x[0][1];
	ret.x[1][0] = x[1][0] + y.x[1][0];
	ret.x[1][1] = x[1][1] + y.x[1][1];

	return ret;
}

//
// Matrix::sub() - 自身の行列と行列 y との差を求める
//
Matrix Matrix::sub(Matrix y) {
	Matrix ret;

	ret.x[0][0] = x[0][0] - y.x[0][0];
	ret.x[0][1] = x[0][1] - y.x[0][1];
	ret.x[1][0] = x[1][0] - y.x[1][0];
	ret.x[1][1] = x[1][1] - y.x[1][1];

	return ret;
}

//
// Matrix::mul() - 自身の行列と行列 y との積を求める
//
Matrix Matrix::mul(Matrix y) {
	Matrix ret;

	ret.x[0][0] = x[0][0] * y.x[0][0] + x[0][1] * y.x[1][0];
	ret.x[0][1] = x[0][0] * y.x[0][1] + x[0][1] * y.x[1][1];
	ret.x[1][0] = x[1][0] * y.x[0][0] + x[1][1] * y.x[1][0];
	ret.x[1][1] = x[1][0] * y.x[0][1] + x[1][1] * y.x[1][1];

	return ret;
}

//
// Matrix::scan() - 行列の値を標準入力から自身に入力する
//
void Matrix::scan(void) {
	scanf("%lf %lf %lf %lf", &x[0][0], &x[0][1], &x[1][0], &x[1][1]);
}

//
// Matrix::print() - 自身の行列の値を標準出力に出力する
//
void Matrix::print(void) {
	printf("| %f %f |\n| %f %f |\n", x[0][0], x[0][1], x[1][0], x[1][1]);
}
