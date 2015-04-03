//
// matex1.cc - 2次正方行列型
// 作者: 福田真実; 日付: 4/28
//
#include <stdio.h>
#include "matrix.h"


int main(void) {
	Matrix a, b;

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
// a・(2,1,1,2) を出力
	printf("a・(2,1,1,2) = ");
	(a.mul(Matrix(2,1,1,2))).print();
	printf("\n");

	return 0;
}
