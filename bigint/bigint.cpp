#include "bigint.hpp"
#include <string>

bigint::bigint()
{
	number_str = "0";
}

bigint::bigint(int n)
{
	number_str = std::to_string(n);
}

bigint::bigint(const bigint &cpy)
{
	number_str = cpy.number_str;
}
bigint &bigint::operator=(const bigint &cpy)
{
	number_str = cpy.number_str;
	return (*this);
}

std::ostream &operator<<(std::ostream &o, const bigint &big)
{
	o << big.number_str;
	return (o);
}

bigint &bigint::operator+=(const bigint &cpy)
{
	unsigned long	carry;
	unsigned long	res;
	int				i;
	int				j;

	std::string string_result;
	carry = 0;
	res = 0;
	std::string s1 = number_str;
	std::string s2 = cpy.number_str;
	i = s1.size();
	j = s2.size();
	i--;
	j--;
	while (i >= 0 || j >= 0 || carry)
	{
		res = carry;
		if (i != -1)
		{
			res += s1[i] - '0';
			i--;
		}
		if (j != -1)
		{
			res += s2[j] - '0';
			j--;
		}
		carry = res / 10;
		string_result.push_back(res % 10 + '0');
		std::cout << carry << "  " << res << " " << i << " " << j <<std::endl;
	}
	string_result.reserve();
	number_str = string_result;
	return (*this);
}

bigint bigint::operator+(const bigint &cpy) const
{
	bigint tmp(*this);
	tmp += cpy;
	return (tmp);
}


bigint &bigint::operator++()
{
	bigint tmp(1);
	*this += tmp;
	return (*this);
}
bigint bigint::operator++(int)
{
	bigint tmp(1);
	tmp += *this;
	return (tmp);
}

bigint bigint::operator<<(unsigned int n)
{
	bigint tmp(*this);
	tmp <<= n;
	return (tmp);
}

bigint &bigint::operator<<=(unsigned int n)
{
	if (number_str != "0")
		number_str.append(n, '0');
	return (*this);
}

bigint &bigint::operator>>=(const bigint &cpy)
{
	unsigned long	n;
	long			size;

	n = std::atol(cpy.number_str.c_str());
	size = number_str.length();
	if (n <= size)
		number_str = "";
	else
		number_str.erase(size - n);
	return (*this);
}

bool bigint::operator>(const bigint &cpy) const
{
	if (number_str.length() == cpy.number_str.length())
	{
		if (number_str > cpy.number_str)
			return (true);
	}
	else if (number_str.length() > cpy.number_str.length())
		return (true);
	return (false);
}

bool bigint::operator<(const bigint &cpy) const
{
	if (number_str.length() == cpy.number_str.length())
	{
		if (number_str < cpy.number_str)
			return (true);
	}
	else if (number_str.length() < cpy.number_str.length())
		return (true);
	return (false);
}

bool bigint::operator>=(const bigint &cpy) const
{
	return (!(*this < cpy));
}

bool bigint::operator<=(const bigint &cpy) const
{
	return !(*this > cpy);
}

bool bigint::operator==(const bigint &cpy) const
{
	return (number_str == cpy.number_str);
}
bool bigint::operator!=(const bigint &cpy) const
{
	return !(*this == cpy);
}