;//
// matrix.h - 行列(C++版)
//	作者: 定平典久; 日付: 14/04/10
//
#ifndef MATRIX_H
#define MATRIX_H


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
     		// 自身の行列と行列 u との和を求める
	Matrix sub(Matrix u);
		// 自身の行列と行列 u との差を求める
	Matrix mul(Matrix u);
		// 自身の行列と行列u との積を求める
	void scan(void);
		// 行列の値を標準入力から自身に入力する
	void print(void);
		// 自身の行列の値を標準出力に出力する
};

#endif
