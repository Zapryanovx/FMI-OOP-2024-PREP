#include <iostream>
#include "Farm.h"
#include "Animal.h"
#include "AnimalFactory.h"

int main()
{
	Farm f;
	f.addAnimal(AnimalType::Dog);
	f.addAnimal(AnimalType::Cat);
	f.addAnimal(AnimalType::Cow);

	f.roarAll();

	std::cout << (int)f.getTypeByIndex(0) << std::endl;
}