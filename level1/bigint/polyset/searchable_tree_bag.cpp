#include "searchable_tree_bag.hpp"

bool searchable_tree_bag::has(int n) const
{
	if (!tree)
		return false;
	node *tmp = tree;
	while (tmp)
	{
		if (tmp->value == n)
			return true;
		else if (n >= tmp->value)
			tmp = tmp->r;
		else
			tmp = tmp->l;
	}
	return false;
}
