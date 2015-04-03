//
// cardset.cc - トランプカードの集合型(C++版)
//	作者: (大砂咲樹); 日付: (２０１４年4月28日)
//
#include <iostream>
#include "cardset.h"

//
// Card::scan() - 標準出力から自身に入力する(true: エラー; false: 正常終了)
//
bool Card::scan(void)
{      scanf("%d", &number);
      if(number<0 || number>52)
    return false;
      return true;
}

//
// Card::print() - 自身の値を標準出力に出力する
//
void Card::print(void)
{
  char* suitname[] = { "spade", "diamond", "heart", "club" };
  int suit=gsuit();
  if(suit < SUIT_JOKER)
    if(number%14==0)
      printf("[%s %d]", suitname[suit], number/14);
    else 
      printf("[%s %d]", suitname[suit], number%14);
  else if(suit == SUIT_JOKER)
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
    for(num = 1; num <= 53; num++) {
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
  remove(*ret); 
  
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
bool CardSet::remove(Card target){
     int i;
    
  for(i=0; i<numcard; i++)
   {
     if((cdat[i].gsuit()==target.gsuit() && cdat[i].gnumber()==target.gnumber())|| (target.gsuit()==target.SUIT_JOKER && cdat[i].gsuit()==target.gsuit()))
        {
	  cdat[i].set(cdat[numcard-1].gsuit(),cdat[numcard-1].gnumber());
	 cdat[numcard-1].set(-1, -1);
	  numcard = numcard-1;

	 return true;
      }
   }
   return false;
}

//
// CardSet::remove() - 自身から数字が num であるカードを除く(true: 失敗; false: 成功)
//
bool CardSet::remove(int num){
  int i,j,no;
     bool k=false;

 for(i=0; i<numcard; i++)
   {
      if(cdat[i].gnumber()==0) no=0;
      else if(cdat[i].gnumber()%14==0) no=14;
      else no=cdat[i].gnumber()%14;
      if(no==num)
      {
         for(j=i; j<numcard-1; j++)
         {
            cdat[j].set(cdat[j+1].gsuit(), cdat[j+1].gnumber());
         }
         cdat[j].set(-1, -1);
         numcard = numcard-1;
     k=true;
     if(num==0) break;
     else i--;
      
       /*  for(i=0; i<numcard; i++)
   {
     if(cdat[i].gnumber()==num)
      {
         for(j=i; j<numcard-1; j++)
         {
            cdat[j].set(cdat[j+1].gsuit(), cdat[j+1].gnumber());
         }
         cdat[j].set(-1, -1);
         numcard = numcard-1;
     i--;
     k=true;

     if(cdat[i].gnumber()==0) no=0;
      else if(cdat[i].gnumber()%13==0) no=13;
     else no=cdat[i].gnumber()%13;
      if(no==num)
      {
	//for(j=i; j<numcard-1; j++)
	   // {
	//  cdat[j].set(cdat[j+1].gsuit(), cdat[j+1].gnumber());
	//} 
	cdat[i].set(cdat[numcard-1].gsuit(),cdat[numcard-1].gnumber());
	 cdat[numcard-1].set(-1, -1);
	  numcard = numcard-1;

	  //cdat[j].set(-1, -1);
	  //numcard = numcard-1;
	 k=true;
	 if(num==0) break;
	 else i--;*/
      }
   }
   return k;
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
