//
// en5.h - 行列型
//      大高弥  4/17
//
// Matrix -  配列型
//

class Matrix {

private:
	double x[2];
	double y[2];

public:
	Matrix(void) {};

	Matrix add(Matrix m);

	Matrix sub(Matrix m);

	Matrix pro(Matrix m);

	void scan(void);
	
	void print(void);
};

