//#ОБЯСНЕНИЕ НА ЗАДАЧАТА:
// 
// Представете в шестнадесетичен вид съдържание на файл, което се състои само от букви и цифри

#include <iostream>
#include <fstream>
#include <iomanip>

struct HexViewerFile
{
	unsigned char* data;
	size_t dataSize;
};

//вече сме писали тази функция
size_t getFileSize(std::ifstream& file)
{
	size_t currPos = file.tellg();

	file.seekg(0, std::ios::end);
	size_t size = file.tellg();

	file.seekg(currPos);

	return size;
}

HexViewerFile init(const char* str)
{
	std::ifstream ifs(str, std::ios::in | std::ios::binary);
	HexViewerFile myFile;

	//в случай че файлът не е намерен, създаваме обект с празна [data] и [dataSize] равен на 0
	if (!ifs.is_open())
	{
		myFile.data = nullptr;
		myFile.dataSize = 0;
		return myFile;
	}

	myFile.dataSize = getFileSize(ifs);
	myFile.data = new unsigned char [myFile.dataSize];
	ifs.read((char*)myFile.data, myFile.dataSize);

	//не забравяме да затворим потока в scope-a, в който е отворен
	ifs.close();
	return myFile;
}

void freeHexViewerFile(HexViewerFile& file)
{
	delete[] file.data;
	file.dataSize = 0;
}

bool isValidSymbol(unsigned char ch)
{
	return ch >= 'a' && ch <= 'z'
		|| ch >= 'A' && ch <= 'Z'
		|| ch >= '0' && ch <= '9';
}

void print(const HexViewerFile& myFile)
{

	//отпечатване на масива в hex
	for (int i = 0; i < myFile.dataSize; i++)
	{
		//std::setw(2) - изходът се състои от поне 2 символа
		//std::setfill('0') - ако се състои от по-малко, добавя водещи 0
		std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)myFile.data[i] << " ";
	}
	std::cout << std::endl;

	//отпечатване на масива в стандартния му вид
	for (int i = 0; i < myFile.dataSize; i++)
	{
		if (isValidSymbol(myFile.data[i]))
		{
			std::cout << myFile.data[i] << " ";
		}

		else
		{
			//invalid symbol
			std::cout << ".. ";
		}
	}
	std::cout << std::endl;

}

int main()
{
	std::ofstream ofs("student.dat");
	ofs << "123testtAAest12ZZZ3";
	ofs.close();

	HexViewerFile myFile = init("student.dat");
	print(myFile);
	freeHexViewerFile(myFile);

	return 0;
}
