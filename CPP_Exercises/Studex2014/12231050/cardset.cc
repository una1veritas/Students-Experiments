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
      //set(s);//suit = s;
      if(scanf("%d", &number) < 1)
	return true;
      if(number < 1 || number > 13)
	return true;
      return false;
    }
	
  // joker はそのまま(number は 0 とする)
  if(!strcmp(buf, "joker")) {
    //suit = SUIT_JOKER;
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
  char* suitsave[100];
  if(0 < number && number < 53){//if(suit < SUIT_JOKER)
	suitsave[100] = suitname[gsuit()];
	if(suitname[gsuit()] == "spade"){
		printf("[%s %d]", suitsave[100], number);
	}else if(suitname[gsuit()] == "diamond"){
		//number = number-12;
		printf("[%s %d]", suitsave[100], number-13);
	}else if(suitname[gsuit()] == "heart"){
		//number = number-24;
		printf("[%s %d]", suitsave[100], number-26);
	}else if(suitname[gsuit()] == "club"){
		printf("[%s %d]", suitsave[100], number-39);
		//number = number-36;
	}
    //printf("[%s %d]", suitsave[100], number);
  }
	
  if(number == 0)//else if(suit == SUIT_JOKER)
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

//自身のカードからひかれたカードを自身の持ち札から削除する感じ？

bool CardSet::remove(Card target){
int i;
	if(locate(target) != -1){
		for(i = locate(target);i<numcard;i++)
			cdat[i] = cdat[i+1];
		numcard--;
		return  false;
	}else{
		return true;
	}
}


	/*for(int i = 0; i < numcard; i++){//ターゲットのカードを探す
	    if(target.equal(cdat[i])){//見付かったか？
      		for(int i;i<numcard;i++){//見付かったら、後ろのカードを前に持っていって、ターゲットのカード削除
			cdat[i] = cdat[i+1];
		}
		numcard--;
		return false;
	    }
	}
	return true;
}*/

bool CardSet::remove(int num){

		int basyo;

		if(locate(num) != -1){
			for(int basyo = locate(num); basyo<numcard;basyo++){
				cdat[basyo] = cdat[basyo+1];
			}
	
			numcard--;
			return false;
		}else{
	
			return true;
		}
}





