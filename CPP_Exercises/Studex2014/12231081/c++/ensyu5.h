//演習5

#ifndef VECTOR2P_H
#define VECTOR2P_H

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
	Vector2(void)	{
	  x = 0; y = 0;
	  printf("check.");
	}
		// デフォルトコンストラクタ(初期値不定)
	Vector2(double x0, double y0);
		// x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
	Vector2(const Vector2 & v);
	       // copy
	Vector2 add(Vector2 u);
		// 自身のベクトルとベクトル u との和を求める
	Vector2 sub(Vector2 u);
		// 自身のベクトルとベクトル u との差を求める
	void scan(void);
		// ベクトルの値を標準入力から自身に入力する
	void print(void);
		// 自身のベクトルの値を標準出力に出力する
};


//
// Matrix22 - 2次正方行列型
//
class Matrix22 {
// メンバ変数
private:
	double x[2][2];	// x値
// メンバ関数
public:
	Matrix22(void)	{
	  x[0][0] = 0; x[0][1] = 0; x[1][0] = 0; x[1][1] = 0;
      	}
		// デフォルトコンストラクタ(初期値不定)
	Matrix22(double x0, double x1, double x2, double x3);
		// x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
	Matrix22(const Matrix22 & v);
	       // copy
	Matrix22 add(Matrix22 z);
	
	Matrix22 sub(Matrix22 z);
	
	Matrix22 mul(Matrix22 z);
	
	void scan(void);
	
	void print(void);
	
};




#endif
