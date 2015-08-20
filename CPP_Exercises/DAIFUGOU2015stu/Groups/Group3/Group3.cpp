/* 
 * File:   Group3.cpp
 * Author: yuuya
 *
 * Created on 2015/05/17, 20:34
 */
#include <iostream>
#include <string>
 
#include "Card.h"
#include "CardSet.h"
#include "Player.h"
#include "Group3.h"
 
// ゲームを始めるにあたり必要な初期化をする．
void Group3::ready() {
  hand.makeEmpty(); //hand.clear();
  memory.makeEmpty(); //memory.clear();
  trump.makeEmpty(); //trump.clear();
  InitArray();
}
 
// カードを出す思考処理を組み込む．
bool Group3::follow(const GameState & gstat, CardSet & cards) {
  CardSet pile(gstat.pile);
  Card tmp;
  int i, count;
 
  cards.makeEmpty();        
  HandOrder();
  PairFlag();
  Check();
 
 
 
  //  std::cout << "( " << hand << " )" << std::endl; // デバック用：表示        
  // デバック用
  /*  printf("pair:( ");
  for(i = 0; i < N; i++)
    printf("%2d", pairlist[i]);
  printf(" )\n");
         
  printf("discard:( ");
  for(i = 0; i < N; i++)
    printf("%2d", discard[i]);
  printf(" )\n");
  */
     
  // 捨て札選択の処理
  switch(pile.size()) {
    // 最初のターンのとき
  case 0:
    // 優先順位: 1枚 > 2枚 > それ以上の枚数　で捨てる
    // 1枚
    for(i = 0; i < hand.size(); i++) {
      if(pairlist[i] == 1) {
	if(Field(hand[i].getNumber(), 3, 8)) {
	  PF_Sort(i);
	  hand.pickup(tmp, i);
	  cardlist[tmp.getSuit()][tmp.getNumber()] = getId() + 1;
	  cards.insert(tmp);
	  return true;
	}
      }
    }
    // 2枚
    for(i = 0; i < hand.size(); i++) {
      if(pairlist[i] == 2 && Field(hand[i].getNumber(), 3, 8)) {
	count = pairlist[i] - 1;
	while(count >= 0) {
	  PF_Sort(i + count);
	  hand.pickup(tmp, i + count);
	  cardlist[tmp.getSuit()][tmp.getNumber()] = getId() + 1;
	  cards.insert(tmp);
	  count--;
	}
	return true;
      }
    }
    // それ以上の枚数
    for(i = 0; i < hand.size(); i++) {
      if(pairlist[i] > 2 && Field(hand[i].getNumber(), 3, 8)) {
	count = pairlist[i] - 1;
	while(count >= 0) {
	  PF_Sort(i + count);
	  hand.pickup(tmp, i + count);
	  cardlist[tmp.getSuit()][tmp.getNumber()] = getId() + 1;
	  cards.insert(tmp);
	  count--;
	}
	return true;
      }
    }
                 
    // 数字が9以上のとき
    count = pairlist[0] - 1;
    while(count >= 0) {
      PF_Sort(0 + count);
      hand.pickup(tmp, 0 + count);
      cardlist[tmp.getSuit()][tmp.getNumber()] = getId() + 1;
      cards.insert(tmp);
      count--;
    }
    return true;
                 
    // 1枚出しのとき
  case 1:
    for(i = 0; i < hand.size(); i++)
      if(hand[i].isGreaterThan(pile.at(0)) && pairlist[i] == 1) {
	if(Stronger(i) >= hand.size() - 6) {
	  PF_Sort(i);
	  hand.pickup(tmp, i);
	  cardlist[tmp.getSuit()][tmp.getNumber()] = getId() + 1;
	  cards.insert(tmp);
	  return true;
	}
	else {
	  if(hand.size() < 6 || Active(gstat)) {
	    if(HaveJoker() && hand.size() < 5) {
	      PF_Sort(hand.size() -1);
	      hand.pickup(tmp, hand.size() - 1);
	      cardlist[tmp.getSuit()][tmp.getNumber()] = getId() + 1;
	      cards.insert(tmp);
	      return true;
	    }
	    else {
	      PF_Sort(i);
	      hand.pickup(tmp, i);
	      cardlist[tmp.getSuit()][tmp.getNumber()] = getId() + 1;
	      cards.insert(tmp);
	      return true;
	    }
	  }
	}
      }
    return false;
                 
    // 複数枚のとき
  default:
    for(i = 0; i <= hand.size() - pile.size(); i++) {
      if(hand[i].isGreaterThan(pile.at(0)) && pairlist[i] == pile.size()) {
	if(Stronger(i) >= hand.size() - 6) {
	  count = pile.size() - 1;
	  while(count >= 0) {
	    PF_Sort(i + count);
	    hand.pickup(tmp, i + count);
	    cardlist[tmp.getSuit()][tmp.getNumber()] = getId() + 1;
	    cards.insert(tmp);
	    count--;
	  }
	  return true;
	}
	else { 
	  if(hand.size() < 6 || Active(gstat)) {
	    if(hand[i].getNumber() == 2 && hand.size() - pairlist[i] == 1) {
	      count = pile.size() - 1;
	      while(count >= 0) {
		PF_Sort(i + count);
		hand.pickup(tmp, i + count);
		cardlist[tmp.getSuit()][tmp.getNumber()] = getId() + 1;
		cards.insert(tmp);
		count--;
	      }
	      return true;
	    }
	    count = pile.size() - 1;
	    while(count >= 0) {
	      PF_Sort(i + count);
	      hand.pickup(tmp, i + count);
	      cardlist[tmp.getSuit()][tmp.getNumber()] = getId() + 1;
	      cards.insert(tmp);
	      count--;
	    }
	    return true;
	  }
	}
      }
    }
    return false;
  } 
  return false;
}
 
