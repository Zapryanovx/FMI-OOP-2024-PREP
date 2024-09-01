#include "CreatureContainer.h"

void CreatureContainer::copyFrom(const CreatureContainer& other)
{
	size = other.size;
	capacity = other.capacity;

	data = new Creature * [capacity];
	for (int i = 0; i < size; i++)
	{
		data[i] = other.data[i]->clone();
	}
}

void CreatureContainer::moveFrom(CreatureContainer&& other)
{
	data = other.data;
	other.data = nullptr;

	size = other.size;
	capacity = other.capacity;

	other.size = other.capacity = 0;
}

void CreatureContainer::free()
{
	for (int i = 0; i < size; i++)
	{
		delete data[i];
	}

	delete[] data;
}

void CreatureContainer::resize(size_t newCap)
{
	Creature** newData = new Creature * [newCap];
	for (int i = 0; i < size; i++)
	{
		newData[i] = data[i];
	}

	delete[] data;
	data = newData;
	newData = nullptr;

	capacity = newCap;
}

CreatureContainer::CreatureContainer()
{
	capacity = 8;
	data = new Creature*[capacity];
}

CreatureContainer::CreatureContainer(const CreatureContainer& other)
{
	copyFrom(other);
}

CreatureContainer& CreatureContainer::operator=(const CreatureContainer& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

CreatureContainer::CreatureContainer(CreatureContainer&& other) noexcept
{
	moveFrom(std::move(other));
}

CreatureContainer& CreatureContainer::operator=(CreatureContainer&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

CreatureContainer::~CreatureContainer()
{
	free();
}

const Creature* CreatureContainer::getCreature(size_t index) const
{
	if (index >=size)
	{
		throw std::out_of_range("Invalid index");
	}

	return data[index];
}

Creature* CreatureContainer::getCreature(size_t index)
{
	if (index >= size)
	{
		throw std::out_of_range("Invalid index");
	}

	return data[index];
}

void CreatureContainer::addCreature(const Creature& obj)
{
	if (size == capacity)
	{
		resize(capacity * 2);
	}

	data[size++] = obj.clone();
}

void CreatureContainer::removeCreature(size_t index)
{
	if (index >= size)
	{
		return;
	}

	delete data[index];
	std::swap(data[index], data[size - 1]);
	size--;
}

size_t CreatureContainer::fight(size_t index) const
{
	if (index >= size)
	{
		throw std::out_of_range("Invalid index");
	}

	size_t winCount = 0;
	for (int i = 0; i < size; i++)
	{
		if (i != index)
		{
			if (data[i]->fightWith(data[index]) == 1)
			{
				winCount++;
			}
		}
	}

	return winCount;
}
