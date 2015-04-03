//
// vector2p.h - 2次元ベクトル型(C++版)
//　作成者：朝比奈　涼；　作成日：2104 /4/24
//
#ifndef VECTOR2P_H
#define VECTOR2P_H

//
// Vector2 - 2次元ベクトル型
//
class Vector {
// メンバ変数
private:
	double x[2][2];	// 行列の値
// メンバ関数
public:
	Vector(void);
		// デフォルトコンストラクタ(初期値不定)
	Vector(double [2][2]);
		// x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
	Vector(const Vector &);
	        //全く同じx及びy成分を初期化されたオブジェクトを作成するコンストラクタ
	Vector add(Vector u);
		// 自身のベクトルとベクトル u との和を求める
      	Vector sub(Vector u);
		// 自身のベクトルとベクトル u との差を求める
       	Vector mul(Vector u);
		// 自身のベクトルとベクトル u との内積を求める
	Vector div(Vector u);
		// 自身のベクトルとベクトル u との外積を求める
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
	Vector2(void);
		// デフォルトコンストラクタ(初期値不定)
	Vector2(double x0, double y0);
		// x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
	Vector2(const Vector2 &);
	        //全く同じx及びy成分を初期化されたオブジェクトを作成するコンストラクタ
	Vector2 add(Vector2 u);
		// 自身のベクトルとベクトル u との和を求める
	Vector2 sub(Vector2 u);
		// 自身のベクトルとベクトル u との差を求める
	void scan(void);
		// ベクトルの値を標準入力から自身に入力する
	void print(void);
		// 自身のベクトルの値を標準出力に出力する
};

#endif
