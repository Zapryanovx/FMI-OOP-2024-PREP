#pragma once
#include <iostream>

struct A
{
	int x = 3;
	int y = 2;
};

class DynamicArrayOfPointers
{
	A** _data = nullptr;	
	size_t _capacity = 0;
	size_t _count = 0;

	void resize(size_t newCap);
	int getFirstFreeIndex() const;

	void copyFrom(const DynamicArrayOfPointers& other);
	void moveFrom(DynamicArrayOfPointers&& other);
	void free();

public:
	DynamicArrayOfPointers();

	DynamicArrayOfPointers(const DynamicArrayOfPointers& other);
	DynamicArrayOfPointers& operator=(const DynamicArrayOfPointers& other);

	DynamicArrayOfPointers(DynamicArrayOfPointers&& other) noexcept;
	DynamicArrayOfPointers& operator=(DynamicArrayOfPointers&& other) noexcept;

	~DynamicArrayOfPointers();

	void addAtFirstFreeIndex(const A& obj);
	void addAtFirstFreeIndex(A&& obj);

	bool containsAt(unsigned ind) const;
	void popBack();
	void removeAt(size_t index);

	void setAtIndex(const A& obj, size_t index);
	void setAtIndex(A&& obj, size_t index);

	size_t size() const;
	const A& operator[](size_t index) const;
	A& operator[](size_t index);
};


