/*
 * BigIntExample.cpp
 *
 *  Created on: 2015/06/18
 *      Author: sin
 */

#include <iostream>
#include "BigInt.h"

int main(int argc, char * argv[]) {
	std::cout << "Hello baby." << std::endl;

	BigInt xbig = 325, ybig = 400013, zbig = 400013;
	ybig.printOn(std::cout);
	std::cout << std::endl;

	std::cout << (xbig.lessThan(zbig)) << ", " << (ybig.lessThan(zbig)) << ", " << (ybig.equals(zbig)) << std::endl;

	xbig = ybig.add(xbig);

	std::cout << xbig << std::endl;

	return 0;
}

