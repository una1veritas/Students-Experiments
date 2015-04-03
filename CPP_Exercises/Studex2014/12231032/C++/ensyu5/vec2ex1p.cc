//
// vec2ex1p.cc - 2次元ベクトル型(C++版)テストプログラム
//	作者:核雅瑛 (あなたの名前); 日付: 2014/4/10(完成した日付)
//
#include <stdio.h>
#include "vector2p.h"

//
// main() - テストプログラム
//
int main(void)
{
        Matrix matA, matB;
	Vector2 vecA,vecB;
	//宣言後のベクトルの中身をみる

// a, b を入力
	printf("MatrixA  = ? ");
	matA.scan();
	printf("\n");

	printf("MatrixB  = ? ");
	matB.scan();
	printf("\n");
	
	matA.print();
	printf("\n");
	matB.print();
	printf("\n");
	
	printf("VectorA  = ? ");
	vecA.scan();
	printf("\n");

	printf("VectorB  = ? ");
	vecB.scan();
	printf("\n");
	
	vecA.print();
	vecB.print();
	

// a + b を出力
	printf("matA + matB = \n");
	(matA.add(matB)).print();
	printf("\n");

// a + b を出力
	printf("vecA + vecB = \n");
	(vecA.add(vecB)).print();
	printf("\n");


// a - b を出力
//	printf("a - b = \n");
//	(a.sub(b)).print();
//	printf("\n");
	
//a * b を出力 
//	printf("a * b = \n");
//	(matrix.mul(vector)).print();

//普通に代入
/*	a = b;
	a.print();
	b.print();

     
	Matrix c=a;
	a.print();
	b.print();
*/
	return 0;
}
