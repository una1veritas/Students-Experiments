//
// vec2ex1p.cc - 2次元ベクトル型(C++版)テストプログラム
// 大高弥  4/10
//
#include <stdio.h>
#include "vector2p.h"

//
// main() - テストプログラム
//
int main(void)
{
	Vector2 a, b(1,1),c(b);
	a.print();
	b.print();
	c.print();
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
// a ・ b を出力
    printf("a ・ b = ");
    (a.in(b)).print();
    printf("\n");
// a × b を出力
    printf("a × b = ");
    (a.out(b)).print();
    printf("\n");

// a + (2, 1) を出力
	printf("a + (2,1) = ");
	(a.add(Vector2(2, 1))).print();
	printf("\n");

	return 0;
}
