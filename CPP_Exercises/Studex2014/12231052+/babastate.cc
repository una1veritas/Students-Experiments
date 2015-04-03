//
// babastate.cc - ババ抜きの状態型(C++版)
//	作者: 長濱彰秀; 日付:4月２４日
//
#include "babastate.h"
#include <iostream>
#include <stdio.h>

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

//
// BabaState::print() - 自身の状態を標準出力に出力する
//
void BabaState::print(void)
{
  /*for(int i = 0; i < numplayer; i++) {
    std::cout <<"PLAYER " << i;
    hand[i].print();
  }*/
  std::cout <<"PLAYER " << 0;
  hand[0].print();
}

//
// BabaState::membercard - 他のプレーヤーのカードの残り枚数を出力する
//
void BabaState::membercard(void){

  for(int i = 1; i < numplayer; i++) {
    std::cout <<"PLAYER " << i << ":";
    printf(" %d" ,hand[i].CardSet::gmember());
    std::cout << "枚\n";
  }
}
//
// BabaState::move - カードを移動させる
//
bool BabaState::move(int from, int to)
{
  printf("move:request\n");
  Card c;
  if(hand[from].pickup(&c, -1))	//fromからcを取り出す
	return true;

  if(hand[to].remove(c.gnumber()))// 取りだしたカードと同じ番号のカードがあれば捨て、
	hand[to].insert(c);	  // なければtoにそのカードを加える。

  return false;
}



