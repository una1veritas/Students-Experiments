// babastate.cc - ババ抜きの状態型(C++版)
//	作者: 井本賢; 日付: 2014/4/27
#include "babastate.h"
#include <iostream>

//
// BabaState::reset() - リセット(最初にカードを配った状態にする)
//
void BabaState::reset(void)
{
  // 各プレーヤのフラグを未了にし，持ち手を空にする
  for(int i = 0; i < numplayer; i++) {
    hand[i].makeempty();
  }
  // デック(1セット)のカードを initcs に入れる
  CardSet initcs;
  initcs.makedeck();
  // 無くなるまで initcs から無作為にカードをとり plr 番のプレーヤに配る
  int plr = 0;	// 配る相手のプレーヤ
  Card c;		// 配るカード
  while(!initcs.pickup(&c)) {
    // 既に配られたカードと同じ番号があれば
    // 今度のカードと既に配られたカードとの両方を捨てる
    // 無ければ今度のカードを自分の手に加える
    if(hand[plr].remove(c.gnumber()))
      hand[plr].insert(c);
    // plr を次のプレーヤにする
    if(++plr >= numplayer)
      plr = 0;
  }
}

bool BabaState::move(int from, int to)
{
	Card c;
	hand[from].pickup(&c);
	if(hand[to].remove(c.gnumber()))
		hand[to].insert(c);
}

// CardSet::locate() - 内部での target のカードの位置を返す(-1: ない)
int CardSet::locate(Card target)
{
  for(int i = 0; i < numcard; i++)
    if(target.equal(cdat[i]))
      return i;  
  return -1;	// 見つからなかった
}

// Card::print() - 自身の値を標準出力に出力する
void Card::print(void)
{
  char* suitname[] = { "spade", "diamond", "heart", "club" };
  
  if(suit < SUIT_JOKER)
    printf("[%s %d]", suitname[suit], number);
  else if(suit == SUIT_JOKER)
    printf("[joker]");
}

// CardSet::locate() - 内部で数字が num のカードの位置を返す(-1: ない)
int CardSet::locate(int number)
{
  for(int i = 0; i < numcard; i++)
    if(number == cdat[i].gnumber())
      return i;
  
  return -1;	// 見つからなかった
}

// CardSet::makedeck() - 自身に全部の(maxnumcard 枚の)カードを入れる
void CardSet::makedeck(void)
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

// CardSet::pickup() - 自身から targetpos 枚目のカードを除き *ret に返す
//	targetpos が -1 のときはランダムに選ぶ(true: 失敗; false: 成功)
bool CardSet::pickup(Card* ret, int targetpos /* = -1 */)
{
  if(numcard == 0)
    return true;
  if(targetpos < 0)
    targetpos = random() % numcard;
  else
    targetpos %= numcard;
  
  *ret = cdat[targetpos];
   remove(*ret); // remove() 実現後にコメントを外せ
  
  return false;
}

// CardSet::insert() - 自身に newcard のカードを入れる(true: 失敗; false: 成功)
bool CardSet::insert(Card newcard)
{
  if(locate(newcard) >= 0)
    return true;	// 既にある
  // 最後に追加
  cdat[numcard] = newcard;
  numcard++;
  
  return false;
}

bool CardSet::remove(Card target)
{
	for(int i = 0; i < numcard; i++)
		if(target.equal(cdat[i])){
			for(int j = i; j < numcard; j++)
				cdat[j] = cdat[j + 1];
			numcard = numcard - 1;
			return false;
		}
	return true;
}

bool CardSet::remove(int num)
{
	for(int i = 0; i < numcard; i++)
    		if(num == cdat[i].gnumber()){
			for(int j = i; j < numcard; j++)
				cdat[j]= cdat[j+1];
			numcard = numcard - 1;
      			return false;
 		}
	return true; 
}





// CardSet::print() - 自身の状態を標準出力に出力する
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
