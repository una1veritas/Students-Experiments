//
// cardset.h - トランプカードの集合型(C++版) 演習9版
// 作者: Yuya Uekama; 日付: 2013.04.18
//
#ifndef CARDSET_H
#define CARDSET_H

//
// Card - トランプカード型(整数のみでカードを表現)
//
class Card {
// クラス定数
// トランプの組(suit)のコード
public:
	enum {
		SUIT_SPADE,
		SUIT_DIAMOND,
		SUIT_HEART,
		SUIT_CLUB,
		SUIT_JOKER
	};

// メンバ変数
private:
	int suit;	// 組
	int number;	// 番号
// メンバ関数
public:
	// デフォルトコンストラクタ(初期値不定)
	Card(void) { }

	// 組と番号を設定する
	void set(int st, int num) {
		if (num == 0) {
			number = 52;
		} else {
			number = ((st * 13) + (num - 1));
		}
	}

	// 自身と tgt のカードの組，番号が等しいか判定 (true: 同; false: 異)
	// データとして同じオブジェクトかどうかではない．
	bool equal(Card tgt) {
		return (number == tgt.number);
	}

	bool isValid() {
		return (0 <= number && number <= 52);
	}

	// アクセサ
	int gnumber(void) {
		if (number == 52)
			return 0;
		else
			return ((number % 13) + 1);
	}

	int gsuit(void)	{
		return (number / 13) ;
	}

	// 標準出力から自身に入力する(true: エラー; false: 正常終了)
	bool scan(void);

	// 自身の値を標準出力に出力する
	void print(void);
};

//
// CardSet - トランプカードの集合型
//
class CardSet {
// 定義・宣言
public:
	const static int maxnumcard = 53;	// カード総数
// メンバ変数
private:
	int numcard;	// 現在の集合内のカード数
	Card cdat[maxnumcard];	// カードのデータ
// メンバ関数
private:
	// 内部での target のカードの位置を返す(-1: ない)
	int locate(Card target);
	// 内部で数字が num のカードの位置を返す(-1: ない)
	int locate(int num);
public:
	// デフォルトコンストラクタ(初期値空集合)
	CardSet(void) { makeempty(); }

	// 自身を空集合にする
	void makeempty(void) { numcard = 0; }

	// 自身が空集合か否かの判定 (true: 空; false: 非空)
	bool isempty(void) { return numcard == 0; }

	// 自身に全部の(maxnumcard 枚の)カードを入れる
	void makedeck(void);

	// 自身から targetpos 枚目のカードを除き *ret に返す
	// targetpos が -1 のときはランダムに選ぶ
	// (true: 失敗; false: 成功)
	bool pickup(Card* ret, int targetpos = -1);

	// 自身に newcard のカードを入れる(true: 失敗; false: 成功)
	bool insert(Card newcard);

	// 自身から target のカードを除く(true: 失敗; false: 成功)
	bool remove(Card target);

	// 自身から数字が num であるカードを除く(true: 失敗; false: 成功)
	bool remove(int num);

	// 自身の状態を標準出力に出力する
	void print(void);
};

#endif

 
