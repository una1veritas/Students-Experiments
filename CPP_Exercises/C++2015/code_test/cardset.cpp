//
// cardset.cc - トランプカードの集合型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <iostream>
#include "card.h"
#include "cardset.h"

//
// CardSet::locate() - 内部での target のカードの位置を返す(-1: ない)
//
int CardSet::locate(Card target)
{
  for(int i = 0; i < numcard; i++)
    if(target.equal(cdat[i]))
      return i;
  
  return -1;	// 見つからなかった
}

//
// CardSet::locate() - 内部で数字が num のカードの位置を返す(-1: ない)
//
int CardSet::locate(int number)
{
  for(int i = 0; i < numcard; i++)
    if(number == cdat[i].getNumber())
      return i;
  
  return -1;	// 見つからなかった
}

//
// CardSet::setupDeck() - 自身に全部の(maxnumcard 枚の)カードを入れる
//
void CardSet::setupDeck(void)
{
  Card c;
  int suit, num;
  
  for(suit = Card::SUIT_SPADE; suit <= Card::SUIT_CLUB; suit++)
    for(num = 1; num <= 13; num++) {
      c.set(suit, num);
      insert(c);
    }
  c.set(Card::SUIT_JOKER, 0);
  insert(c);
}

//
// CardSet::pickup() - 自身から targetpos 枚目のカードをぬき *ret に返す
//	targetpos が -1 のときはランダムに選ぶ(-1: 失敗; 0以上: 成功)
//
int CardSet::pickup(Card* ret, int targetpos /* = -1 */)
{
  if(numcard == 0)
    return -1;
  if(targetpos < 0)
    targetpos = random() % numcard;
  else
    targetpos %= numcard;
  
  *ret = cdat[targetpos];
  // remove(*ret); // remove() 実現後にコメントを外せ
  
  return targetpos;
}

//
// CardSet::insert() - 自身に newcard のカードを入れる(常に成功，挿入／存在位置を返す)
//
int CardSet::insert(Card newcard)
{
	int location = locate(newcard);
	if( location >= 0)
		return location;	// 既にある
	// 最後に追加
	if ( numcard >= maxnumcard )
		return -1; // もうはいらないし，入れるカードはないはず
	location = numcard;
	cdat[location] = newcard;
	numcard++;
  
  return location;
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

int CardSet::remove(Card target) {
	// 自身から target のカードを除く(-1: 失敗; 0以上: 成功)
	int location = locate(target);
	if( location < 0)
		return location;	// 既にない
	numcard--;
	for(int i = location; i <= numcard ; i++) {
		cdat[i] = cdat[i+1];
	}
  return location;
}

int CardSet::remove(int num) {
	// 自身から数字が num であるカードいずれか一枚を除く(-1: 失敗; 0以上: 成功)
	// 自身から target のカードを除く(-1: 失敗; 0以上: 成功)
	int location = locate(num);
	if( location < 0)
		return location;	// 既にない
	numcard--;
	for(int i = location; i <= numcard ; i++) {
		cdat[i] = cdat[i+1];
	}
  return location;
}
