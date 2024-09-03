#include "Deserializator.h"
#pragma warning(disable: 4996)

Deserializator::Deserializator(const char* str)
{
	std::strcpy(fileName, str);
}

