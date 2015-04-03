//
// ensyu8.cc - ババ抜きプログラム(C++版)
//	作者: (あなたの名前); 日付: (完成した日付)
//
#include "ensyu8.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//
// main() - ババ抜きプログラム
//
int main(void)
{
	time_t seed;
// 乱数発生のシード
// (デバッグ等で同じ乱数を発生させたい時は，以下の2行を除くこと)
	time(&seed);
	srandom(seed);

	BabaState bs;	// ババ抜きの状態

	bs.print();

// 終了条件になるまでカードを引き続ける
	int from, to = 0; // to は from からカードを取る
	while(1) {
	// 次の from と to を探す
		for(to = (to + 1) % BabaState::numplayer;
		 bs.isfinished(to);
		 to = (to + 1) % BabaState::numplayer)
			;
		for(from = (to + BabaState::numplayer - 1) % BabaState::numplayer;
		 bs.isfinished(from);
		 from = (from + BabaState::numplayer - 1) % BabaState::numplayer)
			;
// 終了判定
		if(from == to)	// ゲームの終了条件(1人以外は上がった)
			break;

// 何枚目のカードを引くか選ぶ
		int num = -1;
		if(to == 0) {		
		  std::cout << "何枚目のカードを引きますか？(ランダムは0以下)";
		  cin >> num;
		}
		num--;

// from から to にカードが渡る
		bs.move(from, to, num);
		std::cout << "# プレーヤ " << from << " からプレーヤ " << to << " にカードが渡る"<< std::endl;
		bs.print();
	}

	std::cout << std::endl << "### FINISHED ###" << std::endl;

	return 0;
}
