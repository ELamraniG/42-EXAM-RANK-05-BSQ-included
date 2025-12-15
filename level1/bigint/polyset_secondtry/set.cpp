#include "set.hpp"

set::~set()
{
}
set::set(searchable_bag &cpy) : our_bag((cpy))
{
}

set::set(set &cpy) : our_bag(cpy.our_bag)
{

}
set & set::operator=(set &cpy)
{
	our_bag = cpy.our_bag;
	return *this;
}

void set::insert(int n)
{
	if (our_bag.has(n))
		return;
	our_bag.insert(n);
}
void set::insert(int *n, int size)
{
	for (int i = 0; i < size;i++)
	{
		if (our_bag.has(n[i]))
			continue;;
		our_bag.insert(n[i]);
	}
}

bool set::has(int n) const
{
	return our_bag.has(n);
}
void set::print()
{
	our_bag.print();
}
void set::clear()
{
	our_bag.clear();
}
searchable_bag &set::get_bag()
{
	return our_bag;
}

