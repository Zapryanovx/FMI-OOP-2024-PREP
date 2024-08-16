#include "Shape.h"
#include <assert.h>

const Shape::Point& Shape::getPointAtIndex(size_t index) const
{
	if (index >= pointsCount)
	{
		throw std::exception("Invalid point index!");
	}

	return points[index];
}

void Shape::copyFrom(const Shape& other)
{
	points = new Point[other.pointsCount];
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

Shape::Shape(size_t pointsCount): pointsCount(pointsCount)
{
	points = new Point[pointsCount];
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

void Shape::setPoint(size_t pointIndex, int x, int y)
{
	if (pointIndex >= pointsCount)
	{
		throw std::exception("Invalid point index!");
	}

	points[pointIndex] = Point(x, y);
}

double Shape::getPer() const
{
	//ако нямаме поне 3 точки, фигурата ни не е валидна
	assert(pointsCount >= 3);

	double per = 0;

	//пресмятаме разстоянието между всеки две съседни точки
	for (int i = 0; i < pointsCount - 1; i++)
	{
		per += points[i].getDist(points[i + 1]);
	}

	//трябва да добавим разстоянието между първата и последната точка
	return per + points[pointsCount - 1].getDist(points[0]);
}


