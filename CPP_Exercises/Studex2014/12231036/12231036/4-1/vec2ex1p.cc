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
	
	Matrix22 c,d;
	
// a, b を入力
	printf("c = ? ");
	c.scanm();
	
	printf("d = ? ");
	d.scanm();
// a + b を出力
	printf("c + d = ");
	(c.addm(d)).printm();
	printf("\n");
// a - b を出力
	printf("c - d = ");
	(c.subm(d)).printm();
	printf("\n");
// a * b を出力
	printf("c * d = ");
	(c.mulm(d)).printm();
	printf("\n");
// a + (2, 1,1,2) を出力
	printf("c + (2,1,1,2) = ");
	(c.addm(Matrix22(2, 1,1,2))).printm();
	printf("\n");
}
