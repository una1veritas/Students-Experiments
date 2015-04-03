//
// vec2ex1p.cc - 2次元ベクトル型(C++版)テストプログラム
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "vector2p.h"

//
// main() - テストプログラム
//
int main(void)
{
	Mtrix a, b;
	Vector2 c, d;

// a, b を入力
	printf("a = ? ");
	a.scan();
	printf("b = ? ");
	b.scan();
	printf("c = ? ");
	c.scan();
	printf("d = ? ");
	d.scan();

	printf("a + b\n = ");
	(a.add(b)).print();
	printf("\n");

	printf("a - b\n = ");
	(a.sub(b)).print();
	printf("\n");
	
	printf("c + d\n = ");
	(c.add(d)).print();
	printf("\n");

	printf("c - d\n = ");
	(c.sub(d)).print();
	printf("\n");

	(a.mul(b)).print();
	printf("\n");

	return 0;
}
