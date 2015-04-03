// Matrix2p.cc - 2次正方行列型
//	作者: (市川　舞); 日付: (2014/04/17)
#include <stdio.h>
#include "matrix2p.h"

// Matrix2::Matrix2() - x0,x1,x2,x3を与えて行列Xを得るコンストラクタ
Matrix2::Matrix2(double x0, double x1, double x2, double x3)
{
  val[0][0] = x0;
  val[0][1] = x1;
  val[1][0] = x2;
  val[1][1] = x3;
}

// Matrix2::Matrix2() - コピーコンストラクタ
Matrix2::Matrix2(const Matrix2 & v)
{
  val[0][0] = v.val[0][0];
  val[0][1] = v.val[0][1];
  val[1][0] = v.val[1][0];
  val[1][1] = v.val[1][1];

}

// Matrix2::add() - 自身の行列と行列uとの和を求める
Matrix2 Matrix2::add(Matrix2 u)
{
	Matrix2 ret;
	
	ret.val[0][0] = val[0][0] + u.val[0][0];
	ret.val[0][1] = val[0][1] + u.val[0][1];
	ret.val[1][0] = val[1][0] + u.val[1][0];
	ret.val[1][1] = val[1][1] + u.val[1][1];

	return ret;
}

// Matrix2::sub() - 自身の行列と行列uとの差を求める
Matrix2 Matrix2::sub(Matrix2 u)
{
	Matrix2 ret;

	ret.val[0][0] = val[0][0] - u.val[0][0];
	ret.val[0][1] = val[0][1] - u.val[0][1];
	ret.val[1][0] = val[1][0] - u.val[1][0];
	ret.val[1][1] = val[1][1] - u.val[1][1];


	return ret;
}

// Matrix2::mul() - 自身の行列と行列uとの積を求める
Matrix2 Matrix2::mul(Matrix2 u)
{
	Matrix2 ret;

	ret.val[0][0] = val[0][0]*u.val[0][0] + val[0][1]*u.val[1][0];
	ret.val[0][1] = val[0][0]*u.val[0][1] + val[0][1]*u.val[1][1];
	ret.val[1][0] = val[1][0]*u.val[0][0] + val[1][1]*u.val[1][0];
	ret.val[1][1] = val[1][0]*u.val[0][1] + val[1][1]*u.val[1][1];

	return ret;
}

// Matrix2::scan() - ベクトルの値を標準入力から自身に入力する
void Matrix2::scan(void)
{
  scanf("%lf %lf %lf %lf", &val[0][0], &val[0][1], &val[1][0], &val[1][1]);
}

// Matrix2::print() - 自身のベクトルの値を標準出力に出力する
void Matrix2::print(void)
{
  printf("%f %f \n%f %f", val[0][0],val[0][1],val[1][0],val[1][1]);
}
