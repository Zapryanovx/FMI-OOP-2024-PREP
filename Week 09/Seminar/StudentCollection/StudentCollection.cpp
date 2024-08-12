﻿#include "StudentCollection.h"

void StudentCollection::free()
{
	for (int i = 0; i < capacity; i++)
	{
		delete data[i];
	}

	delete[] data;
}

void StudentCollection::copyFrom(const StudentCollection& other)
{
	size = other.size;
	capacity = other.capacity;

	data = new Student*[other.capacity];
	for (int i = 0; i < other.capacity; i++)
	{
		if (other.data[i] != nullptr)
		{
			data[i] = new Student(*other.data[i]);
		}
	}


}

void StudentCollection::moveFrom(StudentCollection&& other)
{
	data = other.data;
	other.data = nullptr;

	size = other.size;
	capacity = other.capacity;
	
	other.size = other.capacity = 0;
}

void StudentCollection::resize(size_t newCap)
{
	if (newCap <= capacity)
	{
		return;
	}

	Student** newData = new Student * [newCap] { nullptr };

	for (int i = 0; i < capacity; i++)
	{
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;
	capacity = newCap;
}

size_t StudentCollection::getFirstFreeIndex() const
{
	for (int i = 0; i < capacity; i++)
	{
		if (data[i] == nullptr)
		{
			return i;
		}
	}

	return capacity;
}

StudentCollection::StudentCollection(): size(0), capacity(8)
{
	data = new Student * [capacity] { nullptr };
}

StudentCollection::StudentCollection(const StudentCollection& other)
{
	copyFrom(other);
}

StudentCollection& StudentCollection::operator=(const StudentCollection& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

void StudentCollection::pushAt(size_t idx, const Student& other)
{
	if (idx > capacity)
	{
		throw std::out_of_range("StudentCollection::pushAt invalid");
	}

	if (data[idx] == nullptr)
	{
		data[idx] = new Student(other);
		size++;
	}

	else
	{
		*data[idx] = other;
	}
}

void StudentCollection::pushAt(size_t idx, Student&& other)
{
	if (idx > capacity)
	{
		throw std::out_of_range("StudentCollection::pushAt invalid");
	}
	
	if (data[idx] == nullptr)
	{
		data[idx] = new Student(std::move(other));
		size++;
	}

	else
	{
		*data[idx] = std::move(other);
	}
}

void StudentCollection::push(const Student& other)
{
	size_t index = getFirstFreeIndex();
	
	if (index == capacity)
	{
		resize(capacity + capacity / 2);
	}
	
	pushAt(index, other);
}

void StudentCollection::push(Student&& other)
{
	size_t index = getFirstFreeIndex();

	if (index == capacity)
	{
		resize(capacity + capacity / 2);
	}

	pushAt(index, std::move(other)); // [!]
}

void StudentCollection::removeAt(size_t idx)
{
	if (idx >= capacity)
	{
		throw std::out_of_range("StudentCollection::removeAt invalid index");
	}

	//ако няма студент на този индекс, няма какво да махнем
	if (!contains(idx))
	{
		return;
	}

	delete data[idx];
	data[idx] = nullptr;
	size--;
}

bool StudentCollection::contains(size_t idx) const
{
	return (data[idx] != nullptr);
}

const Student& StudentCollection::at(size_t idx) const
{
	if (idx >= capacity)
	{
		throw std::out_of_range("StudentCollection::removeAt invalid index");
	}

	if (!contains(idx))
	{
		throw std::runtime_error("StudentCollection::at trying to access empty object");
	}

	return *data[idx];
}

size_t StudentCollection::getCapacity() const
{
	return capacity;
}

size_t StudentCollection::getSize() const
{
	return size;
}

StudentCollection::StudentCollection(StudentCollection&& other) noexcept
{
	moveFrom(std::move(other));
}

StudentCollection& StudentCollection::operator=(StudentCollection&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

StudentCollection::~StudentCollection()
{
	free();
}