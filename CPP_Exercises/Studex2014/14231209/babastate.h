//
// babastate.h - �o�o�����̏�Ԍ^(C++��)
//	���: �����@�^�l; ���t: 2014/04/24
//
#ifndef BABASTATE_H
#define BABASTATE_H

#include "cardset.h"

//
// BabaState - �o�o�����̏�Ԍ^
//
class BabaState {
// ��`�E�錾
public:
	static const int numplayer = 5;	// �v���[����
// �����o�ϐ�
private:
	CardSet hand[numplayer];  // �e�v���[���̎�����
// �����o�֐�
public:
	BabaState(void)	{ reset(); }
		// �f�t�H���g�R���X�g���N�^(�����l�̓J�[�h��z�������)
	void reset(void);
		// ���Z�b�g(�ŏ��ɃJ�[�h��z������Ԃɂ���)
	bool isfinished(int plr)	{ return hand[plr].isempty(); }
		// plr �Ԃ̃v���[�����オ����(�I������)���ۂ��̔���
		// (true: �オ����; false: ����)
	bool move(int from, int to);
		// to �Ԃ̃v���[���� from �Ԃ̃v���[������J�[�h�����
		// (true: ���s; false: ����)
	void print(void);
		// ���g�̏�Ԃ�W���o�͂ɏo�͂���
};

#endif
