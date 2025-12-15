#include "vect2.hpp"

vect2::vect2() : x(0), y(0)
{
}

vect2::vect2(int x, int y) : x(x), y(y)
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
vect2 &vect2::operator=(const vect2 &cpy)
{
	x = cpy.x;
	y = cpy.y;
	return (*this);
}

std::ostream &operator<<(std::ostream &o,const vect2 &v2)
{
	o << "{" << v2.x << ", " << v2.y << "}";
	return (o);
}

int vect2::operator[](const int index) const
{
	if (index == 0)
		return (x);
	else  
		return (y);

}

int &vect2::operator[](int index)
{
	if (index == 0)
		return (x);
	else  
		return (y);
}

vect2 &vect2::operator++()
{
	x++;
	y++;
	return (*this);
}
vect2 &vect2::operator--()
{
	x--;
	y--;
	return (*this);
}

vect2 vect2::operator++(int)
{
	vect2 vect_tmp(x, y);
	x++;
	y++;
	return (vect_tmp);
}
vect2 vect2::operator--(int)
{
	vect2 vect_tmp(x, y);
	x--;
	y--;
	return (vect_tmp);
}

vect2 &vect2::operator+=(const vect2 &cpy)
{
	x += cpy.x;
	y += cpy.y;
	return (*this);
}
vect2 &vect2::operator-=(const vect2 &cpy)
{
	x -= cpy.x;
	y -= cpy.y;
	return (*this);
}
vect2 &vect2::operator*=(int n)
{
	x *= n;
	y *= n;
	return (*this);
}

vect2 vect2::operator*(int n) const
{
	vect2 vect2_tmp(x * n,y * n);
	return vect2_tmp;
}
vect2 vect2::operator+(const vect2 &cpy) const
{
	vect2 vect2_tmp(x + cpy.x,y + cpy.y);
	return vect2_tmp;
}
vect2 vect2::operator-(const vect2 &cpy) const
{
	vect2 vect2_tmp(x - cpy.x,y - cpy.y);
	return vect2_tmp;
}

vect2 operator*(int n, const vect2 &cpy)
{
	vect2 vect2_tmp(n * cpy.x, n * cpy.y);
	return vect2_tmp;
}

vect2 vect2::operator-() const
{
	vect2 vect2_tmp(-x, -y);
	return vect2_tmp;
}



bool vect2::operator==(const vect2 &cpy) const
{
	return (x == cpy.x && y == cpy.y);
}
bool vect2::operator!=(const vect2 &cpy) const
{
	return !(x == cpy.x && y == cpy.y);
}