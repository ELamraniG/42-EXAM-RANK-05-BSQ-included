#pragma once
#include <iostream>
#include <ostream>
class bigint
{
    public :
        std::string our_number;
    bigint(int n);
    bigint(std::string our_number);
    bigint();
    ~bigint();
    friend std::ostream &operator<<(std::ostream &o,const bigint &bigi)
    {
        o<<bigi.our_number;
        return o;
    }
    bigint& operator+=(const bigint &cpy);
    bigint operator+(const bigint &cpy) const;
    // << >>= <<=
    bigint& operator<<=(int n) ;
    bigint& operator>>=(int n) ;
    bigint operator<<(int n) const;
    bigint& operator>>=(const bigint &cpy);

    // < 
    bool operator<(const bigint &cpy) const;
    bool operator>(const bigint &cpy) const;

};