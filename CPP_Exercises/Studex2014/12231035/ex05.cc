//
// ex05.cc - 2次正方行列型と2次元ベクトル型(C++版)
//	作者: 島内拓海; 日付:4/17
//
#include <stdio.h>
#include "ex05.h"
#include "ex03.h"

Vector2::Vector2()
{
  x=0; y=0;
  printf("x=%lf\n",x);
  printf("y=%lf\n",y);
}

//
// Vector2::Vector2() - x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
//
Vector2::Vector2(double x0, double y0)
{
	x = x0;
	y = y0;
	printf("x=%lf,y=%lf \n",x,y);
}

Vector2::Vector2(const Vector2 &v)
{
  x=v.x;  y=v.y;
  printf("x=%lf,y=%lf \n",x,y);
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
// Vector2::sub() - 自身のベクトルとベクトル u との差を求める
//
Vector2 Vector2::sub(Vector2 u)
{
	Vector2 ret;
	ret.x = x - u.x;
	ret.y = y - u.y;

	return ret;
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



row2::row2(double x0,double x1,double y0,double y1)
{
  x[0][0]=x0; x[0][1]=x1;
  x[1][0]=y0; x[1][1]=y1;
}



//
// row2::add() - 自身の行列と行列 u との和を求める
//
row2 row2::add(row2 u)
{
	row2 ret;

	ret.x[0][0] = x[0][0]+u.x[0][0];
	ret.x[0][1] = x[0][1]+u.x[0][1];
	ret.x[1][0] = x[1][0]+u.x[1][0];
	ret.x[1][1] = x[1][1]+u.x[1][1];

	return ret;
}

//
// row::sub() - 自身の行列と行列 u との差を求める
//
row2 row2::sub(row2 u)
{
	row2 ret;

	ret.x[0][0] = x[0][0]-u.x[0][0];
	ret.x[0][1] = x[0][1]-u.x[0][1];
	ret.x[1][0] = x[1][0]-u.x[1][0];
	ret.x[1][1] = x[1][1]-u.x[1][1];

	return ret;
}

//
// row::mul() - 自身の行列と行列 u との積を求める
//
row2 row2::mul(row2 u)
{
	row2 ret;

	ret.x[0][0] = x[0][0]*u.x[0][0] + x[0][1]*u.x[1][0];
	ret.x[0][1] = x[0][0]*u.x[0][1] + x[0][1]*u.x[1][1];
	ret.x[1][0] = x[1][0]*u.x[0][0] + x[1][1]*u.x[1][0];
	ret.x[1][1] = x[1][0]*u.x[0][1] + x[1][1]*u.x[1][1];

	return ret;
}



//
// row2::scan() - ベクトルの値を標準入力から自身に入力する
//
void row2::scan(void)
{
	scanf("%lf %lf", &x[0][0], &x[0][1]);
	scanf("%lf %lf", &x[1][0], &x[1][1]);

}

//
// row2::print() - 自身のベクトルの値を標準出力に出力する
//
void row2::print(void)
{
        printf("\n");
	printf("( %2.0f , %2.0f )", x[0][0], x[0][1]);
	printf("\n");
	printf("( %2.0f , %2.0f )", x[1][0], x[1][1]);
}
