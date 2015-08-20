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
		static const int NUMBER_JOKER = 92;
		static const Card Joker;

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
	
// メンバ関数
public:
	// デフォルトコンストラクタ(初期値は白カード)
	Card(void) : suit(SUIT_BLANK), number(0) {}

	Card(const int su, const int num) : suit(su), number(num) {}

	Card(const char * str);
		// 文字列 str から作成する(文字列が適切なカードを表さない場合は、Card(void) と同じ。)

	// 自身と tgt のカードの組，番号が等しいか判定 (true: 同; false: 異)
	// データとして同じオブジェクトかどうかではない．
	bool equal(Card tgt) const {
		return (suit == tgt.suit) && (number == tgt.number); 
	}

	// まともなカードか？
	bool isValid(void) const;

	// アクセサ
	// 組と番号を設定する
	void set(int st, int num) {
		suit = st;
		number = num;
	}

	int getNumber(void) const {
		return number;
	}
	int getRank(void) const { return getNumber(); }  // for backward compatibility.

	int getSuit(void) const {
		return suit;
	}

	// 入力ストリームからカードの値をよみ自身に設定する(true: 正常終了; false: 値をよめなかった)
	bool scan(const char * str);
	bool scan(std::istream & str);

	bool isJoker() const { return suit == SUIT_JOKER; }

	// it's game dependent.
	/*
	bool isGreaterThan(const Card & c) const;
	*/
	
	// 自身の値を標準出力に出力する
	void print(void) { printOn(std::cout); }
	std::ostream & printOn(std::ostream& ostr) const;

	// おまけ
	friend std::ostream & operator<<(std::ostream& ostr, const Card & card) {
		return card.printOn(ostr);
	}
};

#endif
