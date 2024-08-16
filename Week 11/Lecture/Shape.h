#pragma once
#include <iostream>

class Shape //тъй като Shape съдържа чисто виртуална функция, 
{			//това означава, че е абстрактен клас

protected:

	//тъй като ще описваме фигурите чрез точки,
	//можем да отделим всичко, свързано с тях 
	struct Point
	{
		int x;
		int y;

		Point(): x(0), y(0) {}
		Point(int x, int y): x(x), y(y) {}
		
		//формула за разстояние между две точки
		double getDist(const Point& other) const
		{

			int dx = x - other.x;
			int dy = y - other.y;

			return sqrt(dx * dx + dy * dy);
		}
	};

	const Point& getPointAtIndex(size_t index) const;

private:
	Point* points;
	size_t pointsCount;

	void copyFrom(const Shape& other);
	void moveFrom(Shape&& other);
	void free();

public:
	Shape(size_t pointsCount);

	Shape(const Shape& other);
	Shape(Shape&& other) noexcept;

	Shape& operator=(const Shape& other);
	Shape& operator=(Shape&& other) noexcept;

	virtual ~Shape(); //[!] при полиморфична йерархия деструктора на базовия клас
	                  //винаги е virtual

	void setPoint(size_t pointIndex, int x, int y);

	virtual double getArea() const = 0; //чисто виртуална функция (задължително се презаписва)
	virtual double getPer() const;
	virtual bool isPointIn(int x, int y) const = 0; //чисто виртуална функция (задължително се презаписва)
};

