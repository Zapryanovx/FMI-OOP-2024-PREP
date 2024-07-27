#include <iostream>
#include <fstream>

namespace MAX_SIZE_CONSTANTS
{
	const int MAX_SIZE_LINE = 128;
}

bool stringComp(char const* strFirst, char const* strSecond)
{
	int size = 0;
	while (strFirst[size])
	{
		if (strFirst[size] != strSecond[size])
		{
			return false;
		}

		size++;
	}

	if (strSecond[size] != '\0')
	{
		return false;
	}
	return true;
}

int getLinesOfFile(std::ifstream& fileIn)
{
	int countNewLines = 0;
	while (!fileIn.eof())
	{
		char demin = fileIn.get();
		if (demin == '\n')
		{
			countNewLines++;
		}
	}

	return countNewLines + 1;
}

void checkDiffs(std::ifstream& fileFirst, std::ifstream& fileSecond, std::ofstream& fileDiffs)
{	
	char fileFirstLine[MAX_SIZE_CONSTANTS::MAX_SIZE_LINE] = "";
	char fileSecondLine[MAX_SIZE_CONSTANTS::MAX_SIZE_LINE] = "";

	while (!fileFirst.eof() && !fileSecond.eof())
	{
		fileFirst.getline(fileFirstLine, MAX_SIZE_CONSTANTS::MAX_SIZE_LINE);
		fileSecond.getline(fileSecondLine, MAX_SIZE_CONSTANTS::MAX_SIZE_LINE);

		std::cout << "[First]" << fileFirstLine << std::endl;
		std::cout << "[Second]" << fileSecondLine << std::endl;

		if (stringComp(fileFirstLine, fileSecondLine))
		{
			fileDiffs << fileFirstLine << std::endl;
		}

		else
		{
			fileDiffs << " - " << fileFirstLine << std::endl;
			fileDiffs << " + " << fileSecondLine << std::endl;
		}
	}

	while (!fileFirst.eof())
	{
		fileFirst.getline(fileFirstLine, MAX_SIZE_CONSTANTS::MAX_SIZE_LINE);
		fileDiffs << " - " << fileFirstLine << std::endl;

	}

	while (!fileSecond.eof())
	{
		fileSecond.getline(fileSecondLine, MAX_SIZE_CONSTANTS::MAX_SIZE_LINE);
		fileDiffs << " + " << fileSecondLine << std::endl;
	}
}


int main()

{
	std::ifstream fileFirst("05_file_first.txt");
	std::ifstream fileSecond("05_file_second.txt");

	std::ofstream fileDiffs("05_file_diff.txt");

	checkDiffs(fileFirst, fileSecond, fileDiffs);

	fileFirst.close();
	fileSecond.close();
	fileDiffs.close();

	return 0;
}