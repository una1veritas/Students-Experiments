/*
 * vector2c.c - 2次元ベクトル型(C版)
 *	作者: (あなたの名前); 日付: (完成した日付)
 */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>    /* ERANGE を使用するために必要 */
#include <math.h>   /* HUGE_VAL を使用するために必要 */

#include "vector2c.h"

/*
 * initv2() - x0, y0 を与えて，定数 (x0, y0) を得る
 */
vector2 vector2init(double x, double y)
{
	vector2 me;
	me.x = x;
	me.y = y;
	return me;
}

/*
 * addv2() - ベクトル u と v の和 u + v を求める
 */
vector2 vector2add(vector2 u, vector2 v)
{
	vector2 ret;

	ret.x = u.x + v.x;
	ret.y = u.y + v.y;

	return ret;
}

/*
 * vector2scan() - ベクトルを文字列から作成する
 */
vector2 vector2scan(char * str)
{
	vector2 v;
	sscanf("(%lf,%lf)", str, &v.x, &v.y);
	return v;
}

/*
 *  vector2toString() - ベクトル u の値を文字列で出力する
 */
char * vector2toString(char * str, vector2 v)
{
	sprintf(str, "(%f, %f)", v.x, v.y);
	return str;
}
