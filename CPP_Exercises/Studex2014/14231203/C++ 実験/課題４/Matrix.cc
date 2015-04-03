//
// Matrix.cc - 行列型
//      作者: (あなたの名前); 日付: (完成した日付)
//
#include <stdio.h>
#include "Matrix.h"

Matrix Matrix::add(Matrix u)
{
	Matrix ret;

	ret.x1 = x1 + u.x1;
	ret.y1 = y1 + u.y1;
	ret.x2 = x2 + u.x2;
	ret.y2 = y2 + u.y2;

	return ret;
}

Matrix Matrix::sub(Matrix u)
{
	Matrix ret;

        ret.x1 = x1 - u.x1;
        ret.y1 = y1 - u.y1;
        ret.x2 = x2 - u.x2;
        ret.y2 = y2 - u.y2;

        return ret;

}

Matrix Matrix::mul(Matrix u)
{
	Matrix ret;
	ret.x1 = x1*u.x1 + y1*u.x2;
	ret.y1 = x1*u.y1 + y1*u.y2;
	ret.x2 = x2*u.x1 + y2*u.x2;
	ret.y2 = x2*u.y1 + y2*u.y2;

	return ret;
	
}

void Matrix::scan(void)
{
	scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
}

void Matrix::print(void)
{
	printf("( %f %f )\n( %f %f )\n",x1,y1,x2,y2);
}

