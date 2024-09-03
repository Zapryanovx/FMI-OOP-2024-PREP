#pragma once
#include <iostream>

class ThreeMultiSet
{
public:
	static const short BITS_PER_NUM;
	static const short MAX_COUNT_OF_NUMBER;
	static const short BITS_IN_BYTE;
	static const short NUMS_IN_BUCKET;

private:
	uint32_t* buckets;
	size_t size;
	size_t u;

	void copyFrom(const ThreeMultiSet& other);
	void moveFrom(ThreeMultiSet&& other);
	void free();

	size_t bucket(size_t num) const;
	size_t position(size_t num) const;
	void replace(size_t num, size_t count);
	size_t shift(size_t num) const;

public:
	ThreeMultiSet();
	explicit ThreeMultiSet(size_t u);
	
	ThreeMultiSet(const ThreeMultiSet& other);
	ThreeMultiSet& operator=(const ThreeMultiSet& other);

	ThreeMultiSet(ThreeMultiSet&& other) noexcept;
	ThreeMultiSet& operator=(ThreeMultiSet&& other) noexcept;

	~ThreeMultiSet();

	size_t getU() const;

	void insert(size_t num);
	void remove(size_t num);
	int count(size_t num) const;

	void printAll() const;

	friend ThreeMultiSet intersect(const ThreeMultiSet& lhs, const ThreeMultiSet& rhs);
	
};

