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
		int rank;	// 番号
		
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


	Card(void) : suit(SUIT_INVALID), rank(RANK_INVALID) {}
		// デフォルトコンストラクタ
	Card(const char * str);
		// 文字列 str から作成する(文字列が適切なカードを表さない場合は、Card(void) と同じ。)


	void set(int s, int r)
		{ suit = s; rank = r; return; }
		// 自身に指定した組と番号を入れる

	bool isEqualTo(const Card & tgt) const
		{ return suit == tgt.suit && rank == tgt.rank; }
		// 自身と tgt が同じか否かの判定 (true: 同; false: 異)
	bool operator==(const Card & tgt) const { return isEqualTo(tgt); }

	int getRank(void) const	{ return rank; }

	int getSuit(void) const	{ return suit; }
		// アクセサ

	bool isJoker() { return rank == RANK_JOKER; }
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

