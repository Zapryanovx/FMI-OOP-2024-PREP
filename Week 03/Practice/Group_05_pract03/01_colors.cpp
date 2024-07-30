//#include <iostream>
//#include <fstream>
//#include <cstring>
//
//struct Color
//{
//	char name[8];
//	int code;
//};
//
//void readColors(Color* colors, size_t n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		std::cin >> colors[i].name >> colors[i].code;
//	}
//}
//
//void saveColors(Color* colors, size_t n, std::ofstream& fileOut)
//{
//	for (int i = 0; i < n; i++)
//	{
//		fileOut << colors[i].name << " " << colors[i].code << std::endl;
//	}
//}
//
//void saveColorsBinary(const Color* colors, size_t n, std::ofstream& fileOut)
//{
//	fileOut.write((const char*) colors, n * sizeof(Color));0
//}
//
//int main()
//{
//	int n = 0;
//	std::cin >> n;
//
//	char filePath[10] = "";
//	std::cin.ignore();
//	std::cin.getline(filePath, 10);
//
//	Color* colors = new Color[n];
//	std::ofstream fileOut(filePath, std::ios::app | std::ios::binary);
//
//	readColors(colors, n);
//	//saveColors(colors, n, fileOut);
//	saveColorsBinary(colors, n, fileOut);
//
//
//	fileOut.close();
//	delete[] colors;
//
//	return 0;
//}