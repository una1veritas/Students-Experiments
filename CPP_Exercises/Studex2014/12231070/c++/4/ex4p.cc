//
// ex4p.cc - 2次元ベクトル型(C++版)テストプログラム
//	作者: 藤戸梨乃; 日付: 4/17
//
#include <stdio.h>
#include "ex4.h"

//
// main() - テストプログラム
//
int main(void)
{
	Matrix22 A, B;

//行列を入力
	printf("A = ? ");
	A.scan();
	printf("B = ? ");
	B.scan();
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

	return 0;
}
