//#ОБЯСНЕНИЕ НА ЗАДАЧАТА:

// Да се реализира функция, която връща големината на даден файл 

#include <iostream>
#include <fstream>

size_t getFileSize(const char* fileName)
{
	//Идея: когато отидем накрая на файла, ще се намираме на индекса,
	//който отговаря и на големината на файла

	std::ifstream ifs(fileName, std::ios::binary); 
	if (ifs.is_open())
	{
		//ще запазим индекса, на който се намираме, за да
		//се върнем на него, когато намерим големината
		size_t currIdx = ifs.tellg(); 
		
		//отиваме в края и запазваме индекса (големината)
		ifs.seekg(0, std::ios::end);
		size_t size = ifs.tellg();

		//връщаме се докъдето сме стигнали
		ifs.seekg(currIdx);
		return size;
	}

	//ако файлът не е отворен
	return -1;
}

int main()
{
	std::ofstream ofs("test.txt");
	ofs << "asd1237";
	ofs.close();

	std::cout << getFileSize("test.txt");

	return 0;
}