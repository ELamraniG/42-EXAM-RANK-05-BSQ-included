#pragma once
#include <fstream>
#include <ostream>
class vect2
{
	public :
		int x;
		int y;
	vect2();
	vect2(const int,const int);
	~vect2();
	vect2(const vect2 &cpy);
	vect2 & operator=(const vect2 &cpy);
	int operator[](int n) const;
	int &operator[](int n);


	vect2 &operator++();
	vect2 operator++(int);
	vect2 &operator--();
	vect2 operator--(int);

	vect2 &operator+=(const vect2 &cpy );
	vect2 &operator-=(const vect2 &cpy );
	vect2 &operator*=(const int n);

	vect2 operator+(const vect2 &cpy ) const;
	vect2 operator-(const vect2 &cpy ) const;
	vect2 operator*(const int n);


};

std::ostream & operator<<(std::ostream& o,const vect2 &vec)
{
	o << "{" << vec.x << ", " << vec.y << "}";
	return o;
}