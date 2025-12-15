#include "set.hpp" 
#include "array_bag.hpp"
#include "searchable_array_bag.hpp"
#include "searchable_tree_bag.hpp"

set::set(searchable_bag &_bag_arr) : bag_array(_bag_arr)
{
	
}


	
	
	
	searchable_bag& set::get_bag() const
	{
		return bag_array;
	}

	bool set::has(int n) const
	{
		return bag_array.has(n);
	}
	void set::insert(int n)
	{
		if (bag_array.has(n))
			return;
		bag_array.insert(n);
	}
	void set::insert(int *dataa, int size)
	{
		for (int i = 0; i < size; i++)
		{
			if (bag_array.has(dataa[i]))
				continue;
			bag_array.insert(dataa[i]);
		}
	}
	void set::print()
	{
		bag_array.print();
	}
	void set::clear()
	{
		bag_array.clear();
	}
