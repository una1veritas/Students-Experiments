/*
 * ex1.cpp
 *
 *  Created on: 2015/06/19
 *      Author: sin
 */

#include <cstdlib>
#include <iostream>

#include "BigBCD.h"

int main(int argc, char * argv[]) {
	std::cout << "Thus begin; " << std::endl;

	BigBCD x(1);

	std::cout << "This is a big bcd: " << x << std::endl;
	std::cout << "This is the next: " << ++x << std::endl;
	std::cout << "And the next: " << ++x << std::endl;


	return EXIT_SUCCESS;
}

