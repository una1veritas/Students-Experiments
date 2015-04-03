//
// vector2p.h - 2�����x�N�g���^(C++��)
//	���: �����@�^�l; ���t: 2014/04/10
//
#ifndef VECTOR2P_H
#define VECTOR2P_H

//
// Vector2 - 2�����x�N�g���^
//
class Vector2 {
// �����o�ϐ�
private:
	double x;	// x�l
	double y;	// y�l
// �����o�֐�
public:
	Vector2(void)	{printf("�f�t�H���g�R���X�g���N�^\n");x = 0;y = 0; }
		// �f�t�H���g�R���X�g���N�^(�����l�s��)
	Vector2(Vector2 & v);
		// �R�s�[�R���X�g���N�^
	Vector2(double x0, double y0);
		// x0, y0 ��^���Ē萔 (x0, y0) �𓾂�R���X�g���N�^
	Vector2 add(Vector2 u);
		// ���g�̃x�N�g���ƃx�N�g�� u �Ƃ̘a�����߂�
	Vector2 sub(Vector2 u);
		// ���g�̃x�N�g���ƃx�N�g�� u �Ƃ̍������߂�
	double naiseki(Vector2 u);
	        //���g�̃x�N�g���ƃx�N�g�� u �Ƃ̓��ς����߂�
	double gaiseki(Vector2 u);
	        //���g�̃x�N�g���ƃx�N�g�� u �Ƃ̊O�ς����߂�
	void scan(void);
		// �x�N�g���̒l��W�����͂��玩�g�ɓ��͂���
	void print(void);
		// ���g�̃x�N�g���̒l��W���o�͂ɏo�͂���
};

class Matrix22 {
// �����o�ϐ�
	private:
	double x[2][2];
// �����o�֐�
	public:
	Matrix22(void) {
		x[0][0]=0;
		x[0][1]=0;
		x[1][0]=0;
		x[1][1]=0;
}
		// �f�t�H���g�R���X�g���N�^(�����l�s��)
	Matrix22(double x0, double x1, double x2, double x3);
		// x0, x1, x2, x3 ��^���Ē萔 (x0, x1, x2, x3) �𓾂�R���X�g���N�^
	Matrix22(Matrix22 & m);
		//�R�s�[�R���X�g���N�^
	Matrix22 add(Matrix22 u);
		// ���g�̍s��ƍs�� u �Ƃ̘a�����߂�
	Matrix22 sub(Matrix22 u);
		// ���g�̍s��ƍs�� u �Ƃ̍������߂�
	Matrix22 mul(Matrix22 u);
		// ���g�̍s��ƍs�� u �Ƃ̐ς����߂�
	void scan(void);
		// �s��̒l��W�����͂��玩�g�ɓ��͂���
	void print(void);
		// ���g�̍s��̒l��W���o�͂ɏo�͂���
};
#endif
