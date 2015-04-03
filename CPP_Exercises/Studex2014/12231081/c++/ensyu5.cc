#include <stdio.h>
#include "ensyu5.h" 

Vector2::Vector2(double x0, double y0)
{
	x = x0;
	y = y0;
	printf("check!");
}

Vector2::Vector2(const Vector2 & v)
{
        x = v.x;
	y = v.y;
	printf("check!!");
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
Matrix22::Matrix22(double x0, double x1, double x2, double x3)
{
	x[0][0] = x0;
	x[0][1] = x1;
	x[1][0] = x2;
	x[1][1] = x3;
}

Matrix22::Matrix22(const Matrix22 & v)
{
        x[0][0] = v.x[0][0];
	x[0][1] = v.x[0][1];
	x[1][0] = v.x[1][0];
	x[1][1] = v.x[1][1];
}

//
//
Matrix22 Matrix22::add(Matrix22 z)
{
	Matrix22 ret;

	ret.x[0][0] = x[0][0] + z.x[0][0];
	ret.x[0][1] = x[0][1] + z.x[0][1];
	ret.x[1][0] = x[1][0] + z.x[1][0];
	ret.x[1][1] = x[1][1] + z.x[1][1];

	return ret;
}



//
//
Matrix22 Matrix22::mul(Matrix22 z)
{
	Matrix22 ret;

	ret.x[0][0] = x[0][0]*z.x[0][0] + x[0][1]*z.x[1][0];
	ret.x[0][1] = x[0][0]*z.x[0][1] + x[0][1]*z.x[1][1];
	ret.x[1][0] = x[1][0]*z.x[0][0] + x[1][1]*z.x[0][1];
	ret.x[1][1] = x[1][0]*z.x[0][1] + x[1][1]*z.x[1][1];

	return ret;
}



//
//
Matrix22 Matrix22::sub(Matrix22 z)
{
	Matrix22 ret;

	ret.x[0][0] = x[0][0] - z.x[0][0];
	ret.x[0][1] = x[0][1] - z.x[0][1];
	ret.x[1][0] = x[1][0] - z.x[1][0];
	ret.x[1][1] = x[1][1] - z.x[1][1];

	return ret;
}



//
// Vector2::scan() - ベクトルの値を標準入力から自身に入力する
//
void Matrix22::scan(void)
{
  scanf("%lf %lf %lf %lf", &x[0][0], &x[0][1], &x[1][0], &x[1][1]);
}

//
//
void Matrix22::print(void)
{
  printf(" %f %f %f %f ", x[0][0], x[0][1], x[1][0], x[1][1]);
}
