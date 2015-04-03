//
// ensyu5.cc - 2次元正方行列型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "ensyu5.h"

//
// Matrix2::Matrix2() - デフォルトコンストラクタ
//
Matrix2::Matrix2()
{
      x1y1 = 0;
      x1y2 = 0;
      x2y1 = 0;
      x2y2 = 0;
}


//
// Matrix2::Matrix2() - x1y1, x1y2, x2y1, x2y2 を与えて二次元正方行列を得るコンストラクタ
//
Matrix2::Matrix2(double xa, double xb, double ya, double yb)
{
      x1y1 = xa;
      x1y2 = xb;
      x2y1 = ya;
      x2y2 = yb;
}

//
// Matrix2::Matrix2() - 自身の行列と行列 u との和を求める
//
Matrix2 Matrix2::add(Matrix2 u)
{
      Matrix2 ret;

      ret.x1y1 = x1y1 + u.x1y1;
      ret.x1y2 = x1y2 + u.x1y2;
      ret.x2y1 = x2y1 + u.x2y1;
      ret.x2y2 = x2y2 + u.x2y2;

      return ret;
}

//
// Matrix2::Matrix2() - 自身の行列と行列 u との差を求める
//
Matrix2 Matrix2::sub(Matrix2 u)
{
      Matrix2 ret;

      ret.x1y1 = x1y1 - u.x1y1;
      ret.x1y2 = x1y2 - u.x1y2;
      ret.x2y1 = x2y1 - u.x2y1;
      ret.x2y2 = x2y2 - u.x2y2;

      return ret;
}

//
// Matrix2::Matrix2() - 自身の行列と行列 u との積を求める
//
Matrix2 Matrix2::mul(Matrix2 u)
{
      Matrix2 ret;

      ret.x1y1 = x1y1 * u.x1y1 + x1y2 * u.x2y1;
      ret.x1y2 = x1y1 * u.x1y2 + x1y2 * u.x2y2;
      ret.x2y1 = x2y1 * u.x1y1 + x2y2 * u.x2y1;
      ret.x2y2 = x2y1 * u.x1y2 + x2y2 * u.x2y2;

      return ret;
}

// Matrix2::scan() - 行列の値を標準入力から自身に入力する
//
void Matrix2::scan(void)
{
	scanf("%lf %lf", &x1y1, &x1y2);
	//	printf("\n");
	scanf("%lf %lf", &x2y1, &x2y2);
}

//
// Matrix2::print() - 自身の行列の値を標準出力に出力する
//
void Matrix2::print(void)
{
	printf("( %f %f )\n", x1y1, x1y2);
	printf("( %f %f )\n", x2y1, x2y2);
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
// Vector2::Vector2() - vベクトルと同じxy成分で初期化するコピーコンストラクタ
//
Vector2::Vector2(const Vector2 & v)
{
        printf("copy\n");
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
	printf("( %f %f )", x, y);
}
