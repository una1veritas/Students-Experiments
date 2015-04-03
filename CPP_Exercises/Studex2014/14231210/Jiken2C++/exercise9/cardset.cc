//
// cardset.cc - トランプカードの集合型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <iostream>
#include "cardset.h"
#include<stdio.h>
#include<string.h>
#include<cstdlib>
//
// Card::scan() - 標準出力から自身に入力する(true: エラー; false: 正常終了)
//
bool Card::scan(void)
{
  char buf[BUFSIZ];
  // initialize static const variable
  const char * suitnames[] = {
  		"spade",
  		"diamond",
  		"heart",
  		"club",
  		"joker"
  };

  // 4組のいずれかなら番号も入力する
  if(scanf("%s", buf) < 1)
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
	
  // joker はそのまま(number は 0 とする)
  if(!strcmp(buf, "joker")) {
    suit = SUIT_JOKER;
    number = 0;
    return false;
  }
  
  return true;	// エラー
}

//
// Card::print() - 自身の値を標準出力に出力する
//
void Card::print(void)
{
  char* suitname[] = { "spade", "diamond", "heart", "club" };
  
  if(suit < SUIT_JOKER)
    printf("[%s %d]", suitname[suit], number);
  else if(suit == SUIT_JOKER)
    printf("[joker]   ");
}

int CardSet::locate(Card target)
{
  for(int i = 0; i < numcard; i++)
    if(target.equal(cdat[i]))
      return i;
  
  return -1;	// 見つからなかった
}

bool CardSet::insert(Card newcard)
{
  if(locate(newcard) >= 0)
    return true;	// 既にある
  // 最後に追加
  cdat[numcard] = newcard;
  numcard++;
  
  return false;
}

//
// CardSet::makedeck() - 自身に全部の(maxnumcard 枚の)カードを入れる
//
void CardSet::makedeck(void)
{
  Card c;
  int suit, num;
  for(suit = Card::SUIT_SPADE; suit <= Card::SUIT_CLUB; suit++)
  //for(suit = 1; suit <= 4; suit++)
  {
    for(num = 1; num <= 13; num++) {
      c.set(suit, num);
      insert(c);
    }
  }
  c.set(Card::SUIT_JOKER, 0);
  insert(c);
}


void CardSet::swap(int ind1, int ind2)
{
     Card c = cdat[ind1];
     cdat[ind1] = cdat[ind2];
     cdat[ind2] = c;
}

bool CardSet::equalnumber(int ind1, int ind2)
{
      return cdat[ind1].equal(cdat[ind2].gnumber());
}
//
// CardSet::print() - 自身の状態を標準出力に出力する
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

void CardSet::print(int a[])
{
  //printf("((CARDSET))\n");
  if(numcard == 0) {
    printf("\tno card\n");
    return;
  }
  printf("\n");
  for(int i = 0; i < numcard; i++) {
    if(i!=0 && i%5==0) std::cout<<"\n";
    if(a[i]!=-1) {cdat[i].print(); printf("\t");}
    else printf("*******\t\t");
  }
}


int CardSet::getnumcard(void)
{
	return numcard;
}

