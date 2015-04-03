//
// cardset.cc - トランプカードの集合型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <iostream>

#include "Card.h"
#include "CardSet.h"

CardSet::CardSet(void)	{
	clear();
}

CardSet::CardSet(const CardSet & orig) {
	numcard = orig.numcard;		// 現在の集合内のカード数
	for(int i = 0; i < numcard; i++)
		cards[i] = orig.cards[i];	// カードのデータ
}

//
// CardSet::locate() - 内部での target のカードの位置を返す(-1: ない)
//
int CardSet::locate(Card target)
{
	for(int i = 0; i < numcard; i++)
		if(target.isEqualTo(cards[i]))
			return i;

	return -1;	// 見つからなかった
}

//
// CardSet::locate() - 内部での num 番のカードの位置を返す(-1: ない)
//
int CardSet::locate(int number)
{
	for(int i = 0; i < numcard; i++)
		if(number == cards[i].getRank())
			return i;

	return -1;	// 見つからなかった
}

//
// CardSet::makeDeck() - 自身に全部の(maxnumcard 枚の)カードを入れる
//
void CardSet::setupDeck(void)
{
	Card c;
	int suit, num;

	for(suit = c.SUIT_SPADE; suit <=c.SUIT_CLUB; suit++)
		for(num = 1; num <= 13; num++) {
			c.set(suit, num);
			insert(c);
		}
	c.set(c.SUIT_JOKER, 0);
	insert(c);
}


//
// CardSet::pickup() - 自身から pos 枚目のカードを除き ret に返す
//	pos が適切な配列の添字の範囲外のとき（典型的には -1）はランダムに選ぶ。
// true: カードを選び抜き出すことに成功、false: カードが一枚もない。
//
bool CardSet::pickup(Card & ret, int pos)
{
	if(numcard == 0)
		return false;
	if( pos < 0 || pos >= numcard )
		pos = random() % numcard;
	ret = cards[pos];
	return remove(ret);
}

//
// CardSet::insert() - 自身に newcard のカードを入れる(true: 失敗; false: 成功)
//
bool CardSet::insert(Card newcard)
{
	if(locate(newcard) >= 0)
		return false;	// 既にある
// 最後に追加
	cards[numcard] = newcard;
	numcard++;
	cards[numcard] = Card();
	return true;
}

bool CardSet::insertAll(const CardSet & orig) {
	for(int i = 0; i < orig.numcard; i++) {
		insert(orig.cards[i]);
	}
	return true;
}

//
// CardSet::remove() - 自身から target のカードを除く(true: 失敗; false: 成功)
//
bool CardSet::remove(Card target)
{
	int pos;

// 除くカードの位置を求める
	if((pos = locate(target)) < 0)
		return false;	// target は無い
	target = cards[pos];
// 1つずつ前に詰める
	numcard--;
	for(int i = pos; i < numcard; i++)
		cards[i] = cards[i+1];
	return true;
}

//
// CardSet::remove() - ランクが rnum のカードを除く(true: 失敗; false: 成功)
//
bool CardSet::remove(int rnum)
{
	int pos;

// 除くカードの位置を求める
	if((pos = locate(rnum)) < 0)
		return false;	// rnum のカードは無い
// 1つずつ前に詰める
	for(int i = pos + 1; i < numcard; i++)
		cards[i-1] = cards[i];
	numcard--;

	return true;
}

//
// CardSet::print() - 自身の状態を標準出力に出力する
//
void CardSet::print(void)
{
	//printf("((CARDSET))\n\t");
	if(numcard == 0) {
		printf("no cards");
		return;
	}
	for(int i = 0; i < numcard; i++) {
		//printf("\t");
		cards[i].print();
		printf(", ");
	}
	printf("\n");
}

std::ostream & CardSet::printOn(std::ostream& out) const {
	if(numcard == 0) {
		out << "(no card)";
		return out;
	}
	out << cards[0];
	for(int i = 1; i < numcard; i++) {
		out << ' ';
		out << cards[i];
	}
	return out;
}


void CardSet::shuffle(void) {
    int t, i, j, k;
    Card swap;
    time_t seed;
    
    time(&seed);
    srandom(seed);
    for (t = 0; t < 100; t++) {
      i = random() % numcard;
      j = i + (random() % (numcard-i));
      /* std::cout << "shuffling [" << i << ", " << j << ")" << std::endl; */
      for (k = 0; i + k < j; k++) {
    	  swap = cards[k];
    	  cards[k] = cards[j-k - 1];
    	  cards[j-k - 1] = swap;
       }
      /* std::cout << std::endl;
      for(k = 0; k < maxnumcard+1; k++) {
    	  std::cout << cards[k] << ", ";
      }
      std::cout << std::endl; */
    }
}

