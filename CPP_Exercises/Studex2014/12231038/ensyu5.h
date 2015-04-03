//
// ensyu5.h - 2次元ベクトル型.2次正方行列(C++版)
//      作者: (あなたの名前); 日付: (完成した日付)
//
#ifndef ENSYU5_H
#define ENSYU5_H

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
		// 自身のベクトルの値を標準出力に出力する
	Vector2(const Vector2& v);
};

class Ensyu4 {
// メンバ変数
private:
  double x[2][2];
// メンバ関数
public:
	Ensyu4(void);
		// デフォルトコンストラクタ(初期値不定)
        Ensyu4(double x1, double x2, double x3, double x4);
		// x[][]を与えて定数 (x0, y0) を得るコンストラクタ
	Ensyu4 add(Ensyu4 u);
		// 自身のベクトルとベクトル u との和を求める
	Ensyu4 sub(Ensyu4 u);
	        // 自身のベクトルとベクトル u との差を求める
	Ensyu4 mul(Ensyu4 u);
	        // 自分のベクトルとベクトル u との差を求める
	void scan(void);
		// ベクトルの値を標準入力から自身に入力する
	void print(void);
		// 自身のベクトルの値を標準出力に出力する
	Ensyu4(const Ensyu4& v);
};


#endif
