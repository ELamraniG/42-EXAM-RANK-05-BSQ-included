#pragma once
#include <iostream>
#include <string>
#include <fstream>


class bigint
{
	public :
		std::string number_str;
		bigint();
		bigint(bigint &cpy);
		bigint& operator=(const bigint& cpy);
		bigint(int n);
		bigint &operator+=(const bigint &cpy);
	friend std::ostream & operator<<(std::ostream &o,const bigint &big);

};