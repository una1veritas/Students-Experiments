//
// enshu4.h - 2次元ベクトル型(C++版)
//      作者: (あなたの名前); 日付: (完成した日付)
//
#ifndef MATRIX2P_H
#define MATRIX2P_H

//
// enshu4 - 2次正方行列型
//
class Matrix22 {
// メンバ変数
private:
        double x[2][2];       // 2次元配列を宣言


// メンバ関数
public:
        Matrix22();
                // デフォルトコンストラクタ(初期値不定)
        Matrix22(double a0, double b0, double c0, double d0);
                // a0, b0, c0, d0 を与えて定数 (a0, b0, c0, d0) を得るコンストラクタ
        Matrix22(const Matrix22 & v);
                //コピーコンストラクタを作成
        Matrix22 add(Matrix22 u);
                // 自身の行列と行列 u との和を求める
        Matrix22 sub(Matrix22 u);
                // 自身の行列と行列u との差を求める
	Matrix22 mul(Matrix22 u);
	        // 自身の行列と行列uとの積を求める
        void scan(void);
                // 行列の値を標準入力から自身に入力する
        void print(void);
                // 自身の行列の値を標準出力に出力する

};

#endif
