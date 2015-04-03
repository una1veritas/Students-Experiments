//
// babanuki1_8.cc - ババ抜きプログラム(C++版)
//	大高弥  4/26
//
#include "babastate_8.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>

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
		 to = (to + 1) % BabaState::numplayer);
		printf("to = %d\n",to);
		for(from = (to + BabaState::numplayer - 1) % BabaState::numplayer;
		 bs.isfinished(from);
		 from = (from + BabaState::numplayer - 1) % BabaState::numplayer);
		
		printf("to = %d\n",from);
		// 終了判定
		if(from == to)	// ゲームの終了条件(1人以外は上がった)
			break;
// from から to にカードが渡る
		bs.move(from, to);
	std::cout << "# プレーヤ " << from << " からプレーヤ " << to << " にカードが渡る"<< std::endl;
		bs.print();
	}

	std::cout << std::endl << "### FINISHED ###" << std::endl;

	return 0;
}
