//
// babastate.cc - ババ抜きの状態型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
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

bool BabaState::move(int from , int to){	
	Card pick;
	int pno;
	// カード選択
	printf("%d\n",hand[from].retnum());

	printf("select card :");
	for(int i=0; i < hand[from].retnum() ; i++)
			  printf("%d ",i);
	printf("\n");
	
	bool c_flag = true; 

	do{
			printf(" card =?"); scanf("%d",&pno);
			for(int i = 0; i < hand[from].retnum(); i++){
				if(pno == i)
					c_flag = false;
			}	
	}while(c_flag);
	hand[from].pickup(&pick,pno);

	//	カード照合
	if(hand[to].remove(pick.gnumber())){
	
	}
	else hand[to].insert(pick);

	return true;
}
