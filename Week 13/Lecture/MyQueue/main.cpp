#include <iostream>
#include "Queue.hpp"

int main()
{
	MyQueue<int> q;

	for (int i = 0; i < 100; i++)
	{
		q.push(i);
	}

	MyQueue<int> qCopy = q;

	while (!qCopy.isEmpty())
	{
		std::cout << qCopy.peek() << " ";
		qCopy.pop();
	}

	return 0;
}