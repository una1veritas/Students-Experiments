//
// vector2p.cc - 2次元ベクトル型(C++版)
//      作者: 竹下純哉; 日付: 14/04/10
//
#include <stdio.h>
#include "ensyu4.h"

//
// Gyoretu2::add() - 行列の和を求める
//
Gyoretu2 Gyoretu2::add(Gyoretu2 u) {
  Gyoretu2 ret;

  ret.x[0][0] = x[0][0] + u.x[0][0];
  ret.x[0][1] = x[0][1] + u.x[0][1];
  ret.x[1][0] = x[1][0] + u.x[1][0];
  ret.x[1][1] = x[1][1] + u.x[1][1];

  return ret;
}

//
// Gyoretu2::sub() - 行列の差を求める
//
Gyoretu2 Gyoretu2::sub(Gyoretu2 u) {
  Gyoretu2 ret;

  ret.x[0][0] = x[0][0] - u.x[0][0];
  ret.x[0][1] = x[0][1] - u.x[0][1];
  ret.x[1][0] = x[1][0] - u.x[1][0];
  ret.x[1][1] = x[1][1] - u.x[1][1];

  return ret;
}

//
// Gyoretu2::mult - 行列の掛け算を求める
//
Gyoretu2 Gyoretu2::mult(Gyoretu2 u) {
  Gyoretu2 ret;

  ret.x[0][0] = x[0][0] * u.x[0][0] + x[0][1] * u.x[1][0];
  ret.x[0][1] = x[0][0] * u.x[0][1] + x[0][1] * u.x[1][1];
  ret.x[1][0] = x[1][0] * u.x[0][0] + x[1][1] * u.x[1][0];
  ret.x[1][1] = x[1][0] * u.x[0][1] + x[1][1] * u.x[1][1];

  return ret;
}

//
// Gyoretu2::scan() - 行列の値を入力する
//
void Gyoretu2::scan(void) {
  scanf("%lf %lf %lf %lf", &x[0][0], &x[0][1], &x[1][0], &x[1][1]);
}

//
// Gyoretu2::print() - 自身の行列の値を標準出力する
//
void Gyoretu2::print(void) {
  printf("%f %f\n        %f %f", x[0][0], x[0][1], x[1][0], x[1][1]);
}
