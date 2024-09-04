#pragma once
#include <iostream>

size_t weightOf(const char* data)
{
	size_t weight = 0;
	while (*data)
	{
		weight += *(data++);
	}

	return weight;
}

bool isCharIn(char ch, const char* rhs)
{
	size_t size = std::strlen(rhs);
	for (int i = 0; i < size; i++)
	{
		if (ch == rhs[i])
		{
			return true;
		}
	}

	return false;
}

void shiftLeft(char* lhs, int i)
{
	size_t size = std::strlen(lhs);
	for (int j = i; j < size - 1; j++)
	{
		lhs[j] = lhs[j + 1];
	}

	lhs[size - 1] = '\0';
}

void diff(char* lhs, const char* rhs)
{
	size_t i = 0;
	while (lhs[i] != '\0') 
	{
		if (isCharIn(lhs[i], rhs))
		{
			shiftLeft(lhs, i);  
		}
		else
		{
			i++;  
		}
	}
}