//
// cardset.h - トランプカードの集合型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#ifndef CARDSET_H
#define CARDSET_H
//
// CardSet - トランプカードの集合型
//
class CardSet {
// 定義・宣言
public:
	const static int maxnumcard = 53;	// カード総数
// メンバ変数
private:
	int numcard;		// 保持しているカードの数
	Card cards[maxnumcard+1];	// カードを入れる配列
// メンバ関数
private:
	int locate(Card target);
		// 配列の先頭から最初にみつかる target のカードの位置（添字）を返す。ない場合は -1 を返す。
	int locate(int rank);
		// 配列の先頭から最初にみつかるランクが rank のカードの位置（添字）を返す。ない場合は -1 を返す。
public:
	CardSet(void);
	// デフォルトコンストラクタ
	CardSet(const CardSet & cards);

	void clear(void)	{ numcard = 0 ; }
		// 空にする.

	int size() { return numcard; }
	bool isEmpty(void)	{ return size() == 0; }
		// 自身は空集合か否か (true: 空; false: 空でない)

	const Card & operator[](const int i) const { return (i >= 0 && i < numcard ? cards[i] : cards[numcard]); }
	Card & operator[](const int i) { return (i >= 0 && i < numcard ? cards[i] : cards[numcard]); }
	
	void setupDeck(void);
		// 自身にすべて(maxnumcard 枚の)カードを入れる

	bool pickup(Card & ret, int pos = -1);
		// 自身から pos 枚目のカードを除き ret に返す
		// pos が適正な範囲外のときはランダムに選ぶ
		// true: ぬきとり成功; false: 失敗（一枚もなかった）
	bool insert(Card newcard);
	// 自身に newcard のカードを入れる(true: 成功; false: 失敗)

	bool insertAll(const CardSet & cards);

	bool remove(Card target);
		// カード target を削除（最初にみつけた一枚）。削除した場合 true, なかった場合 false
	bool remove(int rnum);
		// カードのランクが rnum の最初にみつけたカード一枚をのぞく。削除した場合 true、なかった場合 false
	void print(void);
		// 標準出力に印字。

	void shuffle(void);

	// Streaming
	//
	std::ostream&  printOn(std::ostream& out) const;

	friend std::ostream& operator<<(std::ostream& out, const CardSet & c) {
		return c.printOn(out);
	}
};

#endif
