//
// vec2ex1p.cc - 2次元ベクトル型(C++版)テストプログラム
//	作者: (あなたの名前); 日付: (完成した日付)
//

#include <stdio.h>
#include "vector2.h"

//
// main() - テストプログラム
//
int main(void)
{
	Vector2 a, b;
	char buf[64];

// a, b を入力
	printf("a = (x, y) = ? ");
	fgets(buf,63,stdin);
	a.scan(buf);
	printf("b = (x, y) = ? ");
	fgets(buf,63,stdin);
	b.scan(buf);
	printf("\na = ");
	a.toString(buf);
	printf("%s\n",buf);
	printf("b = ");
	b.toString(buf);
	printf("%s\n",buf);
	printf("\n");
// a + b を出力
	printf("a + b = ");
	(a.add(b)).toString(buf);
	printf("%s\n", buf);
	// a + (2, 1) を出力
	printf("a + (2,1) = ");
	(a.add(Vector2(2, 1))).toString(buf);
	printf("%s\n",buf);

	// a + c を出力
	Vector2 c(0.9, 0.33);
	printf("a + c ");
	(a+c).toString(buf);
	printf("%s\n", buf);
	printf("d = a ");
	Vector2 d = a;   // コピーコンストラクタが未定義の場合，エラーにならずプレインコピーによる初期化が行われるようだ．
	// しかし，Vector2 d; d = a; とすると，コピーコンストラクタの未定義エラーになる．
	d.toString(buf);
	printf("%s\n",buf);

	return 0;
}
