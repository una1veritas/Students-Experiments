//
// vec2ex1p_3-1.cc - 2次元ベクトル型(C++版)テストプログラム（演習３(1)）
//	作者: Dewi; 日付: 2014/4/10
//
#include <stdio.h>
#include "vector2p_3-1.h"

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
// a + (2, 1) を出力
	printf("a + (2,1) = ");
	(a.add(Vector2(2, 1))).print();
	printf("\n");
// a - b を出力
	printf("a - b = ");
	(a.sub(b)).print();
	printf("\n");
	
	return 0;
}
