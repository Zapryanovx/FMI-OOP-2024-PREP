//#include <iostream>
//#include <fstream>
//
//unsigned getCharsCountInFile(const char* fileName, const char ch)
//{
//	std::ifstream fileIn(fileName);
//
//	if (!fileIn.is_open())
//	{
//		std::cout << "[ERROR] File not found.";
//		return 0;
//	}
//
//	int count = 0;
//	while (true)
//	{
//		if (fileIn.eof())
//		{
//			fileIn.close();
//			return count;
//		}
//
//		char currentCh = fileIn.get();
//		if (currentCh == ch)
//		{
//			count++;
//		}
//	}
//}
//
//int getLinesCountInFile(const char* fileName)
//{
//	return getCharsCountInFile(fileName, '\n') + 1;
//}
//
//int main()
//{
//	
//	std::cout << getLinesCountInFile("03_count_lines_of_file.txt");
//
//	return 0;
//}