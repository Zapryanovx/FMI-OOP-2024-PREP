#include "NormalCollection.h"
#include <iostream>

void NormalCollection::add(int arg)
{
	if (size == capacity)
	{
		resize(capacity * 2);
	}

	data[size++] = arg;
}

void NormalCollection::remove(int arg)
{
	if (size == 0)
	{
		return;
	}

	int idx = -1;
	for (int i = 0; i < size; i++)
	{
		if (data[i] == arg)
		{
			idx = i;
			break;
		}
	}

	if (idx != -1)
	{
		std::swap(data[idx], data[size - 1]);
		size--;
	}

}

size_t NormalCollection::count(int arg) const
{
	unsigned count = 0;
	for (int i = 0; i < size; i++)
	{
		if (data[i] == arg)
		{
			count++;
		}
	}

	return count;
}

bool NormalCollection::contains(int arg) const
{
	for (int i = 0; i < size; i++)
	{
		if (data[i] == arg)
		{
			return true;
		}
	}

	return false;
}