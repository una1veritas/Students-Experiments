//
// babastate.cc - ババ抜きの状態型(C++版)
//	作者: (大砂咲樹; 日付: (２０１４年4月28日)
//
#include "babastate.h"
#include <iostream>

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
    if(!hand[plr].remove(c.gnumber()))
      hand[plr].insert(c);
    // plr を次のプレーヤにする
    if(++plr >= numplayer)
      plr = 0;
  }
}

//
// BabaState::print() - 自身の状態を標準出力に出力する
//
void BabaState::print(void)
{
  for(int i = 0; i < numplayer; i++) {
    std::cout <<"PLAYER " << i;
    hand[i].print();
  }
}

//
//BabaState::move()-to 番のプレーヤが from 番のプレーヤからカードを取る(true: 失敗; false: 成功)
//	
bool BabaState::move(int from, int to){
   int num;
   Card c;
   std::cout<<"何番目のカードを引きますか？(0から"<<hand[from].getnumcard()-1<<"まで入力): \n";
   do
   {
     std::cin>>num;//カード番号の入力
   }while(!(0<=num && num<hand[from].getnumcard()));
    
   if(hand[from].pickup(&c, num))//fromから入力された番号のカードを引く
     return true;
   if(!hand[to].remove(c.gnumber()))//取り除くものがなければ
     hand[to].insert(c);//加える
   else 
     hand[to].remove(c.gnumber());//除く
    return false;
     }
//    return false;

//}
int CardSet::getnumcard(void)
{
   return numcard;
}
