#include <stdio.h>
#include "C+5ex.h"

//
// Vector::Vector() - x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
//　作成者：朝比奈　涼；　作成日：2104 /4/24
//


Vector::Vector(void)
{
        x[0][0] = 0;
	x[0][1] = 0;
	x[1][0] = 0;
	x[1][1] = 0;

}

Vector::Vector(double y[2][2])
{
        x[0][0] = y[0][0];
	x[0][1] = y[0][1];
	x[1][0] = y[1][0];
	x[1][1] = y[1][1];

	//printf("コンストラクタ\n");
}

Vector::Vector(const Vector & y)
{
        x[0][0] = y.x[0][0];
	x[0][1] = y.x[0][1];
	x[1][0] = y.x[1][0];
	x[1][1] = y.x[1][1];
	//printf("コピー\n");
}

//
// Vector2::add() - 自身のベクトルとベクトル u との和を求める
//
Vector Vector::add(Vector u)
{
        Vector ret;

        ret.x[0][0] = x[0][0] + u.x[0][0];
	ret.x[0][1] = x[0][1] + u.x[0][1];
	ret.x[1][0] = x[1][0] + u.x[1][0];
	ret.x[1][1] = x[1][1] + u.x[1][1];	

	return ret;
}

//
// Vector2::sub() - 自身のベクトルとベクトル u との差を求める
//
Vector Vector::sub(Vector u)
{
	Vector ret;

        ret.x[0][0] = x[0][0] - u.x[0][0];
	ret.x[0][1] = x[0][1] - u.x[0][1];
	ret.x[1][0] = x[1][0] - u.x[1][0];
	ret.x[1][1] = x[1][1] - u.x[1][1];

	return ret;
}



//
// Vector2::scan() - ベクトルの値を標準入力から自身に入力する
//
void Vector::scan(void)
{
        scanf("%lf %lf %lf %lf", &x[0][0], &x[0][1] , &x[1][0] ,&x[1][1]);
}

//
// Vector2::print() - 自身のベクトルの値を標準出力に出力する
//
void Vector::print(void)
{
	printf(" %f %f \n",x[0][0], x[0][1] );
	printf(" %f %f   " ,x[1][0] ,x[1][1] );

}


