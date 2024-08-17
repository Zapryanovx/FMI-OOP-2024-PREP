#include "DynamicCollection.h"
#include <iostream>

void DynamicCollection::copyFrom(const DynamicCollection& other)
{
	size = other.size;
	capacity = other.capacity;

	data = new int[other.capacity];
	for (int i = 0; i < other.size; i++)
	{
		data[i] = other.data[i];
	}
}

void DynamicCollection::moveFrom(DynamicCollection&& other)
{
	data = other.data;
	data = nullptr;

	size = other.size;
	capacity = other.capacity;

	other.size = other.capacity = 0;
}

void DynamicCollection::free()
{
	delete[] data;
}

void DynamicCollection::resize(size_t newCap)
{
	int* newData = new int[newCap];
	for (int i = 0; i < size; i++)
	{
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;
	capacity = newCap;
}

DynamicCollection::DynamicCollection(size_t cap)
{
	size = 0;
	capacity = cap;

	data = new int[capacity] {};
}

DynamicCollection::DynamicCollection() : DynamicCollection(8){}

DynamicCollection::DynamicCollection(const DynamicCollection& other)
{
	copyFrom(other);
}

DynamicCollection::DynamicCollection(DynamicCollection&& other) noexcept
{
	moveFrom(std::move(other));
}

DynamicCollection& DynamicCollection::operator=(const DynamicCollection& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

DynamicCollection& DynamicCollection::operator=(DynamicCollection&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

DynamicCollection::~DynamicCollection()
{
	free();
}

