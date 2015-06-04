//
// vector2p.h - 2次元ベクトル型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#ifndef VECTOR2P_H
#define VECTOR2P_H

#define MESSAGE_OUT
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
	Vector2(void)	{
#ifdef MESSAGE_OUT
	printf("this is Vector2::Vector2(void).\n");
#endif
	x = 0; y = 0;
	}
		// デフォルトコンストラクタ(初期値不定)
	Vector2(const double x0, const double y0);
		// x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
	Vector2(const Vector2 & v);
	Vector2 add(const Vector2 & u);
		// 自身のベクトルとベクトル u との和を求める
	Vector2 sub(const Vector2 & u);
		// 自身のベクトルとベクトル u との差を求める
	void scan(void);
		// ベクトルの値を標準入力から自身に入力する
	void print(void) const;
		// 自身のベクトルの値を標準出力に出力する
};

#endif
