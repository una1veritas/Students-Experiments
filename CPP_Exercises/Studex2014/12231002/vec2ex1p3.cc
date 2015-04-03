//
// vec2ex1p3.cc - 2次元ベクトル型(C++版)テストプログラム
//	作者: 伊佐　真誠; 日付: 14/4/10
//
#include <stdio.h>
#include "vector2p3.h"

//
// main() - テストプログラム
//
int main(void)
{
        Vector2 a, b;

// a, b の初期化の確認
	a.print();
	printf("\n");
	b.print();
	printf("\n");
// a, b を入力
	printf("a = ? ");
	a.scan();
	printf("b = ? ");
	b.scan();
// a と同じ成分を持つベクトルの作成
	printf("c = ");
	Vector2(a).print();
	printf("\n");
// a + b を出力
	printf("a + b = ");
	(a.add(b)).print();
	printf("\n");
// a - b を出力
	printf("a - b = ");
	(a.sub(b)).print();
	printf("\n");
//aとbの内積を出力
	printf("内積 = %lf", a.naiseki(b));
	printf("\n");
// a + (2, 1) を出力
	printf("a + (2,1) = ");
	(a.add(Vector2(2, 1))).print();
	printf("\n");

	return 0;
}
