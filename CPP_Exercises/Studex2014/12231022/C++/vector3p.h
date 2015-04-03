//
// vector2p.h - 2次元ベクトル型(C++版)
//	作者: 工藤慎也; 日付: ４/１７
//
#ifndef VECTOR3P_H
#define VECTOR3P_H

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
	// デフォルトコンストラクタ(初期値) 
	Vector2(double x0, double y0);
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
