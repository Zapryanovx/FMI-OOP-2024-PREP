//#include <iostream>
//#include <fstream>
//
//void readNums(int& a, int& b, int& c)
//{
//	std::ifstream fileIn("02_max_of_nums_in_file.txt");
//
//	if (!fileIn.is_open())
//	{
//		std::cout << "[ERROR] File not found.";
//		return;
//	}
//
//	fileIn >> a >> b >> c;
//	fileIn.close();
//}
//
//int getMaxNum(const int a, const int b, const int c)
//{
//	int maxNum = a;
//	if (b > maxNum)
//	{
//		maxNum = b;
//	}
//
//	if (c > maxNum)
//	{
//		maxNum = c;
//	}
//
//	return maxNum;
//}
//
//int main()
//{
//	int a = 0, b = 0, c = 0;
//	readNums(a, b, c);
//	std::cout << getMaxNum(a, b, c);
//
//	return 0;
//}