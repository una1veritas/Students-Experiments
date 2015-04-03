
//
// vector2p.h - 2次元ベクトル型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#ifndef MATRIX_H
#define MATRIX_H
//
// Vector2 - 2次元ベクトル型
//
class Matrix {
// メンバ変数
private:
  double x00 ,x10 ,x01 ,x11 ;
// メンバ関数
public:
	Matrix(){x00=0; x01=0; x11=0; x10=0;}
		// デフォルトコンストラクタ(初期値不定)
	Matrix(double x00,double x01, double x10 ,double x11);
		// x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
	Matrix add(Matrix u);
		// 自身のベクトルとベクトル u との和を求める
	Matrix sub(Matrix u);
		// 自身のベクトルとベクトル u との差を求める
	Matrix mul(Matrix u);
	void scan(void);
		// ベクトルの値を標準入力から自身に入力する
	void print(void);
		// 自身のベクトルの値を標準出力に出力する
};

#endif
