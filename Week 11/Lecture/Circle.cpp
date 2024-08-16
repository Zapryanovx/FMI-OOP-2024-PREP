#include "Circle.h"

const double PI = 3.1415;
Circle::Circle(int x, int y, double radius) : Shape(1), radius(radius)
{
	setPoint(0, x, y);
}

double Circle::getArea() const
{
	return PI * radius * radius;
}

double Circle::getPer() const
{
	return 2 * PI * radius;
}

bool Circle::isPointIn(int x, int y) const
{	
	Shape::Point p(x, y);

	return getPointAtIndex(0).getDist(p) <= radius;
}