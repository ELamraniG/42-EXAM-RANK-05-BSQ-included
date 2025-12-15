#pragma once
#include <fstream>
#include <ostream>
class vect2
{
	public :
		int x;
		int y;
	vect2();
	vect2(int x, int y);
	~vect2();
	vect2(const vect2 &cpy);
	vect2 & operator=(const vect2 &cpy);

	//+= -= *=
	vect2 & operator+=(const vect2 &cpy);
	vect2 & operator-=(const vect2 &cpy);
	vect2 & operator*=(int n);

	// + -
	vect2  operator+(const vect2 &cpy) const;
	vect2  operator-(const vect2 &cpy) const;

	// vect2 * n and  n * vect2
	vect2 operator*(int n) const;
	friend vect2 operator*(int n,vect2 &cpy);

	// []const and []not const
	int & operator[](int n);
	int operator[](int n) const;

	//++ --  before ++ -- after
	vect2 & operator++();
	vect2 & operator--();

	vect2 operator++(int);
	vect2 operator--(int);

	// == !=
	bool operator==(const vect2 &cpy) const;
	bool operator!=(const vect2 &cpy) const;
	// <<
	friend std::ostream & operator<<(std::ostream &o, const vect2 &cpy);

	// -vect2
	vect2 operator-() const;
};