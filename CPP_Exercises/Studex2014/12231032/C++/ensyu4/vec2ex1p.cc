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
	Matrix a, b;
	//宣言後のベクトルの中身をみる

// a, b を入力
	printf("a = ? ");
	a.scan();
	a.print();
	printf("\n");
	
	printf("b = ? ");
	b.scan();
	b.print();
	printf("\n");

// a + b を出力
	printf("a + b = \n");
	(a.add(b)).print();
	printf("\n");

// a - b を出力
	printf("a - b = \n");
	(a.sub(b)).print();
	printf("\n");
	
//a * b を出力 
	printf("a * b = \n");
	(a.mul(b)).print();

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
