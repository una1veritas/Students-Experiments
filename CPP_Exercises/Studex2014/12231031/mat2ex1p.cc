//
// vec2ex1p.cc - 2次元ベクトル型(C++版)テストプログラム
//	作者:佐藤彰哉; 日付:4/10
//
#include <stdio.h>
#include "mat2p.h"

//
// main() - テストプログラム
//
int main(void)
{
	Mat2 a, b;

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
//　a*bを出力
	printf("a * b = ");
	(a.mul(b)).print();
	printf("\n");
	return 0;
}
