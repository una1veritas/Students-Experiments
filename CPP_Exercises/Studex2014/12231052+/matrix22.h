//
// matrix22.h - 2次正方行列型(C++版)
// 作者: 長濱彰秀; 日付:4月２４日
//
#ifndef MATRIX22_H
#define MATRIX22_H

//
// Matrix22 - 2次正方行列型
//
class Matrix22 {
// メンバ変数
private:
	double x[2][2];	// 値
// メンバ関数
public:
	// デフォルトコンストラクタ(初期値0)
	Matrix22(void) {
		x[0][0] = 0;
		x[0][1] = 0;
		x[1][0] = 0;
		x[1][1] = 0;
	}
	// x00, x01, x10, x11 を与えて2次正方行列を得るコンストラクタ
	Matrix22(double x00, double x01, double x10, double x11);
	// コピーコンストラクタ
	Matrix22(const Matrix22 &y);
	// 自身の行列と行列 y との和を求める
	Matrix22 add(Matrix22 y);
	// 自身の行列と行列 y との差を求める
	Matrix22 sub(Matrix22 y);
	// 自身の行列と行列 y との積を求める
	Matrix22 mul(Matrix22 y);
	// 行列の値を標準入力から自身に入力する
	void scan(void);
	// 自身の行列の値を標準出力に出力する
	void print(void);
};

#endif
