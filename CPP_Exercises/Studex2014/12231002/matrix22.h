//
// matrix22.h - 2次正方行列型
//	作者: 伊佐　真誠; 日付: 14/4/10
//


//
// Matrix22 - 2次正方行列型
//
class Matrix22 {
// メンバ変数
private:
	double x[2][2];
// メンバ関数
public:

	Matrix22(void) {x[0][0]=0; x[0][1]=0;x[1][0]=0;x[1][1]=0;}
		// デフォルトコンストラクタ
	Matrix22(double x11, double x12, double x21, double x22);
	        // x11, x12, x21, x22を与えて行列(x11, x12|x21, x22)を作成するコンストラクタ
	Matrix22 add(Matrix22 u);
	        // 自身の行列と行列 u との和を求める
	Matrix22 sub(Matrix22 u);
	        // 自身の行列と行列 u との差を求める
	Matrix22 mul(Matrix22 u);
	        // 自身の行列と行列 u との積を求める
	void scan(void);
		// 行列の値を標準入力から自身に入力する
	void print(void);
		// 自身の行列の値を標準出力に出力する
};

