//
// vector2p.h - 2次元ベクトル型(C++版)
// 作者: 長濱彰秀　; 日付:4月２４日
//
#ifndef VECTOR2P_H
#define VECTOR2P_H

//
// Vector2 - 2次元ベクトル型
//
class Vector2 {
// メンバ変数
private:
	double x;	// x値
	double y;	// y値	
// メンバ関数
public:
	// デフォルトコンストラクタ(初期値0)
	Vector2(void) {
		x = 0;
		y = 0;
		printf("Default Constructor ( %f %f )\n", x, y);
	}
	// x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
	Vector2(double x0, double y0);
	// コピーコンストラクタ
	Vector2(const Vector2 &v);
	// 自身のベクトルとベクトル u との和を求める
	Vector2 add(Vector2 u);
	// 自身のベクトルとベクトル u との差を求める
	Vector2 sub(Vector2 u);
	// 自身のベクトルとベクトル u との内積を求める
	double dot(Vector2 u);
	// 自身のベクトルとベクトル u との外積を求める
	double cross(Vector2 u);
	// ベクトルの値を標準入力から自身に入力する
	void scan(void);
	// 自身のベクトルの値を標準出力に出力する
	void print(void);
};

#endif
