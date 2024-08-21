#include "Farm.h"
#include "AnimalFactory.h"

void Farm::copyFrom(const Farm& other)
{
	animals = new Animal * [other.capacity];
	animalCount = other.animalCount;
	capacity = other.capacity;

	for (int i = 0; i < other.animalCount; i++)
	{
		Animal* cloned = other.animals[i]->clone();
		
		if (cloned) //nullptr check
		{
			animals[i] = cloned;
		}
	}
}

void Farm::moveFrom(Farm&& other)
{
	animals = other.animals;
	other.animals = nullptr;

	animalCount = other.animalCount;
	capacity = other.capacity;
	
	other.animalCount = other.capacity = 0;
}

void Farm::free()
{
	for (int i = 0; i < animalCount; i++)
	{
		delete animals[i];
	}
	delete[] animals;
}

void Farm::resize()
{
	capacity *= 2;
	Animal** newAnimals = new Animal * [capacity];

	for (int i = 0; i < animalCount; i++)
	{
		newAnimals[i] = animals[i];
	}

	delete[] animals;
	animals = newAnimals;
}

Farm::Farm()
{
	capacity = 8;
	animalCount = 0;
	animals = new Animal * [capacity];
}

Farm::Farm(const Farm& other)
{
	copyFrom(other);
}

Farm& Farm::operator=(const Farm& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Farm::~Farm()
{
	free();
}

Farm::Farm(Farm&& other) noexcept
{
	moveFrom(std::move(other));
}

Farm& Farm::operator=(Farm&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

void Farm::addAnimal(AnimalType animalType)
{
	if (animalCount == capacity)
	{
		resize();
	}

	animals[animalCount++] = animalFactory(animalType);
}

void Farm::addAnimal(const Animal& animal)
{
	if (animalCount == capacity)
	{
		resize();
	}

	animals[animalCount++] = animal.clone();
}

void Farm::roarAll() const
{
	for (int i = 0; i < animalCount; i++)
	{
		animals[i]->roar();
	}
}

AnimalType Farm::getTypeByIndex(unsigned index) const
{
	if (index > animalCount)
	{
		throw std::out_of_range("Invalid index");
	}

	return animals[index]->getType();
}