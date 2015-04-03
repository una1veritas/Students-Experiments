//
// vec2ex1p.cc - 2次元ベクトル型(C++版)テストプログラム
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "vector2p.h"

//
// main() - テストプログラム
//
int main(void)
{
	Vector2 a, b;
	Matrix c,d;
	// a, b を入力
	printf("a = ? ");
	a.scan();
	printf("b = ? ");
	b.scan();
// a + b を出力
	printf("a + b = \n");
	(a.add(b)).print();
	printf("\n");
// a + (2, 1) を出力
	printf("a + (2,1) = \n");
	(a.add(Vector2(2, 1))).print();
	printf("\n");
 // a - b を出力
	printf("a - b = \n");
	(a.sub(b)).print();
	printf("\n");

	printf("(Matrix)a = ? ");
	c.scan();
	printf("(Matrix)b = ? ");
	d.scan();

//(Matrix) a + b を出力
	printf("(Matrix)a + b = \n");
	(c.add(d)).print();
	printf("\n");
 // (Matrix)a - b を出力
	printf("(Matrix)a - b = \n");
	(c.sub(d)).print();
	printf("\n");

 // (Matrix)a * b を出力
	printf("(Matrix)a * b = \n");
	(c.mul(d)).print();
	printf("\n");
	
	return 0;
}
