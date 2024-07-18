//#ОБЯСНЕНИЕ НА ЗАДАЧАТА:

// Да се реализира програма, която сортира N на брой триъгълници спрямо тяхното лице,
// като всеки триъгълник е описан с 3 точки

#include <iostream>

namespace Points
{
	struct Point
	{
		//координатите на една точка
		int x = 0; 
		int y = 0;
	};

	void readPoint(Point& point)
	{
		std::cin >> point.x;
		std::cin >> point.y;
	}

	double getDist(const Point& p1, const Point& p2)
	{
		//формула за разстояние между две точки
		int dx = p2.x - p1.x;
		int dy = p2.y - p1.y;

		return sqrt(dx * dx + dy * dy);
	}

	void printPoint(const Point& point)
	{
		std::cout << "(" << point.x << ", " << point.y << ") ";
	}
}

namespace Figures
{
	//включваме функционалността, отделена в namespace-a Points
	using namespace Points;

	//триъгълник, определен от 3 точки
	struct Triangle
	{
		Point p1;
		Point p2;
		Point p3;
	};

	void readTriangle(Triangle& triangle)
	{
		readPoint(triangle.p1);
		readPoint(triangle.p2);
		readPoint(triangle.p3);
	}

	double getArea(const Triangle& triangle)
	{
		//използване на Хероновата формула за намиране на лице на триъгълник
		double sideA = getDist(triangle.p1, triangle.p2);
		double sideB = getDist(triangle.p2, triangle.p3);
		double sideC = getDist(triangle.p1, triangle.p3);

		double halfPer = (sideA + sideB + sideC) / 2;

		return sqrt(halfPer * (halfPer - sideA) * (halfPer - sideB) * (halfPer - sideC));
	}

	void sortTrianglesByArea(Triangle* triangles, size_t N)
	{
		//за да намалим броя на извикванията на функцията getArea(),
		//ще ги сметнем предварително и ще сортираме спрямо масива,
		//в който ги пазим, а не директно спрямо масива от триъгълници

		//пресмятаме лицата на триъгълниците предварително
		double* areas = new double[N];
		for (int i = 0; i < N; i++)
		{
			areas[i] = getArea(triangles[i]);
		}

		//selection sort
		for (int i = 0; i < N - 1; i++)
		{
			int minAreaTriangleIndex = i;

			for (int j = i + 1; j < N; j++)
			{
				if (areas[j] < areas[minAreaTriangleIndex])
				{
					minAreaTriangleIndex = j;
				}
			}

			if (minAreaTriangleIndex != i)
			{
				//ако намерим триъгълник с по-малко лице
				//разменяме, както в масива от лица, така и в този от триъгълници,
				//за да не разбъркаме кое лице на кой триъгълник отговаря

				std::swap(triangles[i], triangles[minAreaTriangleIndex]);
				std::swap(areas[i], areas[minAreaTriangleIndex]);
			}
		}

		delete[] areas;
	}

	void printTriangle(const Triangle& triangle)
	{
		printPoint(triangle.p1);
		printPoint(triangle.p2);
		printPoint(triangle.p3);
		std::cout << std::endl;
	}
}
//
//int main()
//{
//	size_t N;
//	std::cin >> N;
//
//	Figures::Triangle* triangleArr = new Figures::Triangle[N];
//
//	for (size_t i = 0; i < N; i++)
//	{
//		Figures::readTriangle(triangleArr[i]);
//	}
//
//	Figures::sortTrianglesByArea(triangleArr, N);
//
//	for (size_t i = 0; i < N; i++)
//	{
//		Figures::printTriangle(triangleArr[i]);
//	}
//
//	delete[] triangleArr;
//
//	return 0;
//}