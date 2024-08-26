#include <iostream>

#include "MyStack.hpp"

int main()
{
	MyStack<int, 10> s;

	s.push(3);

	std::cout << s.peek() << std::endl;

	return 0;
}