//#include <iostream>
//#include <fstream>
//
//enum MAX_SIZE_CONSTANTS
//{
//	MAX_SIZE_STR = 32,
//	MAX_SIZE_STRING_MANIPS = 10,
//	MAX_SIZE_LINE = 256,
//};
//
//struct StringManip
//{
//	char key[MAX_SIZE_STR] = "";
//	char value[MAX_SIZE_STR] = "";
//};
//
//struct AllStringManips
//{
//	StringManip manips[MAX_SIZE_STRING_MANIPS];
//	int currManipsCount = 0;
//};
//
//bool stringComp(char const* strFirst, char const* strSecond)
//{
//	int size = 0;
//	while (strFirst[size])
//	{
//		if (strFirst[size] != strSecond[size])
//		{
//			return false;
//		}
//
//		size++;
//	}
//
//	if (strSecond[size] != '\0')
//	{
//		return false;
//	}
//	return true;
//}
//
//void saveChanges(std::ifstream& fileText, std::ofstream& fileRes, AllStringManips& allManips)
//{
//	while (!fileText.eof())
//	{
//		char buff[MAX_SIZE_LINE];
//		fileText >> buff;
//		fileText.get();
//
//		bool isManipFound = false;
//		int idxOfManipFound = 0;
//		for (int i = 0; i < allManips.currManipsCount; i++)
//		{
//			if (stringComp(buff, allManips.manips[i].key))
//			{
//				isManipFound = true;
//				idxOfManipFound = i;
//				break;
//			}
//		}
//
//		if (isManipFound)
//		{
//			fileRes << allManips.manips[idxOfManipFound].value << " ";
//		}
//
//		else
//		{
//			fileRes << buff << " ";
//		}
//
//	}
//}
//
//void readAllManipsFromFile(std::ifstream& fileIn, AllStringManips& allManips)
//{
//	while (!fileIn.eof())
//	{
//		fileIn >> allManips.manips[allManips.currManipsCount].key;
//		fileIn.get();
//		fileIn >> allManips.manips[allManips.currManipsCount].value;
//
//		allManips.currManipsCount++;
//	}
//}
//
//int main()
//{
//	std::ifstream fileManips("02_all_manips.txt");
//	std::ifstream fileText("02_text.txt");
//	std::ofstream fileRes("02_result.txt");
//
//	AllStringManips allManips;
//
//	readAllManipsFromFile(fileManips, allManips);
//	saveChanges(fileText, fileRes, allManips);
//	
//	fileText.close();
//	fileRes.close();
//
//
//	return 0;
//}
