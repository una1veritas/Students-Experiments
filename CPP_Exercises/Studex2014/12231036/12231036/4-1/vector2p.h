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
	Vector2 add(Vector2 u);
		// 自身のベクトルとベクトル u との和を求める
	Vector2 sub(Vector2 u);
		// 自身のベクトルとベクトル u との差を求める
	void scan(void);
		// ベクトルの値を標準入力から自身に入力する
	void print(void);
		// 自身のベクトルの値を標準出力に出力するr
	Vector2(const Vector2 & v);
		//コピーコンストラクタ
};


class Matrix22 {
// メンバ変数
private:
	int x[2][2];	// x値	
// メンバ関数
public:
	Matrix22(void);
		// デフォルトコンストラクタ(初期値不定)
	Matrix22(int x0, int y0,int x1, int y1);
		// x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
	Matrix22 addm(Matrix22 u);
		// 自身のベクトルとベクトル u との和を求める
	Matrix22 subm(Matrix22 u);
		// 自身のベクトルとベクトル u との差を求める
	Matrix22 mulm(Matrix22 u);
		// 自身のベクトルとベクトル u との差を求める
	void scanm(void);
		// ベクトルの値を標準入力から自身に入力する
	void printm(void);
		// 自身のベクトルの値を標準出力に出力する
	Matrix22(const Matrix22 & v);
		//コピーコンストラクタ
};



#endif
