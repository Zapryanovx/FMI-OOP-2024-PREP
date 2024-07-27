//#ОБЯСНЕНИЕ НА ЗАДАЧАТА:

// Да се реализира функция, която връща броят на редовете на даден файл 

#include <iostream>
#include <fstream>

const char NEW_LINE_CHAR = '\n';

int getCharCount(std::ifstream& ifs, char ch)
{

	int count = 0;
	while (!ifs.eof())
	{
		//взимаме символ по символ съдържанието на файла
		char curr = ifs.get();

		//ако открием символа, подаден на функцията, 
		//увеличаваме броя на срещанията
		if (curr == ch)
		{
			count++;
		}
	}

	return count;
}

//специализирана функция за броене на редове
int getLinesCount(const char* fileName)
{
	//в случай, че fileName е nullptr
	if (!fileName)
	{
		return -1;
	}

	std::ifstream ifs(fileName);

	//в случай, че файлът не е отворен
	if (!ifs.is_open())
	{
		return -1;
	}

	return getCharCount(ifs, NEW_LINE_CHAR) + 1;
}


int main()
{
	std::ofstream ofs("file.txt");
	ofs << "asdasdasdd" << std::endl;
	ofs << std::endl;
	ofs << std::endl;
	ofs << std::endl;
	ofs.close();

	std::ifstream ifs("file.txt");
	std::cout << getCharCount(ifs, 'd') << std::endl;
	ifs.close();

	std::cout << getLinesCount("file.txt") << std::endl;

	return 0;
}