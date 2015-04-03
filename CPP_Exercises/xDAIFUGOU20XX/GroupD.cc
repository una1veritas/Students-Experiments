/*
 * GroupD.cpp
 *  PlayingCard
 *
 *  Created by GroupD on 13/05/16.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#include <iostream>
#include <string>

#include "Card.h"
#include "CardSet.h"
#include "Player.h"
#include "GroupD.h"

GroupD::GroupD(const char * s) : Player(s) {}

bool GroupD::approve(CardSet & pile, int numCards[]) {
  memory.insert(pile);
  // memoryには他のプレイヤーが場に出したカードがストックされる 
  
  // 自分自身のidは getId() で獲得できる　
   std::cout << "Demo: Called GroupD::approve() for '"<< getName() << "', id = " << getId() << ". " << std::endl;

   std::cout << "Demo: Player's cards in hands: " << std::endl;
  for (int i=0; numCards[i] != 99; i++){
    // numCardsには自分を含めたそれぞれの持ち札の数が格納されている
    // 配列の最後には終端検知のため"99"という値が入っている
    // numCardsの添字はプレイヤーのidを表す
     std::cout << "ID " << i << ": " << numCards[i] << std::endl;
  }
  std::cout << std::endl;

  return true;
  
}

bool GroupD::follow(CardSet & pile, CardSet & s) {
  int i,k = 0,lib,address=0,count[14];
  Card tmp;
  s.makeempty();
  if(pile.isempty()){
    if(cardSetOfSameRanks(s,-1,4)){
    }
    else if(cardSetOfSameRanks(s,-1,3)){
    }
    else if(cardSetOfSameRanks(s,-1,2)){
    }
    else{

      for(i = 0;i < inHand().size(); i++){
	if(inHand().at(address).isGreaterThan(inHand().at(i)))
	  address = i;		
      }
      inHand().pickup(&tmp, address); // anyway, choose a card.
      // hand は Player の private な変数なので直接さわれないことに注意
      s.insert(tmp);
      // the card idential to tmp is already removed from the hand. 
    }
  }
  else {
    if(pile.size() > 1){
      cardSetOfSameRanks(s, pile.at(0).getrank(), pile.size());
    }
    else{
      for(i = 0;i < 14;i++)
	count[i] = 0;
      
      for(i = 0;i < inHand().size(); i++){
	if(!inHand().at(i).isJoker())
	    count[inHand().at(i).getrank()]++;
      }
      for(i = 0;i < inHand().size();i++)
	if(count[inHand().at(i).getrank()] == 1)
	  address = i;

      for(i = 0;i < inHand().size();i++){
       	if(count[inHand().at(i).getrank()] == 1){
	  if(inHand().at(i).isGreaterThan(pile.at(0)) &&
	     inHand().at(address).isGreaterThan(inHand().at(i)) ){
	    address = i;
	    k = 1;
	  }
	  else if(inHand().at(i).isGreaterThan(pile.at(0)) &&
		  (pile.at(0).isGreaterThan(inHand().at(address)) ||
		   inHand().at(address).getrank() == pile.at(0).getrank())) {
	    address = i;
	    k = 1;
	  }
	}
      }
      if(k == 0)
	for(i = 0;i < inHand().size();i++){
	  if(inHand().at(i).isGreaterThan(pile.at(0)) &&
	     inHand().at(address).isGreaterThan(inHand().at(i)) ){
	    address = i;
	  }
	  else if(inHand().at(i).isGreaterThan(pile.at(0)) &&
		  pile.at(0).isGreaterThan(inHand().at(address))) {
	    address = i;
	  }
      }
      inHand().pickup(&tmp, address);
 // anyway, choose a card.
      // hand は Player の private な変数なので直接さわれないことに注意
      s.insert(tmp);
      // the card idential to tmp is already removed from the hand. 
    }
  }
  
  //	cardSetOfSameRanks(s, pile.size());
  // たとえば、複数枚のカードを探す関数。ただしこの関数は未実装。
  // 現状ではこの follow は Player.cc のものと等価
  return true;
}


bool GroupD::cardSetOfSameRanks(CardSet &s,int x, int y){
  int i=0,j,k=0, address,count[14];
  Card tmp;
  for(i = 0;i < 14;i++)
    count[i] = 0;
  
  for(j = 0;j < inHand().size(); j++){
    if(!inHand().at(j).isJoker())
      count[inHand().at(j).getrank()]++;
  }
  
  for(i = 3;i < 14 && k == 0; i++){
    if(count[i] == y && i > x)
      k = i;
  }
  if(k > 0){
    for(address = 0; address < inHand().size(); address++){
      if(inHand().at(address).getrank() == k){
	inHand().pickup(&tmp, address);
	s.insert(tmp);
	address--;
      }
    }

    return true;
  }
  
  return false;
  
};


