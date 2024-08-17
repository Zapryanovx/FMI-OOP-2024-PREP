#include "SortedCollection.h"

int SortedCollection::lowerBound(int arg) const
{
	int left = 0;
	int right = size - 1;

	int indexToReturn = size;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (data[mid] < arg)
		{
			left = mid + 1;
		}

		else
		{
			right = mid - 1;
			indexToReturn = mid;
		}
	}

	return indexToReturn;
}

int SortedCollection::upperBound(int arg) const
{
	int left = 0;
	int right = size - 1;
	
	int indexToReturn = size;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (data[mid] <= arg)
		{
			left = mid + 1;
		}

		else
		{
			right = mid - 1;
			indexToReturn = mid;
		}
	}

	return indexToReturn;
}

void SortedCollection::add(int elem)
{
	if (size == capacity)
	{
		resize(capacity * 2);
	}

	int idx = size;
	while (idx != 0 && data[idx - 1] > elem)
	{
		data[idx] = data[idx - 1];
		--idx;
	}

	data[idx] = elem;
	++size;
}

void SortedCollection::remove(int arg)
{
	int elementIndex = lowerBound(arg);

	if (elementIndex == size || data[elementIndex] != arg)
	{
		return;
	}

	for (int i = elementIndex; i < size - 1; i++)
	{
		data[i] = data[i + 1];
	}

	size--;
}

size_t SortedCollection::count(int arg) const
{
	int leftIndex = lowerBound(arg);

	if (leftIndex == size || data[leftIndex] != arg)
	{
		return 0;
	}

	int rightIndex = upperBound(arg);

	return rightIndex - leftIndex;
}

bool SortedCollection::contains(int arg) const
{
	int leftIndex = lowerBound(arg);

	return leftIndex != size && data[leftIndex] == arg;
}