#include "BitSet.h"
#include <iostream>
#include <cstring>
#pragma warning(disable: 4996)

void BitSet::free()
{
	delete[] data;
}

void BitSet::copyFrom(const BitSet& other)
{
	data = new char[other.bucketsCount];

	bucketsCount = other.bucketsCount;
	limit = other.limit;

	for(size_t i = 0; i < bucketsCount; i++)
	{
		data[i] = other.data[i];
	}

}

BitSet::BitSet() : BitSet(8){}

size_t BitSet::bucketsNeeded(size_t n) const
{
	size_t toReturn = n / 8;

	//знаем, че при делението резултатът се закръгля до по-малкото,
	//затова трябва да имаме предвид, че ако n не се дели на 8,
	//то ни е нужен с един повече bucket
	
	//Напр.:
	//n = 33 => toReturn = 33 / 8 = 4,
	//но не ни стигат 4 bucket-a, тъй като е възможно да имаме и числото 32 (n - 1)
	//в нашето множество => ни трябва още един bucket

	//n = 32 => toReturn = 32 / 8 = 4,
	//bucket-ите ни стигат, тъй като обхващат всички възможни числа, които може
	//да имаме в множеството си [0; 31], или [0; n-1]
	if (n % 8 != 0)
	{
		toReturn++;
	}

	return toReturn;
}

size_t BitSet::getBucket(size_t n) const
{
	return n / 8;
}

size_t BitSet::getPosition(size_t n) const
{
	return n % 8;
}

BitSet::BitSet(size_t n)
{
	bucketsCount = bucketsNeeded(n);
	data = new char[bucketsCount] {};
	limit = n;
}

void BitSet::addNumber(size_t number)
{
	//out of range check
	if (number >= limit)
	{
		return;
	}

	size_t bucket = getBucket(number);
	size_t pos = getPosition(number);

	//подсигуряваме бита, отговарящ за нашето число да е единица,
	//тоест че числото ни е в нашето множество
	data[bucket] |= (1ull << pos);
}

void BitSet::removeNumber(size_t number) const
{
	//out of range check
	if (number >= limit)
	{
		return;
	}

	size_t bucket = getBucket(number);
	size_t pos = getPosition(number);

	//подсигуряваме бита, отговарящ за нашето число да е нуля,
	//тоест че числото НЕ е в нашето множество
	//data[bucket] &= (0ull << pos);
	data[bucket] &= ~(1ull << pos);
}

bool BitSet::hasNumber(size_t number) const
{
	//out of range check
	if (number >= limit)
	{
		return false;
	}

	size_t bucket = getBucket(number);
	size_t pos = getPosition(number);

	return ((data[bucket] & (1ull << pos)) != 0);
}

void BitSet::print()
{
	for (int i = 0; i < limit; i++)
	{
		//ако множеството съдържа това число, го отпечатай
		if (hasNumber(i))
		{
			std::cout << i << " ";
		}
	}
	std::cout << std::endl;
}

BitSet::BitSet(const BitSet& other)
{
	copyFrom(other);
}

BitSet& BitSet::operator=(const BitSet& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

BitSet Union(const BitSet& lhs, const BitSet& rhs)
{
	
	const BitSet& bigger = std::max(lhs.limit, rhs.limit);
	size_t unionBucketsMax = std::max(lhs.bucketsCount, rhs.bucketsCount);
	size_t unionBucketsMin = std::min(lhs.bucketsCount, rhs.bucketsCount);

	BitSet toReturn(bigger.limit);

	//тук възниква проблем, когато имаме число в едното множество, 
	//надхвърлящо лимита на другото множество
	//тогава в един момент няма как да достъпим i-тия bucket от по-малкото множество,
	//тъй като той де факто не съществува,
	//но би трябвало да можем в по-голямото, затова ни трябват 2 for цикъла 
	for (int i = 0; i < unionBucketsMin; i++)
	{
		toReturn.data[i] = (lhs.data[i] | rhs.data[i]);
	}

	for (int i = unionBucketsMin; i < unionBucketsMax; i++)
	{
		toReturn.data[i] = bigger.data[i];
	}

	toReturn.limit = bigger.limit;
	toReturn.bucketsCount = bigger.bucketsCount;
	
	return toReturn;
}

BitSet Intersect(const BitSet& lhs, const BitSet& rhs)
{
	size_t intersectLimit = std::min(lhs.limit, rhs.limit);
	size_t intersectBuckets = std::min(lhs.bucketsCount, rhs.bucketsCount);

	BitSet toReturn(intersectLimit);
	for (int i = 0; i < intersectBuckets; i++)
	{
		//вместо да търсим число по число, можем да вземем bucket по bucket
		//и чрез побитовата операция & ще получим общите числа в дадения bucket
		toReturn.data[i] = (lhs.data[i] & rhs.data[i]);
	}

	toReturn.limit = intersectLimit;
	toReturn.bucketsCount = intersectBuckets;

	return toReturn;
}

BitSet::~BitSet()
{
	free();
}
