#include <iostream>
#include "DynamicArrayOfPointers.h"

int main()
{
	DynamicArrayOfPointers test;

	A obj1{ 3,1 };
	A obj2{ 0,0 };

	test.addAtFirstFreeIndex(obj1);

	test.addAtFirstFreeIndex(obj2);

	std::cout << test[0].x << std::endl;
	std::cout << test[1].x << std::endl;
	std::cout << test.size() << std::endl;
	std::cout << std::endl;

	test.popBack();

	std::cout << test[0].x << std::endl;
	//std::cout << test[1].x << std::endl; [ERROR] Doesn't exist anymore

	std::cout << test.size();
}