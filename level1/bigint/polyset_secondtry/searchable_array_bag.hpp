#pragma once
#include "searchable_bag.hpp"
#include "array_bag.hpp"
class searchable_array_bag : public searchable_bag , public array_bag
{
	public :
	bool has(int) const;
};