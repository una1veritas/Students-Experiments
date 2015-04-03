// vec2ex1p.cc - 2次元ベクトル型と2次正方行列型テストプログラム
//	作者: (市川　舞); 日付: (2014/04/17)
#include <stdio.h>
#include "vector2p.h"
#include "matrix2p.h"

// main() - テストプログラム
int main(void)
{
  Vector2 a,b;
  Matrix2 c,d;

// a, b を入力(ベクトル)
	printf("a = ? ");
	a.scan();
	printf("b = ? ");
	b.scan();
// C, D を入力(行列)
	printf("C = ? ");
	c.scan();
	printf("D = ?");
	d.scan();
// a + b を出力
	printf("a + b = \n");
	(a.add(b)).print();
	printf("\n");
// C + D を出力
	printf("C + D = \n");
	(c.add(d)).print();
	printf("\n");
// a + (2, 1) を出力
	printf("a + (2,1) = ");
	(a.add(Vector2(2,1))).print();
	printf("\n");
// C + {{1,2},{3,4}} を出力
	printf("C + {{1,2},{3,4}} = \n");
	(c.add(Matrix2(1,2,3,4))).print();
	printf("\n");
// a - b を出力
	printf("a - b = ");
	(a.sub(b)).print();
	printf("\n");
// C - D を出力
	printf("C - D = \n");
	(c.sub(d)).print();
	printf("\n");
// C * D を出力
	printf("C * D = \n");
	(c.mul(d)).print();
	printf("\n");
	return 0;
}
