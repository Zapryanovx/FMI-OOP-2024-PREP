#include <iostream>
#include "Interval.h"

int main()
{
	Interval v1(1, 10);

	Interval v2(2, 8);

	Interval v3 = intersectIntervals(v1, v2);

	std::cout << v3.getA() << " " << v3.getB() << std::endl;

	return 0;
}