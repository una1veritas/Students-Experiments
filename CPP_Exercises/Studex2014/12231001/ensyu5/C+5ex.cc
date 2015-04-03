//
// vec2ex1p.cc - 2次元ベクトル型(C++版)テストプログラム
//　作成者：朝比奈　涼；　作成日：2104 /4/24
//
#include <stdio.h>
#include "C+5ex.h"

//
// main() - テストプログラム
//
int main(void)
{

//2次元ベクトル
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




//2次正方行列
	Vector c, d;

// a, b を入力
	printf("c = ? ");
	c.scan();
	printf("d = ? ");
	d.scan();
// a + b を出力
	printf("c + d = \n");
	(c.add(d)).print();
	printf("\n");

// a - b を出力
	printf("c - d = \n");
	(c.sub(d)).print();
	printf("\n");

	return 0;
}
