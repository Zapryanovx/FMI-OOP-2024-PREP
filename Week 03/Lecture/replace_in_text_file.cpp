#include <iostream>
#include <fstream>

void replaceInFile(char from, char to, std::fstream& file)
{
	while (!file.eof())
	{
		char curr = file.get();
		if (curr != from)
		{
			continue;
		}
		
		//тъй като get() мести пойнтъра с една позиция напред,
		//то трябва да се върнем с една позиция, където е открито съвпадение
		//и да пренапишем новия символ върху стария
		file.seekg(-1, std::ios::cur);
		file.put(to);
		file.flush();		
	}
}

int main()
{
	std::fstream file("treasureTrail.txt", std::ios::in | std::ios::out);


	if (!file.is_open())
	{
		std::cout << "Error while opening the file!" << std::endl;
		return -1;
	}

	replaceInFile('a', 'X', file);

	return 0;
}