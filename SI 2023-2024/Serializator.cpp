#include "Serializator.h"
#pragma warning(disable: 4996)

Serializator::Serializator(const char* str, const HexArray& arr) : arr(arr)
{
	std::strcpy(fileName, str);
}

