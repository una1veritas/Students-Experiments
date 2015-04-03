//
//      演習５
//	作者: 諸正梨乃; 日付: 4/24
//
#include <stdio.h>
#include "ensyu5.h"

//
// main() - テストプログラム
//
int main(void)
{
	Vector2 a, b;
	Matrix22 j, k; 

// a, b を入力
	printf("a = ? ");
	a.scan();
	printf("b = ? ");
	b.scan();
	printf("ok.");
// a + b を出力
	printf("a + b = ");
	(a.add(b)).print();
	printf("\n");
// a - b を出力
	printf("a - b = ");
	(a.sub(b)).print();
	printf("\n");

// a + (2, 1) を出力
	printf("a + (2,1) = ");
	(a.add(Vector2(2, 1))).print();
	printf("\n");
	printf("2次元ベクトル型終わり\n");

// a, b を入力
	printf("j[][] = ? ");
	j.scan();
	printf("k[][] = ? ");
	k.scan();
// a + b を出力
	printf("j + k = ");
	(j.add(k)).print();
	printf("\n");
// a - b を出力
	printf("j - k = ");
	(j.sub(k)).print();
	printf("\n");

// a * b を出力
	printf("j * k = ");
	(j.mul(k)).print();
	printf("\n");

	printf("2次正方行列型終わり\n");
	
	return 0;
}
