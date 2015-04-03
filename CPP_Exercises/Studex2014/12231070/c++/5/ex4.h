//
// ex.h - 2次元ベクトル型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#ifndef MATRIX22P_H
#define MATRIX22P_H
//
// Matrix22 - 2次元ベクトル型
//
class Matrix22 {
// メンバ変数
private:
	double x[2][2];
// メンバ関数
public:
	Matrix22(void)	{ 
		x[0][0] = 0;
		x[0][1] = 0;
		x[1][0] = 0;
		x[1][1] = 0;
	}
		// デフォルトコンストラクタ

	Matrix22(double x1, double x2, double x3, double x4);
		// xを与えて定数を得るコンストラクタ
	Matrix22 add(Matrix22 z);
		// 自身のベクトルとベクトル u との和を求める
	Matrix22 sub(Matrix22 z);
		// 自身のベクトルとベクトル u との差を求める
	Matrix22 mul(Matrix22 z);
		// 
	void scan(void);
		// ベクトルの値を標準入力から自身に入力する
	void print(void);
		// 自身のベクトルの値を標準出力に出力する
};

#endif
