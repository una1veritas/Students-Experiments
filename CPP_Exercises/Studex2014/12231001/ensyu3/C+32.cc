#include <stdio.h>
#include "C+3ex2.h"

//
// Vector2::Vector2() - x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
//　作成者：朝比奈　涼；　作成日：2104 /4/24
//

Vector2::Vector2(void)
{
        x = 0;
	y = 0;
	//printf("デフォルトコンストラクタ ( %f %f)\n",x,y);

}

Vector2::Vector2(double x0, double y0)
{
	x = x0;
	y = y0;
	//printf("コンストラクタ ( %f %f)\n",x,y);
}

Vector2::Vector2(const Vector2 & v)
{
        x = v.x;
        y = v.y;
	printf("コピーコンストラクタ ( %f %f)\n",x,y);
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
// Vector2::nai() - 自身のベクトルとベクトル u との内積を求める
//
double Vector2::nai(Vector2 u)
{
	double ret;

	ret = (x * u.x) + (y * u.y);

	return ret;
}

//
// Vector2::gai() - 自身のベクトルとベクトル u との外積を求める
//
double Vector2::gai(Vector2 u)
{
	double ret;

	ret = (x * u.y) + (y * u.x);

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