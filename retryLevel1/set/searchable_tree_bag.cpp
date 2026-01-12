#include "searchable_tree_bag.hpp"
 bool searchable_tree_bag::has(int n) const
 {
    node *tmp = tree;
    while (tmp != 0)
    {
        if (n == tmp->value)
            return true;
        else if (n < tmp->value)
           tmp = tmp->l;
        else
            tmp = tmp->r;
    }
    return false;
 }


