//
// Matrix.h - 行列型
//      作者: (あなたの名前); 日付: (完成した日付)

//
// Matrix -  配列型
//

class Matrix {

private:
	double x1,x2;
	double y1,y2;

public:
	Matrix(void) {};

	Matrix add(Matrix u);

	Matrix sub(Matrix u);

	Matrix mul(Matrix u);

	void scan(void);
	
	void print(void);
};

