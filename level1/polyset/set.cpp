#include "set.hpp"

set::set(searchable_bag &cpy) : bag(cpy)
{

}

set::~set()
{
}
set::set(const set &copy) : bag(copy.bag)
{
}
set &set::operator=(const set &copy)
{
	bag = copy.bag;
	return *this;
}

void set::insert(int n)
{
	if (bag.has(n))
		return ;
	bag.insert(n);
}
void set::insert(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (bag.has(arr[i]))
			continue ;
		bag.insert(arr[i]);
	}
}
void set::print() const
{
	bag.print();
}
void set::clear()
{
	bag.clear();
}

bool set::has(int n) const
{
	return (bag.has(n));
}