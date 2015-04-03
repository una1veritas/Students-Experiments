//
// ensyu4.cc - 2次正方行列型(C++版)
//      作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "ensyu4.h"

//
// Ensyu4::Ensyu4() - x1, x2, x3, x4 を与えて定数を得るコンストラクタ
//
Ensyu4::Ensyu4(double x1, double x2, double x3, double x4)
{
        x[0][0] = x1;
	x[0][1] = x2;
	x[1][0] = x3;
	x[1][1] = x4;
}

//
// Ensyu4::add() - 自身のベクトルとベクトル u との和を求める
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
// Ensyu4::scan() - ベクトルの値を標準入力から自身に入力する
//
void Ensyu4::scan(void)
{
        scanf("%lf %lf", &x[0][0], &x[0][1]);
        scanf("%lf %lf", &x[1][0], &x[1][1]);
}

//
// Ensyu4::print() - 自身のベクトルの値を標準出力に出力する
//
void Ensyu4::print(void)
{
        printf("( %2.0f %2.0f )", x[0][0], x[0][1]);
	printf("\n"); printf("\t");
        printf("( %2.0f %2.0f )", x[1][0], x[1][1]);
}

//
// Ensyu4::sub() - 自身のベクトルとベクトル u との差を求める
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
// Ensyu4::mul() - 自身のベクトルとベクトル u との積を求める
//
Ensyu4 Ensyu4::mul(Ensyu4 u)
{
        Ensyu4 ret;

        ret.x[0][0] = x[0][0] * u.x[0][0] + x[0][1] * u.x[1][0];
        ret.x[0][1] = x[0][0] * u.x[0][1] + x[0][1] * u.x[1][1];
        ret.x[1][0] = x[1][0] * u.x[0][0] + x[1][1] * u.x[1][0];
        ret.x[1][1] = x[1][0] * u.x[0][1] + x[1][1] * u.x[1][1];

        return ret;
}
