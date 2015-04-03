//
// vector2p.h - 2次元ベクトル型(C++版)
// TAKAHASHI Manaka
//
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
	// デフォルトコンストラクタ初期値0,0
	Vector2(void) {  
	  x = 0.0;
	  y = 0.0;
	  printf("dcon( %f, %f )\n", x, y);
	}

	// コンストラクタ
	Vector2(double x0, double y0)
	  {
	    x = x0;
	    y = y0;
	    printf("con( %f, %f )\n", x, y);
	  }
	// コンストラクタ
	Vector2(Vector2 &v)
	  {
	    x = v.x;
	    y = v.y;
	    printf("ccon( %f, %f )\n", x, y);
	  }
	// 自身のベクトルとベクトル u との和を求める
	Vector2 add(Vector2 u);
	
	// 自身のベクトルとベクトル u との差を求める
	Vector2 sub(Vector2 u);

	// 自身のベクトルとベクトルuとの内積を求める
	double inp(Vector2 u);
	
	// 自身のベクトルとベクトルuとの外積を求める
	Vector2 out(Vector2 u);
	
	// ベクトルの値を標準入力から自身に入力する
	void scan(void);

	// 自身のベクトルの値を標準出力に出力する
	void print(void);
};

#endif
