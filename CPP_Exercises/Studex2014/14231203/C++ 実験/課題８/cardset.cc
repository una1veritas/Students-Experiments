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
      card = s*13;
	  int number;
      if(scanf("%d", &number) < 1)
		return true;
      if(number < 1 || number > 13){
		card+=number-1;
		return true;
	  }
      return false;
    }
	
  // joker はそのまま(number は 0 とする)
  if(!strcmp(buf, "joker")) {
    card = 52;
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
  
  if(card < 52)
    printf("[%s %d]", suitname[card/13], card%13+1);
  else if(card == 52)
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
  if(number != 52){
	for(int i = 0; i < numcard; i++)
	  if(number%13 == cdat[i].gnumber()%13 )
  
      return i;
  }
  return -1;	// 見つからなかった
}

//
// CardSet::makedeck() - 自身に全部の(maxnumcard 枚の)カードを入れる
//
void CardSet::makedeck(void)
{
  Card c;
  int suit, num;
  
  for(int i = 0; i <= 52; i++){
      c.set(i);
      insert(c);
    }
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
//カードの削除

bool CardSet::remove(Card target){
	int def = locate(target);
	if(def>=0){
		while(def != numcard){
        		cdat[def]=cdat[def+1];
        		def++;
		}	
		numcard--;
		return true;	
   }
	else return false; 
}

bool CardSet::remove(int num){
	int def = locate(num);
	if(def >=0){
			 while(def != numcard){
        			cdat[def]=cdat[def+1];
        			 def++;
			}
		numcard--;
		return true;
	}
	
	else return false;
}

