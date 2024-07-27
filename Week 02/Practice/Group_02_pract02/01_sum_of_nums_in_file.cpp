//#include <iostream>
//#include <fstream>
//
//void readNums(int& a, int& b)
//{
//	std::ifstream fileIn("01_sum_of_nums_in_file.txt");
//	if (!fileIn.is_open())
//	{
//		std::cout << "[ERROR] File not found.";
//		return;
//	}
//	
//	fileIn >> a >> b;
//	fileIn.close();
//}
//
//int sumNums(const int a, const int b)
//{
//	return a + b;
//}
//
//int main()
//{
//	int a = 0, b = 0;
//	readNums(a, b);
//	std::cout<<sumNums(a, b);
//
//	return 0;
//}