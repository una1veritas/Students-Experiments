/*
 *  GroupI.cpp
 *  PlayingCard
 *
 *  Created by iwasaki satouru on 13/05/02.
 *  Modified by Kazutaka Shimada on 09/04/21.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#include <iostream>
#include <string>

#include "Card.h"
#include "CardSet.h"
#include "Player.h"
#include "GroupI.h"

GroupI::GroupI(const char * s) : Player(s) {}

bool GroupI::approve(CardSet & pile, int numCards[]) {
  memory.insert(pile);
  // memoryには他のプレイヤーが場に出したカードがストックされる 
  
  // 自分自身のidは getId() で獲得できる　
   std::cout << "your information is "<< getName() << " " << getId() << std::endl;

  for (int i=0; numCards[i] != 99; i++){
    // numCardsには自分を含めたそれぞれの持ち札の数が格納されている
    // 配列の最後には終端検知のため"99"という値が入っている
    // numCardsの添字はプレイヤーのidを表す
     std::cout << i << " " << numCards[i] << std::endl;
  }

  return true;
  
}

bool GroupI::follow(CardSet & pile, CardSet & s) {
        CardSet same;
	Card tmp;
	int loc = -1,i = 0,f=0,a=4;

	s.makeempty();

	sort(inHand());

	if(pile.size() == 1) { // 山札が１
	  tmp = pile.at(pile.size() - 1);
	  while(inHand().size() > i) {
	    loc = i;
	    if (inHand().at(loc).isGreaterThan(tmp)) {
	      f = 1;
	      break;
	    }
	    i++;
	  }
	}
	else if(pile.size() > 1) { // 山札が２以上
	  tmp = pile.at(pile.size() - 1);
	  while(inHand().size() > i) {
	    loc = i;
	    if (inHand().at(loc).isGreaterThan(tmp)) {
	      same.makeempty();
	      same.insert(inHand().at(loc));
	      if(cardSetOfSameRanks1(same, pile.size())) {
		f = 1;
		break;
	      }
	    }
	    i++;
	  }
	}
	else { // 山札無し
	  while(a > 1) {
	    while(inHand().size() > i) {
	      loc = i; 
	      same.makeempty();
	      same.insert(inHand().at(loc));
	      if(cardSetOfSameRanks1(same,a)) {
		f = 1;
		break;
	      }
	      i++;
	    }
	    if(cardSetOfSameRanks1(same,a)) {
	      break;
	    }
	    i = 0;
	    a--;
	  }
	  if(f == 0 || (inHand().at(0).getrank() >= 3 && inHand().at(0).getrank() <= 7)) {
	    loc = 0;
	    f = 1;
	  }
	}
	if(f) {
	  inHand().pickup(&tmp, loc); // anyway, choose a card.
	  // hand は Player の private な変数なので直接さわれないことに注意
	  s.insert(tmp);
	  // the card idential to tmp is already removed from the hand. 
	  cardSetOfSameRanks(s, pile.size());
	  // 複数枚のカードを探す関数
	  
	}
	return true;
}

bool GroupI::sort(CardSet & s) {
  int size = s.size();
  Card c[size], temp;

  for(int i = 0; i < size; i++) {
    c[i] = s.at(i);
  }
  for(int i = 0; i < size - 1; i++) {
    for(int j = i + 1; j < size ; j++) {
      if(c[i].isGreaterThan(c[j])){
	temp = c[i];
	c[i] = c[j];
	c[j] = temp;
      }
    }
  }
  for(int i = 0; i < size; i++) {
    inHand().remove(c[i]);
  }
  for(int i = 0; i < size; i++) {
    inHand().insert(c[i]);
  }

  return true;
  }

bool GroupI::cardSetOfSameRanks(CardSet & s, int size){

  int i =0,j=0,rank = s.at(0).getrank();
  Card tmp;
  if(size != 1)
    while(j < 4) {
      while(inHand().size() > i) {
	if (rank == inHand().at(i).getrank()){
	  inHand().pickup(&tmp, i); 
	  s.insert(tmp);
	  break;
	}
	i++;
      }
      if(s.size() == size)
	return true;
      j++;
    }

  return false;
}

bool GroupI::cardSetOfSameRanks1(CardSet & s, int size){

  int i =0,rank = s.at(0).getrank(),r = 0;

      while(inHand().size() > i) {
	if (rank == inHand().at(i).getrank()){
	  r++;
	  if(r == size)
	    return true;
	}
	i++;
      }

  return false;
}

/*
1 25
2 21
3 6
4 4
5 4

TA
1 33
2 31
3 27
4 34
5 33
 */
