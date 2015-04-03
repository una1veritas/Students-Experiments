//
// vector4p.h - 2次元ベクトル型(C++版)
//	作者: 工藤慎也; 日付: ４/１７
//
#ifndef VECTOR5P_H
#define VECTOR5P_H

//
// Matrix4 - 2次元行列型
//
class Matrix4 {
// メンバ変数
private:
	double x[2][2];	// x値

// メンバ関数
public:
	Matrix4(void)
	{
	   x[0][0] = 0;
	   x[0][1] = 0;
	   x[1][0] = 0;
	   x[1][1] = 0; 
	   printf("引数無し\n");
	}

	Matrix4(double x0, double x1, double x2, double x3)
	{
	    x[0][0] = x0; 
	    x[0][1] = x1;
	    x[1][0] = x2;
	    x[1][1] = x3;
	    printf("引数あり\n");
	}

	// デフォルトコンストラクタ(初期値) 
	Matrix4(const Matrix4 &v)
	{
	    x[0][0] = v.x[0][0]; 
	    x[0][1] = v.x[0][1];
	    x[1][0] = v.x[1][0];
	    x[1][1] = v.x[1][1];
	    printf("コピー\n");
	}
	// コピーコンストラクタ
	Matrix4 add(Matrix4 u);
		// 自身の行列と行列 u との和を求める
	Matrix4 sub(Matrix4 u);
		// 自身の行列と行列 u との差を求める
	Matrix4 mul(Matrix4 u);
		// 自身の行列と行列uの乗算を求める
	void scan(void);
		// 行列の値を標準入力から自身に入力する
	void print(void);
		// 自身の行列の値を標準出力に出力する
};

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
	Vector2(void)
	{
	   x = 0;
	   y = 0;
	   printf("引数無し\n");
	}

	Vector2(double x0, double y0)
	{
	    x = x0; 
	    y = y0;
	    printf("引数あり\n");
	}

	// デフォルトコンストラクタ(初期値) 
	Vector2(const Vector2 &v)
	{
	    x = v.x; 
	    y = v.y;
	    printf("コピー\n");
	}
	// コピーコンストラクタ
	Vector2 add(Vector2 u);
		// 自身のベクトルとベクトル u との和を求める
	Vector2 sub(Vector2 u);
		// 自身のベクトルとベクトル u との差を求める
	double inp(Vector2 u);
		// 自身のベクトルとベクトルuの内積を求める
	double oup(Vector2 u);
		// 自身のベクトルとベクトルuの外積を求める
	void scan(void);
		// ベクトルの値を標準入力から自身に入力する
	void print(void);
		// 自身のベクトルの値を標準出力に出力する
};

#endif
