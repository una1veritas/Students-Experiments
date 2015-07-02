/*
 * cardset_remove.cpp
 *
 *  Created on: 2015/04/15
 *      Author: sin
 */

#include "../Card.h"
#include "../CardSet.h"

int CardSet::remove(Card & target) {
	// 自身から target と同一のカードを取り除く(-1: 失敗; 0以上: 成功)
	int pos = locate(target);
	if( pos == -1 )
		// ない
		return -1;
	for( ; pos < numcard; pos++) {
		cdat[pos] = cdat[pos+1];
	}
	numcard--;
	return pos;
}


int CardSet::remove(int num) {
		// 自身から数字が num であるカードいずれか一枚を除く(-1: 失敗; 0以上: 成功)
	int pos = locate(num);
	if( pos == -1 )
		// ない
		return -1;
	for( ; pos < numcard; pos++) {
		cdat[pos] = cdat[pos+1];
	}
	numcard--;
	return pos;

}
