#pragma once

class BitSet
{
private:
	char* data = nullptr;
	size_t limit;
	size_t bucketsCount;

	void free();
	void copyFrom(const BitSet& other);

	size_t bucketsNeeded(size_t n) const;
	size_t getBucket(size_t n) const;
	size_t getPosition(size_t n) const;

public:
	BitSet();
	BitSet(size_t n);

	void addNumber(size_t number);
	void removeNumber(size_t number) const;

	bool hasNumber(size_t number) const;

	void print();

	BitSet(const BitSet& other);
	BitSet& operator=(const BitSet& other);

	friend BitSet Union(const BitSet& lhs, const BitSet& rhs);
	friend BitSet Intersect(const BitSet& lhs, const BitSet& rhs);

	~BitSet();
};

