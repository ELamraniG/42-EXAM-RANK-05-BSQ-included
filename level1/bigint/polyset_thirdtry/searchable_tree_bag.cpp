#include "searchable_tree_bag.hpp"

bool searchable_tree_bag::has(int n) const
{
	node *tmp = tree;

	while (tmp)
	{
		if (n == tmp->value)
			return true;
		if (n > tmp->value)
			tmp = tmp->r;
		if (n < tmp->value)
			tmp = tmp->l;
	}
	return false;
}