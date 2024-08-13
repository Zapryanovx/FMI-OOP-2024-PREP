#include "DynamicSet.h"

void DynamicSet::free()
{
	delete[] buckets;
	buckets = nullptr;

	bucketsCount = 0;
}

void DynamicSet::copyFrom(const DynamicSet& other)
{
	buckets = new uint8_t[other.bucketsCount];
	bucketsCount = other.bucketsCount;
	N = other.N;

	for (int i = 0; i < other.bucketsCount; i++)
	{
		buckets[i] = other.buckets[i];
	}

}

unsigned DynamicSet::getBucketIndex(unsigned num) const
{
	return num / elementsInBucket;
}

unsigned DynamicSet::getBucketCount(unsigned num) const
{
	if (num % elementsInBucket != 0)
	{
		return num / elementsInBucket + 1;
	}

	return num / elementsInBucket;
}

DynamicSet::DynamicSet(unsigned N)
{
	bucketsCount = getBucketCount(N);
	buckets = new uint8_t[bucketsCount]{ 0 };
	this->N = N;
}

DynamicSet::DynamicSet(const DynamicSet& other)
{
	copyFrom(other);
}

DynamicSet& DynamicSet::operator=(const DynamicSet& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

DynamicSet::~DynamicSet()
{
	free();
}

void DynamicSet::add(unsigned num)
{
	if (num > N)
	{
		return;
	}

	unsigned bucketIndex = getBucketIndex(num);
	unsigned bitIndex = num % elementsInBucket;

	uint8_t mask = 1 << bitIndex;
	buckets[bucketIndex] |= mask;
}

void DynamicSet::remove(unsigned num)
{
	if (num > N)
	{
		return;
	}

	unsigned bucketIndex = getBucketIndex(num);
	unsigned bitIndex = num % elementsInBucket;

	uint8_t mask = ~(1 << bitIndex);
	buckets[bucketIndex] &= mask;
}

bool DynamicSet::contains(unsigned num) const
{
	if (num >= N)
	{
		return false;
	}

	unsigned bucketIndex = getBucketIndex(num);
	unsigned bitIndex = num % elementsInBucket;

	uint8_t mask = (1 << bitIndex);
	return buckets[bucketIndex] & mask;
}

unsigned  DynamicSet::getN() const
{
	return N;
}

void DynamicSet::print() const
{
	std::cout << '{';

	for (int i = 0; i <= N; i++)
	{
		if (contains(i))
		{
			std::cout << i << " ";
		}
	}

	std::cout << '}' << std::endl;
}


void DynamicSet::removeAll()
{
	for (int i = 0; i < bucketsCount; i++)
	{
		buckets[i] = 0;
	}
}

DynamicSet UnionOfSets(const DynamicSet& lhs, const DynamicSet& rhs)
{
	DynamicSet result(std::max(lhs.N, rhs.N));
	unsigned minBucketsCount = std::min(lhs.bucketsCount, rhs.bucketsCount);

	for (int i = 0; i < minBucketsCount; i++)
	{
		result.buckets[i] = lhs.buckets[i] | rhs.buckets[i];
	}

	const DynamicSet& biggerN = lhs.bucketsCount > rhs.bucketsCount ? lhs : rhs;

	for (int i = minBucketsCount; i < biggerN.bucketsCount; i++)
	{
		result.buckets[i] = biggerN.buckets[i];
	}

	return result;
}

DynamicSet IntersectionOfSets(const DynamicSet& lhs, const DynamicSet& rhs)
{
	DynamicSet result(std::min(lhs.N, rhs.N));
	unsigned minBucketCount = std::min(lhs.bucketsCount, rhs.bucketsCount);

	for (int i = 0; i < minBucketCount; i++)
	{
		result.buckets[i] = lhs.buckets[i] & rhs.buckets[i];
	}

	return result;
}

