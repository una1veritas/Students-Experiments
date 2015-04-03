//
// cardset.h - トランプカードの集合型(C++版)
//	作者: (山本晃也); 日付:4/25 (完成した日付) 未完成の課題８
//
#ifndef CARDSET_H
#define CARDSET_H

//
// Card - トランプカード型
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
		SUIT_JOKER,
		SUIT_NUMBER
	};
	
// メンバ変数
private:
	int suit;	// 組
	int number;	// 番号
// メンバ関数
public:
	// デフォルトコンストラクタ(初期値不定)
	Card(void)	{ }
	// 組と番号を設定する
	void set(int st, int num) {
		suit = st;
		number = st * num; 
	}

	// 自身と tgt のカードの組，番号が等しいか判定 (true: 同; false: 異)
	// データとして同じオブジェクトかどうかではない．
	bool equal(Card tgt) { 
	  if(number % 13 + 1 == tgt.number % 13+1)
	     return true;
	}

	bool isValid() {
		if (number < 0 || number > 52)
			return true;
		//	else if (s)
		//	return true;
		return false;
	}
	
	// アクセサ
	int gnumber(void) {
	  return number % 13 + 1;//ここで数字をいじろうとした
	}
	
	int gsuit(void)	{
	  if(0<=number&& number<13)//数字をここでわりふろうとした
	    return 1;
	  if(13<=number&&number<26)
	    return 2;
	  if(26 <= number && number <39)
	    return 3;
	  if(39 <= number && number <52)
	    return 4;
	  if(number == 52)
	    return 5;
	  
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
	int numcard;		// 現在の集合内のカード数
	Card cdat[maxnumcard];	// カードのデータ
// メンバ関数
private:
	int locate(Card target);
		// 内部での target のカードの位置を返す(-1: ない)
	int locate(int num);
		// 内部で数字が num のカードの位置を返す(-1: ない)
public:
	CardSet(void)		{ makeempty(); }
		// デフォルトコンストラクタ(初期値空集合)
	void makeempty(void)	{ numcard = 0 ; }
		// 自身を空集合にする
	bool isempty(void)	{ return numcard == 0; }
		// 自身が空集合か否かの判定 (true: 空; false: 非空)
	void makedeck(void);
		// 自身に全部の(maxnumcard 枚の)カードを入れる
	bool pickup(Card* ret, int targetpos = -1);
		// 自身から targetpos 枚目のカードを除き *ret に返す
		// targetpos が -1 のときはランダムに選ぶ
		// (true: 失敗; false: 成功)
	bool insert(Card newcard);
		// 自身に newcard のカードを入れる(true: 失敗; false: 成功)
	bool remove(Card target);
		// 自身から target のカードを除く(true: 失敗; false: 成功)
	bool remove(int num);
		// 自身から数字が num であるカードを除く(true: 失敗; false: 成功)
	void print(void);
		// 自身の状態を標準出力に出力する
		
};

#endif
