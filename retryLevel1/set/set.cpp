#include "set.hpp"

set::set( searchable_bag &cpy) : our_bag(cpy)
{

}
set::~set()
{

}
set::set(const set &cpy) : our_bag(cpy.get_bag())
{

}
set & set::operator=(const set &cpy)
{
   ( void)(cpy);
    return *this;
}
searchable_bag & set::get_bag() const
{
    return our_bag;
}


bool set::has(int n) const
{
    return our_bag.has(n);
}
void set::print() const
{  
    our_bag.print();
}
void set::clear()
{
    our_bag.clear();
}
void set::insert(int n)
{
    if (our_bag.has(n))
        return;
    our_bag.insert(n);
}
void set::insert(int *arr, int sizeofarr)
{
    for (int i = 0;i < sizeofarr ;i++)
    {
        if(our_bag.has(arr[i]))
            continue;
        our_bag.insert(arr[i]);
    }
}