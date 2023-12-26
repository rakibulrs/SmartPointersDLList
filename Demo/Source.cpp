#include <iostream>
#include "../SmartPointersDLList/DoubleLinkedList.h"

int main()
{
	try
	{
		DLList<int> a{ 1,2,3 };
		DLList<int> b{ 1,2,3,4 };
		std::cout << (a == b);
		std::cout << (a == a);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what();
	}
	return 0;
}