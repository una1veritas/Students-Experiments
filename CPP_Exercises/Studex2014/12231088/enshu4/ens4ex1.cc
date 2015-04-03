#include <stdio.h>
#include "mat2.h"


int main(void)
{
  Matrix2 a,b;

  printf("a = ?\n");
  a.scan();
  printf("b = ?\n");
  b.scan();

  printf("a + b = \n");
  (a.add(b)).print();
  printf("a - b = \n");
  (a.sub(b)).print();
  printf("a * b = \n");
  (a.mul(b)).print();

  return 0;
}
