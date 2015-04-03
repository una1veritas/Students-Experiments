//
// mat2p.cc - 2次行列型(C++版)
//	作者:佐藤彰哉; 日付:4/10
//
#include <stdio.h>
#include "mat2p.h"

//
// Mat2::Mat2() - x0, y0 ,z0, w0を与えて定数 (x0, y0, z0, w0) を得るコンストラクタ
//
Mat2::Mat2(double x0, double y0, double z0,double w0)
{
	x = x0;
	y = y0;
	z = z0;
	w = w0;
	printf("Mat2\n x=%f y=%f z=%f w=%f\n",x,y,z,w);
}
Mat2::Mat2(){
  x = 0;
  y = 0;
  z = 0;
  w = 0;
  printf("デフォ\n x=%f y=%f z=%f w=%f\n",x,y,z,w);
}

Mat2::Mat2(const Mat2 & v){
  x = v.x;
  y = v.y;
  z = v.z;
  w = v.w; 
  printf("copy\n x=%f y=%f z=%f w=%f\n",x,y,z,w);
}
//
// Mat2::add() - 自身の行列と行列u との和を求める
//
Mat2 Mat2::add(Mat2 u)
{
	Mat2 ret;

	ret.x = x + u.x;
	ret.y = y + u.y;
	ret.z = z + u.z;
	ret.w = w + u.w;

	return ret;
}
//
// Mat2::sub() - 自身のベクトルとベクトル u との差を求める
//
Mat2 Mat2::sub(Mat2 u)
{
	Mat2 ret;

	ret.x = x - u.x;
	ret.y = y - u.y;
	ret.z = z - u.z;
	ret.w = w - u.w;

	return ret;
}

//
// Mat2::mul() - 自身のベクトルとベクトル u との積を求める
//
Mat2 Mat2::mul(Mat2 u)
{
	Mat2 ret;

	ret.x = x * u.x + y * u.z;
	ret.y = x * u.y + y * u.w;
	ret.z = z * u.x + w * u.z;
	ret.w = w * u.w + z * u.y;

	return ret;
}
//
// Mat2::scan() - 行列の値を標準入力から自身に入力する
//
void Mat2::scan(void)
{
  scanf("%lf %lf %lf %lf", &x, &y,&z,&w);
}

//
// Mat2::print() - 自身の行列の値を標準出力に出力する
//
void Mat2::print(void)
{
  printf("( %f %f %f %f)", x, y, z, w);
}
