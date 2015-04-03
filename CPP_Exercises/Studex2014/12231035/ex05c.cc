//
// ex05c.cc - 2次正方行列型と2次元ベクトル型(C++版)テストプログラム
//	作者: 島内拓海; 日付: 4/17
//
#include <stdio.h>
#include "ex05.h"
#include "ex03.h"

//
// main() - テストプログラム
//
int main(void)
{
        Vector2 a,b;
	row2 c, d;

// a, b を入力
	printf("(ベクトル)a = ? ");
	a.scan();
	printf("(ベクトル)b = ? ");
	b.scan();

// a + b を出力
	printf("a + b = ");
	(a.add(b)).print();
	printf("\n");
// a - b を出力
	printf("a - b = ");
	(a.sub(b)).print();
	printf("\n");

// a + (2, 1) を出力
	printf("a + (2,1) = ");
	(a.add(Vector2(2, 1))).print();
	printf("\n");

// c, d を入力
	printf("(行列)c = ? ");
	c.scan();
	printf("(行列)d = ? ");
	d.scan();

// c + d を出力
	printf("c + d = ");
	(c.add(d)).print();
	printf("\n");
// c - d を出力
	printf("c - d = ");
	(c.sub(d)).print();
	printf("\n");
// c * d を出力
	printf("c * d =");
	(c.mul(d)).print();
	printf("\n");


	return 0;
}
