#pragma once
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"

class Triangle: public Shape
{
public:
	Triangle(int x1, int y1, int x2, int y2, int x3, int y3);

	bool intersectsWith(const Shape* other) const override;
	bool intersectsWithTriangle(const Triangle* other) const override;
	bool intersectsWithRect(const Rectangle* other) const override;
	bool intersectsWithCircle(const Circle* other) const override;
};

