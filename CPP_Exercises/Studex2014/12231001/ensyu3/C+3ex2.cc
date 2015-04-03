//
// vec2ex1p.cc - 2次元ベクトル型(C++版)テストプログラム
//　作成者：朝比奈　涼；　作成日：2104 /4/24
//
#include <stdio.h>
#include "C+3ex2.h"

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
// a - b を出力
	printf("a - b = ");
	(a.sub(b)).print();
	printf("\n");
// a + (2, 1) を出力
	printf("a + (2,1) = ");
	(a.add(Vector2(2, 1))).print();
	printf("\n");
// a - (2, 1) を出力
	printf("a - (2,1) = ");
	(a.sub(Vector2(2, 1))).print();
	printf("\n");
//aとbの内積を出力
	printf("a . b = %f",a.nai(b));
	printf("\n");
//aとbの外積を出力
	printf("a * b = %f",a.gai(b));
	printf("\n");
	

	return 0;
}
