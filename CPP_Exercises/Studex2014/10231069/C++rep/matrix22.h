//
// matrix22.h - 2次元正方行列型(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#ifndef MATRIX22_H
#define MATRIX22_H

//
// Matrix22 - 2次元正方行列型
//
class Matrix22 {
// メンバ変数
private:
	double x[2][2];
// メンバ関数
public:
	Matrix22(void)	{x[0][0] = 0; x[0][1] = 0; x[1][0] = 0; x[1][1] = 0;}
		// デフォルトコンストラクタ
	Matrix22(double x00, double x01, double x10, double x11);
		// x00,x01,x10,x11 を与えて定数 を得るコンストラクタ
	Matrix22 add(Matrix22 u);
		// 自身の行列と行列 u との和を求める
	Matrix22 sub(Matrix22 u);
		// 自身の行列と行列 u との差を求める
	Matrix22 mul(Matrix22 u);
		// 自身の行列と行列 u との積を求める
	void scan(void);
		// 行列の値を標準入力から自身に入力する
	void print(){printf("|%f %f|\n",x[0][0],x[0][1]);
		 printf("|%f %f|",x[1][0],x[1][1]);}
		// 自身の行列の値を標準出力に出力する
};

#endif
