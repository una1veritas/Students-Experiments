//
// cardset.cc - トランプカードの集合型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <iostream>
#include "cardset.h"

//
// Card::scan() - 標準出力から自身に入力する(true: エラー; false: 正常終了)
//
bool Card::scan(void)
{
  int number;

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
      scanf("%d", &number);
      tr = (s * 13) + number;
      if(number < 1)
	return true;
      if(number < 1 || number > 13)
	return true; 
       return false;
    }
	
  // joker はそのまま(number は 0 とする)
  if(!strcmp(buf, "joker")) {
    tr = 53;
    return false;
  }
  
  return true;	// エラー
}

//
// Card::print() - 自身の値を標準出力に出力する
//
void Card::print(void)
{
  int number;
  char* suitname[] = { "spade", "diamond", "heart", "club" };
 
  if((1 <= tr) && (tr <= 13)){
    number = tr; 
    printf("[%s %d]", suitname[0], number);
  }
  else if((14 <= tr) && (tr <= 26)){
    if(tr == 26)
      number = 13;
    else 
      number = tr % 13;
    printf("[%s %d]", suitname[1], number);
  }
  else if((27 <= tr) && (tr <= 39)){
    number = tr % 26;
    printf("[%s %d]", suitname[2], number);
  }
  else if((40 <= tr) && (tr <= 52)){
    number = tr / 39;
    printf("[%s %d]", suitname[3], number);
  }
    else if(tr == 53)
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

bool CardSet::remove(Card target)
{
  if(locate(target)>=0){ 
    for(int i = locate(target); i < numcard; i++)
      cdat[i] = cdat[i + 1];
    numcard -= 1;
    return false;
  }
  else
    return true;
}
bool CardSet::remove(int num)
{
  if(locate(num)>= 0){
  for(int i = locate(num); i < numcard; i++)
    cdat[i] = cdat[i + 1];
  numcard -= 1;
  return false;
  }
  else
    return true;
}
