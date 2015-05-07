//
// Card - トランプカード型
//
#ifndef _CARD_H_
#define _CARD_H_

#include <iostream>

class Card {
	// メンバ変数
	private:
		int suit;	// 組
		int number;	// 番号
		
		static const char suitname[][8];
		static const char suitabbrevname[][4];

	// メンバ関数
	public:
	// トランプの組(suit)のコード
	enum SUIT {
		SUIT_SPADE = 0,
		SUIT_DIAMOND,
		SUIT_HEART,
		SUIT_CLUB,
		SUIT_JOKER,
		SUIT_INVALID = 7,
	};

	enum RANK {
		RANK_ACE = 1,
		RANK_TWO = 2,
		RANK_THREE = 3,
		RANK_FOUR = 4,
		RANK_FIVE = 5,
		RANK_SIX = 6,
		RANK_SEVEN = 7,
		RANK_EIGHT = 8,
		RANK_NINE = 9,
		RANK_TEN = 10,
		RANK_JACK = 11,
		RANK_QUEEN = 12,
		RANK_KING = 13,
		RANK_JOKER = 14,
		RANK_INVALID = 15,
		RANK_NULL = 0,
	};


	Card(void) : suit(SUIT_INVALID), number(RANK_INVALID) {}
		// デフォルトコンストラクタ
	Card(const char * str);
		// 文字列 str から作成する(文字列が適切なカードを表さない場合は、Card(void) と同じ。)


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

	void print(void);
		// 自身の値を標準出力に出力する
	/*
	 * Streaming
	 */
	std::ostream & printOn(std::ostream &out) const;

	friend std::ostream& operator<<(std::ostream& out, const Card & c) {
		return c.printOn(out);
	}
};

#endif

