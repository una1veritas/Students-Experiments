//
// cardset.cc - トランプカードの集合型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include <iostream>
#include "card.h"

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
  int s;

  // 4組のいずれ？
  if(scanf("%s", buf) < 1)
    return false;
  for(s = SUIT_SPADE; s <= SUIT_CLUB; s++) {
	  if( buf[0] == Card::suitnames[s][0] ) { // 一文字目だけで判定
		  suit = s;
		  break;
	  }
  }
  if ( s <= SUIT_CLUB ) {
	  // なら番号もスキャン
	  if( (scanf("%d", &number) < 1) )
		  return false;
	  if ( 0 < number && number <= 13 )
		  return true;
	  return false;
  }
  // joker は number は使わない． 0 としておく．
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
