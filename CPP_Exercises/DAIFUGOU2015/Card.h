//
// card.h - トランプカードの型
//	作者: (あなたの名前); 日付: (完成した日付)
//
#ifndef CARD_H
#define CARD_H

#include <cstdio>
#include <iostream>
//
// Card - トランプカード型
//
class Card {
	// メンバ変数
	private:
		int suit;	// 組
		int number;	// 番号
		
	// クラス定数
		static const char suitname[][8];
		static const char suitabbrevname[][4];
		static const char ranksymbol[][3];

	// メンバ関数
	public:
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
<<<<<<< HEAD


	Card(void) : suit(SUIT_INVALID), number(RANK_INVALID) {}
=======
	
// メンバ関数
public:
	// デフォルトコンストラクタ(初期値は白カード)
	Card(void) : suit(SUIT_BLANK), number(0) {}
>>>>>>> master
		// デフォルトコンストラクタ
	Card(const char * str);
		// 文字列 str から作成する(文字列が適切なカードを表さない場合は、Card(void) と同じ。)

	// 組と番号を設定する
	void set(int st, int num) {
		suit = st;
		number = num; 
	}

<<<<<<< HEAD
	void set(int s, int r)
		{ suit = s; number = r; return; }
		// 自身に指定した組と番号を入れる

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
	int getNumber(void) const {
		return number;
	}
	int getRank(void) const { return getNumber(); }  // for backward compatibility.

	int getSuit(void) const {
		return suit;
	}


	bool isJoker() { return suit == SUIT_JOKER; }
	bool isGreaterThan(Card c);
=======
	// 自身と tgt のカードの組，番号が等しいか判定 (true: 同; false: 異)
	// データとして同じオブジェクトかどうかではない．
	bool equal(Card tgt) const {
		return (suit == tgt.suit) && (number == tgt.number); 
	}

	// まともなカードか？
	bool isValid(void) const;
>>>>>>> master

	// アクセサ
	int getNumber(void) const {
		return number;
	}
	int getRank(void) const { return getNumber(); }  // for backward compatibility.

	int getSuit(void) const {
		return suit;
	}
	
	bool isJoker() const { return suit == SUIT_JOKER; }
	bool isGreaterThan(const Card & c) const;

	// 標準出力から自身に入力する(true: 正常終了; false: 異常終了)
	bool scan(void);
	
	
	// 自身の値を標準出力に出力する
	void print(void) { printOn(std::cout); }
	std::ostream & printOn(std::ostream& ostr) const;

	// おまけ
	friend std::ostream & operator<<(std::ostream& ostr, const Card & card) {
		return card.printOn(ostr);
	}
};

#endif
