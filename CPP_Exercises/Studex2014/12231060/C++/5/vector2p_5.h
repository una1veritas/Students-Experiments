#ifndef VECTOR2P_H
#define VECTOR2P_H

class Mtrix{
 private:
  double x1;
  double y1;
  double x2;
  double y2;
  
 public:
  Mtrix(void){}
  Mtrix(double x1_0, double y1_0, double x2_0, double y2_0);
  Mtrix add(Mtrix u);
  Mtrix sub(Mtrix u);
  Mtrix mul(Mtrix u);
  void print(void);
  void scan(void);
};

class Vector2 {
// メンバ変数
private:
	double x;	// x値
	double y;	// y値
// メンバ関数
public:
	Vector2(void){ x = 0; y = 0;}
		//デフォルトコンストラクタ(初期値不定)
	Vector2(double x0, double y0);
	Vector2 add(Vector2 u);
		// 自身のベクトルとベクトル u との和を求める
	Vector2 sub(Vector2 u);
		// 自身のベクトルとベクトル u との差を求める
	double inner_product(Vector2 u);
	double cross_product(Vector2 u);
	void scan(void);
		// ベクトルの値を標準入力から自身に入力する
	void print(void);
		// 自身のベクトルの値を標準出力に出力する
	double xx(void);
	double yy(void);
	Vector2 vetor(Vector2 &v);
	
};

#endif
