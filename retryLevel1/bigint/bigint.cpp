#include "bigint.hpp"
#include <algorithm>

bigint::bigint(int n)
{
    our_number = std::to_string(n);
}
bigint::bigint(std::string our_number) : our_number(our_number)
{
}
bigint::bigint()
{
    our_number = "0";
}
bigint::~bigint()
{

}


bigint& bigint::operator+=(const bigint &cpy)
{
    std::reverse(our_number.begin(),our_number.end());
    std::string tmp = cpy.our_number;
    std::reverse(tmp.begin(),tmp.end());
    std::string new_string;
    unsigned int carry = 0;
    unsigned int res = 0;
    int i = 0, j = 0;
    while (our_number[i] || tmp[j] || carry != 0)
    {
        res = 0;
        res += carry;
        if (our_number[i])
        {
            res += our_number[i] - '0';
            i++;
        }
        if (tmp[j])
        {
            res += tmp[j] - '0';
            j++;
        }
        carry = res / 10;
        new_string += res % 10 + '0';
    }
    std::reverse(new_string.begin(),new_string.end());
    our_number = new_string;
    return *this;
}



bigint bigint::operator+(const bigint &cpy) const
{
    bigint tmp(cpy.our_number);
    tmp += *this;
    return tmp;
}

bigint& bigint::operator<<=(int n)
{
    for (int i = 0; i < n; i++)
        our_number += '0';
    return *this;
}

bigint bigint::operator<<(int n) const
{
    bigint tmp(our_number);
    tmp <<= n;
    return tmp;
}


bigint& bigint::operator>>=(int n)
{
    if (our_number == "0")
        return *this;
    for (int i = 0; i < n; i++)
    {
        our_number.pop_back();
    }
    if (our_number.empty())
        our_number = "0";
    return *this;
}

bigint& bigint::operator>>=(const bigint &cpy)
{
    int n = std::atol(cpy.our_number.c_str());
    if (our_number == "0")
        return *this;
    for (int i = 0; i < n; i++)
    {
        our_number.pop_back();
    }
    if (our_number.empty())
        our_number = "0";
    return *this;
 }


 bool bigint::operator<(const bigint &cpy) const
 {
    if (our_number.size() == cpy.our_number.size())
        return our_number < cpy.our_number;
    return our_number.size() < cpy.our_number.size();
 }
 bool bigint::operator>(const bigint &cpy) const
 {
    if (our_number.size() == cpy.our_number.size())
        return our_number > cpy.our_number;
    return our_number.size() > cpy.our_number.size();
 }