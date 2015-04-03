//
// vector2p.cc - 2次元ベクトル型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "vector3p.h"

//
// Vector2::Vector2() - x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
//
Vector2::Vector2(double x0, double y0)
{
	x = x0;
	y = y0;
}

double Vector2::getx()
{
	return x;
}

double Vector2::gety()
{
        return y;
}

void Vector2::setx(double dx)
{
	x=dx;
}

void Vector2::sety(double dy)
{
        y=dy;
}

//Vector2::Vector2(Vector2& v)
//{
//}
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
// Vector2::sub() 
//
Vector2 Vector2::sub(Vector2 u)
{
        Vector2 ret;

        ret.x = x - u.x;
        ret.y = y - u.y;

        return ret;
}
//
// Vector2::product()
//
double Vector2::product(Vector2 u)
{
	double ans;
        ans = x * u.x +  y * u.y;

        return ans;
}

//
// Vector2::gaiseki()
//
double Vector2::gaiseki(Vector2 u)
{
        double ans;

        ans = x*u.y - y*u.x; 

        return ans;
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

Matrix::Matrix(Vector2 m1, Vector2 m2)
{
	m[0] = m1;
	m[1]= m2;
}
	
Matrix Matrix::add(Matrix b)
{
	Matrix ret;
	for(int i=0; i<2; i++)	
		ret.m[i]= m[i].add(b.m[i]);

	return ret;
}

Matrix  Matrix::sub(Matrix b)
{
	Matrix ret;
	for(int i=0; i<2 ; i++)
           ret.m[i]= m[i].sub(b.m[i]);

        return ret;
}
Matrix Matrix::product(Matrix b)
{
	Matrix ret;
	ret.m[0].setx(m[0].getx()*b.m[0].getx() + m[0].gety()*b.m[1].getx());
	ret.m[0].sety(m[0].getx()*b.m[0].gety() + m[0].gety()*b.m[1].gety());
 	ret.m[1].setx(m[1].getx()*b.m[0].getx() + m[1].gety()*b.m[1].getx());
       ret.m[1].sety(m[1].getx()*b.m[0].gety() + m[1].gety()*b.m[1].gety());

	return ret;
}
void Matrix::scan(void)
{
	for(int i=0; i<2; i++)
		m[i].scan();
}
void Matrix::print(void)
{
	for(int i=0; i<2; i++)
	{
		m[i].print();
		printf("\n");
	}
}
