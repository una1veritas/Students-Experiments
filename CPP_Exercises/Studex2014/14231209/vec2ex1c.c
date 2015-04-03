/*
 * vec2ex1c.c - 2�����x�N�g���^(C��)�e�X�g�v���O����
 *	���: �����@�^�l; ���t: 2014/04/10
 */
#include <stdio.h>
#include "vector2c.h"

/*
 * main() - �e�X�g�v���O����
 */
int main(void)
{
	struct vector2 a, b;

/* a, b ����� */
	printf("a = ? ");
	scanv2(&a);
	printf("b = ? ");
	scanv2(&b);
/* a + b ���o�� */
	printf("a + b = ");
	printv2(addv2(a, b));
	printf("\n");
/* a - b ���o�� */
	printf("a - b = ");
	printv2(subv2(a,b));
	printf("\n");
/* a + (2, 1) ���o�� */
	printf("a + (2,1) = ");
	printv2(addv2(a, constv2(2, 1)));
	printf("\n");
/* a - (2, 1) ���o�� */
	printf("a - (2,1) = ");
	printv2(subv2(a, constv2(2, 1)));
	printf("\n");

	return 0;
}
