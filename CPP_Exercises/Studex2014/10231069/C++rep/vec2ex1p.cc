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

	printf("\na = ");
	a.print();
	printf("\n");
	printf("b = ");
	a.print();
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
// a - b を出力
	printf("a - b = ");
	(a.sub(b)).print();
	printf("\n");
// a - (2, 1) を出力
	printf("a - (2,1) = ");
	(a.sub(Vector2(2, 1))).print();
	printf("\n");
// a と b の内積を出力
	printf("a1b1 + a2b2 = ");
	printf("%f\n", (a.dotp(b)));
// a と b の外積を出力
	printf("a1b2 - a2b1 = ");
	printf("%f\n", (a.crop(b)));
// コピーコンストラクタの利用
	Vector2().print();
	printf("\n");
	Vector2(a).print();
	printf("\n");

	return 0;
}
