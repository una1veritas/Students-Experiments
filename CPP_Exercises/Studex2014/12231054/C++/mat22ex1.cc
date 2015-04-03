//
// mat22ex1.cc - 2次行列テストプログラム
//      作者: Kento NOMIYAMA; 日付: 2014.04.10
//

#include <stdio.h>
#include "matrix22.h"

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

	printf("a + b");
	(a.add(b)).print();

	printf("a + (3,5,2,1)");
	(a.add(Matrix22(3,5,2,1))).print();
	
	printf("a - b");
	(a.sub(b)).print();

	printf("a * c");
	(a.mul(c)).print();

	return 0;
	}
