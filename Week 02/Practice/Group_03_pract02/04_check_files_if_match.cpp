//#include <iostream>
//#include <fstream>
//
//enum MAX_SIZE_CONSTANTS
//{
//	MAX_SIZE_LINE = 1024,
//};
//
//bool compareStr(const char* firstLine, const char* secondLine)
//{
//	int size = 0;
//	while (firstLine[size])
//	{
//		if (firstLine[size] != secondLine[size])
//		{
//			return false;
//		}
//		
//		size++;
//	}
//
//	if (secondLine[size] != '\0')
//	{
//		return false;
//	}
//	return true;
//}
//
//void checkMatch(std::ifstream& firstFile, std::ifstream& secondFile)
//{
//	char firstLine[MAX_SIZE_CONSTANTS::MAX_SIZE_LINE] = "";
//	char secondLine[MAX_SIZE_CONSTANTS::MAX_SIZE_LINE] = "";
//
//	while (!firstFile.eof())
//	{
//		firstFile.getline(firstLine, MAX_SIZE_CONSTANTS::MAX_SIZE_LINE);
//		secondFile.getline(secondLine, MAX_SIZE_CONSTANTS::MAX_SIZE_LINE);
//		
//		if (!compareStr(firstLine, secondLine))
//		{
//			std::cout << "[DIFF] " << firstLine;
//			return;
//		}
//	}
//
//	if (!secondFile.eof())
//	{
//		secondFile.getline(secondLine, MAX_SIZE_CONSTANTS::MAX_SIZE_LINE);
//		std::cout << "[DIFF] " << secondLine;
//		return;
//	}
//
//	std::cout << "[MATCH] The two files are identical." << std::endl;
//}
//
//int main()
//{
//	std::ifstream firstFile("04_first.txt");
//	std::ifstream secondFile("04_second.txt");
//
//	if (!firstFile.is_open() || !secondFile.is_open())
//	{
//		return -1;
//	}
//
//
//	checkMatch(firstFile, secondFile);
//
//	return 0;
//}