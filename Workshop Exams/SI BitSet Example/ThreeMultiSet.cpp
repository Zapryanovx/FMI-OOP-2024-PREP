#include "ThreeMultiSet.h"

constexpr short DEFAULT_U = 16;

const short ThreeMultiSet::BITS_PER_NUM = 2;
const short ThreeMultiSet::MAX_COUNT_OF_NUMBER = (1 << BITS_PER_NUM);
const short ThreeMultiSet::BITS_IN_BYTE = 8;
const short ThreeMultiSet::NUMS_IN_BUCKET = sizeof(uint32_t) * BITS_IN_BYTE / BITS_PER_NUM;

void ThreeMultiSet::copyFrom(const ThreeMultiSet& other)
{
	buckets = new uint32_t[other.size];
	size = other.size;
	u = other.u;

	for (int i = 0; i < size; i++)
	{
		buckets[i] = other.buckets[i];
	}
}

void ThreeMultiSet::moveFrom(ThreeMultiSet&& other)
{
	buckets = other.buckets;
	other.buckets = nullptr;

	size = other.size;
	u = other.u;

	other.size = other.u = 0;
}

void ThreeMultiSet::free()
{
	delete[] buckets;
}

size_t ThreeMultiSet::bucket(size_t num) const
{
	return num / NUMS_IN_BUCKET;
}

size_t ThreeMultiSet::position(size_t num) const
{
	return MAX_COUNT_OF_NUMBER << shift(num);
}

size_t ThreeMultiSet::shift(size_t num) const
{
	return BITS_PER_NUM * (NUMS_IN_BUCKET - 1 - num % NUMS_IN_BUCKET);
}

void ThreeMultiSet::replace(size_t num, size_t count)
{
	size_t bucketIdx = bucket(num);

	buckets[bucketIdx] &= ~position(num);
	buckets[bucketIdx] |= (count << shift(num));
}

ThreeMultiSet::ThreeMultiSet(): ThreeMultiSet(DEFAULT_U) {}

ThreeMultiSet::ThreeMultiSet(size_t u)
{
	this->u = u;
	this->size = (bucket(u - 1) + 1);
	this->buckets = new uint32_t[size];
}

ThreeMultiSet::ThreeMultiSet(const ThreeMultiSet& other)
{
	copyFrom(other);
}

ThreeMultiSet& ThreeMultiSet::operator=(const ThreeMultiSet& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

ThreeMultiSet::ThreeMultiSet(ThreeMultiSet&& other) noexcept
{
	moveFrom(std::move(other));
}

ThreeMultiSet& ThreeMultiSet::operator=(ThreeMultiSet&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

ThreeMultiSet::~ThreeMultiSet()
{
	free();
}

size_t ThreeMultiSet::getU() const
{
	return u;
}

void ThreeMultiSet::insert(size_t num)
{
	size_t countNum = count(num);
	if (num >= u || countNum > MAX_COUNT_OF_NUMBER)
	{
		return;
	}

	countNum++;
	replace(num, countNum);
}

void ThreeMultiSet::remove(size_t num)
{
	size_t countNum = count(num);
	if (num >= u || countNum == 0)
	{
		return;
	}

	countNum--;
	replace(num, countNum);
}

int ThreeMultiSet::count(size_t num) const
{
	if (num >= u)
	{
		return 0;
	}

	size_t bucketIdx = bucket(num);
	return(buckets[bucketIdx] & position(num)) >> shift(num);
}

void ThreeMultiSet::printAll() const
{
	for (int i = 0; i < u; i++)
	{
		size_t countNum = count(i);
		while (countNum--)
		{
			std::cout << i << ' ';
		}
	}
}

ThreeMultiSet intersect(const ThreeMultiSet& lhs, const ThreeMultiSet& rhs)
{
	ThreeMultiSet res(std::min(lhs.u, rhs.u));

	for (int i = 0; i < res.u; i++)
	{
		size_t countI = std::min(lhs.count(i), rhs.count(i));
		res.replace(i, countI);
	}

	return res;
}
