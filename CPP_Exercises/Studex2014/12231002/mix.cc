//
// mix.cc - 複合時(C++版)テストプログラム
//	作者: 伊佐　真誠; 日付: 14/4/17
//
#include <stdio.h>
#include "matrix22.h"
#include "vector2p.h"

//
// main() - テストプログラム
//
int main(void)
{

	Vector2 a, b;
	Matrix22 c, d;

// a, b を入力
	printf("a,bは二次元ベクトル\n");
	printf("a = ? ");
	a.scan();
	printf("b = ? ");
	b.scan();
// c, d を入力
	printf("c,dは二次正方行列\n");
	printf("c = ? ");
	c.scan();
	printf("d = ? ");
	d.scan();
// a, b を出力
 	printf("a =\n");
	a.print();
	printf("\n");
	printf("b =\n");
	b.print();
	printf("\n");
// c, d を出力
 	printf("c =\n");
	c.print();
	printf("\n");
	printf("d =\n");
	d.print();
	printf("\n");
// a + b を出力
	printf("a + b = \n");
	(a.add(b)).print();
	printf("\n");
// c + d を出力
	printf("c + d = \n");
	(c.add(d)).print();
	printf("\n");
// a - b を出力
	printf("a - b = \n");
	(a.sub(b)).print();
	printf("\n");
// c - d を出力
	printf("c - d = \n");
	(c.sub(d)).print();
	printf("\n");
// c * d を出力
	printf("c * d = \n");
	(c.mul(d)).print();
	printf("\n");

	return 0;
}
