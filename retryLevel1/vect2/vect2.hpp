#pragma once
#include <ostream>
class vect2
{
    public :
        int x;
        int y;
        vect2(int x,int y);
        vect2();
        ~vect2();
        vect2(const vect2 &cpy);
        vect2& operator=(const vect2 &cpy);

    friend std::ostream &operator<<(std::ostream &o,const vect2 &vect);

    // --vect ++vect 
    vect2 &operator--();
    vect2 &operator++();

     // vect++ vect++
    vect2 operator--(int);
    vect2 operator++(int);
    // []
    int operator[](int i) const;
    int &operator[](int i);
    // += -=
    vect2& operator+=(const vect2 vect);
    vect2& operator-=(const vect2 vect);
    // vect + vect  vect - vect
    vect2 operator+(const vect2 vect) const;
    vect2 operator-(const vect2 vect) const;
    // vect * 55
    vect2 operator*(int n) const;
    // 55 * vect
    friend vect2 operator*(int n,const vect2 vect) ;
    // vect *= 42
    vect2& operator*=(int n);
    // -vect
    vect2 operator-() const;
    vect2 operator+() const;


    // == != 
    bool operator==(const vect2 vect) const;
    bool operator!=(const vect2 vect) const;
};