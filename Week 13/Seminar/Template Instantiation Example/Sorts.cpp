#include "Sorts.h"
#include <algorithm>

template<class T>
void SelectionSort(T* pArr, size_t Size)
{
	if (!pArr || Size == 0)
	{
		return;
	}

	for (int i = 0; i < Size - 1; i++)
	{
		int min = i;

		for (int j = i + 1; j < Size; j++)
		{
			if (pArr[j] < pArr[i])
			{
				min = j;
			}
		}

		if (i != min)
		{
			std::swap(pArr[i], pArr[min]);
		}
	}
}

template<class T>
void BubbleSort(T* pArr, size_t Size)
{
	if (!pArr || Size == 0)
	{
		return;
	}

	for (int i = 0; i < Size - 1; i++)
	{
		for (int j = Size - 1; j > i; i--)
		{
			if (pArr[j] < pArr[j - 1])
			{
				std::swap(pArr[j], pArr[j - 1]);
			}
		}
	}
}

//казваме с какви типове да се генерират функциите
template void SelectionSort<double>(double* pArr, size_t Size);

template void BubbleSort<double>(double* pArr, size_t Size);
template void BubbleSort<A>(A* pArr, size_t Size);



