//
// vec2ex1p.cc - 2次元ベクトル型(C++版)テストプログラム
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "vector2.h"

//
// main() - テストプログラム
//
int main(void)
{
	Vector2 a, b;

// a, b を入力
	printf("x, y = ? ");
	a.scan();
	printf("x, y = ? ");
	b.scan();
	printf("\na = ");
	a.print();
	printf("\nb = ");
	b.print();
	printf("\n\n");
// a + b を出力
	printf("a + b = ");
	(a.add(b)).print();
	printf("\n");
	// a + (2, 1) を出力
	printf("a + (2,1) = ");
	(a.add(Vector2(2, 1))).print();
	printf("\n");

	// a + c を出力
	Vector2 c(0.9, 0.33);
	printf("a = a + c ");
	a.add(c).print();
	printf("\n");
	printf("d = a ");
	Vector2 d = a;
	d.print();
	printf("\n");

	return 0;
}
