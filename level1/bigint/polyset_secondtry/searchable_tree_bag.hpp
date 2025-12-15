#pragma once
#include "searchable_bag.hpp"
#include "tree_bag.hpp"
class searchable_tree_bag : public searchable_bag , public tree_bag
{
	bool has(int) const;
};