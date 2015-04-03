#include <stdio.h>
#include "mat2.h"
#include "vector2p.h"

int main(void)
{
  Matrix2 c, d;
  Vector2 a, b;

  a.print();
  printf("\n");
  b.print();
  printf("\n");
  
  // a, b を入力
  printf("a = ? ");
  a.scan();
  printf("b = ? ");
  b.scan();
  
  a.print();
  printf("\n");
  b.print();
  printf("\n");
  
  // a + b を出力
  printf("a + b = ");
  (a.add(b)).print();
  printf("\n");
  printf("a - b = ");
  (a.sub(b)).print();
  printf("\n");
  // a + (2, 1) を出力
  printf("a + (2,1) = ");
  (a.add(Vector2(2, 1))).print();
  printf("\n");
  printf("a - (2,1) = ");
  (a.sub(Vector2(2, 1))).print();
  printf("\n");
  
  
  printf("c = ?\n");
  c.scan();
  printf("d = ?\n");
  d.scan();
  
  printf("c + d = \n");
  (c.add(d)).print();
  printf("c - d = \n");
  (c.sub(d)).print();
  printf("c * d = \n");
  (c.mul(d)).print();

  return 0;
}
