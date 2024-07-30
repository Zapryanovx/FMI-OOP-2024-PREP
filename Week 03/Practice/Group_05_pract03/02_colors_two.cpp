#include <iostream>
#include <fstream>
#include <cstring>


//�� �� ���������� ��������� :
//
//size_t colorshoInFile(const char* filePath);
//����� ����� ����� ��������� �� ��� Color ����� �������� ��� ���� � ��� filePath.
//
//Color findColorByName(const char* name, const char* filePath);
//����� ��������� ���� ��� ���� filePath ��� ��������� � name �������� ����� �� name.
//��� ��� ������, � �����.��� ���� ������, ����� ���� ��������� Color ��� ��������� "ERROR", -1.
//��� ��� ������� ���������, ���������� �� ���� �������, �� �� ����� �������.

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