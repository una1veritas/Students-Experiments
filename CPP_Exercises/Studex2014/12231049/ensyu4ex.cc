//
// ensyu4ex.cc - 2次元ベクトル型(C++版)テストプログラム
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "ensyu4.h"

//
// main() - テストプログラム
//
int main(void)
{
	Matrix2 a;
	Matrix2 b = a;

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
	printf("a + b = \n");
	(a.add(b)).print();
	printf("\n");
// a - b を出力
    printf("a - b = \n");
	(a.sub(b)).print();
	printf("\n");
// a * b を出力
    printf("a * b = \n");
	(a.mul(b)).print();
	printf("\n");

	return 0;
}
