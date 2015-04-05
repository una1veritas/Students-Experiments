//<演習5>
// vector2p.h - 2次元ベクトル型(C++版)
//	作者: 本石　大記; 日付: 2014/04/10
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
	Vector2(const Vector2 &v);
	//
	Vector2 add(Vector2 u);
		// 自身のベクトルとベクトル u との和を求める
	Vector2 sub(Vector2 u);
		// 自身のベクトルとベクトル u との差を求める
	void scan(void);
		// ベクトルの値を標準入力から自身に入力する
	void print(void);
		// 自身のベクトルの値を標準出力に出力する
};

//
// MATRIX  2次正方行列
//
class Matrix{
private:
    double x[2][2];    // x値
// メンバ関数
public:
    Matrix(void);
        // デフォルトコンストラクタ(初期値不定)
    Matrix(double x0[2][2]);
        // x0[2][2]を能えてx[][] を得るコンストラクタ
    Matrix add(Matrix u);
        // 自身のmatrixとmatrix u との和を求める
    Matrix sub(Matrix u);
        // 自身のmatrixとmatrix u との差を求める
    Matrix mul(Matrix u);
        // 自身のmatrixとmatrix u との積を求める
    void scan(void);
        // ベクトルの値を標準入力から自身に入力する
    void print(void);
        // 自身のベクトルの値を標準出力に出力する
};

#endif