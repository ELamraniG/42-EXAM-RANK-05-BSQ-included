#include "searchable_tree_bag.hpp"

bool searchable_tree_bag::has(int n) const
{
	node *tmp = tree;
	while (tmp)
	{
		if (tmp->value == n)
			return true;
		if (n < tmp->value)
			tmp = tmp->l;
		else
			tmp = tmp->r;
	}
	return false;
}