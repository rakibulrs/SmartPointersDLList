#include <iostream>
#include "../SmartPointersDLList/DoubleLinkedList.h"

int main()
{
	try
	{
		DLList<int> a{ 1,2,3 };
		DLList<int> b{ 1,2,3,4 };
		b = a;
		std::cout << a<<std::endl;
		std::cout << b << std::endl;
		a.push_back(10);
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
	return 0;
}