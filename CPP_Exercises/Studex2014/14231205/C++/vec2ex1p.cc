//
// vec2ex1p.cc - 2次元ベクトル型(C++版)テストプログラム
// TAKAHASHI Manaka
//
#include <stdio.h>
#include "vector2p.h"

//
// main() - テストプログラム
//
int main(void)
{
  printf("Vector2 a, bを宣言\n");
  Vector2 a, b;
	
// a, b を入力
  printf("a = ? ");
  a.scan();
  printf("b = ? ");
  b.scan();
// a + b を出力
//	printf("a + b = ");
//	(a.add(b)).print();
//	printf("\n");
// a - b
//	printf("a - b = ");
//	(a.sub(b)).print();
//	printf("\n");
// a・b 
//	double ret = a.inp(b);
//	printf("a・b = ");
//	printf("%f", ret);
//	printf("\n");

// a × b
//	printf("a × b = ");
//	(a.out(b)).print();
//	printf("\n");

  printf("Vector2 vec(5,6)を宣言\n");
  Vector2 vec(5,6);

  printf("Vector2 vecをコピー\n");
  Vector2 vecc(vec);

  return 0;
}
