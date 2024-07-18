//#include <iostream>
//
//struct Vector
//{
//	double x;
//	double y;
//	double z;
//
//};
//
//Vector sumOfVectors(const Vector& v1, const Vector& v2)
//{
//	return { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z };
//
//}
//
//void printCoordinates(const Vector& v1)
//{
//	std::cout << v1.x << " " << v1.y << " " << v1.z << std::endl;
//}
//
//bool isLinearDependent(const Vector& v1, const Vector& v2)
//{
//	return v1.x / v2.x == v1.y / v2.y == v1.z / v2.z;
//}
//
//int main()
//{
//	Vector v1 = { 1, 2, 3 };
//	Vector v2 = { 1, 2, 3 };
//
//	Vector v3 = sumOfVectors(v1, v2);
//
//	std::cout << v3.x << " " << v3.y << " " << v3.z << std::endl;
//
//	printCoordinates(v1);
//	std::cout<<isLinearDependent(v1, v2);
//
//	return 0;
//}