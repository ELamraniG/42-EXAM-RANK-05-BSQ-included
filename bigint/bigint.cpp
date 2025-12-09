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

bigint::bigint(bigint &cpy)
{
	number_str = cpy.number_str;
}
bigint& bigint::operator=(const bigint& cpy) 
{
	number_str = cpy.number_str;
	return *this;
}

std::ostream & operator<<(std::ostream &o, const bigint &big)
{
	o << big.number_str;
	return o;
}


bigint &bigint::operator+=(const bigint &cpy)
{
	std::string string_result;
	unsigned int carry = 0;
	int res = 0;

	std::string s1 = number_str;
	std::string s2 = cpy.number_str;
	int i = s1.size();
	int j = s2.size();
	i--;
	j--;
	while (i >= 0 || j >= 0 || carry)
	{
		res += carry;
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
	}	
	string_result.reserve();
	number_str = string_result;
	return *this;

}