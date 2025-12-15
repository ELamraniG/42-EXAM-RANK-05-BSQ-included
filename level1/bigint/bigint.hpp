#pragma once
#include <iostream>
#include <string>
#include <fstream>


class bigint
{
	public :
		std::string number_str;
		bigint();
		bigint(const bigint &cpy);
		bigint& operator=(const bigint& cpy);
		bigint(int n);

		// + and +=
		bigint &operator+=(const bigint &cpy);
		bigint operator+(const bigint &cpy) const;

		//  ++ before and after
		bigint &operator++();
		bigint operator++(int);

		// << >>= <<=
		bigint operator<<(unsigned int n);
		bigint &operator<<=(unsigned int n);
		bigint &operator>>=(const bigint &cpy);

		// < > <= >=
		bool operator<(const bigint &cpy) const;
		bool operator>(const bigint &cpy) const;
		bool operator<=(const bigint &cpy) const;
		bool operator>=(const bigint &cpy) const;

		// == !=
		bool operator==(const bigint &cpy) const;
		bool operator!=(const bigint &cpy) const;
	friend std::ostream & operator<<(std::ostream &o,const bigint &big);

};