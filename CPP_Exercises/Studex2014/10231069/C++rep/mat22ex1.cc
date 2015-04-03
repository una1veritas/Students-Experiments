//
// mat22ex1.cc - 2次元正方行列型(C++版)テストプログラム
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "matrix22.h"

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
	printf("a + b = \n");
	(a.add(b)).print();
	printf("\n");
// a + E(単位行列) を出力
	printf("a + E = \n");
	(a.add(Matrix22(1, 0, 0, 1))).print();
	printf("\n");
// a - b を出力
	printf("a - b = \n");
	(a.sub(b)).print();
	printf("\n");
// a - E を出力
	printf("a - E = \n");
	(a.sub(Matrix22(1, 0, 0, 1))).print();
	printf("\n");
// a と b の積を出力
	printf("a * b = \n");
	(a.mul(b)).print();
	printf("\n");

	return 0;
}
