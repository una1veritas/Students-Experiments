// vector2p.h - 2次元ベクトル型(C++版)
//	作者: (市川　舞); 日付: (2014/04/17)
#ifndef VECTOR2P_H
#define VECTOR2P_H

// Vector2 - 2次元ベクトル型
class Vector2 {
// メンバ変数
private:
	double x;	// x値
	double y;	// y値
// メンバ関数
public:
	Vector2() { // デフォルトコンストラクタ(初期値0)
	  x = 0;
	  y = 0;
	}
	Vector2(double x0, double y0); // x0,y0を与えて定数(x0,y0)を得るコンストラクタ
	Vector2(const Vector2 & v); // コピーコンストラクタ
	Vector2 add(Vector2 u);
		// 自身のベクトルとベクトルuとの和を求める
	Vector2 sub(Vector2 u);
		// 自身のベクトルとベクトルuとの差を求める
	void scan(void);
		// ベクトルの値を標準入力から自身に入力する
	void print(void);
		// 自身のベクトルの値を標準出力に出力する
};

#endif
