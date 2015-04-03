//
//  matrix22.h - 2次正方行列
//

#ifndef MATRIX22_H
#define MATRIX22_H

//
// matrix22
//

class Matrix22{
//メンバ変数
private:
	double x[2][2];

public:
	Matrix22(void) { x[0][0] = 0; x[0][1] = 0; x[1][0] = 0; x[1][1] = 0;}
	Matrix22(double x0, double x1, double x2, double x3);
	Matrix22 add(Matrix22 u);
	Matrix22 sub(Matrix22 u);
	Matrix22 mul(Matrix22 u);
	void scan(void);
	void print(void);
};

#endif
	

