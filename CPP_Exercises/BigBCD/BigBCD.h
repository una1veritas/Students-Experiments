/*
 * BigBCD.h
 *
 *  Created on: 2015/06/19
 *      Author: sin
 */

#ifndef BIGBCD_H_
#define BIGBCD_H_

class BigBCD {
	private:
		char * digit;  // uint8_t
		int digit_size; 		// uint8_t

		static const int DEFAULT_SIZE = 1;

	public:
		BigBCD(void) {
			digit_size = DEFAULT_SIZE;
			digit = new char [digit_size];
			digit[0] = 0;
		}

		BigBCD(const unsigned int & val) {
			digit_size = 4;
			digit = new char [digit_size];
			unsigned int rmd = val;
			for(unsigned int d = 0; rmd > 0; d++) {
				digit[d] = rmd % 10;
				rmd /= 10;
			}
		}

		BigBCD(const BigBCD & val) {
			std::cout << "I'm copied! ";
			digit_size = val.digit_size;
			digit = new char [digit_size];
			for(int i = 0; i < digit_size; i++) {
				digit[i] = val.digit[i];
			}
		}

		~BigBCD(void) {
			delete [] digit;
		}

		BigBCD & inc(void) {
			int i;
			for(i = 0; i < digit_size; i++) {
				if ( digit[i] < 9 ) {
					digit[i]++;
					return *this;
				}
				digit[i] = 0;
			}
			if ( !(i < digit_size) ) {
				delete [] digit;
				digit_size++;
				digit = new char [digit_size];
			}
			for(int j = 0; j < i - 1; j++) {
				digit[j] = 0;
			}
			digit[i] = 1;
			return * this;
		}


		BigBCD & operator++() {
			inc();
			return *this;
		}

		int intval(void) const {
			int val = 0;
			int mul = 1;
			for(int i = 0; i < digit_size; i++) {
				val += mul*digit[i];
				mul *= 10;
			}
			return val;
		}

		std::ostream & printOn(std::ostream & out) const {
			bool sw = false;
			for(int i = digit_size; i > 0; --i) {
				if ( digit[i-1] != 0)
					sw = true;
				if ( sw )
					out << (unsigned int) digit[i-1];
			}
			return out;
		}

		friend std::ostream & operator<<(std::ostream & out, const BigBCD & x) {
			return x.printOn(out);
		}

};


#endif /* BIGBCD_H_ */
