/*
 * vector2c.h - 2�����x�N�g���^(C��)
 *	���: �����@�^�l; ���t: 2014/04/10
 * [����] �ȍ~�̉��K�ł́C��L��K�؂ɏ��������邱��
 */
#ifndef VECTOR2C_H
#define VECTOR2C_H

/* �f�[�^��`�E�錾 */
struct vector2 { /* 2�����x�N�g���^ */
	double x;	/* x�l */
	double y;	/* y�l */
};

/* �v���g�^�C�v�錾 */
struct vector2 constv2(double x0, double y0);
	/* x0, y0 ��^���āC�萔 (x0, y0) �𓾂� */
struct vector2 addv2(struct vector2 u, struct vector2 v);
	/* �x�N�g�� u �� v �̘a u + v �����߂� */
struct vector2 subv2(struct vector2 u, struct vector2 v);
	/* �x�N�g�� u �� v �̍� u - v �����߂� */
void scanv2(struct vector2* pu);
	/* �x�N�g���̒l��W�����͂��� *pu �ɓ��͂��� */
void printv2(struct vector2 u);
	/* �x�N�g�� u �̒l��W���o�͂ɏo�͂��� */

#endif
