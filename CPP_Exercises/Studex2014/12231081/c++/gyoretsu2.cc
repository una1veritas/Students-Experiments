//
//
#include <stdio.h>
#include "gyoretsu.h"

//
// main() - テストプログラム
//
int main(void)
{
	Matrix22 a, b;

// a, b を入力
	printf("a[][] = ? ");
	a.scan();
	printf("b[][] = ? ");
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
	(a.mul(b)).print();
	printf("\n");

	return 0;
}
