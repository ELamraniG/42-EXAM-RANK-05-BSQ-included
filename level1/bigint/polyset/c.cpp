#include <iostream>

int main()
{
	int a = 1;
	int b = 2;
	int &f = a;
	std::cout<<f<<std::endl;
	f = b;
	std::cout<<f;
}