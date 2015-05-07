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
int CardSet::locate(Card & target)
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
// CardSet::pickup() - 自身から targetpos 枚目のカードをぬき card にセットし返す
//	targetpos が -1 のときはランダムに選ぶ．
// (-1: 失敗; 0以上: 成功)
//
// remove() 実現後にコメントを外せ
/*
int CardSet::pickup(Card & card, int targetpos)
{
	if( numcard == 0 )
		return -1;
	if(targetpos < 0)
		targetpos = random() % numcard;
	else
		targetpos %= numcard;
	card = cdat[targetpos];
	remove(card);
	return targetpos;
}
*/

//
// CardSet::insert() - 自身に newcard を入れる(常に成功，挿入／存在位置を返す)
//
int CardSet::insert(Card newcard) {
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

bool CardSet::insert(CardSet & cards) {
	for(int i = 0; i < cards.numcard; i++) {
		insert(cards.cdat[i]);
	}
	return true;
}


void CardSet::shuffle(void) {
    int t, i, j;
    Card swap;
    time_t seed;

    time(&seed);
    srandom(seed);
    for (t = 0; t < 100; t++) {
      i = random() % numcard;
      j = ((random() % (numcard-1)) + 1 + i) % numcard;
      swap = cdat[i];
      cdat[i] = cdat[j];
      cdat[j] = swap;
    }
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

std::ostream & CardSet::printOn(std::ostream& out) const {
	if (numcard == 0) {
		out << "(no card)";
		return out;
	}
	out << cdat[0];
	for(int i = 1; i < numcard; i++) {
		out << ' ';
		out << cdat[i];
	}
	return out;
}

//

Card & CardSet::at(int i) {
	return cdat[i];
}

Card & CardSet::operator[](int i) {
	return at(i);
}


// 演習で作成した関数
int CardSet::pickup(Card & card, int targetpos) {
	if( numcard == 0 )
		return -1;
	if(targetpos == -1 )
		targetpos = random() % numcard;
	else
		targetpos %= numcard;
	card = cdat[targetpos];
	remove(card);
	return targetpos;
}


int CardSet::remove(Card & target) {
	// 自身から target と同一のカードを取り除く(-1: 失敗; 0以上: 成功)
	int pos = locate(target);
	if( pos == -1 )
		// ない
		return -1;
	for( ; pos < numcard; pos++) {
		cdat[pos] = cdat[pos+1];
	}
	numcard--;
	return pos;
}


int CardSet::remove(int num) {
		// 自身から数字が num であるカードいずれか一枚を除く(-1: 失敗; 0以上: 成功)
	int pos = locate(num);
	if( pos == -1 )
		// ない
		return -1;
	for( ; pos < numcard; pos++) {
		cdat[pos] = cdat[pos+1];
	}
	numcard--;
	return pos;

}
