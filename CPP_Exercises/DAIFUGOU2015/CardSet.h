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
	const static int maxnumcard = 53;	// カード総数
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
<<<<<<< HEAD
		// 空にする.
=======
		// 自身を空集合にする
	bool isEmpty(void) const { return numcard == 0; }
		// 自身が空集合か否かの判定 (true: 空; false: 非空)
>>>>>>> master


	int size() const { return numcard; }
	const Card & at(int) const;
	Card & operator[](int);

<<<<<<< HEAD
	int pickup(Card & card, int targetpos = -1);
		// 自身から pos 枚目のカードを除き ret に返す
		// pos が適正な範囲外のときはランダムに選ぶ
		// true: ぬきとり成功; false: 失敗（一枚もなかった）
	int insert(Card newcard);
		// 自身に newcard を入れる(-1: もう入らないので失敗; 0以上: 成功)
	int insertAll(const CardSet & cards);
		// カードセットの内容を追加する
	int remove(Card & target);
		// 自身から target と同一のカードを取り除く(-1: 失敗; 0以上: 成功)
	int remove(int num);
		// 自身から数字が num であるカードいずれか一枚を除く(-1: 失敗; 0以上: 成功)

=======
	void setupDeck(void);
		// 自身に全部の(maxnumcard 枚の)カードを入れる
	int pickup(Card & card, int targetpos);
		// 自身から targetpos 枚目のカードを除き，そのカードを返す
	int pickup(Card & card) { return pickup(card, -1); }
		// 同様だが，ランダムに選ぶ
		// (-1: 失敗; 0以上: 成功)
	int insert(Card newcard);
		// 自身に newcard を入れる(-1: もう入らないので失敗; 0以上: 成功)
	int insert(const CardSet & cards);
	int insertAll(CardSet & cards) { return insert(cards); }

	int remove(Card & target);
		// 自身から target と同一のカードを取り除く(-1: 失敗; 0以上: 成功)
	int remove(int num);
		// 自身から数字が num であるカードいずれか一枚を除く(-1: 失敗; 0以上: 成功)

>>>>>>> master
	void print(void);
		// 自身の状態を標準出力に出力する

	void shuffle(void);

	// Streaming
	//
	std::ostream&  printOn(std::ostream& out) const;

	friend std::ostream& operator<<(std::ostream& out, const CardSet & c) {
		return c.printOn(out);
	}

};

#endif
