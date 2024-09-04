#pragma once
#include <iostream>
#pragma warning(disable: 4996)

void multi(char*& data, size_t k)
{
	size_t newSize = std::strlen(data) * k + 1;
	char* newData = new char[newSize];
	newData[0] = '\0';

	for (int i = 0; i < k; i++)
	{
		std::strcat(newData, data);
	}

	delete[] data;
	data = newData;

}

bool contains(const char* data, char ch)
{
	size_t size = std::strlen(data);
	for (int i = 0; i < size; i++)
	{
		if (data[i] == ch)
		{
			return true;
		}
	}

	return false;
}

void saveUnique(char*& dist, size_t& startIndex, const char* source)
{
	size_t size = std::strlen(source);
	for (int i = 0; i < size; i++)
	{
		if (!contains(dist, source[i]))
		{
			dist[startIndex++] = source[i];
		}
	}
	dist[startIndex] = '\0';
}

const char* unionOf(const char* lhs, const char* rhs)
{
	size_t idxRes = 0;
	size_t sizeRes = std::strlen(lhs) + std::strlen(rhs) + 1;
	char* res = new char[sizeRes];
	res[0] = '\0';

	saveUnique(res, idxRes, lhs);
	saveUnique(res, idxRes, rhs);

	return res;
}

size_t weightOf(const char* data)
{
	size_t weight = 0;
	while (*data)
	{
		weight += *(data++);
	}

	return weight;
}


