#pragma once
#include "searchable_bag.hpp"
class set
{
    private :
        searchable_bag &our_bag;
    public :
        set( searchable_bag &cpy);
        ~set();
        set(const set &cpy);
        set & operator=(const set &cpy);
        searchable_bag & get_bag() const;


        bool has(int) const;
	    void print() const;
	    void clear();
        void insert(int);
	    void insert(int *, int);
};