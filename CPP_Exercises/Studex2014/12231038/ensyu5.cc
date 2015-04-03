//
// ensyu5.cc - 2次正方行列型2次正方行列(C++版)
//      作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "ensyu5.h"

//Vector2:コンストラクタ
Vector2::Vector2(void)
{
  x = 0;
  y = 0;

}

//
// Vector2::Vector2() - x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
//
Vector2::Vector2(double x0, double y0)
{
	x = x0;
	y = y0;

}

//Vector2:コピーコンストラクタ
Vector2::Vector2(const Vector2 & v)
{
  x = v.x;
  y = v.y;

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
	printf("( %f %f )\n", x, y);
}


Ensyu4::Ensyu4(void)
{
  x[0][0] = 0;
  x[0][1] = 0;
  x[1][0] = 0;
  x[1][1] = 0;

}

Ensyu4::Ensyu4(double x1, double x2, double x3, double x4)
{
  x1 = x[0][0];
  x2 = x[0][1];
  x3 = x[1][0];
  x4 = x[1][1];
  
}
Ensyu4::Ensyu4(const Ensyu4 & v)
{
  x[0][0] = v.x[0][0];
  x[0][1] = v.x[0][1];
  x[1][0] = v.x[1][0];
  x[1][1] = v.x[1][1];

}

//
// Ensyu4::add() - 自身の行列と行列 u との和を求める
//

Ensyu4 Ensyu4::add(Ensyu4 u)
{
  Ensyu4 ret;
  
  ret.x[0][0] = x[0][0] + u.x[0][0];
  ret.x[0][1] = x[0][1] + u.x[0][1];
  ret.x[1][0] = x[1][0] + u.x[1][0];
  ret.x[1][1] = x[1][1] + u.x[1][1];
  
  return ret;
}

//
// Ensyu4::sub() - 自身の行列と行列 u との差を求める
//
Ensyu4 Ensyu4::sub(Ensyu4 u)
{
  Ensyu4 ret;
  
  ret.x[0][0] = x[0][0] - u.x[0][0];
  ret.x[0][1] = x[0][1] - u.x[0][1];
  ret.x[1][0] = x[1][0] - u.x[1][0];
  ret.x[1][1] = x[1][1] - u.x[1][1];
  
  return ret;
}

//
// Ensyu4::scan() - 行列の値を標準入力から自身に入力する
//
void Ensyu4::scan(void)
{
  scanf("%lf %lf %lf %lf", &x[0][0], &x[0][1], &x[1][0], &x[1][1]);
}

//
// Ensyu4::print() - 自身の行列の値を標準出力に出力する
//
void Ensyu4::print(void)
{
  printf("\n| %f %f |\n", x[0][0], x[0][1]);
  printf("| %f %f |\n", x[1][0], x[1][1]);
}
