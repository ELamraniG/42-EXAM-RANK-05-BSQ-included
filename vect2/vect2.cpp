#include "vect2.hpp"

vect2::vect2(const int x, const int y) : x(x), y(y)
{
}

vect2::vect2() : x(0), y(0)
{
}
vect2::~vect2()
{
}
vect2::vect2(const vect2 &cpy) : x(cpy.x), y(cpy.y)
{
}
vect2 &vect2::operator=(const vect2 &cpy)
{
	x = cpy.x;
	y = cpy.y;
	return (*this);
}

int vect2::operator[](int n) const
{
	if (n != 0 || n != 1)
		return (-1);
	if (n == 0)
		return (x);
	else
		return (y);
}
int &vect2::operator[](int n)
{
	if (n == 0)
		return (x);
	else
		return (y);
}

vect2 &vect2::operator++()
{
	x++;
	y++;
	return *this;
}
vect2 vect2::operator++(int)
{
	vect2	v2;

	v2 = *this;
	x++;
	y++;
	return (v2);
}

vect2 &vect2::operator--()
{
	x--;
	y--;
	return *this;
}
vect2 vect2::operator--(int)
{
	vect2	v2;

	v2 = *this;
	x--;
	y--;
	return (v2);
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
vect2 &vect2::operator*=(const int n)
{
	x *= n;
	y *= n;
	return (*this);
}

vect2 vect2::operator+(const vect2 &cpy) const
{
	return (vect2(x + cpy.x, y + cpy.y));
}
vect2 vect2::operator-(const vect2 &cpy) const
{
	return (vect2(x - cpy.x, y - cpy.y));
}
vect2 vect2::operator*(const int n) const
{
	return (vect2(x * n, y * n));
}

std::ostream &operator<<(std::ostream &o, const vect2 &vec)
{
	o << "{" << vec.x << ", " << vec.y << "}";
	return (o);
}

vect2 operator*(const int n, const vect2 &vec)
{
	vect2 v3(n * vec.x, n * vec.y);
	return (v3);
}

vect2 vect2::operator-()
{
	vect2 vtmp(-this->x, -this->y);
	return (vtmp);
}


bool vect2::operator==(const vect2 &cpy)
{
	return (this->x == cpy.x && this->y == cpy.y);
}
bool vect2::operator!=(const vect2 &cpy)
{
	return (this->x != cpy.x && this->y != cpy.y);
}