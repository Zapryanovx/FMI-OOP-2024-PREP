#pragma once
#include "Animal.h"

class Farm
{
	Animal** animals;
	size_t animalCount;
	size_t capacity;

	void copyFrom(const Farm& other);
	void moveFrom(Farm&& other);
	void free();
	
	void resize();

public:

	Farm();
	Farm(const Farm& other);
	Farm& operator=(const Farm& other);
	~Farm();

	Farm(Farm&& other) noexcept;
	Farm& operator=(Farm&& other) noexcept;

	void addAnimal(AnimalType animalType);
	void addAnimal(const Animal& animal);
	void roarAll() const;

	AnimalType getTypeByIndex(unsigned index) const;
};

