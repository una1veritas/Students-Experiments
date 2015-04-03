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
	Matrix a1,b1;
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
	printf("(matrix)a1 = ? ");
    	a1.scan();
    	printf("(matrix)b1 = ? ");
    	b1.scan();
	printf("(matrix)a1 + b1 = \n");
    	(a1.add(b1)).print();
    	printf("\n");
	printf("(matrix)a1 - b1 = \n");
    	(a1.sub(b1)).print();
    	printf("\n");
    	printf("(matrix)a1 * b1 = \n");
    	(a1.mul(b1)).print();
    	printf("\n");
	return 0;
}
