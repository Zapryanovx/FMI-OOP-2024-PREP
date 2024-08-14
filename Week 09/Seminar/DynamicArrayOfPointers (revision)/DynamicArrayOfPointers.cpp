#include "DynamicArrayOfPointers.h"

void DynamicArrayOfPointers::resize(size_t newCap)
{
	if (_capacity >= newCap)
	{
		return;
	}

	A** newDataPtr = new A * [newCap] { nullptr};

	for (int i = 0; i < _capacity; i++)
	{
		newDataPtr[i] = _data[i];
	}

	delete[] _data;
	_data = newDataPtr;

	_capacity = newCap;
}

void DynamicArrayOfPointers::copyFrom(const DynamicArrayOfPointers& other)
{
	_data = new A * [other._capacity];

	for (int i = 0; i < other._capacity; i++)
	{
		if (other._data[i] == nullptr)
		{
			_data[i] = nullptr;
		}

		else
		{
			_data[i] = new A(*other._data[i]);
		}
	}

	_count = other._count;
	_capacity = other._capacity;

}

void DynamicArrayOfPointers::moveFrom(DynamicArrayOfPointers&& other) 
{
	_data = other._data;
	other._data = nullptr;

	_count = other._count;
	_capacity = other._capacity;

	_count = _capacity = 0;
}

void DynamicArrayOfPointers::free()
{
	for (int i = 0; i < _capacity; i++)
	{
		delete _data[i];
	}

	delete[] _data;
}

DynamicArrayOfPointers::DynamicArrayOfPointers()
{
	_capacity = 8;
	_data = new A * [_capacity] {nullptr};
}

DynamicArrayOfPointers::DynamicArrayOfPointers(const DynamicArrayOfPointers& other)
{
	copyFrom(other);
}

DynamicArrayOfPointers& DynamicArrayOfPointers::operator=(const DynamicArrayOfPointers& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

DynamicArrayOfPointers::DynamicArrayOfPointers(DynamicArrayOfPointers&& other) noexcept
{
	moveFrom(std::move(other));
}

DynamicArrayOfPointers& DynamicArrayOfPointers::operator=(DynamicArrayOfPointers&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

DynamicArrayOfPointers::~DynamicArrayOfPointers()
{
	free();
}

int DynamicArrayOfPointers::getFirstFreeIndex() const
{
	for (int i = 0; i < _capacity; i++)
	{
		if (_data[i] == nullptr)
		{
			return i;
		}
	}

	return -1;
}

void DynamicArrayOfPointers::addAtFirstFreeIndex(const A& obj)
{
	if (_count >= _capacity)
	{
		resize(_capacity * 2);
	}

	int ind = getFirstFreeIndex();
	if (ind == -1)
	{
		return;
	}

	_data[ind] = new A(obj);
	_count++;
}

void DynamicArrayOfPointers::addAtFirstFreeIndex(A&& obj)
{
	if (_count >= _capacity)
	{
		resize(_capacity * 2);
	}

	int ind = getFirstFreeIndex();
	if (ind == -1)
	{
		return;
	}

	_data[ind] = new A(std::move(obj));
	_count++;
}

bool DynamicArrayOfPointers::containsAt(unsigned ind) const
{
	return ind < _capacity && _data[ind] != nullptr;
}

void DynamicArrayOfPointers::popBack()
{
	if (size() == 0)
	{
		return;
	}

	for (int i = _capacity - 1; i >= 0; i--)
	{
		if (_data[i] != nullptr)
		{
			delete _data[i];
			_count--;
			break;
		}
	}

	if (_count == _capacity / 4 && _capacity > 1)
	{
		resize(_capacity / 2);
	}
}

void DynamicArrayOfPointers::removeAt(size_t index)
{
	if (index >= _capacity || _data[index] == nullptr)
	{
		return;
	}

	delete _data[index];
	_data[index] = nullptr;
	_count--;

	if (_count == _capacity / 4 && _capacity > 1)
	{
		resize(_capacity / 2);
	}
}

void DynamicArrayOfPointers::setAtIndex(const A& obj, size_t index)
{
	if (index >= _capacity) //what if index >= _capacity * 2 ?
	{
		resize(_capacity * 2);
	}

	if (_data[index] != nullptr)
	{
		_data[index]->operator=(obj);
	}

	else
	{
		_data[index] = new A(obj);
		_count++;
	}
}

void DynamicArrayOfPointers::setAtIndex(A&& obj, size_t index)
{
	if (index >= _capacity) //what if index >= _capacity * 2 ?
	{
		resize(_capacity * 2);
	}

	if (_data[index] != nullptr)
	{
		_data[index]->operator=(std::move(obj));
	}

	else
	{
		_data[index] = new A(std::move(obj));
		_count++;
	}
}

const A& DynamicArrayOfPointers::operator[](size_t index) const
{
	return *_data[index]; //nullptr possibility
}

A& DynamicArrayOfPointers::operator[](size_t index)
{
	return *_data[index]; //nullptr possibility
}

size_t DynamicArrayOfPointers::size() const
{
	return _count;
}
