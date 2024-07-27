//#include <iostream>
//#include <fstream>
//
//void saveDataInFile(std::ofstream& fileOut, int a, int b, int c, int (*pred) (int, int, int))
//{
//	fileOut << pred(a, b, c) << " ";
//}
//
//int getDiffOfSumAndMul(std::ifstream& fileIn)
//{
//	int sum = 0, mul = 0;
//	fileIn >> sum >> mul;
//	return sum - mul;
//}
//
//int main()
//{
//	int a = 0, b = 0, c = 0;
//	std::cin >> a >> b >> c;
//
//	std::ofstream fileOut("01_results.txt");
//	saveDataInFile(fileOut, a, b, c, [](int a, int b, int c) -> int{ return a + b + c; });
//	saveDataInFile(fileOut, a, b, c, [](int a, int b, int c) -> int{ return a * b * c; });
//	fileOut.close();
//
//	std::ifstream fileIn("01_results.txt");
//	std::cout << getDiffOfSumAndMul(fileIn);
//	fileIn.close();
//
//	return 0;
//}