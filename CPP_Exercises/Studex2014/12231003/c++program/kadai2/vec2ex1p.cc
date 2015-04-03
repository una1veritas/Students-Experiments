// vec2ex1p.cc - 2次元ベクトル型(C++版)テストプログラム
//	作者: (市川　舞); 日付: (2014/04/10)
#include <stdio.h>
#include "vector2p.h"

// main() - テストプログラム
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
// a + (2, 1) を出力
	printf("a + (2,1) = ");
	(a.add(Vector2(2,1))).print();
	printf("\n");
// 課題2-(2)にて追加
// a - b を出力
	printf("a - b = ");
	(a.sub(b)).print();
	printf("\n");
// b - (2, 1) を出力
	printf("b - (2,1) = ");
	(b.sub(Vector2(2,1))).print();
	printf("\n");

	return 0;
}
