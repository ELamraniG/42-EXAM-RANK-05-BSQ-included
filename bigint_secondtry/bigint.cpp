#include "bigint.hpp"
#include <string>

bigint::bigint() : our_number("0")
{
	
}
bigint::bigint(unsigned long number)
{
	our_number = std::to_string(number);
}
bigint::bigint(const bigint &cpy)
{
	our_number = cpy.our_number;
}
bigint & bigint::operator=(const bigint &cpy)
{
	our_number = cpy.our_number;
	return *this;
}
bigint::~bigint()
{
	
}

std::ostream & operator<<(std::ostream &o, const bigint &cpy)
{
	o<< cpy.our_number;
	return o;
}


bigint &bigint::operator+=(const bigint &cpy)
{
	unsigned long carry = 0;
	unsigned long res = 0;
	std::string s1 = our_number;
	std::string s2 = cpy.our_number;
	s1.reserve();
	s2.reserve();
	unsigned long i = 0;
	unsigned long j = 0;
	std::string tmp;
	while (i < s1.length() || j < s2.length() || carry)
	{
		res = carry;
		if (s1[i])
		{
			res += s1[i] - '0';
			i++;
		}
		if (s2[j])
		{
			res += s2[j] - '0';
			j++;
		}
		carry = res / 10;
		tmp += res % 10 + '0';
	}
	our_number = tmp;
	return *this;
}
bigint  bigint::operator+(const bigint &cpy) const
{
	bigint tmp(*this);
	tmp += cpy;
	return tmp;
}

bigint &bigint:: operator++()
{
	bigint tmp(1);
	*this += tmp;
	return *this;
}
bigint  bigint::operator++(int)
{
	bigint tmp(1);
	*this += tmp;
	tmp = *this;
	return tmp;
}


bool bigint::operator<(const bigint &cpy) const
{
	if (our_number.length() == cpy.our_number.length())
		return our_number < cpy.our_number;
	if (our_number.length() < cpy.our_number.length())
		return true;
	return false;
}
bool bigint::operator<=(const bigint &cpy) const
{
	if (*this == cpy || *this < cpy)
		return true;
	return false;
}
bool bigint::operator>(const bigint &cpy) const
{
	return !(*this <= cpy);
}
bool bigint::operator>=(const bigint &cpy) const
{
	return !(*this < cpy);
}
bool bigint::operator==(const bigint &cpy) const
{
	if (cpy.our_number == our_number)
		return true;
	return false;
}
bool bigint::operator!=(const bigint &cpy) const
{
	return !(*this == cpy);
}




bigint  bigint::operator<<(unsigned int n) const
{
	bigint tmp(*this);
	tmp <<= n;
	return tmp;
}
bigint &bigint:: operator<<=(unsigned int n)
{
	if (our_number == "0")
		return *this;
	for (int i = 0;i < n;i++)
		our_number += "0";
	return *this;
}
bigint &bigint:: operator>>=(const bigint &cpy)
{
	unsigned long n = atol(cpy.our_number.c_str());
	for (unsigned long i = 0;i < n;i++)
		our_number.pop_back();
	if (our_number.length() == 0)
		our_number = "0";
	return *this;
}
