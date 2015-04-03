//
// ensyu4.h - 2次正方行列型(C++版)
//      作者: (あなたの名前); 日付: (完成した日付)
//
#ifndef ENSYU4_H
#define ENSYU4_H

//
// Vector2 - 2次正方行列型
//
class Ensyu4 {
// メンバ変数
private:
        double x[2][2];       // x値
// メンバ関数
public:
        Ensyu4 (void)   { x[0][0] = 0;  x[0][1] = 0; x[1][0] = 0; x[1][1] = 0; }
                // デフォルトコンストラクタ(初期値不定)
        Ensyu4(double x1, double x2, double x3, double x4);
                // x[][]を与えて定数 (x0, y0) を得るコンストラクタ
        Ensyu4 add(Ensyu4 u);
                // 自身のベクトルとベクトル u との和を求める
        Ensyu4 sub(Ensyu4 u);
                // 自身のベクトルとベクトル u との差を求める
        Ensyu4 mul(Ensyu4 u);
                // 自身のベクトルとベクトル u との積を求める
        void scan(void);
                // ベクトルの値を標準入力から自身に入力する
        void print(void);
                // 自身のベクトルの値を標準出力に出力する
};

#endif
