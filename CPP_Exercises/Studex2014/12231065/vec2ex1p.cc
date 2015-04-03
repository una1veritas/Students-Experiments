//
// vec2ex1p.cc - 2次元ベクトル型(C++版)テストプログラム
//	作者: 福田真実; 日付: (4/28)
//
#include <stdio.h>
#include "vector2p.h"
#include "matrix.h"

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

	Vector2 c = b;
// a + b を出力
	printf("a + b = ");
	(a.add(b)).print();
	printf("\n");
// a - b を出力
	printf("a - b = ");
	(a.sub(b)).print();
	printf("\n");
// 内積
	printf("内積 = %lf" ,a.in(b));
	printf("\n");
//外積
	printf("外積 = %lf" ,a.out(b));
	printf("\n");
	
// a + (2, 1) を出力
	printf("a + (2,1) = ");
	(a.add(Vector2(2, 1))).print();
	printf("\n");
// c - (2, 1) を出力
	printf("c - (2,1) = ");
	(c.sub(Vector2(2, 1))).print();
	printf("\n");
	
    
	Matrix e, d;

// a, b を入力
	printf("e = ? ");
	e.scan();
	printf("d = ? ");
	d.scan();
// a + b を出力
	printf("e + d = ");
	(e.add(d)).print();
	printf("\n");
// a - b を出力
	printf("e - d = ");
	(e.sub(d)).print();
	printf("\n");
// a・(2,1,1,2) を出力
	printf("e・(2,1,1,2) = ");
	(e.mul(Matrix(2,1,1,2))).print();
	printf("\n");

	return 0;
}
