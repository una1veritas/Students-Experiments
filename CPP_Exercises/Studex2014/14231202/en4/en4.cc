//
// en4.cc - 行列型
//   大高弥  4/17
//
#include <stdio.h>
#include "en4.h"

Matrix Matrix::add(Matrix m)
{
	Matrix ret;
	for(int i=0;i<2;i++){
		ret.x[i] = x[i] + m.x[i];
		ret.y[i] = y[i] + m.y[i];
	}

	return ret;
}

Matrix Matrix::sub(Matrix m)
{
	Matrix ret;

	for(int i=0;i<2;i++){
		ret.x[i] = x[i] - m.x[i];
		ret.y[i] = y[i] - m.y[i];
	}

        return ret;

}

Matrix Matrix::pro(Matrix m)
{
	Matrix ret;
	for(int i=0;i<2;i++){
		ret.x[i] = x[0]* m.x[i]+x[1]*m.y[i];
		ret.y[i] = y[0]* m.y[i]+y[1]*m.y[i];
	
	}
	return ret;
	
}

void Matrix::scan(void)
{
	scanf("%lf %lf %lf %lf",&x[0],&x[1],&y[0],&y[1]);
}

void Matrix::print(void)
{
	printf("| %f %f |\n| %f %f |\n",x[0],x[1],x[1],y[1]);
}

