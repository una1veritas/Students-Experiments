//
// enshu5.h - 2次元ベクトル型と2次正方行列型(C++版)テストプログラム
//	作者: Dewi; 日付: 2014/4/24
//
#ifndef ENSHU5
#define ENSHU5

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
	Vector2(void);
	Vector2(double x0, double y0);
		// x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
	Vector2 add(Vector2 u);
		// 自身のベクトルとベクトル u との和を求める
	Vector2 sub(Vector2 u);
		// 自身のベクトルとベクトル u との差を求める
	void scan(void);
		// ベクトルの値を標準入力から自身に入力する
	void print(void);
		// 自身のベクトルの値を標準出力に出力する
	Vector2(const Vector2 & v);
};


//
// Matrix22 - 2次正方行列型
//

class Matrix22 {
// メンバ変数
private:
	double x[2][2];
   
// メンバ関数
public:
	Matrix22(void);	
		// デフォルトコンストラクタ
	Matrix22(double a, double b, double c, double d);
		
	Matrix22 add(Matrix22 u);
		// 自身のmatrixとmatrix u との和を求める
	Matrix22 sub(Matrix22 u);
		// 自身のmatrixとmatrix u との差を求める
	Matrix22 mul(Matrix22 u);

	void scan(void);
		// matrixの値を標準入力から自身に入力する
	void print(void);
		// 自身のmatrixの値を標準出力に出力する
	Matrix22(const Matrix22 & v);
};

#endif
