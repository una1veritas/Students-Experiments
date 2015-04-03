//
// vec2ex1p.cc - 2次元ベクトル型(C++版)テストプログラム
//	作者: 竹下純哉; 日付: 14/04/10
//
#include <stdio.h>
#include "ensyu3.h"

//
// main() - テストプログラム
//
int main(void)
{
	Vector2 a, b;
       
	printf("a = ");a.print();printf("\n");
	printf("b = ");b.print();printf("\n");
// a, b を入力
	printf("a = ? ");
	a.scan();
	printf("b = ? ");
	b.scan();
	printf("a = ");a.print();printf("\n");
	printf("b = ");b.print();printf("\n");
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
