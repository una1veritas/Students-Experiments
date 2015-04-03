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

// a bの内積を出力
	printf("a * b = ");
	printf("%f",(a.innerProduct(b)));
	printf("\n");

// a bの外積を出力
	printf("a × b = ");
	printf("%f",(a.crossProduct(b)));
	printf("\n");


	return 0;
}
