/*
 *  LittleThinkPlayer.cpp
 *  PlayingCard
 *
 *  Created by 下薗 真一 on 09/04/12.
 *  Modified by Kazutaka Shimada on 09/04/21.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */
#include <iostream>
#include <string>

#include "../Card.h"
#include "../CardSet.h"
#include "../Player.h"
#include "GroupB.h"

bool GroupB::approve(const GameState & gstat) {
	CardSet pile(gstat.pile);

  memoryInsert(pile);
  // memoryには他のプレイヤーが場に出したカードがストックされる
  
  // 自分自身のidは getId() で獲得できる
  // std::cerr << "your information is "<< getName() << " " << getId() << std::endl;

  return true;
  
}

bool GroupB::follow(const GameState & gstat, CardSet & s) {
	CardSet pile(gstat.pile);
  sort();
  searchPair();

  s.clear();

  if(pile.isEmpty()){
    // 最初の手番
    Card temp;
    do{
      // std::cerr << "check1\n";
      inHand().pickup(temp, 0);
      s.insert(temp);
      if(inHand().isEmpty()){
	break;
      }
    } while(inHand()[0].getNumber() == temp.getNumber());
  }
  else{
    if(pile.size() >= 2){
      multiCard(pile, s);
    }
    else{
      // 前回のカードを見る
      Card pileCard = pile[0];
      pileCard.print();
      
      // 弱いカードから出せるか見ていく
      for(int i=0; i < inHand().size(); i++){
	Card handCard = inHand()[i];

	if(myCards == 1 && handCard.isGreaterThan(pileCard)){
	  inHand().pickup(handCard, i);
	  s.insert(handCard);
	  break;
	}

	if(handCard.getNumber() == handGreatestCard.getNumber()){
	  if(handCard.isGreaterThan(fieldGreatestCard) ||
	     handCard.getNumber() == fieldGreatestCard.getNumber()){
	    if(handCard.isGreaterThan(pileCard)){
	      inHand().pickup(handCard, i);
	      s.insert(handCard);
	      break;
	    }
	  }
	}
	else{
	  if(!pairFlag[i] && handCard.isGreaterThan(pileCard)){
	    inHand().pickup(handCard, i);
	    s.insert(handCard);
	    break;
	  }
	  if(myCards <= 6 && handCard.isGreaterThan(pileCard)){
	    inHand().pickup(handCard, i);
	    s.insert(handCard);
	    break;
	  }
	}
      }
    }
  }

  memoryInsert(s);

  if(inHand().isEmpty()){
    init();
  }

  return true;
}

// こいつは使ってない
bool GroupB::multiCard(CardSet & s)
{
  for(int i=0; i < inHand().size(); i++){
    if(pairFlag[i]){
      Card c;
      do{
	inHand().pickup(c, i);
	s.insert(c);
      } while(inHand()[i].getNumber() == c.getNumber());
      return true;
    }
  }

  return false;
}

bool GroupB::multiCard(CardSet & pile, CardSet & s)
{
  int pileSize = pile.size();
  Card pileCard = pairRank(pile);

  CardSet temp;

  for(int i=0; i < inHand().size(); i++){
    if(pairFlag[i] && 
       inHand()[i].isGreaterThan(pileCard) &&
       inHand()[i].getNumber() != handGreatestCard.getNumber()){
      Card c;
      do{
	if(i >= inHand().size()){
	  break;
	}
	inHand().pickup(c, i);
	temp.insert(c);
      } while(inHand()[i].getNumber() == c.getNumber());
      if(temp.size() == pileSize){
	s.insertAll(temp);
	return true;
      }
      //i += (temp.size() - 1);
      inHand().insertAll(temp);
      sort();
      searchPair();
    }
  }

  return false;
}

void GroupB::init()
{
  memory.clear();
  fieldGreatestCard.set(4, 0); // JOKER
}

void GroupB::sort()
{
  int size = inHand().size();
  Card* hand = new Card[size];
  for(int i=0; i < size; i++){
    inHand().pickup(hand[i], 0);
  }

  Card temp;
  for(int i=0; i < size-1; i++){
    for(int j=size-1; j > i; j--){
      if(hand[j-1].isGreaterThan(hand[j])){
	temp = hand[j];
	hand[j] = hand[j-1];
	hand[j-1] = temp;
      }
    }
  }

  for(int i=0; i < size; i++){
    inHand().insert(hand[i]);
  }

  handGreatestCard = hand[size-1];
#ifdef DEBUG
  std::cout << "\nHand Greatest Card : ";
  handGreatestCard.print();
  std::cout << "\n";
  std::cout << "\nsort : ";
  inHand().print();
  std::cout << "\n";
#endif

  delete [] hand;

  // std::cerr << "\nSort End\n";
}

void GroupB::searchPair()
{
  int size = inHand().size();

  if (pairFlag != NULL){
    delete [] pairFlag;
  }
  pairFlag = new bool[size];

  for(int i=0; i < size; i++){
    pairFlag[i] = false;
  }

  for(int i=0; i < size-1; i++){
    if(inHand()[i].getNumber() == inHand()[i+1].getNumber()){
      pairFlag[i] = pairFlag[i+1] = true;
    }
  }
}

int GroupB::searchMemory(int num)
{
  int count = 0;
  for(int i=0; i < memory.size(); i++){
    Card c = memory[i];
    if(c.getNumber() == num){
      count++;
    }
  }

  return count;
}

void GroupB::memoryInsert(CardSet& cards)
{
  memory.insertAll(cards);

  int flag;
  do{
    flag = false;
    if(fieldGreatestCard.isJoker() && 
       searchMemory(fieldGreatestCard.getNumber()) >= 1){
      fieldGreatestCard.set(0, 2);
      flag = true;
      // std::cerr << "Joker is taked out\n";
    }
    else if(searchMemory(fieldGreatestCard.getNumber()) >= 4){
      int rank = fieldGreatestCard.getNumber();
      if(rank == 3){
	break;
      }
      // std::cerr << rank << " is taked out\n";
      if(--rank <= 0){
	rank = 13;
      }
      fieldGreatestCard.set(0, rank);
      flag = true;
    }
  } while(flag);

#ifdef DEBUG
  std::cout << "\nField Greatest Card : ";
  fieldGreatestCard.print();
  std::cout << "\n";
#endif
}

Card GroupB::pairRank(CardSet &pile)
{
  if(pile.size() > 1)
    if(pile[0].isJoker())
      return pile[1];

  return pile[0];
}
