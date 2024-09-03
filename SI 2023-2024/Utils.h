#pragma once
#include <fstream>

static bool isValidSymbol(unsigned char ch)
{
	return ch >= 32;
}

static unsigned char* createAndFillByteArray(size_t destSize, const unsigned char* source, size_t sourceSize)
{
	unsigned char* dest = new unsigned char[destSize];
	for (int i = 0; i < destSize && i < sourceSize; i++)
	{
		dest[i] = source[i];
	}

	return dest;
}

static const char* getFileExtension(const char* str)
{
	while (*str && *str != '.')
	{
		str++;
	}

	return str;
}

static int getCharCount(std::ifstream& ifs, char ch)
{
	if (ifs.is_open())
	{
		return -1;
	}

	int count = 0;
	while (true)
	{
		char curr = ifs.get();

		if (ifs.eof())
		{
			return count;
		}

		if (curr = ch)
		{
			count++;
		}
	}
	
	return 0;
}

static size_t getFileSize(std::ifstream& file)
{
	size_t currPos = file.tellg();
	file.seekg(0, std::ios::end);
	size_t fileSize = file.tellg();

	file.seekg(currPos);
	return fileSize;
}

