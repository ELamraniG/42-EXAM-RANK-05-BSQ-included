
#include "vect2.hpp"
vect2::vect2(int x,int y) : x(x),y(y)
{

}

vect2::vect2() : x(0), y(0)
{

}

vect2::~vect2()
{

}

vect2::vect2(const vect2 &cpy)
{
    x = cpy.x;
    y = cpy.y;
}

vect2& vect2::operator=(const vect2 &cpy)
{
    x = cpy.x;
    y = cpy.y;
    return *this;
}
        

std::ostream &operator<<(std::ostream &o,const vect2 &vect)
{
    o << "{" << vect.x << ", " << vect.y << "}";
    return o;
}

vect2& vect2::operator--()
{
    x--;
    y--;
    return *this;
}
vect2& vect2::operator++()
{
    x++;
    y++;
    return *this;
}


vect2 vect2::operator--(int)
{
    vect2 tmp(*this);
    x--;
    y--;
    return tmp;
}
vect2 vect2::operator++(int)
{
    vect2 tmp(*this);
    x++;
    y++;
    return tmp;
}

int vect2::operator[](int i) const
{
    if (i == 0)
        return x;
    return y;
}
int & vect2::operator[](int i)
{
    if (i == 0)
        return x;
    return y;
}

vect2& vect2::operator+=(const vect2 vect)
{
    x += vect.x;
    y += vect.y;
    return *this;
}

vect2& vect2::operator-=(const vect2 vect)
{
    x -= vect.x;
    y -= vect.y;
    return *this;
}

vect2 vect2::operator+(const vect2 vect) const
{
    vect2 tmp(x + vect.x,y + vect.y);
    return tmp;
}
vect2 vect2::operator-(const vect2 vect) const
{
    vect2 tmp(x - vect.x,y - vect.y);
    return tmp;
}

vect2 vect2::operator*(int n) const
{
   vect2 tmp(x * n,y * n);
   return tmp;
}

vect2 operator*(int n,const vect2 vect) 
{
     vect2 tmp(vect.x * n,vect.y * n);
   return tmp;
}

vect2& vect2::operator*=(int n)
{
    x*=n;
    y*=n;
    return *this;
}

vect2 vect2::operator-() const
{
    vect2 tmp(-x,-y);
    return tmp;
}
vect2 vect2::operator+() const
{
    vect2 tmp(x,y);
    return tmp;
}

bool vect2::operator==(const vect2 vect) const
{
    if (vect.x == x && vect.y == y)
        return true;
    return false;
}
bool vect2::operator!=(const vect2 vect) const
{
    return !(vect == *this);
}