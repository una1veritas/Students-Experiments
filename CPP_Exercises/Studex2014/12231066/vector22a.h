//
//*vector2c.h - 2次元ベクトル型(C版)
// 	作者: (あなたの名前); 日付: (完成した日付)
//[注意] 以降の演習では，上記を適切に書き換えること

#ifndef VECTOR2C_H
#define VECTOR2C_H
#include <stdio.h>

/* データ定義・宣言 */
class Vector22 {

private:
        double x[2][2];

public:
	Vector22(void){
	  x[0][0]= 0;
	  x[0][1]= 0;
	  x[1][0]= 0;
	  x[1][1]= 0;
	}

        Vector22(double x0, double x1, double y0, double y1);
	/* x0, y0 を与えて，定数 (x0, y0) を得る */
	Vector22 add(Vector22);
	/* ベクトル u と v の和 u + v を求める */
	Vector22 sub(Vector22 u);
	/* ベクトル u と v の差 u - v を求める */
	Vector22 mul(Vector22 v);
	void scans(void);
	/* ベクトルの値を標準入力から *pu に入力する */
	void prints(void);
	/* ベクトル u の値を標準出力に出力する */
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
	Vector2(void){
	  x = 0;
	  y = 0;
	}
		// デフォルトコンストラクタ(初期値不定)
	Vector2(double x0, double y0);
		// x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
	Vector2 add(Vector2 u);
		// 自身のベクトルとベクトル u との和を求める
	Vector2 sub(Vector2 u);
		// 自身のベクトルとベクトル u との差を求める
	double inner_pro(Vector2 u);
		// 自身のベクトルとベクトル u との内積を求める
	double cross_pro(Vector2 u);
		// 自身のベクトルとベクトル u との外積を求める
	Vector2 mul(Vector22 u);
	        //2次元正方行列との積
	void scan(void);
		// ベクトルの値を標準入力から自身に入力する
	void print(void);
		// 自身のベクトルの値を標準出力に出力する
};

#endif
