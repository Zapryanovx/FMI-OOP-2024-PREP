#include "DynamicArrayOfA.h"

static size_t closestPowerOfTwo(size_t n)
{
	n--;

	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;
	n |= n >> 32;

	return n + 1;
}

void DynamicArray::resize(size_t newCap)
{
	if (newCap <= capacity)
	{
		return; 
	}

	A* newArr = new A[newCap];
	for (int i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}

	capacity = newCap;
	delete[] arr;
	arr = newArr;
}

void DynamicArray::copyFrom(const DynamicArray& other)
{
	arr = new A[other.capacity];
	for (int i = 0; i < other.size; i++)
	{
			arr[i] = other.arr[i];
	}

	size = other.size;
	capacity = other.capacity;

}

void DynamicArray::moveFrom(DynamicArray&& other)
{
	arr = other.arr;
	other.arr = nullptr;

	size = other.size;
	capacity = other.capacity;

	other.size = other.capacity = 0;
}

void DynamicArray::free()
{
	delete[] arr;
}

DynamicArray::DynamicArray(): DynamicArray(8) {}

DynamicArray::DynamicArray(size_t capacity) : size(0)
{
	this->capacity = closestPowerOfTwo(capacity);
	arr = new A[this->capacity];
}

DynamicArray::DynamicArray(const DynamicArray& other)
{
	copyFrom(other);
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

DynamicArray::DynamicArray(DynamicArray&& other) noexcept
{
	moveFrom(std::move(other));
}

DynamicArray& DynamicArray::operator=(DynamicArray&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

DynamicArray::~DynamicArray()
{
	free();
}

void DynamicArray::pushBack(const A& newElem)
{
	if (size >= capacity)
	{
		resize(capacity * 2);
	}

	arr[size++] = newElem;
}

void DynamicArray::pushBack(A&& newElem)
{
	if (size >= capacity)
	{
		resize(capacity * 2);
	}

	arr[size++] = std::move(newElem);
}

void DynamicArray::popBack()
{
	if (size != 0)
	{
		size--;
	}

	else
	{
		throw std::length_error("Already empty!");
	}

	if (size * 4 <= capacity && capacity > 1)
	{
		resize(capacity / 2);
	}
}

void DynamicArray::setAtIndex(const A& element, size_t index)
{
	if (index >= size)
	{
		throw std::length_error("No such index!");
	}

	arr[index] = element;
}

void DynamicArray::setAtIndex(A&& element, size_t index)
{
	if (index >= size)
	{
		throw std::length_error("No such index!");
	}

	arr[index] = std::move(element);
}

size_t DynamicArray::getSize() const
{
	return size;
}

bool DynamicArray::isEmpty() const
{
	return size == 0;
}

const A& DynamicArray::operator[](size_t index) const
{
	if (index >= size)
	{
		throw std::length_error("No such index!");
	}

	return arr[index];
}

A& DynamicArray::operator[](size_t index)
{
	if (index >= size)
	{
		throw std::length_error("No such index!");
	}

	return arr[index];
}
