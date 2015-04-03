//
// vector2p.h - 2次元ベクトル型(C++版)
//	作者:核雅瑛 (あなたの名前); 日付:2014/4/10 (完成した日付)
//
#ifndef VECTOR2P_H
#define VECTOR2P_H

//
// Vector2 - 2次元ベクトル型
//
class Matrix {
// メンバ変数
private:
        double elem[2][2];//行列の要素elementの略
// メンバ関数
public:     
	Matrix(void); 
		// デフォルトコンストラクタ(初期値不定)
	Matrix(double x0, double y0, double z0, double w0);
		// 引数４つのコンストラクタ
	Matrix(const Matrix & v);
	        //コピーコンストラクタ
	Matrix add(Matrix u);
		// 自身の行列と行列 u との和を求める
	Matrix sub(Matrix u);
		// 自身の行列と行列u との差を求める
	Matrix mul(Matrix u);
	          //自身の行列と行列uとの積を求める
	void scan(void);
		// 行列の値を標準入力から自身に入力する
	void print(void);
		// 自身の行列の値を標準出力に出力する
};

#endif
