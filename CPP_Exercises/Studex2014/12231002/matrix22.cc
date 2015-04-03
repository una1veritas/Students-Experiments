//
// matrix22.cc - 2次正方行列型(C++版)
//	作者: 伊佐　真誠; 日付: 14/4/10
//
#include <stdio.h>
#include "matrix22.h"

//
// Matrix22::Matrix22() - x11, x12, x21, x22 を与えて(x11, x12|x21, x22) を得るコンストラクタ
//
Matrix22::Matrix22(double x11, double x12, double x21, double x22)
{
	x[0][0] = x11;
	x[0][1] = x12;
	x[1][0] = x21;
	x[1][1] = x22;
	printf("madeconst\n");
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
  double a[2][2];
  scanf("%lf %lf %lf %lf", &a[0][0], &a[0][1], &a[1][0], &a[1][1]);
  x[0][0] = a[0][0];
  x[0][1] = a[0][1];
  x[1][0] = a[1][0];
  x[1][1] = a[1][1];
  
}

//
// Matrix22::print() - 自身の行列の値を標準出力に出力する
//
void Matrix22::print(void)
{
  printf("( %lf %lf \n  %lf %lf )", x[0][0], x[0][1], x[1][0], x[1][1]);
}
