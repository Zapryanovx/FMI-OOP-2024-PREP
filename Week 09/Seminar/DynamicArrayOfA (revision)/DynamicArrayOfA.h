#pragma once
#include <iostream>

struct A
{
	int a = 4;
	int b = 3;
};

class DynamicArray
{
private:
	A* arr = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void resize(size_t newCap);

	void copyFrom(const DynamicArray& other);
	void moveFrom(DynamicArray&& other);
	void free();

public:
	DynamicArray();
	DynamicArray(size_t capacity);
	
	DynamicArray(const DynamicArray& other);
	DynamicArray& operator=(const DynamicArray& other);

	DynamicArray(DynamicArray&& other) noexcept;
	DynamicArray& operator=(DynamicArray&& other) noexcept;

	~DynamicArray();

	void pushBack(const A& newElem);
	void pushBack(A&& newElem);

	void popBack();

	void setAtIndex(const A& element, size_t index);
	void setAtIndex(A&& element, size_t index);

	size_t getSize() const;
	bool isEmpty() const;

	const A& operator[](size_t index) const;
	A& operator[](size_t index);
};

