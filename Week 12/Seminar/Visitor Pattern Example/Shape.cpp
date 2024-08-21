#include "Shape.h"

Shape::Shape(size_t pointsCount) : pointsCount(pointsCount)
{
	points = new point[pointsCount];
}

void Shape::copyFrom(const Shape& other)
{
	points = new point[other.pointsCount];
	pointsCount = other.pointsCount;

	for (int i = 0; i < pointsCount; i++)
	{
		points[i] = other.points[i];
	}
}

void Shape::free()
{
	delete[] points;
}

Shape::Shape(const Shape& other)
{
	copyFrom(other);
}

Shape& Shape::operator=(const Shape& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Shape::~Shape()
{
	free();
}

const Shape::point& Shape::getPointAtIndex(size_t index) const
{
	if(index >= pointsCount)
	{
		throw std::exception("Invalid point index!");
	}

	return points[index];
}

void Shape::setPoint(size_t pointIndex, int x, int y)
{
	if (pointIndex >= pointsCount)
	{
		throw std::exception("Invalid point index!");
	}

	points[pointIndex] = point(x, y);
}