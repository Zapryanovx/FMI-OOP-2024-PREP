//#include <iostream>
//#include <fstream>
//
//enum  MAX_SIZE_CONSTANTS
//{
//	MAX_SIZE_LIST = 64,
//};
//
//int getSizeOfList(std::ifstream& fileIn)
//{
//	int size = 0;
//	fileIn >> size;
//	return size;
//}
//
//void checkIfNewMaxIsFound(int& maxCount, const int currCount)
//{
//	if (maxCount < currCount)
//	{
//		maxCount = currCount;
//	}
//}
//
//void readAllNums(std::ifstream& fileIn, int* allNums, size_t size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		fileIn >> allNums[i];
//	} 
//
//}
//
//int getMostCommonNum(std::ifstream& fileIn, size_t size)
//{
//	int allNums[MAX_SIZE_CONSTANTS::MAX_SIZE_LIST] = {};
//	readAllNums(fileIn, allNums, size);
//
//	int maxCount = 0;
//	for (int i = 0; i < size; i++)
//	{
//		int currCount = 0;
//		for (int j = 0; j < size; j++)
//		{
//			if (allNums[i] == allNums[j])
//			{
//				currCount++;
//			}
//		}
//
//		checkIfNewMaxIsFound(maxCount, currCount);
//	}
//
//	return maxCount;
//}
//
//int main()
//{
//	std::ifstream fileIn("02_list.txt");
//	if (!fileIn.is_open())
//	{
//		return -1;
//	}
//
//	size_t size = getSizeOfList(fileIn);
//
//	std::cout << getMostCommonNum(fileIn, size) << std::endl;
//
//	return 0;
//}