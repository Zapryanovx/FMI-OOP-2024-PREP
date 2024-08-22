#include <iostream>
#include "ShapeCollection.h"
#include "ShapeFactory.h"

int main()
{
	ShapeCollection collection;
	size_t n;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		collection.addFigure(shapeFactory());
	}

	double maxArea = 0;
	for (int i = 0; i < collection.getSize(); i++)
	{
		double currArea = collection[i]->getArea();
		if (currArea > maxArea)
		{
			maxArea = currArea;
		}
	}
	std::cout << maxArea << std::endl;

}