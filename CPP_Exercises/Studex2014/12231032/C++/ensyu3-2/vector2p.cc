//
// vector2p.cc - 2次元ベクトル型(C++版)
//	作者: 核雅瑛(あなたの名前); 日付:2014/4/10 (完成した日付)
//
#include <stdio.h>
#include "vector2p.h"


//
//Vector2::Vector2(double x,double y)引数ありのコンストラクタ
//

Vector2::Vector2(double x0,double y0){
        x = x0;
	y = y0;
	printf("引数ありのコンストラクタ\n");
}

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
