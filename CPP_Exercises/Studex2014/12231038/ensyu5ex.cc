//
// ensyu5ex.cc - 2次元ベクトル型.2次正方行列型(C++版)
//      作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "ensyu5.h"

//
// main() - テストプログラム
//
int main(void){
  Vector2 a, b;
  Ensyu4 i, j;
  
  printf("a = ");a.print();
  printf("b = ");b.print();
  printf("i = \n");i.print();
  printf("j = \n");j.print();
  
  /* a, b を入力 */
  printf("2次元ベクトルの計算\n");
  printf("a = ? ");
  a.scan();
  printf("b = ? ");
  b.scan();

  /* a + b を出力 */
  printf("a + b = \n");
  (a.add(b)).print();
  printf("\n");

  /* a - b を出力 */
  printf("a - b = \n");
  (a.sub(b)).print();
  printf("\n");

  /* i, j を入力 */
  printf("2次正方行列の計算\n");
  printf("i = ? ");
  i.scan();
  printf("j = ? ");
  j.scan();

  /* i + j を出力 */
  printf("i + j = ");
  (i.add(j)).print();
  printf("\n");

  /* i - j を出力 */
  printf("i - j = ");
  (i.sub(j)).print();
  printf("\n");

  return 0;
}
