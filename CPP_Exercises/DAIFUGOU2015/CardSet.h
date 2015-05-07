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

	void makeEmpty(void)	{ numcard = 0 ; }
	void clear(void)	{ makeEmpty(); }
		// 空にする.

	int size() { return numcard; }
	bool isEmpty(void)	{ return size() == 0; }
		// 自身は空集合か否か (true: 空; false: 空でない)

	const Card & operator[](const int i) const { return (i >= 0 && i < numcard ? cards[i] : cards[numcard]); }
	Card & operator[](const int i) { return (i >= 0 && i < numcard ? cards[i] : cards[numcard]); }
	
	void setupDeck(void);
		// 自身にすべて(maxnumcard 枚の)カードを入れる

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
