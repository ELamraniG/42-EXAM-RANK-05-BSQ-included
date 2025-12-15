#pragma once
#include <fstream>
#include <ostream>

class vect2
{
  public:
	int x;
	int y;

	// canonicale
	vect2();
	vect2(int x, int y);
	~vect2();
	vect2(const vect2 &cpy);
	vect2 &operator=(const vect2 &cpy);

	friend std::ostream &operator<<(std::ostream &o, const vect2 &v2);

	//[]
	int &operator[](int index);
	int operator[](int index) const;

	// ++ -- before
	vect2 &operator++();
	vect2 &operator--();
	// ++ -- after
	vect2 operator++(int);
	vect2 operator--(int);

	// += -=
	vect2 &operator+=(const vect2 &cpy);
	vect2 &operator-=(const vect2 &cpy);
	vect2 &operator*=(int n);
	
	// vect * number
	vect2 operator*(int n) const;

	// vect  - + vect
	vect2 operator+(const vect2 &cpy) const;
	vect2 operator-(const vect2 &cpy) const;

	// number * vect
	friend vect2 operator*(int n, const vect2 &cpy);

	// -vect2
	vect2 operator-() const;

	// == !+
	bool operator==(const vect2 &cpy) const;
	bool operator!=(const vect2 &cpy) const;
};