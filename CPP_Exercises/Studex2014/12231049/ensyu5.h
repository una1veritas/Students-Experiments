//
// ensyu5.h - 2次元正方行列型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#ifndef VECTOR2P_H
#define VECTOR2P_H

//
// Matrix2 - 2次元正方行列型
//
class Matrix2 {
// メンバ変数
private:
	double x1y1;	// 1行1列目
	double x1y2;	// 1行2列目
	double x2y1;    // 2行1列目
	double x2y2;    // 2行2列目

// メンバ関数
public:
	Matrix2(void);
	    // デフォルトコンストラクタ
	Matrix2(double xa, double xb, double ya, double yb);
	    // 値を与えてのコンストラクタ
	Matrix2 add(Matrix2 u);
	    // 自身の行列と行列 u との和を求める
	Matrix2 sub(Matrix2 u);
	    // 自身の行列と行列 u との差を求める
	Matrix2 mul(Matrix2 u);
	    // 自身の行列と行列 u との積を求める
        void scan(void);
	    // 行列の値を標準入力から自身に入力する
	void print(void);
	    // 自身の行列の値を標準出力に出力する

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
	Vector2(void)	{printf("default\n"); x = 0; y = 0;}
		// デフォルトコンストラクタ(初期値不定)
	Vector2(double x0, double y0);
		// x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
	Vector2(const Vector2 & v);
	        // vベクトルと同じxy成分で初期化するコピーコンストラクタ
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
