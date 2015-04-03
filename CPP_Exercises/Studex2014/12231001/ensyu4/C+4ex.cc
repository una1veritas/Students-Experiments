//
// vec2ex1p.cc - 2次元ベクトル型(C++版)テストプログラム
//　作成者：朝比奈　涼；　作成日：2104 /4/24
//
#include <stdio.h>
#include "C+4ex.h"

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
// a / b を出力
	printf("a / b = \n");
	(a.div(b)).print();
	printf("\n");

	return 0;
}
