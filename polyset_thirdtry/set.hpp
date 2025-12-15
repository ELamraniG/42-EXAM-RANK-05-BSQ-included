#pragma once
#include "searchable_array_bag.hpp" 

class set
{
	public: 
		set(searchable_bag &_bag_arr);
		// ~set();
		set();

		bool has(int) const;
		void insert(int);
		void insert(int *, int);
		void print();
		void clear();

		searchable_bag &get_bag() const;
	private :
		searchable_bag &bag_array;
};
