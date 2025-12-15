#pragma once
#include "iostream"
#include "fstream"
#include <ostream>
class bigint
{
	public:
		std::string our_number;
		bigint();
		bigint(unsigned long number);
		bigint(const bigint &cpy);
		bigint & operator=(const bigint &cpy);
		~bigint();

		friend std::ostream & operator<<(std::ostream &o, const bigint &cpy);

		//operator += +
		bigint & operator+=(const bigint &cpy);
		bigint  operator+(const bigint &cpy) const;

		//operator |++ before|  || |after ++|
		bigint & operator++();
		bigint  operator++(int);

		// < <= > >= == !=
		bool operator<(const bigint &cpy) const;
		bool operator<=(const bigint &cpy) const;
		bool operator>(const bigint &cpy) const;
		bool operator>=(const bigint &cpy) const;
		bool operator==(const bigint &cpy) const;
		bool operator!=(const bigint &cpy) const;
		// shifts << <<= >>=
		bigint  operator<<(unsigned int n) const;
		bigint & operator<<=(unsigned int n);
		bigint & operator>>=(const bigint &cpy);


};