//
// vec2ex1p.cc - 2次元ベクトル型(C++版)テストプログラム
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "vector22a.h"

//
// main() - テストプログラム
//
int main(void)
{
	Vector22 c, d;
	Vector2 a, b;
// a, b を入力
	printf("a = ? ");
	a.scan();
	printf("b = ? ");
	b.scan();
// c,d を入力
	printf("c = ? ");
	c.scans();
	c.prints();printf("\n");
	printf("d = ? ");
	d.scans();
	d.prints();printf("\n");
// a + b を出力
	printf("a + b = ");
	(a.add(b)).print();
	printf("\n");
// c + d を出力
	printf("c + d = \n");
	(c.add(d)).prints();
	printf("\n");
	printf("\n");
// a - b を出力
	printf("a - b = ");
	(a.sub(b)).print();
	printf("\n");
// c - d を出力
	printf("c - d = \n");
	(c.sub(d)).prints();
	printf("\n");
// a と b の内積を出力
	printf("aとbの内積:");
	printf("%lf\n",a.inner_pro(b));
// a と b の外積を出力
	printf("aとbの外積:");
	printf("%lf\n",a.cross_pro(b));
// c と d 積を出力
	printf("c * d =\n");
	(c.mul(d)).prints();
	printf("\n");


	return 0;

}

