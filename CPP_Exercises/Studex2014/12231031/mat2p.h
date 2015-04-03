//
// mat2p.h - 2次元ベクトル型(C++版)
//	作者:佐藤彰哉; 日付:4/10
//
#ifndef MAT2P_H
#define MAT2P_H

//
// Mat2 - 2次正方行列型
//
class Mat2 {
// メンバ変数
private:
	double x;	// x値
	double y;	// y値
	double z;       // z値
	double w;       // w値

// メンバ関数
public:
	Mat2(void);
		// デフォルトコンストラクタ(初期値不定)
	Mat2(double x0, double y0,double z0,double w0);
		// x0, y0 z0,w0を与えて定数 (x0, y0) を得るコンストラクタ
	Mat2 add(Mat2 u);
		// 自身の行列と行列 u との和を求める
	Mat2 sub(Mat2 u);
		// 自身の行列と行列 u との差を求める
	Mat2 mul(Mat2 u);
	        //自身の行列と行列 u との積を求める
	void scan(void);
		// 行列の値を標準入力から自身に入力する
	void print(void);
		// 自身の行列の値を標準出力に出力する
	Mat2(const Mat2 & v);
};

#endif
