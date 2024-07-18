//#include <iostream>
//
//struct Point
//{
//	double x;
//	double y;
//};
//
//struct Rectangle
//{
//	Point lowerLeft;
//	Point upperRight;
//};
//
//double distanceBetweenPoints(const Point& firstPoint, const Point& secondPoint)
//{
//	return std::sqrt((secondPoint.x - firstPoint.x) * (secondPoint.x - firstPoint.x) 
//					+(secondPoint.y - firstPoint.y) * (secondPoint.y - firstPoint.y));
//}
//
//int perimeterOfRectangle(const Rectangle& rectangle)
//{
//	Point upperLeft;
//	upperLeft.x = rectangle.lowerLeft.x;
//	upperLeft.y = rectangle.upperRight.y;
//	
//	Point lowerRight;
//	lowerRight.x = rectangle.upperRight.x;
//	lowerRight.y = rectangle.lowerLeft.y;
//
//	return 2 * distanceBetweenPoints(upperLeft, rectangle.upperRight)
//		 + 2 * distanceBetweenPoints(upperLeft, rectangle.lowerLeft);
//
//}
//
//int areaOfReactangle(const Rectangle& rectangle)
//{
//	Point upperLeft;
//	upperLeft.x = rectangle.lowerLeft.x;
//	upperLeft.y = rectangle.upperRight.y;
//
//	Point lowerRight;
//	lowerRight.x = rectangle.upperRight.x;
//	lowerRight.y = rectangle.lowerLeft.y;
//
//	return distanceBetweenPoints(upperLeft, rectangle.upperRight)
//		 * distanceBetweenPoints(upperLeft, rectangle.lowerLeft);
//}
//
//void checkPosition(const Rectangle& firstRectangle, const Rectangle& secondRectangle)
//{
//	bool isInside = (firstRectangle.lowerLeft.x >= secondRectangle.lowerLeft.x) &&
//		(firstRectangle.upperRight.x <= secondRectangle.upperRight.x) &&
//		(firstRectangle.lowerLeft.y >= secondRectangle.lowerLeft.y) &&
//		(firstRectangle.upperRight.y <= secondRectangle.upperRight.y);
//
//	bool isOverlapping = !(firstRectangle.upperRight.x < secondRectangle.lowerLeft.x ||
//		firstRectangle.lowerLeft.x > secondRectangle.upperRight.x ||
//		firstRectangle.upperRight.y < secondRectangle.lowerLeft.y ||
//		firstRectangle.lowerLeft.y > secondRectangle.upperRight.y);
//
//	if (isInside)
//	{
//		std::cout << "The first rectangle is entirely inside the second rectangle." << std::endl;
//	}
//	else if (isOverlapping)
//	{
//		std::cout << "The first rectangle overlaps partially with the second rectangle." << std::endl;
//	}
//	else 
//	{
//		std::cout << "The first rectangle does not overlap with the second rectangle." << std::endl;
//	}
//
//}
//
//int main()
//{
//	Rectangle rectangle;
//	rectangle.lowerLeft = { 5, 4 };
//	rectangle.upperRight = { 4, 5 };
//	
//	perimeterOfRectangle(rectangle);
//
//	return 0;
//}