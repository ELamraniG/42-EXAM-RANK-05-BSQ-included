#pragma once
#include "tree_bag.hpp"
#include "searchable_bag.hpp"
class searchable_tree_bag : public tree_bag ,public searchable_bag
{
    public :
        bool has(int) const;
};