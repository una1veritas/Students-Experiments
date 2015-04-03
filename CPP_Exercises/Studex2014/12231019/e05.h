#ifndef VECTOR2C_H
#define VECTOR2C_H

class Matrix22{
private:
   double x[2][2];
public:
  Matrix22(void);
  Matrix22(double x0);
  Matrix22 add(Matrix22 u);
  Matrix22 sub(Matrix22 u);
  Matrix22 mul(Matrix22 u);
  void scan(void);
  void print(void);
};

//
class Vector2 {
// メンバ変数
private:
	double x;	// x値
	double y;	// y値
// メンバ関数
public:
	Vector2(void){
		x=0,y=0;
		printf("デフォルトコンストラクタ \n  x=%lf y=%lf \n",x,y);
	}
		// デフォルトコンストラクタ(初期値不定)
	Vector2(const Vector2& v);
	Vector2(double x0, double y0);
		// x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
	Vector2 add(Vector2 u);
		// 自身のベクトルとベクトル u との和を求める
	Vector2 sub(Vector2 u);
		// 自身のベクトルとベクトル u との差を求める
	double nai(Vector2 u);
	double gai(Vector2 u);
	void scan(void);
		// ベクトルの値を標準入力から自身に入力する
	void print(void);
		// 自身のベクトルの値を標準出力に出力する
};

#endif
