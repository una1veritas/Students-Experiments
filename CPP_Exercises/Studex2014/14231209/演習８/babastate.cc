//
// babastate.cc - �o�o�����̏�Ԍ^(C++��)
//	���: �����@�^�l; ���t: 2014/04/24
//
#include "babastate.h"
#include <iostream>

//
// BabaState::reset() - ���Z�b�g(�ŏ��ɃJ�[�h��z������Ԃɂ���)
//
void BabaState::reset(void)
{
  // �e�v���[���̃t���O�𖢗��ɂ��C���������ɂ���
  for(int i = 0; i < numplayer; i++) {
    hand[i].makeempty();
  }
  // �f�b�N(1�Z�b�g)�̃J�[�h�� initcs �ɓ����
  CardSet initcs;
  initcs.makedeck();
  // �����Ȃ�܂� initcs ���疳��ׂɃJ�[�h���Ƃ� plr �Ԃ̃v���[���ɔz��
  int plr = 0;	// �z�鑊��̃v���[��
  Card c;		// �z��J�[�h
  while(!initcs.pickup(&c)) {
    // ���ɔz��ꂽ�J�[�h�Ɠ����ԍ��������
    // ���x�̃J�[�h�Ɗ��ɔz��ꂽ�J�[�h�Ƃ̗������̂Ă�
    // ������΍��x�̃J�[�h�������̎�ɉ�����
    if(hand[plr].remove(c.gnumber()))
      hand[plr].insert(c);
    // plr �����̃v���[���ɂ���
    if(++plr >= numplayer)
      plr = 0;
  }
}

// 
// BabaState::move() - to �Ԃ̃v���[���� from �Ԃ̃v���[������J�[�h�����
// (true: ���s; false: ����)
//
bool BabaState::move(int from, int to){
	Card c;//�������J�[�h
	if(hand[from].pickup(&c))//from����ꖇ�����_���ɔ���
		return true;//�G���[
		// ��D�Ɠ����ԍ��ł����
    // ��������J�[�h���܂ݗ������̂Ă�
    // ������΍��̃J�[�h�������̎�ɉ�����
	if(hand[to].remove(c.gnumber()))//����Ȃ������ꍇ
		hand[to].insert(c);//���炤
	return false;//����
}

//
// BabaState::print() - ���g�̏�Ԃ�W���o�͂ɏo�͂���
//
void BabaState::print(void)
{
  for(int i = 0; i < numplayer; i++) {
    std::cout <<"PLAYER " << i;
    hand[i].print();
  }
}
