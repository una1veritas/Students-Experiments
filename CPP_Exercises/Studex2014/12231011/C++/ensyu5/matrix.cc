
//
// vector2p.cc - 2次元ベクトル型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "matrix.h"
//
// Vector2::Vector2() - x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
//
Matrix::Matrix(double xx00, double xx01,double xx10 ,double xx11 )
{
	x00 = xx00;
	x01 = xx01;
	x11 = xx11;
	x10 = xx10;

}

//
// Vector2::add() - 自身のベクトルとベクトル u との和を求める
//
Matrix Matrix::add(Matrix u)
{
	Matrix ret;
ret.x00=x00+u.x00;
ret.x01=x01+u.x01;
ret.x10=x10+u.x10;
ret.x11=x11+u.x11;
	return ret;
}

//
// Vector2::add() - 自身のベクトルとベクトル u との和を求める
//
Matrix Matrix::sub(Matrix u)
{
	Matrix ret;
ret.x00=x00-u.x00;
ret.x01=x01-u.x01;
ret.x10=x10-u.x10;
ret.x11=x11-u.x11;
	return ret;
}
Matrix Matrix::mul(Matrix u){
  Matrix ret;
  ret.x00=x00*u.x00+x01*u.x10;
  ret.x01=x00*u.x01+x01*u.x11;
  ret.x10=x10*u.x00+x11*u.x10;
  ret.x11=x10*u.x01+x11*u.x11;
  return ret;
  }
//
// Vector2::scan() - ベクトルの値を標準入力から自身に入力する
//
void Matrix::scan(void)
{
	scanf("%lf %lf %lf %lf", &x00, &x01,&x10,&x11);
}

//
// Vector2::print() - 自身のベクトルの値を標準出力に出力する
//
void Matrix::print(void)
{
	printf("( %f %f \n%f %f)", x00, x01,x10,x11);
}
