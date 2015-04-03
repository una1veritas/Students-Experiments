//
// kadai5main.cc - 2次元正方行列型(C++版)テストプログラム
//	作者:浦川楓; 日付: 2014/4/17
//
#include <stdio.h>
#include "kadai5.h"

//
// main() - テストプログラム
//
int main(void)
{
  Vector2 a, b;
  Matrix c,d;
  
  // a, b を入力(ベクトル)
  printf("a = ? ");
  a.scan();
  printf("b = ? ");
  b.scan();
  // c, d を入力(行列)
  printf("c = ? ");
  c.scan();
  printf("d = ? ");
  d.scan();
  // a + b を出力
  printf("a + b = \n");
  (a.add(b)).print();
  printf("\n");
  // c + d を出力
  printf("c + d = \n");
  (c.add(d)).print();
  printf("\n");
  // a - b を出力
  printf("a - b = \n");
  (a.sub(b)).print();
  printf("\n");
  // c - d を出力
  printf("c - d = \n");
  (c.sub(d)).print();
  printf("\n");

  return 0;
}
