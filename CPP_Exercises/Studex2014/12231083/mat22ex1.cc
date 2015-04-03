//
// 
//	作者: 山本晃也); 日付: (4/15)
//
#include <stdio.h>
#include "matrix22.h"


int main(void)
{
  Matrix22   a, b;
  Vector2 c,d;
  	printf("c = ? ");
	c.scan();
	printf("d = ? ");
	d.scan();
// a + b を出力
	printf("c + d = ");
	(c.add(d)).print();
	printf("\n");

// a - b を出力
	printf("c - d = ");
	(c.sub(d)).print();
	printf("\n");
	//a*b
	/*	printf("c * d = ");
	(c.mul(d)).print();
	printf("\n");
	return 0;*/
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
	//a*b
  	printf("a * b = ");
	(a.mul(b)).print();
	printf("\n");
  
	return 0;

}
