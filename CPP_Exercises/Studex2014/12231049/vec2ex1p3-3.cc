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
	Vector2 a, b;

	printf("a = ");
	a.print();
	printf("\n");
	printf("b = ");
	b.print();
	printf("\n");

// a, b を入力
	printf("a = ? ");
	a.scan();
	printf("b = ? ");
	b.scan();
// a + b を出力
	printf("a + b = ");
	(a.add(b)).print();
	printf("\n");
// a + (2, 1) を出力
	printf("a + (2,1) = ");
	(a.add(Vector2(2, 1))).print();
	printf("\n");
// b - (5, 3) を出力
	printf("b - (5,3) = ");
	(b.sub(Vector2(5, 3))).print();
	printf("\n");
// a に b を代入
	a = b;

	return 0;
}
