#include <iostream>

#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

void printAreas(const Shape* const* shapes, size_t shapesCount)
{
	for (int i = 0; i < shapesCount; i++)
	{
		std::cout << shapes[i]->getArea() << std::endl;
	}
}

void printPers(const Shape* const* shapes, size_t shapesCount)
{
	for (int i = 0; i < shapesCount; i++)
	{
		std::cout << shapes[i]->getPer() << std::endl;
	}
}

void checkPointIn(const Shape* const* shapes, size_t shapesCount, int x, int y)
{
	for (int i = 0; i < shapesCount; i++)
	{
		std::cout << shapes[i]->isPointIn(x, y) << std::endl;
	}
}

void freeCollection(Shape** shapes, size_t shapesCount)
{
	for (int i = 0; i < shapesCount; i++)
	{
		delete shapes[i];
	}
	delete[] shapes;
}

int main()
{
	//при абстрактни класове може да имаме пойнтъри от техния тип, но не и обект
	Shape** arr = new Shape * [4];

	// FACTORY
	arr[0] = new Rectangle(3, 4, 6, 8);
	arr[1] = new Circle(3, 3, 4);
	arr[2] = new Circle(1, 4, 5);
	arr[3] = new Triangle(1, 1, 2, 2, 3, 3);

	printAreas(arr, 4);
	std::cout << std::endl;
	printPers(arr, 4);
	std::cout << std::endl;
	checkPointIn(arr, 4, 3, 3);
	std::cout << std::endl;

	freeCollection(arr, 4);
}


