#include <iostream>
#include "../SmartPointersDLList/DoubleLinkedList.h"


int main()
{
	DLList<int> a;
	a.push_back(10);

	std::cout << a.to_string();
	return 0;
}