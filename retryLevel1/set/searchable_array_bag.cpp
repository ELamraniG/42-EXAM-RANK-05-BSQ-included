#include "searchable_array_bag.hpp"

 bool searchable_array_bag::has(int n) const
 {
    for (int i = 0; i < size;i++)
        if (n == data[i])
            return true;
    return false;
 }