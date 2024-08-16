#pragma once
#include "Shape.h"

class Circle: public Shape
{
	double radius;

public:
	Circle(int x, int y, double radius); //координати на център + радиус
	
	double getArea() const override;
	double getPer() const override; //не можем да използваме имплементацията
	                                //на getPer() на Shape, тъй като се използва друга формула
	                                //ще я презапишем

	bool isPointIn(int x, int y) const override;
									
};

