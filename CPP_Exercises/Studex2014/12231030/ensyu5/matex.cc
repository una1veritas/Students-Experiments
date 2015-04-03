//
// matex.cc - 正方行列(C++版)テストプログラム
//	作者: 定平典久; 日付: 14/04/17
//
#include <stdio.h>
#include "matrix.h"

//
// main() - テストプログラム
//
int main(void)
{
        Matrix a,b;
	Vector2 c, d;

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

// a * b を出力
	printf("a * b = ");
	(a.mul(b)).print();
	printf("\n");





// a, b を入力
	printf("a = ? ");
	c.scan();
	printf("b = ? ");
	d.scan();
// a + b を出力
	printf("a + b = ");
	(c.add(d)).print();
	printf("\n");
// a - b を出力
	printf("a - b = ");
	(c.sub(d)).print();
	printf("\n");

// a . b を出力
	printf("a . b = ");
	printf("%f",c.inpro(d));
	printf("\n");

// a * b を出力
	printf("a * b = ");
	printf("%f",c.outpro(d));
	printf("\n");
// a + (2, 1) を出力
	printf("a + (2,1) = ");
	(c.add(Vector2(2, 1))).print();
	printf("\n");
   
	return 0;
}
