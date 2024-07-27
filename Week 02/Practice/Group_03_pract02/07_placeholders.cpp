//#include <iostream>
//#include <fstream>
//
//enum MAX_SIZE_CONSTANTS
//{
//	MAX_SIZE_TITLE = 20,
//	MAX_SIZE_NAME = 40,
//	MAX_SIZE_MESSAGE = 300,
//	MAX_SIZE_SENDER_NAME = 40,
//};
//
//struct Placeholder
//{
//	char title[MAX_SIZE_TITLE];
//	char name[MAX_SIZE_NAME];
//	char message[MAX_SIZE_MESSAGE];
//	char senderName[MAX_SIZE_SENDER_NAME];
//
//};
//
//void readPlaceHolder(std::ifstream& fileIn, Placeholder& placeholder)
//{
//	char bufferTitle[MAX_SIZE_TITLE];
//	fileIn >> bufferTitle;
//	fileIn.get();
//	fileIn.getline(placeholder.title, MAX_SIZE_TITLE);
//
//	char bufferName[MAX_SIZE_NAME];
//	fileIn >> bufferName;
//	fileIn.get();
//	fileIn.getline(placeholder.name, MAX_SIZE_NAME);
//
//	char bufferMessage[MAX_SIZE_MESSAGE];
//	fileIn >> bufferMessage;
//	fileIn.get();
//	fileIn.getline(placeholder.message, MAX_SIZE_MESSAGE);
//
//	char bufferSenderName[MAX_SIZE_SENDER_NAME];
//	fileIn >> bufferSenderName;
//	fileIn.get();
//	fileIn.getline(placeholder.senderName, MAX_SIZE_SENDER_NAME);
//
//}
//
//void saveFilledPlaceHolderInFile(std::ifstream& fileIn, std::ofstream& fileOut, Placeholder placeholder)
//{
//	int bracketCount = 0;
//
//	while (!fileIn.eof())
//	{
//		char ch = fileIn.get();
//		//std::cout << ch << " ";
//		if (ch == '{')
//		{
//			bracketCount++;
//			switch (bracketCount)
//			{
//				case 1:
//					fileOut << placeholder.title;
//					break;
//				case 2:
//					fileOut << placeholder.name;
//					break;
//				case 3:
//					fileOut << placeholder.message;
//					break;
//				case 4:
//					fileOut << placeholder.senderName;
//					break;
//				default:
//					break;
//			}
//			
//			
//			while (fileIn.get() != '}') //skip
//			{
//				continue;
//			}
//		}
//		
//		else
//		{
//			fileOut << ch;
//		}
//
//	}
//
//}
//
//int main()
//{
//	Placeholder placeholder;
//	std::ifstream fileData("07_placeholder_data.txt");
//	readPlaceHolder(fileData, placeholder);
//	
//	std::ifstream fileIn("07_placeholder.txt");
//	std::ofstream fileOut("07_placeholder_filled.txt");
//	saveFilledPlaceHolderInFile(fileIn, fileOut, placeholder);
//
//	fileIn.close();
//	fileOut.close();
//
//	return 0;
//}