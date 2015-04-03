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
	//宣言後のベクトルの中身をみる
	a.print();
	b.print();

// a, b を入力
	printf("a = ? ");
	a.scan();
	
	//aのみ入力されたとき
	a.print();
	b.print();

	printf("b = ? ");
	b.scan();

	//bも入力されたとき
	a.print();
	b.print();
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

	//普通に代入
	a = b;
	a.print();
	b.print();

	//Vector代入
	Vector2 c=a;
	a.print();
	b.print();
	return 0;
}
