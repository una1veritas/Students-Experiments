//
// vec2ex1p.cc - 2次元ベクトル型(C++版)テストプログラム
//	作者: 工藤慎也; 日付: ４/17
//
#include <stdio.h>
#include "vector5p.h"

//
// main() - テストプログラム
//
int main(void)
{
	Vector2 a, b;
	Matrix4 A, B;



// ベクトルa,bと行列A,Bを入力
	printf("a = ? ");
	a.scan();
	printf("b = ? ");
	b.scan();
	printf("A = ? ");
	A.scan();
	printf("B = ? ");
	B.scan();
// 行列の加算を出力
	printf("A + B = ");
	(A.add(B)).print();
	printf("\n");
// 行列の減算を出力
	printf("A - B = ");
	(A.sub(B)).print();
	printf("\n");
// 行列の乗算を出力
	printf("A × B = ");
	(A.mul(B)).print();
	printf("\n");
// ベクトルの加算を出力
	printf("a + b = ");
	(a.add(b)).print();
	printf("\n");
// ベクトルの減算を出力
	printf("a - b = ");
	(a.sub(b)).print();
	printf("\n");
// ベクトルの内積を出力
	printf("a・b = %f",a.inp(b));
	printf("\n");
// ベクトルの外積を出力
	printf("a × b = %f",a.oup(b));
	printf("\n");
// aベクトルと(2, 1)ベクトルの和を出力
	printf("a + (2,1) = ");
	(a.add(Vector2(2, 1))).print();
	printf("\n");

	return 0;
}
