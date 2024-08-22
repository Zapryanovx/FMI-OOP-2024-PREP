#include "Shape.h"
#include <assert.h>

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

void Shape::moveFrom(Shape&& other)
{
	points = other.points;
	other.points = nullptr;

	pointsCount = other.pointsCount;
	other.pointsCount = 0;
}

void Shape::free()
{
	delete[] points;
}

Shape::Shape(const Shape& other)
{
	copyFrom(other);
}

Shape::Shape(Shape&& other) noexcept
{
	moveFrom(std::move(other));
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

Shape& Shape::operator=(Shape&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Shape::~Shape()
{
	free();
}

const Shape::point& Shape::getPointAtIndex(size_t index) const
{
	if (index >= pointsCount)
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

double Shape::getPer() const
{
	assert(pointsCount >= 3);
	double per = 0;

	for (int i = 0; i < pointsCount - 1; i++)
	{
		per += (points[i].getDist(points[i + 1]));
	}

	per += points[0].getDist(points[pointsCount - 1]);

	return per;
}

