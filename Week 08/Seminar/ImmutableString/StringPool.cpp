#include "StringPool.h"
#include <cstring>
#include <iostream>
#pragma warning (disable : 4996)

StringPool::StringPool()
{
	//8 capacity by default
	stringCapacity = 8;
	stringCount = 0;
	stringRecords = new StringRecord[stringCapacity];
}

StringPool::~StringPool()
{
	for (int i = 0; i < stringCapacity; i++)
	{
		delete[] stringRecords[i].str;
	}

	delete[] stringRecords;
}

const char* StringPool::getAllocatedString(const char* str)
{
	int index = findAllocatedString(str);

	if (index != -1)
	{
		stringRecords[index].refCount++;

		//for debug purposes
		std::cout << "String found in cache, ref count: " << stringRecords[index].refCount << std::endl;

		return stringRecords[index].str;
	}

	else
	{
		//for debug purposes
		std::cout << "String NOT found in cache. Allocating.." << std::endl;

		unsigned index = allocatedNewString(str);
		stringRecords[index].refCount++;
		return stringRecords[index].str;
	}
}

void StringPool::removeRecord(unsigned index)
{
	//спестяваме си shift-ването наляво
	std::swap(stringRecords[index], stringRecords[stringCount - 1]);

	delete[] stringRecords[stringCount - 1].str;

	//за да не сочи към вече освободена памет
	stringRecords[stringCount - 1].str = nullptr;
	stringRecords[stringCount - 1].refCount = 0;
	
	stringCount--;
}

void StringPool::releaseString(const char* str)
{
	int index = findAllocatedString(str);
	
	if (index == -1)
	{
		return; //throw (not found)
	}

	stringRecords[index].refCount--;

	if (stringRecords[index].refCount == 0)
	{
		//for debug purposes
		std::cout << "Removing record: " << stringRecords[index].str << " (No more refs)" << std::endl;
		
		removeRecord(index);
	}
}

void StringPool::resize(unsigned newCap)
{
	StringRecord* newStringRecords = new StringRecord[newCap];

	for (int i = 0; i < stringCount; i++)
	{
		//правим shallow copy (тоест имаме два пойнтъра към едно и също място в паметта)
		newStringRecords[i] = stringRecords[i];
	}

	stringCapacity = newCap;

	//тук изтриваме масивът от стрингове, но не и самите стрингове,
	//като по този начин се справяме със shallow copy-то и вече имаме
	//само един пойнър към тези стрингове
	delete[] stringRecords;
	stringRecords = newStringRecords;
}

unsigned StringPool::allocatedNewString(const char* str)
{
	if (stringCount == stringCapacity)
	{
		resize(stringCapacity * 2);
	}
	
	unsigned firstFreeIndex = stringCount++;
	stringRecords[firstFreeIndex].str = new char[strlen(str) + 1]; // + '\0'
	strcpy(stringRecords[firstFreeIndex].str, str);
	stringRecords[firstFreeIndex].refCount = 0;

	return firstFreeIndex;
}

int StringPool::findAllocatedString(const char* str) const
{
	for (int i = 0; i < stringCount; i++)
	{
		//ако намерим стринг със същото съдържание, връщаме позицията, 
		//на която се намира
		if (strcmp(stringRecords[i].str, str) == 0)
		{
			return i;
		}
	}

	return -1;
}