//
// babanuki1.cc - �o�o�����v���O����(C++��)
//	���: �����@�^�l; ���t: 2014/04/24
//
#include "babastate.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>

//
// main() - �o�o�����v���O����
//
int main(void)
{
	time_t seed;
// ���������̃V�[�h
// (�f�o�b�O���œ��������𔭐������������́C�ȉ���2�s����������)
	time(&seed);
	srand(seed);

	BabaState bs;	// �o�o�����̏��

	bs.print();

// �I�������ɂȂ�܂ŃJ�[�h������������
	int from, to = 0; // to �� from ����J�[�h�����
	while(1) {
	// ���� from �� to ��T��
		for(to = (to + 1) % BabaState::numplayer;
		 bs.isfinished(to);
		 to = (to + 1) % BabaState::numplayer)
			;
		for(from = (to + BabaState::numplayer - 1) % BabaState::numplayer;
		 bs.isfinished(from);
		 from = (from + BabaState::numplayer - 1) % BabaState::numplayer)
			;
// �I������
		if(from == to)	// �Q�[���̏I������(1�l�ȊO�͏オ����)
			break;
// from ���� to �ɃJ�[�h���n��
		bs.move(from, to);
		std::cout << "# �v���[�� " << from << " ����v���[�� " << to << " �ɃJ�[�h���n��"<< std::endl;
		bs.print();
	}

	std::cout << std::endl << "### FINISHED ###" << std::endl;

	return 0;
}
