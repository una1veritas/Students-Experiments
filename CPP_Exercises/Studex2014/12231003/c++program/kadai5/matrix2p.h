// matrix2p.h - 2次正方行列型
//	作者: (市川　舞); 日付: (2014/04/17)
#ifndef MATRIX2P_H
#define MATRIX2P_H

// Matrix2 - 2次正方行列型
class Matrix2 {
// メンバ変数
private:
	double val[2][2];

// メンバ関数
public:
	Matrix2() {
	  val[0][0] = 0;
	  val[0][1] = 0;
	  val[1][0] = 0;
	  val[1][1] = 0;
	}
		// デフォルトコンストラクタ(初期値0)
	Matrix2(double x0, double x1, double x2, double x3);
	        // x0,x1,x2,x3を与えて行列Xを得るコンストラクタ
	Matrix2(const Matrix2 & v); // コピーコンストラクタ
	Matrix2 add(Matrix2 u);
		// 自身のベクトルとベクトルuとの和を求める
	Matrix2 sub(Matrix2 u);
		// 自身のベクトルとベクトルuとの差を求める
	Matrix2 mul(Matrix2 u);
                // 自身のベクトルとベクトルuとの積を求める
	void scan(void);
		// ベクトルの値を標準入力から自身に入力する
	void print(void);
		// 自身のベクトルの値を標準出力に出力する
};

#endif
