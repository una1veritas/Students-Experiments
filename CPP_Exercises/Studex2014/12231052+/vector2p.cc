//
// vector2p.cc - 2次元ベクトル型(C++版)
// 作者: 長濱彰秀; 日付:4月２４日
//
#include <stdio.h>
#include "vector2p.h"
#include "matrix22.h"

//
// Vector2::Vector2() - x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
//
Vector2::Vector2(double x0, double y0) {
	x = x0;
	y = y0;
	printf("Vector2 Constructor ( %f %f )\n", x, y);
}

//
// Vector2::Vector2() - コピーコンストラクタ
//
Vector2::Vector2(const Vector2 &v) {
	x = v.x;
	y = v.y;
	printf("Copy Constructor ( %f %f )\n", x, y);
}

//
// Vector2::add() - 自身のベクトルとベクトル u との和を求める
//
Vector2 Vector2::add(Vector2 u) {
	Vector2 ret;

	ret.x = x + u.x;
	ret.y = y + u.y;

	return ret;
}

//
// Vector2::sub() - 自身のベクトルとベクトル u との差を求める
//
Vector2 Vector2::sub(Vector2 u) {
	Vector2 ret;

	ret.x = x - u.x;
	ret.y = y - u.y;

	return ret;
}
//
// Vector2::dot() - 自身のベクトルとベクトル u との内積を求める
//
double Vector2::dot(Vector2 u)
{
	double ret;

	ret = x * u.x + y * u.y;
	

	return ret;
}

//
// Vector2::cross() - 自身のベクトルとベクトル u との外積を求める
//
double Vector2::cross(Vector2 u)
{
	double ret;

	ret = x * u.y - y * u.x;

	return ret;
}

//
// Vector2::scan() - ベクトルの値を標準入力から自身に入力する
//
void Vector2::scan(void) {
	scanf("%lf %lf", &x, &y);
}

//
// Vector2::print() - 自身のベクトルの値を標準出力に出力する
//
void Vector2::print(void) {
	printf("( %f %f )", x, y);
}

//
// Matrix22::Matrix22() - x00, x01, x10, x11 を与えて2次正方行列を得るコンストラクタ
//
Matrix22::Matrix22(double x00, double x01, double x10, double x11) {
	x[0][0] = x00;
	x[0][1] = x01;
	x[1][0] = x10;
	x[1][1] = x11;
}

//
// Matrix22::Matrix22() - コピーコンストラクタ
//
Matrix22::Matrix22(const Matrix22 &y) {
	x[0][0] = y.x[0][0];
	x[0][1] = y.x[0][1];
	x[1][0] = y.x[1][0];
	x[1][1] = y.x[1][1];
}

//
// Matrix22::add() - 自身の行列と行列 y との和を求める
//
Matrix22 Matrix22::add(Matrix22 y) {
	Matrix22 ret;

	ret.x[0][0] = x[0][0] + y.x[0][0];
	ret.x[0][1] = x[0][1] + y.x[0][1];
	ret.x[1][0] = x[1][0] + y.x[1][0];
	ret.x[1][1] = x[1][1] + y.x[1][1];

	return ret;
}

//
// Matrix22::sub() - 自身の行列と行列 y との差を求める
//
Matrix22 Matrix22::sub(Matrix22 y) {
	Matrix22 ret;

	ret.x[0][0] = x[0][0] - y.x[0][0];
	ret.x[0][1] = x[0][1] - y.x[0][1];
	ret.x[1][0] = x[1][0] - y.x[1][0];
	ret.x[1][1] = x[1][1] - y.x[1][1];

	return ret;
}

//
// Matrix22::mul() - 自身の行列と行列 y との積を求める
//
Matrix22 Matrix22::mul(Matrix22 y) {
	Matrix22 ret;

	ret.x[0][0] = x[0][0] * y.x[0][0] + x[0][1] * y.x[1][0];
	ret.x[0][1] = x[0][0] * y.x[0][1] + x[0][1] * y.x[1][1];
	ret.x[1][0] = x[1][0] * y.x[0][0] + x[1][1] * y.x[1][0];
	ret.x[1][1] = x[1][0] * y.x[0][1] + x[1][1] * y.x[1][1];

	return ret;
}

//
// Matrix22::scan() - 行列の値を標準入力から自身に入力する
//
void Matrix22::scan(void) {
	scanf("%lf %lf %lf %lf", &x[0][0], &x[0][1], &x[1][0], &x[1][1]);
}

//
// Matrix22::print() - 自身の行列の値を標準出力に出力する
//
void Matrix22::print(void) {
	printf("| %f %f |\n| %f %f |\n", x[0][0], x[0][1], x[1][0], x[1][1]);
}

