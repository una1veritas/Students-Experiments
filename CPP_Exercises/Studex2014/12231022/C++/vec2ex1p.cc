//
// vec2ex1p.cc - 2次元ベクトル型(C++版)テストプログラム
//	作者: 工藤慎也; 日付: ４/10
//
#include <stdio.h>
#include "vector2p.h"

//
// main() - テストプログラム
//
int main(void)
{
	Vector2 a, b;

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
// 内積を出力
	printf("a・b = %f",a.inp(b));
	printf("\n");
// 外積を出力
	printf("a × b = %f",a.oup(b));
	printf("\n");
// a + (2, 1) を出力
	printf("a + (2,1) = ");
	(a.add(Vector2(2, 1))).print();
	printf("\n");

	return 0;
}
