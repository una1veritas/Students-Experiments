//
// vector2p.cc - 2次元ベクトル型(C++版)
//	作者: 道下　真人; 日付: 2014/04/10
//
#include <stdio.h>
#include "vector2p.h"

//
// Vector2::Vector2() - x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
//
Vector2::Vector2(double x0, double y0)
{
	printf("呼出\n");
	x = x0;
	y = y0;
}

//
//Vector2::Vector2() - コピーコンストラクタ
//
Vector2::Vector2(Vector2 & v)
{
	printf("コピーコンストラクタ\n"); x = v.x;y =v.y;
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

//
//Vector2::sub() - 自身のベクトルとベクトル u との差を求める
//
Vector2 Vector2::sub(Vector2 u)
{
        Vector2 ret;
  
        ret.x = x - u.x;
        ret.y = y - u.y;

        return ret;
}
//
// Vector2::naiseki() - 自身のベクトルとベクトル u との内積を求める
//
double::Vector2::naiseki(Vector2 u)
{
        

       return x*u.x + y*u.y;

}
//
//Vector2::gaiseki() - 自身のベクトルとベクトル u との外積を求める
//
double::Vector2::gaiseki(Vector2 u)
{
 
  
  return x*u.y - u.x*y;

}
//
// Vector2::scan() - ベクトルの値を標準入力から自身に入力する
//
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

//
// Matrix22::Matrix22() - x0, x1, x2, x3 を与えて
// 定数 (x0, x1, x2, x3) を得るコンストラクタ
//
Matrix22::Matrix22(double x0, double x1, double x2, double x3)
{
	x[0][0]=x0;
	x[0][1]=x1;
	x[1][0]=x2;
	x[1][1]=x3;
}
//
//Matrix22::Matrix22() - コピーコンストラクタ
//
Matrix22::Matrix22(Matrix22 & v){
	x[0][0]=v.x[0][0];
	x[0][1]=v.x[0][1];
	x[1][0]=v.x[1][0];
	x[1][1]=v.x[1][1];
}
//
// Matrix22::add() - 自身の行列と行列 u との和を求める
//
Matrix22 Matrix22::add(Matrix22 u)
{
	Matrix22 ret;
	ret.x[0][0]=x[0][0]+u.x[0][0];
	ret.x[0][1]=x[0][1]+u.x[0][1];
	ret.x[1][0]=x[1][0]+u.x[1][0];
	ret.x[1][1]=x[1][1]+u.x[1][1];

	return ret;
}

//
// Matrix22::sub() - 自身の行列と行列 u との差を求める
//
Matrix22 Matrix22::sub(Matrix22 u)
{
	Matrix22 ret;
	ret.x[0][0]=x[0][0]-u.x[0][0];
	ret.x[0][1]=x[0][1]-u.x[0][1];
	ret.x[1][0]=x[1][0]-u.x[1][0];
	ret.x[1][1]=x[1][1]-u.x[1][1];

	return ret;
}

//
// Matrix22::mul() - 自身の行列と行列 u との積を求める
//
Matrix22 Matrix22::mul(Matrix22 u)
{
	Matrix22 ret;
	ret.x[0][0]=x[0][0]*u.x[0][0]+x[0][1]*u.x[1][0];
	ret.x[0][1]=x[0][0]*u.x[0][1]+x[0][1]*u.x[1][1];
	ret.x[1][0]=x[1][0]*u.x[0][0]+x[1][1]*u.x[1][0];
	ret.x[1][1]=x[1][0]*u.x[0][1]+x[1][1]*u.x[1][1];

	return ret;
}

//
// Matrix22::scan() - 行列の値を標準入力から自身に入力する
//
void Matrix22::scan(void)
{
	scanf("%lf %lf %lf %lf", &x[0][0], &x[0][1], &x[1][0], &x[1][1]);
}

//
// Matrix22::print() - 自身の行列の値を標準出力に出力する
//
void Matrix22::print(void)
{
	printf("( %f %f %f %f )", x[0][0], x[0][1], x[1][0], x[1][1]);
}
