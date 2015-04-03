//
// vector2p.h - 2次元ベクトル型と2次元正方行列(C++版)
//      作者: 竹下純哉; 日付: 14/04/10
//
#ifndef ENSYU5_H
#define ENSYU5_H

//
// Vector2 - 2次元ベクトル型
//
class Vector2 {
// メンバ変数
private:
        double x;       // x値
        double y;       // y値
// メンバ関数
public:
        Vector2(void)   {x = 0; y =0;}
                // デフォルトコンストラクタ(初期値不定)
        Vector2(double x0, double y0);
                // x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
        Vector2(const Vector2 & v);
                // コピーコンストラクタ
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
// Gyoretu2 - 2次正方行列型
//
class Gyoretu2 {
// メンバ変数
private:
  double x[2][2];
// メンバ関数
public:
  Gyoretu2(void) { } // デフォルトコンストラクタ
  Gyoretu2 add(Gyoretu2 u); // 自身の行列と行列 u との和を求める
  Gyoretu2 sub(Gyoretu2 u); // 自身の行列と行列 u との差を求める
  Gyoretu2 mult(Gyoretu2 u); // 自身の行列と行列 u との掛け算を求める
  void scan(void); // 行列の値を標準入力から自身に入力する
  void print(void); // 自身の行列の値を標準出力に出力する
};

#endif
