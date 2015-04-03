//
// vec2ex1p.cc - 2次元ベクトル型(C++版)テストプログラム
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "vector22c.h"

//
// main() - テストプログラム
//
int main(void)
{
	Vector22 a, b;

// a, b を入力
	printf("a = ? ");
	a.scanv22();
	a.printv22();printf("\n");
	printf("b = ? ");
	b.scanv22();
	b.printv22();printf("\n");
// a + b を出力
	printf("a + b = \n");
	(a.addv22(b)).printv22();
	printf("\n");
// a + (2, 1) を出力
	printf("a+(2,1) =\n  (2,1)\n");
	(a.addv22(Vector22(2,1,2,1))).printv22();
	printf("\n");
// a - b を出力
	printf("a - b = \n");
	(a.subv22(b)).printv22();
	printf("\n");
// a - (2, 1) を出力
	printf("a-(2,1) =\n  (2,1)\n");
	(a.subv22(Vector22(2,1,2,1))).printv22();
	printf("\n");
// a と b 積を出力
	printf("a * b =\n");
	(a.mulv22(b)).printv22();
	printf("\n");
	return 0;

}

