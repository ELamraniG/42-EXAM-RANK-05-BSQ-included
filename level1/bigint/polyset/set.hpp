#include "searchable_bag.hpp"
#include "searchable_array_bag.hpp"
class set 
{
	private :
		searchable_bag &bag;
	public :
		void insert(int);
		void insert(int *, int);
		void print() const;
		void clear();

		bool has(int) const;

		~set();
		set(const set& copy);
		set	&operator=(const set& copy);


		set(searchable_bag &cpy);
		const searchable_bag& get_bag() const;
};