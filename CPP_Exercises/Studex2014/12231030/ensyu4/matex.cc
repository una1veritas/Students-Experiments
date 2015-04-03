
//
// matex.cc - 2次元ベクトル型(C++版)テストプログラム
//	作者: 定平典久; 日付: 14/04/10
//
#include <stdio.h>
#include "matrix.h"

//
// main() - テストプログラム
//
int main(void)
{
	Matrix a, b;

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
	return 0;
}
