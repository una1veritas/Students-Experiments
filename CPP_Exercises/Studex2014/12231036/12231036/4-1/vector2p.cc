//
// vector2p.cc - 2次元ベクトル型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "vector2p.h"

Vector2::Vector2()
{ 
	x=0;
	y=0;
	printf("デフォルトコンストラクタx=%f y=%f\n",x,y);
}
		
//
// Vector2::Vector2() - x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
//
Vector2::Vector2(double x0, double y0)
{
	x = x0;
	y = y0;
	printf("コンストラクタx=%f y=%f\n",x,y);
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
Vector2::Vector2(const Vector2 & v){
	x=v.x;
	y=v.y;
	printf("コピーコンストラクタ");
}
Matrix22::Matrix22()
{ 
	x[0][0]=0;
	x[0][1]=0;
	x[1][0]=0;
	x[1][1]=0;	
	
}
		

Matrix22::Matrix22(int x0, int y0 ,int x1, int y1)
{
	x[0][0]=x0;
	x[0][1]=y0;
	x[1][0]=x1;
	x[1][1]=y1;	
	
}

//
// Vector2::add() - 自身のベクトルとベクトル u との和を求める
//
Matrix22 Matrix22::addm(Matrix22 u)
{
	Matrix22 ret;

	ret.x[0][0]=x[0][0]+u.x[0][0];
	ret.x[0][1]=x[0][1]+u.x[0][1];
	ret.x[1][0]=x[1][0]+u.x[1][0];
	ret.x[1][1]=x[1][1]+u.x[1][1];

	return ret;
}
//
// Vector2::sub() - 自身のベクトルとベクトル u との差を求める
//
Matrix22 Matrix22::subm(Matrix22 u)
{
	Matrix22 ret;

	ret.x[0][0]=x[0][0]-u.x[0][0];
	ret.x[0][1]=x[0][1]-u.x[0][1];
	ret.x[1][0]=x[1][0]-u.x[1][0];
	ret.x[1][1]=x[1][1]-u.x[1][1];

	return ret;
}
Matrix22 Matrix22::mulm(Matrix22 u){
Matrix22 ret;

	ret.x[0][0]=x[0][0]*u.x[0][0]+x[0][1]*u.x[1][0];
	ret.x[1][0]=x[1][0]*u.x[0][0]+x[1][1]*u.x[1][0];
	ret.x[0][1]=x[0][0]*u.x[1][0]+x[0][1]*u.x[1][1];
	ret.x[1][1]=x[1][0]*u.x[1][0]+x[1][1]*u.x[1][1];

	return ret;
}
//
// Vector2::scan() - ベクトルの値を標準入力から自身に入力する
//
void Matrix22::scanm(void)
{
	scanf("%d %d %d %d", &x[0][0], &x[0][1], &x[1][0], &x[1][1]);
}

//
// Vector2::print() - 自身のベクトルの値を標準出力に出力する
//
void Matrix22::printm(void)
{
	printf("( %d %d )\n( %d %d )", x[0][0], x[0][1], x[1][0], x[1][1]);
}
Matrix22::Matrix22(const Matrix22 & v){
	x[0][0]=v.x[0][0];
	x[0][1]=v.x[0][1];
	x[1][0]=v.x[1][0];
	x[1][1]=v.x[1][1];

	
}
