// matrix.h - 2次正方行列型(C++版)
// 作者: 福田真実; 日付: 4/28
//
#ifndef MATRIX_H
#define MATRIX_H

//
// Matrix - 2次正方行列型
//
class Matrix {
// メンバ変数
private:
	double x[2][2];	// 値
// メンバ関数
public:
	// デフォルトコンストラクタ(初期値0)
	Matrix(void) {
		x[0][0] = 0;
		x[0][1] = 0;
		x[1][0] = 0;
		x[1][1] = 0;
	}
       
	Matrix(double x00, double x01, double x10, double x11);
	// x00, x01, x10, x11 を与えて2次正方行列を得るコンストラクタ
	Matrix(const Matrix &y);
	// コピーコンストラクタ
	Matrix add(Matrix y);
	// 自身の行列と行列 y との和を求める
	Matrix sub(Matrix y);
	// 自身の行列と行列 y との差を求める
	Matrix mul(Matrix y);
	// 自身の行列と行列 y との積を求める
	void scan(void);
	// 行列の値を標準入力から自身に入力する
	void print(void);
	// 自身の行列の値を標準出力に出力する
};

#endif
