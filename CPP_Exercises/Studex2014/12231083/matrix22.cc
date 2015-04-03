//山本　晃也　4/15
#include<stdio.h>
#include "matrix22.h"
Matrix22 ::Matrix22 (double x0,double x1,double x2,double x3)
{ x[0][0] = x0; 
 x[0][1]  = x1;
 x[1][0]  = x2;
  x[1][1] = x3;
}
Matrix22  Matrix22::add(Matrix22 u)
{

Matrix22 ret;

  ret.x[0][0] = x[0][0] + u.x[0][0];
  ret.x[0][1] = x[0][1] + u.x[0][1];
  ret.x[1][0] = x[1][0] + u.x[1][0];
  ret.x[1][1] = x[1][1] + u.x[1][1];



	return ret;
}
Matrix22 Matrix22 ::sub( Matrix22 u)
{
 Matrix22 ret;

  ret.x[0][0] = x[0][0] - u.x[0][0];
  ret.x[0][1] = x[0][1] - u.x[0][1];
  ret.x[1][0] = x[1][0] - u.x[1][0];
  ret.x[1][1] = x[1][1] - u.x[1][1];  

  return ret;

}
Matrix22 Matrix22 ::mul( Matrix22 u)
{
Matrix22 ret;

  ret.x[0][0] = x[0][0]*u.x[0][0] + x[0][1]*u.x[1][0];
  ret.x[0][1] = x[0][0]*u.x[0][1] + x[0][1]*u.x[1][1];
  ret.x[1][0] = x[1][0]*u.x[0][0] + x[1][1]*u.x[1][0];
  ret.x[1][1] = x[1][0]*u.x[0][1] + x[1][1]*u.x[1][1];

  return ret;
}
void Matrix22 ::scan(void)
{
  scanf("%lf %lf %lf %lf", &x[0], &x[0][1],&x[1][0],&x[1][1]);
}

//
// Vector2::print() - 自身のベクトルの値を標準出力に出力する
//
void Matrix22 ::print(void)
{
   printf("        %2f %2f \n", x[0][0], x[0][1]);
  printf("        %2f %2f \n", x[1][0], x[1][1]);
}

#include <stdio.h>
#include "vector2p.h"

//
// Vector2::Vector2() - x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
//


Vector2::Vector2(double x0, double y0)
{
	x = x0;
	y = y0;
}
Vector2 ::Vector2(const Vector2 &v){
  Vector2 ret; 
  x = v.x;
  y = v.y;
  
  
}
  

Vector2 Vector2::add(Vector2 u)
{
	Vector2 ret;

	ret.x = x + u.x;
	ret.y = y + u.y;

	return ret;
}
Vector2 Vector2::sub(Vector2 u)
{
	Vector2 ret;

	ret.x = x - u.x;
	ret.y = y - u.y;

	return ret;
}
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
