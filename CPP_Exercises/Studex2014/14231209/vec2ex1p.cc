//
// vec2ex1p.cc - 2�����x�N�g���^(C++��)�e�X�g�v���O����
//	���: �����@�^�l; ���t: 2014/04/10
//
#include <stdio.h>
#include "vector2p.h"

//
// main() - �e�X�g�v���O����
//
int main(void)
{
	Vector2 a, b,e(2,1);
	printf("a=");
	a.print();
	printf("b=");
	b.print();
	printf("���K�R�i�P�j\n");

	printf("\n");

// a, b �����
	printf("a = ? ");
	a.scan();
	printf("b = ? ");
	b.scan();
// a + b ���o��
	printf("a + b = ");
	(a.add(b)).print();
	printf("\n");
// a - b ���o��
	printf("a - b = ");
	(a.sub(b)).print();
	printf("\n");
// a �E b ���o��
	printf("a �E b = %f",a.naiseki(b));
	printf("\n");
// a �~ b ���o��
	printf("a �~ b = %f",a.gaiseki(b));
	printf("\n");
// a + (2, 1) ���o��
	printf("a + (2,1) = ");
	(a.add(e)).print();
	printf("\n");
//a - (2, 1) ���o��
	printf("a - (2,1) = ");
	(a.sub(e)).print();
	printf("\n\n");

// ���K�R(�R)
	printf("���K�R(�R)�@�R�s�[\n");
	Vector2 c(a),d;
	d=b;
	printf("c(a):");
	c.print();
	printf(" d=b:");
	d.print();

	printf("\n");

		
	Matrix22 p, q;
	
// p, q �����
	printf("p = ? ");
	p.scan();
	printf("q = ? ");
	q.scan();
	
// p + q ���o��
	printf("p + q = ");
	(p.add(q)).print();
	printf("\n");
	
// p - q ���o��
	printf("p - q = ");
	(p.sub(q)).print();
	printf("\n");

// p * q ���o��
	printf("p * q = ");
	(p.mul(q)).print();
	printf("\n");
	
	printf("\n");


	return 0;
}
