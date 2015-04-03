//
// vec2ex1p.cc - 2次元ベクトル型(C++版)テストプログラム
//	作者: 定平典久; 日付: 14/04/10
//
#include <stdio.h>
#include "vector2p.h"

//
// main() - テストプログラム
//
int main(void)
{
	Vector2 a, b;
	//	Vector2(a);
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

// a . b を出力
	printf("a . b = ");
	printf("%f",a.inpro(b));
	printf("\n");

// a * b を出力
	printf("a * b = ");
	printf("%f",a.outpro(b));
	printf("\n");
// a + (2, 1) を出力
	printf("a + (2,1) = ");
	(a.add(Vector2(2, 1))).print();
	printf("\n");

	return 0;
}
