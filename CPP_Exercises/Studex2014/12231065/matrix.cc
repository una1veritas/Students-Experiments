//
// matrix22.cc - 2次正方行列型
// 作者: 福田真実; 日付: 4/28
//
#include <stdio.h>
#include "matrix.h"

//
// Matrix::Matrix() - x00, x01, x10, x11 を与えて2次正方行列を得るコンストラクタ
//
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
