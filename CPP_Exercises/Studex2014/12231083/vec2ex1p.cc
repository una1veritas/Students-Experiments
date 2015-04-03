//
// vec2ex1p.cc - 2次元ベクトル型(C++版)テストプログラム
//	作者: (山本晃也); 日付: (4/10)
//
#include <stdio.h>
#include "vector2p.h"

//
// main() - テストプログラム
//void Vector2::print(void)


int main(void)
{
  Vector2 a, b;

  a.print();
  b.print();


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
	printf("a + (2,1) = ");
	(a.sub(Vector2(2, 1))).print();
	printf("\n");
	return 0;
}
