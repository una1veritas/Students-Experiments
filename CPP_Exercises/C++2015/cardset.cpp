//
// cardset.cc - トランプカードの集合型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <iostream>
#include "cardset.h"

// クラス変数（定数）の初期化
const char * Card::suitnames[] = {
  		"spade",
  		"diamond",
  		"heart",
  		"club",
  		"joker"
};

//
// Card::scan() - 標準出力から自身に入力する(true: 正常終了; false: 異常終了)
//
bool Card::scan(void)
{
  char buf[BUFSIZ];
  // initialize static const variable

  // 4組のいずれか？
  if(scanf("%s", buf) < 1)
    return false;
  for(int s = SUIT_SPADE; s <= SUIT_CLUB; s++) {
	  if( buf[0] == Card::suitnames[s][0] ) { // 一文字目だけで判定
		  suit = s;
		  // なら番号もスキャン
		  if( (scanf("%d", &number) < 1) && (number < 1 || number > 13) )
			  return false;
		  return true;
    }
  }
  // joker はそのまま(number は 0 とする)
  if( buf[0] == 'j' ) {
    suit = SUIT_JOKER;
    number = 0;
    return true;
  }
  
  return false;	// エラー
}

//
// Card::print() - 自身の値を標準出力に出力する
//
void Card::print(void)
{
	printf("[%s %d]", suitnames[suit], number);
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


