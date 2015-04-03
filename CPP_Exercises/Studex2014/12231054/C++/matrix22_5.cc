//
// matrix22.cc - 2次正方行列
//      作者: Kento Nomiyama; 日付: 2014.04.10
//
#include <stdio.h>
#include "matrix22_5.h"

// Matrix22::Matrix22()
Matrix22::Matrix22(double x0, double x1, double x2, double x3){
	x[0][0] = x0;
	x[0][1] = x1;
	x[1][0] = x2;
	x[1][1] = x3;

}

//Matrix22::add()
Matrix22 Matrix22::add(Matrix22 u){
	int i, j;
	Matrix22 ret;
	for(i = 0; i < 2; i++){
		for(j = 0; j < 2; j++){
			ret.x[i][j] = this->x[i][j] + u.x[i][j];
		}
	}
	return ret;
}

//Matrix22::sub()
Matrix22 Matrix22::sub(Matrix22 u){
        int i, j;
        Matrix22 ret;
        for(i = 0; i < 2; i++){
                for(j = 0; j < 2; j++){
                        ret.x[i][j] = this->x[i][j] - u.x[i][j];
                }
        }
        return ret;
}

//Matrix22::mul()
Matrix22 Matrix22::mul(Matrix22 u){
	int i, j, k;
	Matrix22 ret;
	for(i = 0; i < 2; i++){
		for(j = 0; j < 2; j++){
			for(k = 0 ; k < 2; k++){
				ret.x[i][j] += this->x[i][k] * u.x[k][j];
			}
		}
	}
	return ret;
}

//Matrix22::scan()
void Matrix22::scan(void){
	int i, j;
	for(i = 0; i < 2; i++){
		for(j = 0; j < 2; j++){
			scanf("%lf", &x[i][j]);
		}
	}
}

//Matrix22::print()
void Matrix22::print(void){
	int i, j;
	for(i = 0; i < 2; i++){
		printf("|");
		for(j = 0; j < 2 ; j++){
			printf(" %f ", x[i][j]);
		}
		printf("|\n");
	}
}

//vector
//
// Vector2::Vector2() - x0, y0 を与えて定数 (x0, y0) を得るコンストラクタ
//
Vector2::Vector2(double x0, double y0)
{
	x = x0;
	y = y0;

	printf("Vector create: ");
}

Vector2::Vector2(const Vector2 &v)
{
	this->x = v.x;
	this->y = v.y;

	 printf("Vector Copy:");

}

//
// Vector2::add() - 自身のベクトルとベクトル u との和を求める
//
Vector2 Vector2::add(Vector2 u)
{
	Vector2 ret;

	ret.x = x + u.x;
	ret.y = y + u.y;

	return ret;
}

//
// Vector2::scan() - ベクトルの値を標準入力から自身に入力する
//
void Vector2::scan(void)
{
	scanf("%lf %lf", &x, &y);
}

//
// Vector2::print() - 自身のベクトルの値を標準出力に出力する
//
void Vector2::print(void)
{
	printf("( %f %f )", x, y);
}

// Vector2::sub()

Vector2 Vector2::sub(Vector2 u){
	Vector2 ret;

	ret.x = this->x - u.x;
	ret.y = this->y - u.y;

	return ret;

}



