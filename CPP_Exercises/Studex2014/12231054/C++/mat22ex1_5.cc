//
// mat22ex1.cc - 2次行列テストプログラム
//      作者: Kento NOMIYAMA; 日付: 2014.04.10
//

#include <stdio.h>
#include "matrix22_5.h"

// main()

int main(void){
	Matrix22 a,b;
	Matrix22 c(3,5,2,1);
	Matrix22 d(c);
	Matrix22(3,5,2,1).print();

	a.print();
	b.print();
	printf("a = ?");
	a.scan();
	printf("b = ?");
	b.scan();

	printf("a + b\n");
	(a.add(b)).print();

	printf("a + (3,5,2,1)\n");
	(a.add(Matrix22(3,5,2,1))).print();
	
	printf("a - b\n");
	(a.sub(b)).print();

	printf("a * c\n");
	(a.mul(c)).print();

	printf("vector\n");
	Vector2 e, f;
	Vector2 g(5, 3);
	Vector2(2,1).print();	
	Vector2 h(g);
// a, b を入力
	e.print();
	f.print();
	printf("e = ? ");
	e.scan();
	printf("f = ? ");
	f.scan();
// a + b を出力
	printf("e + f = ");
	(e.add(f)).print();
	printf("\n");
// a + (2, 1) を出力
	printf("e + (2,1) = ");
	(e.add(Vector2(2, 1))).print();
	printf("\n");

	printf("e - f =");
	(e.sub(f)).print();
	printf("\n");
	return 0;
	}
