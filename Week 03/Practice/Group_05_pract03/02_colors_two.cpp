#include <iostream>
#include <fstream>
#include <cstring>


//Да се реализират функциите :
//
//size_t colorshoInFile(const char* filePath);
//която казва колко структури от тип Color имаме записани във файл с име filePath.
//
//Color findColorByName(const char* name, const char* filePath);
//която проверява дали във файл filePath има структура с name стойност равна на name.
//Ако има такава, я връща.Ако няма такава, връща нова структура Color със стойности "ERROR", -1.
//Ако има няколко структури, отговарящи на това условие, да се върне първата.

namespace MAX_SIZE_CONSTS
{
	constexpr int MAX_SIZE_LINE = 100;
}

struct Color
{
	char name[8];
	int code;
};

size_t colorshoInFile(const char* filePath)
{
	std::ifstream fileIn(filePath, std::ios::binary);

	fileIn.seekg(0, std::ios::end);
	int len = fileIn.tellg();
	
	fileIn.seekg(0, std::ios::beg);

	return len / sizeof(Color);
}

int main()
{

	std::cout << colorshoInFile("test.txt");

	return 0;
}