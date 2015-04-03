//
// enshu5_main.cc - 2次元ベクトル型と2次正方行列型(C++版)テストプログラム
//	作者: Dewi; 日付: 2014/4/24
//
#include <stdio.h>
#include "enshu5.h"

//
// main() - テストプログラム
//
int main(void)
{
  Vector2 a, b;
  Matrix22 c, d;

  printf("2次元ベクトル型\n");	
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
	

  printf("2次正方行列型\n");
// c, d を入力
  printf("c = ? ");
  c.scan();
  printf("d = ? ");
  d.scan();
// c + d を出力
  printf("c + d = ");
  (c.add(d)).print();
  printf("\n");
// c - d を出力
  printf("c - d = ");
  (c.sub(d)).print();
  printf("\n");
// c * d を出力
  printf("c * d = ");
  (c.mul(d)).print();
  printf("\n");

  return 0;
}
