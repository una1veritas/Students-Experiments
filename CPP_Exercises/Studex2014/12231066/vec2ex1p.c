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

// a, b を入力
	printf("a = ? ");
	a.scan();
	printf("b = ? ");
	b.scan();
// a + b を出力
	printf("a + b = ");
	(a.add(b)).print();
	printf("\n");
// a + (2, 1) を出力
	printf("a + (2,1) = ");
	(a.add(Vector2(2, 1))).print();
	printf("\n");
// a - b を出力
	printf("a - b = ");
	(a.sub(b)).print();
	printf("\n");
// a - (2, 1) を出力
	printf("a -(2,1) = ");
	(a.sub(Vector2(2, 1))).print();
	printf("\n");
// a と b の内積を出力
	printf("aとbの内積:");
	printf("%lf\n",a.inner_pro(b));
// a と b の外積を出力
	printf("aとbの外積:");
	printf("%lf\n",a.cross_pro(b));
	Vector2 v1;
	v1.print();
	printf("\n");
	Vector2 v2(2.2, 6.6);
	v2.print();
	printf("\n");
	Vector2 v3(v2);
	printf("\n");

	return 0;
}
