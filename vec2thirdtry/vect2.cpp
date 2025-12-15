#include "vect2.hpp"

vect2::vect2() : x(0), y(0)
{
}
vect2::vect2(int x, int y) : x(x), y(y)
{

}
vect2::~vect2(){}


vect2::vect2(const vect2 &cpy)
{
	x = cpy.x;
	y = cpy.y;
}
vect2 &vect2::operator=(const vect2 &cpy)
{
	x = cpy.x;
	y = cpy.y;
	return *this;
}

vect2 & vect2::operator+=(const vect2 &cpy)
{
	x += cpy.x;
	y += cpy.y;
	return *this;
}
vect2 & vect2::operator-=(const vect2 &cpy)
{
	x -= cpy.x;
	y -= cpy.y;
	return *this;
}

vect2 & vect2::operator*=(int n)
{
	x *= n;
	y *= n;
	return *this;
}


vect2  vect2::operator+(const vect2 &cpy) const
{
	vect2 tmp(*this);
	tmp += cpy;
	return tmp;
}
vect2  vect2::operator-(const vect2 &cpy) const
{
	vect2 tmp(*this);
	tmp -= cpy;
	return tmp;
}


vect2 vect2::operator*(int n) const
{
	vect2 tmp(*this);
	tmp *= n;
	return tmp;
}
vect2 operator*(int n,vect2 &cpy)
{
	vect2 tmp(cpy);
	tmp *= n;
	return tmp;
}


int & vect2::operator[](int n)
{
	if (n == 0)
		return x;
	return y;
}

int vect2::operator[](int n) const
{
	if (n == 0)
		return x;
	return y;
}


vect2 & vect2::operator++()
{
	x++;
	y++;
	return *this;
}
vect2 & vect2::operator--()
{
	x--;
	y--;
	return *this;
}

vect2 vect2::operator++(int)
{
	vect2 tmp(*this);
	x++;
	y++;
	return tmp;
}

vect2 vect2::operator--(int)
{
	vect2 tmp(*this);
	x--;
	y--;
	return tmp;
}

bool vect2::operator==(const vect2 &cpy) const
{
	if (x == cpy.x && y == cpy.y)
		return true;
	return false;
}
bool vect2::operator!=(const vect2 &cpy) const
{
	return !(*this == cpy);
}

std::ostream & operator<<(std::ostream &o, const vect2 &cpy)
{
	o << "{" << cpy.x << ", "<< cpy.y<<"}";
	return o;
}

vect2 vect2::operator-() const
{
	vect2 tmp(-x,-y);
	return tmp;
}