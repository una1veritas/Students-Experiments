/*
 * vec2ex1c.c - 2次元ベクトル型(C版)テストプログラム
 *	作者: 長濱彰秀 日付: 4月10日
 */
#include <stdio.h>
#include "vector2c.h"

/*
 * main() - テストプログラム
 */
int main(void)
{
	struct vector2 a, b;

/* a, b を入力 */
	printf("a = ? ");
	scanv2(&a);
	printf("b = ? ");
	scanv2(&b);
/* a + b を出力 */
	printf("a + b = ");
	printv2(addv2(a, b));
	printf("\n");
/* a - b を出力 */
	printf("a - b = ");
	printv2(subv2(a, b));
	printf("\n");
/* a + (2, 1) を出力 */
	printf("a + (2,1) = ");
	printv2(addv2(a, constv2(2, 1)));
	printf("\n");

	return 0;
}
