//#include <iostream>
//#include <fstream>
//
//int getResOfNums(int a, int b, int (*pred) (int, int))
//{
//	return pred(a, b);
//}
//
//void saveDataInFile(std::ofstream& fileOut, int sum, int diff)
//{
//	fileOut << sum << " " << diff;
//}
//
//void readDataFromFile(std::ifstream& fileIn, int& sum, int& diff)
//{
//	fileIn >> sum >> diff;
//}
//
//void printOriginalNums(int a, int b)
//{
//	std::cout << a << " " << b << std::endl;
//}
//
//void calcOriginalNums(int sum, int diff)
//{
//	int a = (sum + diff) / 2;
//	int b = sum - a;
//
//	printOriginalNums(a, b);
//}
//
//int main()
//{
//	int a = 0, b = 0;
//	std::cin >> a >> b;
//
//	int sum = getResOfNums(a, b, [](int a, int b) -> int {return a + b; });
//	int diff = getResOfNums(a, b, [](int a, int b) -> int {return a - b; });
//
//	std::ofstream fileOut("01_results1.txt");
//
//	if (!fileOut.is_open())
//	{
//		return -1;
//	}
//	saveDataInFile(fileOut, sum, diff);
//	fileOut.close();
//
//	std::ifstream fileIn("01_results1.txt");
//	if (!fileIn.is_open())
//	{
//		return -1;
//	}
//	readDataFromFile(fileIn, sum, diff);
//	fileIn.close();
//
//	calcOriginalNums(sum, diff);
//
//	return 0;
//}