#pragma once
#include "searchable_array_bag.hpp"
#include "searchable_bag.hpp"

class set
{
  public:
	searchable_bag &our_bag;
	~set();
	set(searchable_bag &cpy);
	set(set &cpy);
	set & operator=(set &cpy);

	void insert(int);
	void insert(int *, int);
	bool has(int) const;
	void print();
	void clear();
	searchable_bag &get_bag();
};