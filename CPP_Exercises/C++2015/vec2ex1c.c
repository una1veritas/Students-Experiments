/*
 * vec2ex1c.c - 2次元ベクトル型(C版)テストプログラム
 *	作者: (あなたの名前); 日付: (完成した日付)
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
	printf("x, y ? ");
	scanv2(&a);
	printf("x, y ? ");
	scanv2(&b);
	printf("\na = ");
	printv2(a);
	printf("\nb = ");
	printv2(b);
	printf("\n\n");
/* a + b を出力 */
	printf("a + b = ");
	printv2(addv2(a, b));
	printf("\n");
/* a + (2, 1) を出力 */
	printf("a + (2,1) = ");
	printv2(addv2(a, initv2(2, 1)));
	printf("\n");

	return 0;
}
