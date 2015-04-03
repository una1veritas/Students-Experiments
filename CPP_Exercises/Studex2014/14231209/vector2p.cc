//
// vector2p.cc - 2�����x�N�g���^(C++��)
//	���: �����@�^�l; ���t: 2014/04/10
//
#include <stdio.h>
#include "vector2p.h"

//
// Vector2::Vector2() - x0, y0 ��^���Ē萔 (x0, y0) �𓾂�R���X�g���N�^
//
Vector2::Vector2(double x0, double y0)
{
	printf("�ďo\n");
	x = x0;
	y = y0;
}

//
//Vector2::Vector2() - �R�s�[�R���X�g���N�^
//
Vector2::Vector2(Vector2 & v)
{
	printf("�R�s�[�R���X�g���N�^\n"); x = v.x;y =v.y;
}


//
// Vector2::add() - ���g�̃x�N�g���ƃx�N�g�� u �Ƃ̘a�����߂�
//
Vector2 Vector2::add(Vector2 u)
{
	Vector2 ret;

	ret.x = x + u.x;
	ret.y = y + u.y;

	return ret;
}

//
//Vector2::sub() - ���g�̃x�N�g���ƃx�N�g�� u �Ƃ̍������߂�
//
Vector2 Vector2::sub(Vector2 u)
{
        Vector2 ret;
  
        ret.x = x - u.x;
        ret.y = y - u.y;

        return ret;
}
//
// Vector2::naiseki() - ���g�̃x�N�g���ƃx�N�g�� u �Ƃ̓��ς����߂�
//
double::Vector2::naiseki(Vector2 u)
{
        

       return x*u.x + y*u.y;

}
//
//Vector2::gaiseki() - ���g�̃x�N�g���ƃx�N�g�� u �Ƃ̊O�ς����߂�
//
double::Vector2::gaiseki(Vector2 u)
{
 
  
  return x*u.y - u.x*y;

}
//
// Vector2::scan() - �x�N�g���̒l��W�����͂��玩�g�ɓ��͂���
//
void Vector2::scan(void)
{
	scanf("%lf %lf", &x, &y);
}

//
// Vector2::print() - ���g�̃x�N�g���̒l��W���o�͂ɏo�͂���
//
void Vector2::print(void)
{
	printf("( %f %f )", x, y);
}

//
// Matrix22::Matrix22() - x0, x1, x2, x3 ��^����
// �萔 (x0, x1, x2, x3) �𓾂�R���X�g���N�^
//
Matrix22::Matrix22(double x0, double x1, double x2, double x3)
{
	x[0][0]=x0;
	x[0][1]=x1;
	x[1][0]=x2;
	x[1][1]=x3;
}
//
//Matrix22::Matrix22() - �R�s�[�R���X�g���N�^
//
Matrix22::Matrix22(Matrix22 & v){
	x[0][0]=v.x[0][0];
	x[0][1]=v.x[0][1];
	x[1][0]=v.x[1][0];
	x[1][1]=v.x[1][1];
}
//
// Matrix22::add() - ���g�̍s��ƍs�� u �Ƃ̘a�����߂�
//
Matrix22 Matrix22::add(Matrix22 u)
{
	Matrix22 ret;
	ret.x[0][0]=x[0][0]+u.x[0][0];
	ret.x[0][1]=x[0][1]+u.x[0][1];
	ret.x[1][0]=x[1][0]+u.x[1][0];
	ret.x[1][1]=x[1][1]+u.x[1][1];

	return ret;
}

//
// Matrix22::sub() - ���g�̍s��ƍs�� u �Ƃ̍������߂�
//
Matrix22 Matrix22::sub(Matrix22 u)
{
	Matrix22 ret;
	ret.x[0][0]=x[0][0]-u.x[0][0];
	ret.x[0][1]=x[0][1]-u.x[0][1];
	ret.x[1][0]=x[1][0]-u.x[1][0];
	ret.x[1][1]=x[1][1]-u.x[1][1];

	return ret;
}

//
// Matrix22::mul() - ���g�̍s��ƍs�� u �Ƃ̐ς����߂�
//
Matrix22 Matrix22::mul(Matrix22 u)
{
	Matrix22 ret;
	ret.x[0][0]=x[0][0]*u.x[0][0]+x[0][1]*u.x[1][0];
	ret.x[0][1]=x[0][0]*u.x[0][1]+x[0][1]*u.x[1][1];
	ret.x[1][0]=x[1][0]*u.x[0][0]+x[1][1]*u.x[1][0];
	ret.x[1][1]=x[1][0]*u.x[0][1]+x[1][1]*u.x[1][1];

	return ret;
}

//
// Matrix22::scan() - �s��̒l��W�����͂��玩�g�ɓ��͂���
//
void Matrix22::scan(void)
{
	scanf("%lf %lf %lf %lf", &x[0][0], &x[0][1], &x[1][0], &x[1][1]);
}

//
// Matrix22::print() - ���g�̍s��̒l��W���o�͂ɏo�͂���
//
void Matrix22::print(void)
{
	printf("( %f %f %f %f )", x[0][0], x[0][1], x[1][0], x[1][1]);
}
