//
// ensyu5ex.cc - 2次元ベクトル型(C++版)テストプログラム
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "ensyu5.h"

//
// main() - テストプログラム
//
int main(void)
{
	Matrix2 a;
	Matrix2 b = a;
	Vector2 c;
	Vector2 d = c;

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

// c, d を入力
	printf("c = ? ");
	c.scan();
	printf("d = ? ");
	d.scan();

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

// c + d を出力
	printf("c + d = ");
	(c.add(d)).print();
	printf("\n");
// c + (2, 1) を出力
	printf("c + (2,1) = ");
	(c.add(Vector2(2, 1))).print();
	printf("\n");
// c - (5, 3) を出力
	printf("c - (5,3) = ");
	(c.sub(Vector2(5, 3))).print();
	printf("\n");	

	return 0;
}
