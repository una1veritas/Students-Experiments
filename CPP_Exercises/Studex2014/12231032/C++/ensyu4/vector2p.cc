//
// vector2p.cc - 2次元ベクトル型(C++版)
//	作者: 核雅瑛(あなたの名前); 日付:2014/4/10 (完成した日付)
//
#include <stdio.h>
#include "vector2p.h"

//まとめるためデフォルトコンストラクタをヘッダからこちらへ
Matrix::Matrix() 
{
        Matrix(0,0,0,0);
        //printf("デフォルトコンストラクタが呼ばれた\n");
}

//
// 引数ありのコンストラクタ
//
Matrix::Matrix(double x0, double y0 , double z0, double w0)
{
        elem[0][0] = x0;
	elem[0][1] = y0;
	elem[1][0] = z0;
	elem[1][1] = w0;
	//printf("引数ありのコンストラクタが呼ばれた\n");
}


//&呼出しをするときにconstはいる
Matrix::Matrix(const Matrix &v) 
{
  /*Cの作法に注意(配列は０から)*/
        //vの要素をコピー
        elem[0][0] = v.elem[0][0];
	elem[0][1] = v.elem[0][1];
	elem[1][0] = v.elem[1][0];
	elem[1][1] = v.elem[1][1];

  //	printf("コピーコンストラクタが呼ばれた\n");
}

//
// Matrix::add() - 自身の行列と行列 u との和を求める
//
Matrix Matrix::add(Matrix u)
{
	Matrix ret;

	ret.elem[0][0] = elem[0][0] + u.elem[0][0];
	ret.elem[0][1] = elem[0][1] + u.elem[0][1];
	ret.elem[1][0] = elem[1][0] + u.elem[1][0];
	ret.elem[1][1] = elem[1][1] + u.elem[1][1];

	return ret;
}


//
// MAtrix::sub() - 自身の行列と行列 u との差を求める
//
Matrix Matrix::sub(Matrix u)
{
	Matrix ret;

	ret.elem[0][0] = elem[0][0] - u.elem[0][0];
	ret.elem[0][1] = elem[0][1] - u.elem[0][1];
	ret.elem[1][0] = elem[1][0] - u.elem[1][0];
	ret.elem[1][1] = elem[1][1] - u.elem[1][1];

	return ret;
}

Matrix Matrix::mul(Matrix u)
{
        Matrix ret;
	
	ret.elem[0][0] = elem[0][0] * u.elem[0][0] + elem[0][1]*u.elem[1][0];
	ret.elem[0][1] = elem[0][0] * u.elem[0][1] + elem[0][1]*u.elem[1][1];
	ret.elem[1][0] = elem[1][0] * u.elem[0][0] + elem[1][1]*u.elem[1][0];
	ret.elem[1][1] = elem[1][0] * u.elem[0][1] + elem[1][1]*u.elem[1][1];

	return ret;
	
}
	

//
// Matrix::scan() - ベクトルの値を標準入力から自身に入力する
//
void Matrix::scan(void)
{
  
        scanf("%lf %lf %lf %lf", &elem[0][0],&elem[0][1],&elem[1][0],&elem[1][1]);
}

//
// MAtrix::print() - 自身のベクトルの値を標準出力に出力する
//
void Matrix::print(void)
{
  /*(1,2,)
    (1,2,)のように行列の中身を表示*/


         int i,j;
	 

	 for(i=0;i<2;i++) {
	   printf("(");
	   for(j=0;j<2;j++) {
	     printf("%f,",elem[i][j]);
	   }
	   printf(")\n");
	 }
}
