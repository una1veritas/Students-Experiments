//
// ensyu8card.cc - トランプカードの集合型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <iostream>
#include "ensyu8card.h"

//
// Card::scan() - 標準出力から自身に入力する(true: エラー; false: 正常終了)
//
bool Card::scan(void)
{
  int cnum, csuit;

  char buf[BUFSIZ];
  char* suitname[] = { "spade", "diamond", "heart", "club" };
  // 4組のいずれかなら番号も入力する
  if(scanf("%s", buf) < 1)
    return true;
  for(int s = SUIT_SPADE; s <= SUIT_CLUB; s++)
    if(!strcmp(buf, suitname[s])) {
      csuit = s;
      if(scanf("%d", &cnum) < 1)
	return true;
      if(cnum < 1 || cnum > 13 )
	return true;
      number = cnum + (13 * csuit) - 1;
      return false;
    }
	
  // joker はそのまま(number は 52 とする)
  if(!strcmp(buf, "joker")) {
    number = 52;
    return false;
  }
  
  return true;	// エラー
}

//
// Card::print() - 自身の値を標準出力に出力する
//
void Card::print(void)
{
  int suit;
  char* suitname[] = { "spade", "diamond", "heart", "club" };
  
  /*  if(suit < SUIT_JOKER)
    printf("[%s %d]", suitname[suit], number);
  else if(suit == SUIT_JOKER)
    printf("[joker]");
  */
  
  if(0 <= number && number <= 12)
    suit = 0;
  else if(13 <= number && number <= 27)
    suit = 1;
  else if(26 <= number && number <= 38)
    suit = 2;
  else if(39 <= number && number <= 51)
    suit = 3;

  if(0 < number && number < 52)
    printf("[%s %d]", suitname[suit], (number % 13) + 1);
  else if(number == 52)
    printf("[joker]");
}



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
    if(number == cdat[i].gnumber())
      return i;
  
  return -1;	// 見つからなかった
}

//
// CardSet::makedeck() - 自身に全部の(maxnumcard 枚の)カードを入れる
//
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

//
// CardSet::pickup() - 自身から targetpos 枚目のカードを除き *ret に返す
//	targetpos が -1 のときはランダムに選ぶ(true: 失敗; false: 成功)
//
bool CardSet::pickup(Card* ret, int targetpos)
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

//
// CardSet::insert() - 自身に newcard のカードを入れる(true: 失敗; false: 成功)
//
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
// CardSet::remove() - 自身から target のカードを除く(true: 失敗; false: 成功)
//

bool CardSet::remove(Card target)
{
  int num;

  num = locate(target);
  if(num >= 0) {
    cdat[num] = cdat[numcard - 1];
    numcard--;
    return false;
  }

  return true;
}

//
// CardSet::remove() - 自身から数字が num であるカードを除く(true: 失敗; false: 成功)
//
bool CardSet::remove(int num)
{
  int k;

  k = locate(num);
  if(k >= 0) {
    cdat[k] = cdat[numcard - 1];
    numcard--;
    return false;
  }

  return true;
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
