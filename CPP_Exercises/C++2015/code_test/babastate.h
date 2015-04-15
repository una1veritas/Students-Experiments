//
// babastate.h - ババ抜きの状態型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#ifndef BABASTATE_H
#define BABASTATE_H

#include "card.h"
#include "cardset.h"

//
// BabaState - ババ抜きの状態型
//
class BabaState {
// 定義・宣言
public:
	static const int numplayer = 5;	// プレーヤ数
// メンバ変数
private:
	CardSet hand[numplayer];  // 各プレーヤの持ち手
// メンバ関数
public:
	BabaState(void)	{ reset(); }
		// デフォルトコンストラクタ(初期値はカードを配った状態)
	void reset(void);
		// リセット(はじめにカードを配りおえた状態にする)
	bool isFinished(int plr)	{ return hand[plr].isEmpty(); }
		// plr 番のプレーヤが上がった(終了した)か否かの判定
		// (true: 上がった; false: 未了)
	bool move(int from, int to);
		// to 番のプレーヤが from 番のプレーヤからカードを取る
		// (true: 成功; false: 失敗)
	void print(void);
		// 自身の状態を標準出力に出力する
};

#endif
