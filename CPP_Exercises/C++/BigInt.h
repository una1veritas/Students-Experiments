/*
 * BigInt.h
 *
 *  Created on: 2015/06/18
 *      Author: sin
 */

#ifndef BIGINT_H_
#define BIGINT_H_

#include <iostream>

// utility macro
#define larger(x,y) ((x) >= (y)? (x) : (y))
#define smaller(x,y) ((x) <= (y)? (x) : (y))
#define abs(x) ((x) >= 0 ? (x) : -(x));

class BigInt {

private: // members
	unsigned char * digit;
	int size;
	char sign;

private:
	static const int MIN_SIZE = (sizeof(long) > 4? sizeof(long) : 4);

public:
	BigInt(void) {
		std::cerr << "Oh my." << std::endl;
		size = MIN_SIZE;
		digit = new unsigned char[size];
		for(int i = 0; i < size; i++)
			digit[i] = 0;
		sign = 1;
	}

	BigInt(const BigInt & val);
	BigInt(const long & val);

	~BigInt(void) { delete [] digit; }

	BigInt & operator=(const BigInt & y) {
		delete [] digit;
		size = y.size;
		digit = new unsigned char[size];
		for(int i = 0; i < size; i++)
			digit[i] = y.digit[i];
		sign = y.sign;
		return *this;
	}

	bool equals(const BigInt & y) const;
	bool lessThan(const BigInt & y) const;
	BigInt add(const BigInt & y) const;

	std::ostream & printOn(std::ostream & out, const int base = 16) const;

	friend std::ostream & operator<<(std::ostream & out, const BigInt & v) {
		return v.printOn(out);
	}
};

#endif /* BIGINT_H_ */
