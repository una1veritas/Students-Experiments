//
// matrix.cc - 2次元ベクトル型(C++版)
//	作者: 定平典久; 日付: 14/04/17
//
#include <stdio.h>
#include "matrix.h"

//
// Matrix::Matrix) - x0, y0,x1,x1 を与えて正方行列を得るコンストラクタ
//
Matrix::Matrix(double x0, double y0,double x1, double y1 )
{
        mat[0][0] = x0;
	mat[0][1] = y0;
	mat[1][0] = x1;
	mat[1][1] = y1;
}

//
// Matrix::add() - 自身のベクトルとベクトル u との和を求める
//
Matrix Matrix::add(Matrix u)
{
	Matrix ret;

	ret.mat[0][0] = mat[0][0] + u.mat[0][0];
	ret.mat[0][1] = mat[0][1] + u.mat[0][1];
	ret.mat[1][0] = mat[1][0] + u.mat[1][0];
	ret.mat[1][1] = mat[1][1] + u.mat[1][1];
	return ret;
}

//
// Matrix::sub() - 自身のベクトルとベクトル u との差を求める
//
Matrix Matrix::sub(Matrix u)
{
	Matrix ret;

        ret.mat[0][0] = mat[0][0] - u.mat[0][0];
	ret.mat[0][1] = mat[0][1] - u.mat[0][1];
	ret.mat[1][0] = mat[1][0] - u.mat[1][0];
	ret.mat[1][1] = mat[1][1] - u.mat[1][1];

	return ret;
}
//
// Matrix::mul() - 正方行列と正方行列u との積を求める
//

Matrix Matrix::mul(Matrix u)
{
	Matrix ret;

	ret.mat[0][0] = mat[0][0] * u.mat[0][0] + mat[0][1] * u.mat[1][0];
	ret.mat[0][1] = mat[0][0] * u.mat[0][1] + mat[0][1] * u.mat[1][1];
	ret.mat[1][0] = mat[1][0] * u.mat[0][0] + mat[1][0] * u.mat[1][1];
	ret.mat[1][1] = mat[1][0] * u.mat[0][1] + mat[1][1] * u.mat[1][1];
	return ret;
}


//
// Matrix::scan() - ベクトルの値を標準入力から自身に入力する
//
void Matrix::scan(void)
{
  //scanf("%lf %lf %lf %lf",&x0,&y0,&x1,&y1);
  scanf("%lf %lf %lf %lf",&mat[0][0],&mat[0][1],&mat[1][0],&mat[1][1]);
}

//
// Matrix::print() - 自身のベクトルの値を標準出力に出力する
//
void Matrix::print(void)
{
  //printf("( %f %f %f %f)",x0,y0,x1,y1);
  printf("( %f %f %f %f)",mat[0][0],mat[0][1],mat[1][0],mat[1][1]);
}
