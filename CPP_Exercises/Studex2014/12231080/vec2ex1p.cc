//<演習5>
// vec2ex1p.cc - 2次元ベクトル型(C++版)テストプログラム
//	作者: 本石　大記; 日付: 2014/04/10
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
// a - (2, 1) を出力
	printf("a - (2,1) = \n");
	(a.sub(Vector2(2, 1))).print();
	printf("\n");
	
	Vector2 c=a;
	(a.add(c)).print();
	printf("\n");

// matrix index
    printf("(matrix)a = ? ");
    a1.scan();
    printf("(matrix)b = ? ");
    b1.scan();

// matrix  a + b を出力
    printf("(matrix)a + b = \n");
    (a1.add(b1)).print();
    printf("\n");
// matrix a - b を出力
    printf("(matrix)a - b = \n");
    (a1.sub(b1)).print();
    printf("\n");
// matrix a * b を出力
    printf("(matrix)a * b = \n");
    (a1.mul(b1)).print();
    printf("\n");

    return 0;
}
