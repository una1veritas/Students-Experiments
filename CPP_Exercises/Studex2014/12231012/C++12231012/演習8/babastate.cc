//
// babastate.cc - ババ抜きの状態型(C++版)
//	作者: 浦川　楓; 日付: 2014/04/24
//
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

//
// BabaState::move(int from, int to) -  to 番のプレーヤーが from 番のプレーヤーからカードを取る(true: 失敗; false: 成功) 
//

bool BabaState:: move(int from, int to)
{
  Card c;//抜いたカード
  int picknum;//何番目のカードを抜くか

  if(to == 0){
    printf("何番目のカード抜きますか？？\n");
    std::cin >> picknum;
    //   scanf("%d", picknum);
    if(hand[from].pickup(&c,picknum))//from番のプレーヤーからpicknum番目のカードを取る
      return true;//失敗
    printf("あなたは");
    c.print();
    printf("をゲットしました！\n");
  }
  else if(hand[from].pickup(&c,-1))//from番目プレーヤーからランダムに一枚引く
    return true;//失敗

  //to番のプレーヤの手の中と、引いたカードが同じ番号であれば
  //2枚とも捨てる
  if(hand[to].remove(c.gnumber()))
    hand[to].insert(c);//同じ番号がなければ、to番のプレーヤーの手札に加える
  return false;//失敗
}

//
// BabaState::print() - 自身の状態を標準出力に出力する
//
void BabaState::print(void)
{
  printf("あなたはplayer0さんですよ！！！！！！！\n");
  printf("自分の手札だよ！！！！！！！！！\n");
  hand[0].print();
  printf("\n");
  for(int i = 0; i < numplayer; i++) {
    std::cout <<"PLAYER " << i;
    hand[i].print();
  }
}
