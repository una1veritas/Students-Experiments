//
// mat2ex1p.cc - 2次正方行列型(C++版)テストプログラム
//	作者: 伊佐　真誠; 日付: 14/4/10
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
// a, b を出力
 	printf("a =\n");
	a.print();
	printf("\n");
	printf("b =\n");
	b.print();
	printf("\n");
// a + b を出力
	printf("a + b = \n");
	(a.add(b)).print();
	printf("\n");
// a - b を出力
	printf("a - b = \n");
	(a.sub(b)).print();
	printf("\n");
//aとbの積を出力
	printf("積 = \n");
	(a.mul(b)).print();
	printf("\n");
// a + (2, 1) を出力
	printf("a + (2,1|2,1) = \n");
	(a.add(Matrix22(2, 1, 2, 1))).print();
	printf("\n");
	return 0;
}
