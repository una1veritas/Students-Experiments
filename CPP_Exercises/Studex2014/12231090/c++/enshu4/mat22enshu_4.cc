//
// mat22enshu_4.cc - 2次正方行列型(C++版)テストプログラム
//	作者: Dewi; 日付: 2014/4/24
//
#include <stdio.h>
#include "matrix22_4.h"

//
// main() - テストプログラム
//
int main(void)
{
	Matrix22 a, b;

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
