//
// cardset.cc - �g�����v�J�[�h�̏W���^(C++��)
//	���: �����@�^�l; ���t: 2014/04/17
//
#include <iostream>
#include <stdio.h>
#include "cardset.h"

//
// Card::scan() - �W���o�͂��玩�g�ɓ��͂���(true: �G���[; false: ����I��)
//
bool Card::scan(void)
{
  char buf[BUFSIZ];
  // initialize static const variable
  const int maxcard=53;
  const char * suitnames[] = {
  		"spade",
  		"diamond",
  		"heart",
  		"club",
  		"joker"
  };

  // 4�g�̂����ꂩ�Ȃ�ԍ������͂���
/*  if(scanf("%s", buf) < 1)
    return true;
  for(int s = SUIT_SPADE; s <= SUIT_CLUB; s++)
    if(!strcmp(buf, suitnames[s])) {
      suit = s;
      if(scanf("%d", &number) < 1)
	return true;
      if(number < 1 || number > 13)
	return true;
      return false;
    }

	
  // joker �͂��̂܂�(number �� 0 �Ƃ���)
  if(!strcmp(buf, "joker")) {
    suit = SUIT_JOKER;
    number = 0;
    return false;
  }
 */
    if(scanf("%s", buf) < 1)
    return true;
  for(int s = SUIT_SPADE; s <= SUIT_CLUB; s++)
    if(!strcmp(buf, suitnames[s])) {
      int tmp;
	  number = s*13;
      if(scanf("%d", &tmp) < 1)
	return true;
      if(number < 1 || tmp > 13){
			  number+=tmp-1;
			  return true;
	  }
      return false;
    }
	
  // joker �͂��̂܂�(number �� 52 �Ƃ���)
  if(!strcmp(buf, "joker")) {
    
    number = maxcard-1;
    return false;
  }
  

  return true;	// �G���[
}

//
// Card::print() - ���g�̒l��W���o�͂ɏo�͂���
//
void Card::print(void)
{
  char* suitname[] = { "spade", "diamond", "heart", "club" };
/*  
  if(suit < SUIT_JOKER)
    printf("[%s %d]", suitname[suit], number);
  else if(suit == SUIT_JOKER)
    printf("[joker]");
	*/
  
  if(number < 52)
    printf("[%s %d]", suitname[number/13], number%13+1);
  else if(number == 52)
    printf("[joker]");

}



//
// CardSet::locate() - �����ł� target �̃J�[�h�̈ʒu��Ԃ�(-1: �Ȃ�)
//
int CardSet::locate(Card target)
{
  for(int i = 0; i < numcard; i++)
    if(target.equal(cdat[i]))
      return i;
  
  return -1;	// ������Ȃ�����
}

//
// CardSet::locate() - �����Ő����� num �̃J�[�h�̈ʒu��Ԃ�(-1: �Ȃ�)
//
int CardSet::locate(int number)
{
	if(number!=52){
  for(int i = 0; i < numcard; i++)
    if(number%13 == cdat[i].gnumber()%13)
      return i;
		}
  return -1;	// ������Ȃ�����
}


 /* for(int i = 0; i < numcard; i++)
    if(number == cdat[i].gnumber())
      return i;
  
  return -1;	// ������Ȃ�����*/


//
// CardSet::makedeck() - ���g�ɑS����(maxnumcard ����)�J�[�h������
//
void CardSet::makedeck(void)
{
  Card c;
  int suit, num;
      for(int i = 0; i <53 ; i++) {
      c.set(i);
      insert(c);
    }
 /* 
  for(suit = Card::SUIT_SPADE; suit <= Card::SUIT_CLUB; suit++)
    for(num = 1; num <= 13; num++) {
      c.set(suit, num);
      insert(c);
    }
  c.set(Card::SUIT_JOKER, 0);
  insert(c);*/
}

//
// CardSet::pickup() - ���g���� targetpos ���ڂ̃J�[�h������ *ret �ɕԂ�
//	targetpos �� -1 �̂Ƃ��̓����_���ɑI��(true: ���s; false: ����)
//
bool CardSet::pickup(Card* ret,int targetpos ){
	
  if(numcard == 0)
    return true;
  if(targetpos < 0)
    targetpos = rand() % numcard;
  else
    targetpos %= numcard;
  
  *ret = cdat[targetpos];

  for(int i=targetpos;i<numcard;i++){
	  cdat[i]=cdat[i+1];
  }
  --numcard;
  remove(*ret); // remove() ������ɃR�����g���O��
  
  return false;
}

//
// CardSet::insert() - ���g�� newcard �̃J�[�h������(true: ���s; false: ����)
//
bool CardSet::insert(Card newcard)
{
  if(locate(newcard) >= 0)
    return true;	// ���ɂ���
  // �Ō�ɒǉ�
  cdat[numcard] = newcard;
  numcard++;
  
  return false;
}



bool CardSet::remove(Card target)
{
		int pos=locate(target);
	if(pos < 0)
		return true;	// ����
	cdat[pos]=cdat[numcard-1];
	numcard--;
	return false;

}
bool CardSet::remove(int num)
{
	int pos=locate(num);
	if(pos < 0)
		return true;	// ����
	cdat[pos]=cdat[numcard-1];
	numcard--;
	return false;

}


//
// CardSet::print() - ���g�̏�Ԃ�W���o�͂ɏo�͂���
//
void CardSet::print(void)
{
  printf("((CARDSET))\n");
  if(numcard == 0) {
    printf("\tno card\n");
    return;
  }
  for(int i = 0; i < numcard; i++) {
    printf("\t");
    cdat[i].print();
    printf("\n");
  }
}


