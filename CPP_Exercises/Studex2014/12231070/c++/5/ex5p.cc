//
// ex5p.cc - 2次元ベクトル型(C++版)テストプログラム
//	作者: 藤戸梨乃; 日付: 4/17
//
#include <stdio.h>
#include "ex4.h"
#include "ex5.h"

//
// main() - テストプログラム
//
int main(void)
{
	Matrix22 A, B;
	Vector2 C, D;

//行列,ベクトルを入力
	printf("A = ? ");
	A.scan();
	printf("B = ? ");
	B.scan();
	printf("C = ? ");
	C.scan();
	printf("D = ? ");
	D.scan();

//結果を出力
	printf("A + B = ");
	(A.add(B)).print();
	printf("\n");

	printf("A - B = ");
	(A.sub(B)).print();
	printf("\n");

	printf("A * B = ");
	(A.mul(B)).print();
	printf("\n");

	printf("C + D = ");
	(C.add(D)).print();
	printf("\n");

	printf("C - D = ");
	(C.sub(D)).print();
	printf("\n");

	printf("C * D = ");
	(C.mul(D)).print();
	printf("\n");

	return 0;
}

