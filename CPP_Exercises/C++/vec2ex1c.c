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
	struct vector2 a, b, c;
	char tmp[64];

/* a, b を入力 */
	printf("a = (x, y) ? ");
	fgets(tmp, 63, stdin);
	a = vector2scan(tmp);
	printf("b = (x, y) ? ");
	fgets(tmp, 63, stdin);
	b = vector2scan(tmp);
	vector2toString(tmp, a);
	printf("\n\na = %s\n", tmp);
	printf("b = %s\n", vector2toString(tmp, b)); /* このようにも書ける. */
/* a + b を出力 */
	printf("a + b = ");
	c = vector2add(a, b);
	printf("%s\n\n", vector2toString(tmp, c));
/* a + (2, 1) を出力 */
	printf("a + (2,1) = ");
	c = vector2add(a, vector2init(2, 1));
	printf("%s\n", vector2toString(tmp, c));
	return 0;
}
