#include <stdio.h>
#include "e05.h"

//
// main() - テストプログラム
//
int main(void)
{
	Vector2 a, b;
	Matrix22 a1, b1;

/*Vector2*/

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
// nai を出力;
	printf("aとbの内積= %lf" ,a.nai(b));
	printf("\n");
// gai を出力;
	printf("aとbの外積= %lf" ,a.gai(b));
	printf("\n");

/*Matrix22 */

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
// a * b を出力
	printf("a * b = ");
	(a1.mul(b1)).print();
	printf("\n");

	return 0;
}
