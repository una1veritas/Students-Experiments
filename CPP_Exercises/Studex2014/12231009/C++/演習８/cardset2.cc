 
//
// cardset.cc - トランプカードの集合型(C++版)
// 作者: Yuya Uekama; 日付: 2014.04.24
//
#include <iostream>
#include "cardset2.h"

//
// Card::scan() - 標準出力から自身に入力する(true: エラー; false: 正常終了)
//
bool Card::scan(void) {
	char buf[BUFSIZ];
	char* suitname[] = { "spade", "diamond", "heart", "club" };
	// 4組のいずれかなら番号も入力する
	if (scanf("%s", buf) < 1) {
		return true;
	}
	number = 53;
	for (int s = SUIT_SPADE; s <= SUIT_CLUB; s++) {
		if (!strcmp(buf, suitname[s])) {
			int num;
			if (scanf("%d", &num) < 1) {
				return true;
			}
			if (num < 1 || num > 13) {
				return true;
			}
			number = ((s * 13) + (num - 1));
			return false;
		}
	}

	// joker は 52
	if (!strcmp(buf, "joker")) {
		number = 52;
		return false;
	}

	return true;	// エラー
}

//
// Card::print() - 自身の値を標準出力に出力する
//
void Card::print(void) {
	char* suitname[] = { "spade", "diamond", "heart", "club" };

	if (number < 52) {
		printf("[%s %d]", suitname[gsuit()], gnumber());
	}
	else if (number == 52)
		printf("[joker]");
}


//
// CardSet::locate() - 内部での target のカードの位置を返す(-1: ない)
//
int CardSet::locate(Card target) {
	for (int i = 0; i < numcard; i++) {
		if (target.equal(cdat[i])) {
			return i;
		}
	}

	return -1;	// 見つからなかった
}

//
// CardSet::locate() - 内部で数字が num のカードの位置を返す(-1: ない)
//
int CardSet::locate(int num) {
	for (int i = 0; i < numcard; i++) {
		if (num == cdat[i].gnumber()) {
			return i;
		}
	}

	return -1;	// 見つからなかった
}

//
// CardSet::makedeck() - 自身に全部の(maxnumcard 枚の)カードを入れる
//
void CardSet::makedeck(void) {
	Card c;
	int suit, num;

	for (suit = Card::SUIT_SPADE; suit <= Card::SUIT_CLUB; suit++) {
		for (num = 1; num <= 13; num++) {
			c.set(suit, num);
			insert(c);
		}
	}
	c.set(Card::SUIT_JOKER, 0);
	insert(c);
}

//
// CardSet::pickup() - 自身から targetpos 枚目のカードを除き *ret に返す
// targetpos が -1 のときはランダムに選ぶ(true: 失敗; false: 成功)
//
bool CardSet::pickup(Card* ret, int targetpos /* = -1 */) {
	if (numcard == 0) {
		return true;
	}
	if (targetpos < 0) {
		targetpos = random() % numcard;
	}
	else {
		targetpos %= numcard;
	}

	*ret = cdat[targetpos];
	remove(*ret);

	return false;
}

//
// CardSet::insert() - 自身に newcard のカードを入れる(true: 失敗; false: 成功)
//
bool CardSet::insert(Card newcard) {
	if (locate(newcard) >= 0)
		return true;	// 既にある
	// 最後に追加
	cdat[numcard] = newcard;
	numcard++;

	return false;
}

//
// CardSet::remove() - 自身から target のカードを除く(true: 失敗; false: 成功)
//
bool CardSet::remove(Card target) {
	int i, del;
 	del = locate(target);

	if(del != -1){
    		for(int i = del; i < numcard; i++)
      			cdat[i] = cdat[i+1];
    		numcard--;
    		return false;
  	}
  	else
    		return true;
}


//
// CardSet::remove() - 自身から数字が num であるカードを除く(true: 失敗; false: 成功)
//
bool CardSet::remove(int num) {
	int i, del;
        del = locate(num);

        if(del != -1){
        	for(int i = del; i < numcard; i++){
      			cdat[i] = cdat[i+1];
    		}   
    		numcard--;
    		return false;
  	}
 	else
   		return true;	
}


//
// CardSet::print() - 自身の状態を標準出力に出力する
//
void CardSet::print(void) {
	printf("((CARDSET))\n");
	if (numcard == 0) {
		printf("\tno card\n");
		return;
	}
	for (int i = 0; i < numcard; i++) {
		printf("\t");
		cdat[i].print();
		printf("\n");
	}
}
