/*
 * vector2c.c - 2�����x�N�g���^(C��)
 *	���: �����@�^�l; ���t: 2014/04/10
 */
#include <stdio.h>
#include "vector2c.h"

/*
 * constv2() - x0, y0 ��^���āC�萔 (x0, y0) �𓾂�
 */
struct vector2 constv2(double x0, double y0)
{
	struct vector2 ret;

	ret.x = x0;
	ret.y = y0;

	return ret;
}

/*
 * addv2() - �x�N�g�� u �� v �̘a u + v �����߂�
 */
struct vector2 addv2(struct vector2 u, struct vector2 v)
{
	struct vector2 ret;

	ret.x = u.x + v.x;
	ret.y = u.y + v.y;

	return ret;
}
/*
 * subv2() - �x�N�g��u��v�̍� u - v�����߂�
 */
struct vector2 subv2(struct vector2 u,struct vector2 v)
{
        struct vector2 ret;
  
        ret.x = u.x - v.x;
        ret.y = u.y - v.y;

        return ret;
}  
/*
 * scanv2() - �x�N�g���̒l��W�����͂��� *pu �ɓ��͂���
 */
void scanv2(struct vector2* pu)
{
	scanf("%lf %lf", &pu->x, &pu->y);
}

/*
 * printv2() - �x�N�g�� u �̒l��W���o�͂ɏo�͂���
 */
void printv2(struct vector2 u)
{
	printf("( %f %f )", u.x, u.y);
}
