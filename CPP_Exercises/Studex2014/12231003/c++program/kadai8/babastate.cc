// babastate.cc - ババ抜きの状態型(C++版)
//	作者: (市川　舞); 日付: (2014/04/28)
#include "babastate.h"
#include <iostream>

// BabaState::reset() - リセット(最初にカードを配った状態にする)
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

// 課題8にて変更
// BabaState::move() - to 番のプレーヤが from 番のプレーヤからカードを取る
bool BabaState::move(int from, int to)
{
  Card pc;
  int pn;

  if(to == 4) {
    std::cout << "what pick up number??" << std::endl;
    std::cin >> pn;

  if(hand[from].pickup(&pc, pn))
    return true;

  std::cout << "you got";
  pc.print();
  std::cout << "!!" << std::endl;
  std::cout << std::endl;
  }

  else if(hand[from].pickup(&pc, -1))
    return true;

  if(hand[to].remove(pc.gnumber()))
    hand[to].insert(pc);

  return false;
}

// 課題8にて変更
// BabaState::print() - 自身の状態を標準出力に出力する
void BabaState::print(void)
{

  std::cout << "your cards are";
  hand[4].print();
  std::cout << std::endl;

  for(int i = 0; i < numplayer; i++) {
    std::cout <<"PLAYER " << i;
    hand[i].print();
  }
}

