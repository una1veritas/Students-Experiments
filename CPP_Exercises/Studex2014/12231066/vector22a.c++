/*
 * vector2c.c - 2次元ベクトル型(C版)
 *	作者: (あなたの名前); 日付: (完成した日付)
 */
#include <stdio.h>
#include "vector22a.h"


/*
 * constv2() - x0, y0 を与えて，定数 (x0, y0) を得る
 */
Vector22::Vector22(double x0,double x1, double y0, double y1)
{
        x[0][0] = x0; x[0][1] = x1;
        x[1][0] = y0; x[1][1] = y1;
}

/*
 * addv2() - ベクトル u と v の和 u + v を求める
 */
Vector22 Vector22::add(Vector22 u)
{
        Vector22 ret;

	ret.x[0][0] = u.x[0][0] + x[0][0]; 
	ret.x[0][1] = u.x[0][1] + x[0][1];
	ret.x[1][0] = u.x[1][0] + x[1][0];
	ret.x[1][1] = u.x[1][1] + x[1][1]; 

	return ret;
}

/*
 * addv2() - ベクトル u と v の和 u + v を求める
 */
Vector22 Vector22::sub(Vector22 u)
{
        Vector22 ret;
	ret.x[0][0] = x[0][0] - u.x[0][0]; 
	ret.x[0][1] = x[0][1] - u.x[0][1];
	ret.x[1][0] = x[1][0] - u.x[1][0];
	ret.x[1][1] = x[1][1] - u.x[1][1]; 
	
	return ret;
}
/*
 * scanv2() - ベクトルの値を標準入力から *pu に入力する
 */
void Vector22::scans(void)
{
  scanf("%lf %lf %lf %lf", &x[0][0], &x[0][1], &x[1][0], &x[1][1]);
}

/*
 * printv2() - ベクトル u の値を標準出力に出力する
 */
void Vector22::prints(void)
{
  printf(" %f %f \n %f %f", x[0][0], x[0][1], x[1][0], x[1][1]);
}

Vector22 Vector22::mul(Vector22 v)
{
        Vector22 ret;

	ret.x[0][0] = x[0][0] * v.x[0][0] + x[0][1] * v.x[1][0];
	ret.x[0][1] = x[0][0] * v.x[0][1] + x[0][1] * v.x[1][1];
	ret.x[1][0] = x[1][0] * v.x[0][0] + x[1][1] * v.x[1][0];
	ret.x[1][1] = x[1][0] * v.x[0][1] + x[1][1] * v.x[1][1];
	
	return ret;
}

//
// Vector2::Vector2() - x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
//
Vector2::Vector2(double x0, double y0)
{
	x = x0;
	y = y0;
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
// Vector2::inner_pro() - 自身のベクトルとベクトル u との内積を求める
//
double Vector2::inner_pro(Vector2 u)
{
	double ret;

	ret = x * u.x + y * u.y;

	return ret;
}

//
// Vector2::cross_pro() - 自身のベクトルとベクトル u との外積を求める
//
double Vector2::cross_pro(Vector2 u)
{
	double ret;

	ret = x * u.y - u.x * y;

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

