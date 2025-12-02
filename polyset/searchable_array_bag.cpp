#include "searchable_array_bag.hpp"
#include <iostream>
bool searchable_array_bag::has(int n) const
{
	for (int i = 0; i < size;i++)
	if (data[i] == n)
			return true;
	return false;
}

// searchable_array_bag::searchable_array_bag()
// {

// }
// searchable_array_bag::~searchable_array_bag()
// {

// }
// searchable_array_bag::searchable_array_bag(const searchable_array_bag &cpy)
// {
// 	this->data = new int[cpy.size];
// 	this->size = cpy.size;
// 	for (int i = 0; i< cpy.size;i++)
// 		data[i] = cpy.data[i];
// }
// searchable_array_bag & searchable_array_bag::operator=(const searchable_array_bag &cpy)
// {
// 	this->data = cpy.data;
// 	this->size = cpy.size;
// 	return *this;
// }