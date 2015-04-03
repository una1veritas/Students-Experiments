//
// vector2p.h - 2次元ベクトル型(C++版)
//	作者: 定平典久; 日付: 14/04/10
//
#ifndef MATRIX_H
#define MATRIX_H

//
// Vector2 - 2次元ベクトル型
//
class Matrix {
// メンバ変数
private:
  double mat[2][2];
   	// y値
// メンバ関数
public:
	Matrix(void)	{ }
		// デフォルトコンストラクタ(初期値不定)
	Matrix(double x0, double y0,double x1, double y1);
		// x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
	Matrix add(Matrix u);
     		// 自身のベクトルとベクトル u との和を求める
	Matrix sub(Matrix u);
		// 自身のベクトルとベクトル u との差を求める
	Matrix mul(Matrix u);
		// 自身のベクトルとベクトル u との内積を求める
	void scan(void);
		// ベクトルの値を標準入力から自身に入力する
	void print(void);
		// 自身のベクトルの値を標準出力に出力する
};

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
	Vector2(void)	{ }
		// デフォルトコンストラクタ(初期値不定)
	Vector2(double x0, double y0);
		// x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
	Vector2 add(Vector2 u);
		// 自身のベクトルとベクトル u との和を求める
	Vector2 sub(Vector2 u);
		// 自身のベクトルとベクトル u との差を求める
	double inpro(Vector2 u);
		// 自身のベクトルとベクトル u との内積を求める
	double outpro(Vector2 u);
	// 自身のベクトルとベクトル u との外積を求める
	void scan(void);
		// ベクトルの値を標準入力から自身に入力する
	void print(void);
		// 自身のベクトルの値を標準出力に出力する
};
#endif
