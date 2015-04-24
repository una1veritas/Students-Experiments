//
// card.h - トランプカードの型
//	作者: (あなたの名前); 日付: (完成した日付)
//
#ifndef CARD_H
#define CARD_H
#include <iostream>

//
// Card - トランプカード型
//
class Card {
	// クラス定数
	// トランプの組(suit)のコード
	public:
	enum {
		SUIT_SPADE, 	// = 0
		SUIT_DIAMOND,
		SUIT_HEART,
		SUIT_CLUB,
		SUIT_JOKER, 	// = 4
		SUIT_BLANK
	};
	
// メンバ変数
private:
//	インスタンスメンバ変数．Card 型データ（オブジェクト）がそれぞれ持っているデータ．
	int suit;	// 組
	int number;	// 番号

//	static は，クラスメンバのこと．Card クラスの中で共通の定数として Card::suitnames で参照できる．
	static const char * suitnames[]; // クラス変数（定数）．値の初期化は .cpp で行う

// メンバ関数
public:
	// デフォルトコンストラクタ(初期値不定)
	Card(void)	{ }

	// コピーコンストラクタ
	Card(const Card & c);

	// 組と番号を設定する
	void set(int st, int num) {
		suit = st;
		number = num; 
	}

	// 自身と tgt のカードの組，番号が等しいか判定 (true: 同; false: 異)
	// データとして同じオブジェクトかどうかではない．
	bool equal(Card tgt) { 
		return (suit == tgt.suit) && (number == tgt.number); 
	}

	bool isValid() {
		if ( ((SUIT_SPADE <= suit) && (suit <= SUIT_CLUB)) 
			 && (1 <= number && (number <= 13)) )
			return true;
		else if (suit == SUIT_JOKER)
			return true;
		return false;
	}
	
	// アクセサ
	int getNumber(void) {
		return number;
	}
	
	int getSuit(void)	{
		return suit;
	}

	// 標準出力から自身に入力する(true: 正常終了; false: 異常終了)
	bool scan(void);
	
	
	// 自身の値を標準出力に出力する
	void print(void);

	// おまけ
	friend std::ostream & operator<<(std::ostream& ostr, const Card & card) {
		ostr << '[' << suitnames[card.suit];
		if (card.suit != SUIT_JOKER )
			ostr << ", " << card.number;
		ostr << ']';
		return ostr;
	}

};
#endif
