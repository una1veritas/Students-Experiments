//
// kadai4main.cc - 2次元正方行列型(C++版)テストプログラム
//	作者:浦川楓; 日付: 2014/4/17
//
#include <stdio.h>
#include "kadai4.h"

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
  printf("a + b = \n");
  (a.add(b)).print();
  printf("\n");
  // a - b を出力
  printf("a - b = \n");
  (a.sub(b)).print();
  printf("\n");
  // a * b を出力
  printf("a * b = \n");
  (a.mul(b)).print();
  printf("\n");

  return 0;
}
