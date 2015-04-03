#include <stdio.h>
#include "mat.h"

//
// Mat2::Mat2() - x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
//
Mat2::Mat2(double x0, double y0,double x1,double y1)
{
 ret[0][0] = x0;
 ret[0][1] = y0;
 ret[1][0] = x1;
 ret[1][1] = y1;
printf("NG!!");
}

 Mat2 Mat2::add(Mat2 u)
{
	Mat2 a;

	a.ret[0][0] = ret[0][0] + u.ret[0][0];
	a.ret[0][1] = ret[0][1] + u.ret[0][1];
	a.ret[1][0] = ret[1][0] + u.ret[1][0];
	a.ret[1][1] = ret[1][1] + u.ret[1][1];

	return a;
}

//
// Mat2::scan() - ベクトルの値を標準入力から自身に入力する
//
void Mat2::scan(void)
{
  scanf("%lf %lf \n %lf %lf", &ret[0][0], &ret[0][1], &ret[1][0], &ret[1][1]);
}

//
// Mat2::print() - 自身のベクトルの値を標準出力に出力する
//
void Mat2::print(void)
{
  printf("( %f %f \n %f %f)", ret[0][0], ret[0][1], ret[1][0], ret[1][1]);
}
//
// Mat2::sub() - 自身のベクトルとベクトル u との差を求める
//
Mat2 Mat2::sub( Mat2 u)
{
	Mat2 a;

	a.ret[0][0] = ret[0][0] - u.ret[0][0];
	a.ret[0][1] = ret[0][1] - u.ret[0][1];
	a.ret[1][0] = ret[1][0] - u.ret[1][0];
	a.ret[1][1] = ret[1][1] - u.ret[1][1];

	return a;}
//
// Mat2::mul() - 自身のベクトルとベクトル u との積を求める
//
	Mat2 Mat2::mul(Mat2 u)
{
	Mat2 a;

	a.ret[0][0] = ret[0][0]*u.ret[0][0] + ret[0][1]*u.ret[1][0];
	a.ret[0][1] = ret[0][0]*u.ret[0][1] + ret[0][1]*u.ret[1][1];
	a.ret[1][0] = ret[1][0]*u.ret[0][0] + ret[1][1]*u.ret[1][0];
	a.ret[1][1] = ret[1][0]*u.ret[0][1] + ret[1][1]*u.ret[1][1];

	return a;
}
