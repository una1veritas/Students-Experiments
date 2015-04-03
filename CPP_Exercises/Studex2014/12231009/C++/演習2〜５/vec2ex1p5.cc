//
// vec2ex1p.cc - 2次元ベクトル型(C++版)テストプログラム
//	作者: Yuya Uekama(あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "vector2p5.h"

//
// main() - テストプログラム
//
int main(void)
{
	Vector2 a, b;
	Matrix22 c, d;
// a, b を入力
	printf("a = ? ");
	a.scan();
	printf("b = ? ");
	b.scan();
// a + b を出力
	printf("a + b = ");
	(a.add(b)).print();
	printf("\n");
// a - b を出力
	printf("a - b = ");
	(a.sub(b)).print();
	printf("\n");
// a * b を出力
	printf("a * b = ");
	(a.mul(b)).print();
	printf("\n");

// a, b を入力
	printf("c = ? ");
	c.scan();
	printf("d = ? ");
	d.scan();
// a + b を出力
	printf("c + d = ");
	(c.add(d)).print();
	printf("\n");
// a - b を出力
	printf("c - d = ");
	(c.sub(d)).print();
	printf("\n");
// a * b を出力
	printf("c * d = ");
	(c.mul(d)).print();
	printf("\n");	

	return 0;
}
