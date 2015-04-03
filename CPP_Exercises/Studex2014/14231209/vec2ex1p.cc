//
// vec2ex1p.cc - 2次元ベクトル型(C++版)テストプログラム
//	作者: 道下　真人; 日付: 2014/04/10
//
#include <stdio.h>
#include "vector2p.h"

//
// main() - テストプログラム
//
int main(void)
{
	Vector2 a, b,e(2,1);
	printf("a=");
	a.print();
	printf("b=");
	b.print();
	printf("演習３（１）\n");

	printf("\n");

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
	printf("a ・ b = %f",a.naiseki(b));
	printf("\n");
// a × b を出力
	printf("a × b = %f",a.gaiseki(b));
	printf("\n");
// a + (2, 1) を出力
	printf("a + (2,1) = ");
	(a.add(e)).print();
	printf("\n");
//a - (2, 1) を出力
	printf("a - (2,1) = ");
	(a.sub(e)).print();
	printf("\n\n");

// 演習３(３)
	printf("演習３(３)　コピー\n");
	Vector2 c(a),d;
	d=b;
	printf("c(a):");
	c.print();
	printf(" d=b:");
	d.print();

	printf("\n");

		
	Matrix22 p, q;
	
// p, q を入力
	printf("p = ? ");
	p.scan();
	printf("q = ? ");
	q.scan();
	
// p + q を出力
	printf("p + q = ");
	(p.add(q)).print();
	printf("\n");
	
// p - q を出力
	printf("p - q = ");
	(p.sub(q)).print();
	printf("\n");

// p * q を出力
	printf("p * q = ");
	(p.mul(q)).print();
	printf("\n");
	
	printf("\n");


	return 0;
}
