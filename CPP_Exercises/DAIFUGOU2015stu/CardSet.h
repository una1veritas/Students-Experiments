//
// cardset.h - トランプカードの集合型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#ifndef CARDSET_H
#define CARDSET_H

#include <cstdlib>

//
// CardSet - トランプカードの集合型
//
class CardSet {
// 定義・宣言
public:
	const static int maxnumcard = 53;	// １デッキ使用の場合のカード最大枚数、ジョーカー１枚ふくむ
// メンバ変数
private:
	int numcard;		// 現在の集合内のカード数
	Card cards[maxnumcard];	// カードのデータ

// メンバ関数
private:
	int locate(const Card & target) const;
		// 内部での target のカードの位置を返す(-1: ない)
	int locate(const int num) const;
		// 内部で数字が num のカードの位置を返す(-1: ない)

public:
	CardSet(void);
		// デフォルトコンストラクタ(初期値空集合)
	CardSet(const CardSet & cset);

	void makeEmpty(void)	{ numcard = 0 ; }
	void clear(void)	{ makeEmpty(); }
		// 自身を空集合にする
	bool isEmpty(void) const { return numcard == 0; }
		// 自身が空集合か否かの判定 (true: 空; false: 非空)

	int size() const { return numcard; }
	const Card & at(int) const;
	Card & operator[](int);

	void setupDeck(const bool useJoker = true);
		// 自身に全部の(maxnumcard 枚の)カードを入れる

	// カード target または番号が num であるカードが何枚めにあるかを返す(-1: ない)
	int find(const Card & target) const { return locate(target); }
	int find(const int num) const { return locate(num); }


	int insert(Card newcard);
		// 自身に newcard を入れる(-1: もう入らないので失敗; 0以上: 成功)
	int insert(const CardSet & cards);
	int insertAll(const CardSet & cards) { return insert(cards); }

	int remove(const Card & target);
		// 自身から target と同一のカードを取り除く(-1: 失敗; 0以上: 成功)
	int remove(const int num);
		// 自身から数字が num であるカードいずれか一枚を除く(-1: 失敗; 0以上: 成功)

	int pickup(Card & card, int targetpos);
		// 自身から targetpos 枚目のカードを除き，そのカードを返す
	int pickup(Card & card) { return pickup(card, -1); }
		// 同様だが，ランダムに選ぶ
		// (-1: 失敗; 0以上: 成功)

	void print(void);
		// 自身の状態を標準出力に出力する

	void shuffle(const time_t & seed);

	void shuffle(void) {
		time_t seed;
	    time(&seed);
	    shuffle(seed);
	}

	// Streaming
	//
	std::ostream&  printOn(std::ostream& out) const;

	friend std::ostream& operator<<(std::ostream& out, const CardSet & c) {
		return c.printOn(out);
	}

};

#endif
