/*
 * BigInt.cpp
 *
 *  Created on: 2015/06/18
 *      Author: sin
 */

#include <iostream>
#include "BigInt.h"

BigInt::BigInt(const BigInt & val) {
	BigInt();
	*this = val;
}

BigInt::BigInt(const long & val) {
	size = MIN_SIZE;
	digit = new unsigned char[size];
	std::cerr << "Wan, ";
	unsigned int value = (val >= 0 ? val : -val);
	std::cerr << "Wan." << std::endl;
	sign = (val >= 0 ? 1 : -1);
	int lastdigit = 1;
	for(int i = 0; i < size; value >>= 8, i++ ) {
		digit[i] = value & 0xff;
		if ( digit[i] != 0 )
			lastdigit = i+1;
	}
	size = lastdigit;
}


bool BigInt::equals(const BigInt & y) const {
	if ( sign != y.sign )
		return false;
	int ld = (size > y.size ? size : y.size);
	int sd = (size < y.size ? size : y.size);
	for(int i = ld-1; i > sd; i--) {
		if (digit[i] > 0) return false;
	}
	for(int i = sd; i >= 0; i--) {
		if (digit[i] != y.digit[i]) return false;
	}
	return true;
}

bool BigInt::lessThan(const BigInt & y) const {
	if ( sign != y.sign )
		return (sign == -1);
	for(int d = size - 1; d >= 0; d--) {
		if ( digit[d] == y.digit[d] )
			continue;
		if ( digit[d] < y.digit[d] ) {
			if ( sign > 0 )
				return true;
			else
				return false;
		} else {
			if ( sign > 0 )
				return false;
			else
				return true;
		}
	}
	// equals.
	return false;
}

BigInt BigInt::add(const BigInt & y) const {
	BigInt ans;
	const BigInt * small, *large;
	if ( this->lessThan(y) ) {
		ans = y;
		small = &y;
		large = this;
	} else {
		ans = *this;
		small = this;
		large = &y;
	}
	unsigned int d;
	unsigned int carry = 0;
	for(int i = 0; i < ans.size; i++) {
		if ( i <= smaller(small->size, large->size) ) {
			d = small->digit[i] + large->digit[i];
		} else {
			d = large->digit[i];
		}
		d += carry;
		ans.digit[i] = d & 0xff;
		if ( (d & 0xf00) != 0 )
			carry = 1;
		else
			carry = 0;
	}
	return ans;
}

std::ostream & BigInt::printOn(std::ostream & out, const int base) const {
	out << "0x";
	for(int i = size-1; i >= 0; i--) {
		out << std::hex << ((((unsigned int)digit[i]) >> 4) & 0x0f);
		out << std::hex << (((unsigned int)digit[i]) & 0x0f) ;
	}
	return out;
}