// 捨てたカードセット等の状況確認をする
bool Group3::approve(const GameState & gstat) {
  CardSet pile(gstat.pile);
  Card c;
  int pilesize = pile.size();
  if(pile.isEmpty() != 1)
    for(int i = 0; i < pilesize; i++){
      pile.pickup(c, 0);
      cardlist[c.getSuit()][c.getNumber()] = gstat.leader + 1;
    }
  return true;
}
 
 
/*
 *　思考処理用の関数群
 */
// 手札のソーティング (弱い順に並び替え)
void Group3::HandOrder(void) {
  int i, j;
  Card tmp;
  for(i = 0; i < hand.size() - 1; i++)
    for(j = i + 1; j <hand.size(); j++)
      if(hand[i].isGreaterThan(hand[j])) {
	tmp = hand[i];
	hand[i] = hand[j];
	hand[j] = tmp;
      }
}
 
// ペアのフラグを管理する
void Group3::PairFlag(void) {
  int i, j, count = 1;
  for(i = 0; i < hand.size(); ) {
    for(j = i + 1; j < hand.size(); j++) {
      if(hand[i].getNumber() == hand[j].getNumber())
	count++;
      else
	break;
    }
    for(j = 0; j < count; j++)
      pairlist[i + j] = count;
    i = i + count;
    count = 1;
  }
}
 
// ペアのフラグ配列の操作（必要ない配列の部分に0をいれる）
void Group3::PF_Sort(int pos){
  int i;
  for(i = pos; i < hand.size() - 1; i++)
    pairlist[i] = pairlist[i + 1];
  for(i = hand.size() - 1; i < N; i++)
    pairlist[i] = 0;
}
 
// lower <= num <= upper が成り立つか
bool Group3::Field(int num, int lower, int upper) {
  if((lower + 10) % 13 <= (num + 10) % 13 && (num + 10) % 13 <= (upper + 10) % 13)
    return true;
  return false;
}
 
// 相手の手札か5枚以下になったことを示すフラグ（戦術切り替え）
bool Group3::Active(const GameState & gstat) {
  int i;
  for(i = 0; i < gstat.nofPlayers; i++) {
    if(gstat.nofCards[i] <= 5)
      return true;
  }
  return false;
}
 
// 役確認用、捨て札確認用の配列の初期化
void Group3::InitArray(void) {
  int i, j;
  for(i = 0; i < N; i++) {
    pairlist[i] = 0;
    discard[i] = 0;
  }
  for(i = 0; i < 6; i++)
    for(j = 0; j < 15; j++)
      cardlist[i][j] = 0;
}
 
// 捨て札の枚数だけを確認する
void Group3::Check(void) {
  int i, j;
  // 重複して数えるため初期化してから値を入れ直す
  for(i = 0; i < N; i++)
    discard[i] = 0;
  // 再入力
  for(i = 0; i < 6; i++)
    for(j = 0; j < 15; j++)
      if(cardlist[i][j] != 0)
	discard[j]++;
}
 
// ジョーカーが場に出ているか（true: 出ていない false: 出ている）
bool Group3::JokerFlag(void) {
  if(cardlist[4][0] == 0)
    return true;
  else
    return false;
}
 
// 自分がジョーカーを持っているか
bool Group3::HaveJoker(void) {
  if(hand[hand.size() - 1].getNumber() == 0)
    return true;
  return false;
}
// 自身の出すカードより強いカードが何枚あるか
int Group3::Stronger(int pos) {
  int i, counter = 0;
  for(i = pos + 1; i < hand.size(); i++)
    if(hand[i].isGreaterThan(hand[pos]))
      counter++;
  return counter;
}
