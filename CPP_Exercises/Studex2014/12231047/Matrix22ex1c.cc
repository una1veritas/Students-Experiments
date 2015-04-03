#include <stdio.h>
#include "Matrix22.h"

int main(void){

  
  Matrix22 a,b;
  Vector2 a1, b1;
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
// a * b を出力
	printf("a * b = ");
	(a.mal(b)).print();
	printf("\n");

	// a, b を入力
	printf("a = ? ");
	a1.scan();
	printf("b = ? ");
	b1.scan();
// a + b を出力
	printf("a + b = ");
	(a1.add(b1)).print();
	printf("\n");
// a - b を出力
	printf("a - b = ");
	(a1.sub(b1)).print();
	printf("\n");
// a  b の内積の出力
	printf("a  b の内積= %lf", a1.in(b1));
	printf("\n");
// a  b の外積の出力
	printf("a  b の外積= %lf", a1.out(b1));
	printf("\n");

	return 0;

}
