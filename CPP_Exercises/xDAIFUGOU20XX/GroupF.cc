/*
 * Created by Group F
 */

#include <iostream>
#include <string>

#include "Card.h"
#include "CardSet.h"
#include "Player.h"
#include "groupf.h"

GroupF::GroupF(const char * s) : Player(s) {}

bool GroupF::approve(CardSet & pile, int numCards[]) {
  if(inHand().size()+memory.size() > 52)
    memory.makeempty();
  memory.insert(pile); // 他のプレイヤーが出したカードをストック
  
  // 自分自身のidは getId() で獲得できる
   std::cout << "your information is "<< getName() << " " << getId() << std::endl;
  for (int i=0; numCards[i] != NO_MORE_PLAYERS; i++){
    // numCardsには自分を含めたそれぞれの持ち札の数が格納されている
    // 配列の最後には終端検知のため NO_MORE_PLAYERSという値が入っている
    // numCardsの添字はプレイヤーのidを表す
    std::cout << i << " " << numCards[i] << std::endl;
  }

  return true;
  
}

bool GroupF::follow(CardSet & pile, CardSet & s) {
  Card tmp;
  int n;
  //int pairs;
  int strength[14],strenmem[14]; // メンバだとなぜかアボートする
  s.makeempty();
  
  sort(inHand());
  setstren(strength,inHand());
  setstren(strenmem,memory);

  /*  
  std::cout << "memory ";
  memory.print();
  std::cout << std::endl;
  inHand().print();
  std::cout << "-----inHand-----" << std::endl;
  printstren(strength);
  std::cout <<"-----memory-----"  << std::endl;
  printstren(strenmem);
  */

  if(pairsnum(strength) < 4 || memory.size() > 25)
    n = latter_half(pile,strength);
  else
    n = first_half(pile,strength);
  if(n >= 0 && n<inHand().size())
    inHand().pickup(&tmp,n);
  else
    return false;
  s.insert(tmp);
  if(pile.isempty())
    cardSetOfSameRanks(s, 5); // 空なら最大4枚までセット
  else
    cardSetOfSameRanks(s, pile.size()); // 残りをセット
  
  memory.insert(s);

  if(!inHand().size())
    memory.makeempty();

  return true;
}

void GroupF::cardSetOfSameRanks(CardSet & s, int rank) {
  Card tmp;
  for(int i=1;i<rank;i++){
    for(int j=0;j<inHand().size();j++){
      if(inHand().at(j).getrank() == s.at(0).getrank()){
	inHand().pickup(&tmp,j);
	s.insert(tmp);
      }
      if(inHand().at(j).getrank() > s.at(0).getrank())
	 break;
    }
  }
}


void GroupF::sort(CardSet & s) {
  Card tmp;
  
  for(int i=s.size();i>0;i--){
    int j=0;
    for(int k=0;k<i;k++){
      if(s.at(j).isGreaterThan(s.at(k)))
	j = k;
    }
    s.pickup(&tmp,j);
    s.insert(tmp);
  }
  
}


int GroupF::rankTostren(int rank){
  int stren;
  switch(rank)
    {
    case 0:
      stren = 13;//joker
      break;
    case 1:
      stren = 11;//A
      break;
    case 2:
      stren = 12;//2
      break;
    case 3://strength 0
    case 4://strength 1
    case 5://strength 2
    case 6://strength 3
    case 7://strength 4
    case 8://strength 5
    case 9://strength 6
    case 10://strength7 
    case 11://strength8
    case 12://strength9
    case 13://strength10
      stren = rank-3;
      break;
  }
  
  return stren;
}

int GroupF::strenTorank(int stren){
  int rank;
  switch(stren)
    {
    case 0://rank3
    case 1://rank4
    case 2://rank5
    case 3://rank6
    case 4://rank7
    case 5://rank8
    case 6://rank9
    case 7://rank10
    case 8://rank11
    case 9://rank12
    case 10://rank13
      rank = stren + 3;
      break;
    case 11://rank1
      rank = 1;
      break;
    case 12://rank2
      rank = 2;
      break;
    case 13://rank0JOKER
      rank = 0;
      break;
    }
  return rank;
}



void GroupF::setstren(int stren[],CardSet s){
  int i;
  for(i = 0; i < 14; i++)
    stren[i] = 0;
  for(i = 0; i < s.size(); i++)
    stren[rankTostren(s.at(i).getrank() )]++;
}

int GroupF::seekstren(int rank, int size,int strength[]){
  int stren = rankTostren(rank);
  
  for(int i=stren+1;i<14;i++)
    if(havecards(strenTorank(i),strength)==size){
      stren = i-1;
      break;
    }
  
  if(stren == -1)
    return -1;
  for(int i = stren + 1; i < 14; i++)
    if(strength[i] >= size)
      return strenTorank(i);
  return -1;
}

int GroupF::SelectNextNum(CardSet & pile,int strength[]) {
  int num = seekstren(pile.at(0).getrank(),pile.size(),strength);
  if(num>=0)
    for(int i=0;i<inHand().size();i++)
      if(inHand().at(i).getrank() == num){
	//	std::cout << "-----success-----" << std::endl;
	return i;
      }
  //  std::cout << "-----error-----" <<std::endl;
  return -1;
}


void GroupF::printstren(int stren[]){
  int i;
  std::cout << "3| ";
  for(i=0;i<5;i++)
    std::cout << stren[i] << " ";
  std::cout << "|7\n8| ";
  for(;i<10;i++)
   std::cout << stren[i] << " ";
  std::cout <<"|Q\nK| ";
  for(;i<14;i++)
    std::cout << stren[i] << " ";
  std::cout << "  |Jkr" << std::endl;
}

int GroupF::findpair(int size, int strength[]){
  int ret=0;
  for(int i=0;i<14;i++)
    if(strength[i] == size)
      ret++;
  return ret;
}

int GroupF::pairsnum(int strength[]){
  int ret=0;
  for(int i=1;i<=4;i++)
    ret += findpair(i,strength);
  return ret;
}

int GroupF::havecards(int rank,int strength[]){
  return strength[rankTostren(rank)];
}

int GroupF::SelectNum(int num) {
  if(num>=0){
    for(int i=0;i<inHand().size();i++){
      if(inHand().at(i).getrank() == num){
	//	std::cout << "success" << std::endl;
	return i;
      }
    }
  }
  //  std::cout << "error" <<std::endl;
  return 0;
}

int GroupF::first_half(CardSet pile,int strength[]){
  int ret = 0;
  if(pile.isempty()){
    for(int i=0;i<14;i++)
      if(havecards(i,strength)>=3)
	ret = SelectNum(i);
    return ret;
  }else
    ret = SelectNextNum(pile,strength); // 出せるカードで最小を
  if(ret == inHand().size()-1){
    //    std::cout << "-----protect-----" << std::endl;
    ret = -1;
  }
  return ret;
}

int GroupF::latter_half(CardSet pile,int strength[]){
  int ret = 0;
  if(pile.isempty()){
    for(int i=0;i<14;i++)
      if(havecards(i,strength)>=2)
	ret = SelectNum(i);
    return ret;
  }else
    ret = SelectNextNum(pile,strength);
  return ret;
}
