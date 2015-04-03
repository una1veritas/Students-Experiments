#include <stdio.h>
#include "main.h"

//
// main() - テストプログラム
//
int main(void)
{
  printf("Vec\n");
  Vec a, b;
// a, b を入力
  printf("a = ? ");
  a.scan();
  printf("b = ? ");
  b.scan();
// a + b を出力
  printf("a + b = \n");
  (a.add(b)).print();
  printf("\n");
// a - b
  printf("a - b = \n");
  (a.sub(b)).print();
  printf("\n");

//----------------------
  printf("SqMat\n");
  SqMat c, d;
// a, b を入力
  printf("c = ? ");
  c.scan();
  printf("d = ? ");
  d.scan();
// a + b を出力
  printf("a + b = \n");
  (c.add(d)).print();
  printf("\n");
// a - b
  printf("a - b = \n");
  (c.sub(d)).print();
  printf("\n");

  return 0;
}
