//
// vector2p.h - 2次元ベクトル型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
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
	Vector2(void);
		// デフォルトコンストラクタ(初期値不定)
	Vector2(double x0, double y0);
		// x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
	Vector2(const Vector2 & v);

	Vector2 add(Vector2 u);
		// 自身のベクトルとベクトル u との和を求める
	Vector2 sub(Vector2 u);
		// 自身のベクトルとベクトル u との差を求める
	void scan(void);
		// ベクトルの値を標準入力から自身に入力する
	void print(void);
		// 自身のベクトルの値を標準出力に出力する
};

class Matrix22 {
// メンバ変数
private:
	double x[2][2];	// x値
// メンバ関数
public:
	Matrix22(void);
		// デフォルトコンストラクタ(初期値不定)
	Matrix22(double x[2][2]);
		// x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
	Matrix22 add(Matrix22 u);
		// 自身のベクトルとベクトル u との和を求める
	Matrix22 sub(Matrix22 u);
		// 自身のベクトルとベクトル u との差を求める
	Matrix22 mul(Matrix22 u);
		// 自身のベクトルとベクトル u との積を求める
	void scan(void);
		// ベクトルの値を標準入力から自身に入力する
	void print(void);
		// 自身のベクトルの値を標準出力に出力する
};

#endif
