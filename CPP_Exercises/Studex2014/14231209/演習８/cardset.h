//
// cardset.h - �g�����v�J�[�h�̏W���^(C++��)
//	���: �����@�^�l; ���t: 2014/04/17
//
#ifndef CARDSET_H
#define CARDSET_H

//
// Card - �g�����v�J�[�h�^
//
class Card {
	// �N���X�萔
	// �g�����v�̑g(suit)�̃R�[�h
	public:
	enum {
		SUIT_SPADE,
		SUIT_DIAMOND,
		SUIT_HEART,
		SUIT_CLUB,
		SUIT_JOKER,
		SUIT_NUMBER
	};
	
// �����o�ϐ�
private:
	int suit;	// �g
	int number;	// �ԍ�
	
// �����o�֐�
public:
	// �f�t�H���g�R���X�g���N�^(�����l�s��)
	Card(void)	{ }
	// �g�Ɣԍ���ݒ肷��
/*	void set(int st, int num) {
		suit = st;
		number = num; 
	}
*/
		void set(int CARD) {
		number=CARD; 
	}

	// ���g�� tgt �̃J�[�h�̑g�C�ԍ��������������� (true: ��; false: ��)
	// �f�[�^�Ƃ��ē����I�u�W�F�N�g���ǂ����ł͂Ȃ��D
	bool equal(Card tgt) { 
		return (suit == tgt.suit) && (number == tgt.number); 
	}

	bool isValid() {
		if ( ((SUIT_SPADE <= suit) && (suit <= SUIT_CLUB)) 
			 && (1 <= number && (number <= 13)) )
			return true;
		else if (suit == SUIT_JOKER)
			return true;
		return false;
	}
	
	// �A�N�Z�T
	int gnumber(void) {
		return number;
	}
	
	int gsuit(void)	{
		return suit;
	}

	// �W���o�͂��玩�g�ɓ��͂���(true: �G���[; false: ����I��)
	bool scan(void);
	
	
	// ���g�̒l��W���o�͂ɏo�͂���
	void print(void);
	
};

//
// CardSet - �g�����v�J�[�h�̏W���^
//
class CardSet {
// ��`�E�錾
public:
	const static int maxnumcard = 53;	// �J�[�h����
// �����o�ϐ�
private:
	int numcard;		// ���݂̏W�����̃J�[�h��
	
	Card cdat[maxnumcard];	// �J�[�h�̃f�[�^
// �����o�֐�
private:
	int locate(Card target);
		// �����ł� target �̃J�[�h�̈ʒu��Ԃ�(-1: �Ȃ�)
	int locate(int num);
		// �����Ő����� num �̃J�[�h�̈ʒu��Ԃ�(-1: �Ȃ�)
public:
	CardSet(void)		{ makeempty(); }
		// �f�t�H���g�R���X�g���N�^(�����l��W��)
	void makeempty(void)	{ numcard = 0 ; }
		// ���g����W���ɂ���
	bool isempty(void)	{ return numcard == 0; }
		// ���g����W�����ۂ��̔��� (true: ��; false: ���)
	void makedeck(void);
		// ���g�ɑS����(maxnumcard ����)�J�[�h������
	bool pickup(Card* ret, int targetpos = -1);
		// ���g���� targetpos ���ڂ̃J�[�h������ *ret �ɕԂ�
		// targetpos �� -1 �̂Ƃ��̓����_���ɑI��
		// (true: ���s; false: ����)
	bool insert(Card newcard);
		// ���g�� newcard �̃J�[�h������(true: ���s; false: ����)

	bool remove(Card target);
		// ���g���� target �̃J�[�h������(true: ���s; false: ����)
	bool remove(int num);
		// ���g���琔���� num �ł���J�[�h������(true: ���s; false: ����)
	
	void print(void);
		// ���g�̏�Ԃ�W���o�͂ɏo�͂���
		
};

#endif
