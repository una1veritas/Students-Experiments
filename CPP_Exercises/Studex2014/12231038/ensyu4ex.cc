//
// ensyu4ex.cc - 2次正方行列型(C++版)
//      作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "ensyu4.h"

//
// main() - テストプログラム
//
int main(void){
  Ensyu4 i, j;

  /* i, j を入力 */
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

  /* i * j を出力 */
  printf("i * j = ");
  (i.mul(j)).print();
  printf("\n");

  return 0;
}
