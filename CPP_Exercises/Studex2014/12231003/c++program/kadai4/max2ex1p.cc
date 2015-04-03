// max2ex1p.cc - 2次正方行列型テストプログラム
//	作者: (市川　舞); 日付: (2014/04/17)
#include <stdio.h>
#include "matrix2p.h"

// main() - テストプログラム
int main(void)
{
  Matrix2 a,b;

// A, B を入力
	printf("A = ? ");
	a.scan();
	printf("B = ?");
	b.scan();
// A + B を出力
	printf("A + B = \n");
	(a.add(b)).print();
	printf("\n");
// A + {{1,2},{3,4}} を出力
	printf("A + (1,2,3,4) = \n");
	(a.add(Matrix2(1,2,3,4))).print();
	printf("\n");
// A - B を出力
	printf("A - B = \n");
	(a.sub(b)).print();
	printf("\n");
// A * B を出力
	printf("A * B = \n");
	(a.mul(b)).print();
	printf("\n");
	return 0;
}
