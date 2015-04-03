//
// matrix22_4.h - 2次正方行列型(C++版)
//	作者: Dewi; 日付: 2014/4/24
//
#ifndef MATRIX22
#define MATRIX22

//
// Matrix22 - 2次正方行列型
//

class Matrix22 {
// メンバ変数
private:
	double x[2][2];
   
// メンバ関数
public:
	Matrix22(void)	
	  {
	    x[0][0] = 0;
	    x[0][1] = 0;
	    x[1][0] = 0;
	    x[1][1] = 0;
	  }
		// デフォルトコンストラクタ
	Matrix22(double a, double b, double c, double d);
		// x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
	Matrix22 add(Matrix22 u);
		// 自身のmatrixとmatrixu との和を求める
	Matrix22 sub(Matrix22 u);
		// 自身のmatrixとmatrixu との差を求める
	Matrix22 mul(Matrix22 u);

	void scan(void);
		// matrixの値を標準入力から自身に入力する
	void print(void);
		// 自身のmatrixの値を標準出力に出力する
};

#endif
