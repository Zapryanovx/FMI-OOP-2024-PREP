#include "Triangle.h"

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3): Shape(3)
{
	setPoint(0, x1, y1);
	setPoint(1, x2, y2);
	setPoint(2, x3, y3);
}

double Triangle::getArea() const
{
	const Shape::Point& p0 = getPointAtIndex(0);
	const Shape::Point& p1 = getPointAtIndex(1);
	const Shape::Point& p2 = getPointAtIndex(2);

	double halfPer = getPer() / 2;
	double firstSide = p0.getDist(p1);
	double secondSide = p1.getDist(p2);
	double thirSide = p0.getDist(p2);

	//херонова формула
	return sqrt(halfPer * (halfPer - firstSide) * (halfPer - secondSide) * (halfPer - thirSide));
}

bool Triangle::isPointIn(int x, int y) const
{
	//една точка е в триъгълника, ако когато направим 3 триъгълника с нея и всеки две точки измежду върховете
	//на триъгълника, тяхното лице е равно на това на оригиналния триъгълник

	Shape::Point p(x, y);

	Triangle t1(getPointAtIndex(0).x, getPointAtIndex(0).y, getPointAtIndex(1).x, getPointAtIndex(1).y, p.x, p.y);
	Triangle t2(getPointAtIndex(1).x, getPointAtIndex(1).y, getPointAtIndex(2).x, getPointAtIndex(2).y, p.x, p.y);
	Triangle t3(getPointAtIndex(0).x, getPointAtIndex(0).y, getPointAtIndex(2).x, getPointAtIndex(2).y, p.x, p.y);

	double sumOfAreas = t1.getArea() + t2.getArea() + t3.getArea();

	return abs(sumOfAreas - getArea()) <= 1e-6;

}

